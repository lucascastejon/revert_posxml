#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "revert_posxml.h"

int main(int argc, char const *argv[])
{
	FILE * pFile;
	long lSize;
	size_t result;
	
	if(argv[1] == NULL)
		exit(1);

	// Open file to read
	dest_file = fopen ( "saida.xml" , "w" );
	if (dest_file==NULL) {fputs ("Dest File error\n",stderr); exit (1);}

	pFile = fopen ( argv[1] , "r" );
  	if (pFile==NULL) {fputs ("File error\n",stderr); fclose(dest_file); exit (1);}

  	fwrite (header_buff , sizeof(char), sizeof(header_buff), dest_file);

  	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

  	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error\n",stderr); fclose(dest_file); fclose(pFile); exit (2);}

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error\n",stderr); fclose(dest_file); fclose(pFile); free (buffer); exit (3);}

	// close file
	fclose (pFile);

	for(file_ptr = 0 ; file_ptr < result ; file_ptr++)
	{
		// printf("%02X ",buffer[file_ptr] );
		write_buff_func(buffer[file_ptr]);
	}

	fwrite (bottom_buff , sizeof(char), sizeof(bottom_buff), dest_file);
	
	// free memory
	free (buffer);
	// close file
	fclose (dest_file);
	return 0;
}

void write_var_int(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<variavelint valor=%s variavel=%s />\n",param1,param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_var_str(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<variavelstr valor=%s variavel=%s />\n",param1,param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_sys_backlight(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<system.backlight nivel=%s variavelretorno=%s />\n",param1,param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_chamafuncao(void)
{
	get_param(param1);
	
	insert_tabs();
	sprintf(write_buffer,"<chamafuncao nome=%s />\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_funcao(void)
{
	get_param(param1);
	
	insert_tabs();
	sprintf(write_buffer,"<funcao nome=%s >\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_endfuncao(void)
{
	
	insert_tabs();
	sprintf(write_buffer,"</funcao>\n");

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_if(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	
	insert_tabs();
	sprintf(write_buffer,"<if operador=%s  valor=%s variavel=%s >\n",param2,param3,param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_endif(void)
{
	
	insert_tabs();
	sprintf(write_buffer,"</if>\n");

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_com_else(void)
{
	
	insert_tabs();
	sprintf(write_buffer,"<else/>\n");

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_emv_settimeout(void)
{
	
	get_param(param1);
	get_param(param2);
	
	insert_tabs();
	sprintf(write_buffer,"<emv.settimeout segundos=%s variavelretorno=%s />\n",param1,param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_int_to_string(void)
{
	
	get_param(param1);
	get_param(param2);
	
	insert_tabs();
	sprintf(write_buffer,"<inttostring variavelint=%s variavelstr=%s />\n",param1,param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_soma_string(void)
{
	
	get_param(param1);
	get_param(param2);
	get_param(param3);
	
	insert_tabs();
	sprintf(write_buffer,"<somastring valor1=%s valor2=%s variaveldestino=%s />\n",param1,param2,param3);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_imprima(void)
{
	
	get_param(param1);

	insert_tabs();
	sprintf(write_buffer,"<imprima mensagem=%s />\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_emv_adddata(void)
{
	
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);

	insert_tabs();
	sprintf(write_buffer,"<emv.adddata parametro=%s tipo=%s valor=%s variavelretorno=%s />\n",param2, param1, param3, param4);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_emv_inittransaction(void)
{
	
	get_param(param1);
	
	insert_tabs();
	sprintf(write_buffer,"<emv.inittransaction variavelretorno=%s />\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_emv_getinfo(void)
{
	
	get_param(param1);
	get_param(param2);
	get_param(param3);

	insert_tabs();
	sprintf(write_buffer,"<emv.getinfo parametro=%s tipo=%s valor=%s />\n",param2, param1, param3);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_emv_processtransaction(void)
{
	
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<emv.processtransaction ctls=%s variavelretorno=%s />\n",param2, param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_editaarquivo(void)
{
	
	get_param(param1);
	get_param(param2);
	get_param(param3);

	insert_tabs();
	sprintf(write_buffer,"<editaarquivo chave=%s nomearquivo=%s valor=%s />\n",param2, param1, param3);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_preconexao(void)
{
	
	get_param(param1);

	insert_tabs();
	sprintf(write_buffer,"<preconexao variavelstatus=%s />\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}

void write_comando_substring(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_comando_stringtoint(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<stringtoint variavelint=%s variavelstr=%s/>\n",param2, param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_display(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);

	insert_tabs();
	sprintf(write_buffer,"<display coluna=%s linha=%s mensagem=%s/>\n",param2, param1, param3);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_imprimagrande(void)
{
	get_param(param1);

	insert_tabs();
	sprintf(write_buffer,"<imprimagrande mensagem=%s />\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_digitainteiro(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);
	get_param(param5);
	get_param(param6);

	insert_tabs();
	sprintf(write_buffer,"<digitainteiro coluna=%s linha=%s maximo=%s mensagem=%s minimo=%s variavel=%s />\n",param3, param2, param6, param4, param5 ,param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_digitaopcao(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);
	get_param(param5);
	get_param(param6);

	insert_tabs();
	sprintf(write_buffer,"<digitaopcao coluna=%s linha=%s maximo=%s mensagem=%s minimo=%s variavel=%s />\n",param3, param2, param6, param4, param5 ,param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_digitavalor(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);

	insert_tabs();
	sprintf(write_buffer,"<digitavalor coluna=%s linha=%s mensagem=%s variavel=%s />\n", param3, param2, param4, param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_digitaformato(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);
	get_param(param5);

	insert_tabs();
	sprintf(write_buffer,"<digitaformato coluna=%s formato=%s linha=%s mensagem=%s variavel=%s />\n",param3, param5, param2, param4, param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_desligamodem(void)
{
	insert_tabs();
	sprintf(write_buffer,"<desligamodem/>\n");

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_pegacartaoevariavel(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_esperatecla(void)
{
	insert_tabs();
	sprintf(write_buffer,"<esperatecla/>\n");

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_espera(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_limpadisplay(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_paperfeed(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_esperateclatimeout(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_getvaluebykey(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_menu(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_learquivo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_variavelintoperador(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_ajustadatahora(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pegadatahora(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_verificapapelimpressora(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_digitadecimal(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_operacaomatematica(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_excluiarquivo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_imprimacodigodebarras(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_execute(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_comando_While(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_comando_EndWhile(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_comando_break(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_openserialport(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_readserialport(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_writeserialport(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_closeserialport(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_length(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer, "<string.length valor=%s variavelretorno=%s />\n",param1, param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_comando_exit(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_baixaarquivo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_diferencadatahora(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_learquivobyindex(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_mostrabitmap(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_imprimabitmap(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_letecla(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_unzipfile(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_conversaointeiro(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_iniciatabelacampos(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_iniciamensagem(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_analisamensagem(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_finalizamensagem(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_inserecampo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_pegacampo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_charat(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_trim(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_find(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_replace(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_substring(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);

	insert_tabs();
	sprintf(write_buffer,"<string.substring length=%s start=%s string=%s variavelretorno=%s />\n",param3, param2, param1, param4);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_string_elements(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_insertat(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_replaceat(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_elementat(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_removeat(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_send(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);

	insert_tabs();
	sprintf(write_buffer,"<network.send buffer=%s tamanho=%s variavelretorno=%s/>\n",param1, param2, param3);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_network_receive(void)
{
	get_param(param1);
	get_param(param2);
	get_param(param3);
	get_param(param4);

	insert_tabs();
	sprintf(write_buffer,"<network.receive tamanhomaximo=%s variavelbuffer=%s variavelbytesrecebidos=%s variavelretorno=%s />\n",param2, param1, param3, param4);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_system_restart(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_filesystem_filesize(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_filesystem_space(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_filesystem_listfiles(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_filesystem_renamefile(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_convert_toint(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_predial(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_checkgprssignal(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_checkbattery(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_ping(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_beep(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_readcard(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_hostdisconnect(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_transactmessage(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_smartcard_cartaoinserido(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_smartcard_inicialeitor(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_smartcard_transmitAPDU(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_smartcard_fechaleitor(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_tohex(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<string.tohex string=%s variavelretorno=%s />\n",param1, param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_string_fromhex(void)
{
	get_param(param1);
	get_param(param2);

	insert_tabs();
	sprintf(write_buffer,"<string.fromhex string=%s variavelretorno=%s />\n",param1, param2);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_crypto_encryptdecrypt(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_gettouchscreen(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_crypto_lrc(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_crypto_xor(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_crypto_crc(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_info(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_open(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_display(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_getkey(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_getpindukpt(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_loadipek(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_pinpad_close(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_emv_open(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_emv_close(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_emv_loadtables(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_emv_cleanstructures(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_emv_finishtransaction(void)
{
	get_param(param1);

	insert_tabs();
	sprintf(write_buffer,"<emv.finishtransaction variavelretorno=%s/>\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_emv_removecard(void)
{
	get_param(param1);

	insert_tabs();
	sprintf(write_buffer,"<emv.removecard variavelretorno=%s/>\n",param1);

	fwrite(write_buffer, sizeof(char), strlen(write_buffer), dest_file);
	go_to_next_command();
}
void write_func_parseticket(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_menu_header(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_input_getvalue(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_file_open(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_file_close(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_file_read(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_file_write(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_string_pad(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_time_calculate(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_inputtransaction(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_update(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_qrcode(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_iso8583_transactmessagesubcampo(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_start(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_coapsend(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_network_coapreceive(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
void write_func_system_activate(void)
{
	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
	exit(10);
}
// void write_func_pegacartao(void)
// {
// 	printf("comando nao encontrado %02X\n", buffer[file_ptr]);
// 	exit(10);
// }

void write_buff_func(unsigned char function)
{
	free_prams_values();
	fwrite("\t\t", sizeof(char), strlen("\t\t"), dest_file);
	switch(function)
	{
		case comando_variavelint:
			write_var_int();
			break;
		case comando_variavelstr:
			write_var_str();
			break;
		case func_system_backlight:
			write_sys_backlight();
			break;
		case comando_chamafuncao:
			remove_jumper();
			write_com_chamafuncao();
			break;
		case comando_funcao:
			remove_jumper();
			write_com_funcao();
			tab_index++;
			break;
		case comando_EndFuncao:
			tab_index--;
			write_com_endfuncao();
			break;
		case comando_IF:
			remove_jumper();
			write_com_if();
			tab_index++;
			break;
		case comando_EndIF:
			tab_index--;
			write_com_endif();
			break;
		case comando_Else:
			remove_jumper();
			tab_index--;
			write_com_else();
			tab_index++;
			break;
		case func_emv_settimeout:
			write_emv_settimeout();
			break;
		case comando_inttostring:
			write_int_to_string();
			break;
		case func_somastring:
			write_soma_string();
			break;
		case func_imprima:
			write_imprima();
			break;
		case func_emv_adddata:
			write_emv_adddata();
			break;
		case func_emv_inittransaction:
			write_emv_inittransaction();
			break;
		case func_emv_getinfo:
			write_emv_getinfo();
			break;
		case func_emv_processtransaction:
			write_emv_processtransaction();
			break;
		case func_editaarquivo:
			write_editaarquivo();
			break;
		case func_preconexao:
			write_preconexao();
			break;
		case comando_substring:
			write_comando_substring();
			break;
		case comando_stringtoint:
			write_comando_stringtoint();
			break;
		case func_display:
			write_func_display();
			break;
		case func_imprimagrande:
			write_func_imprimagrande();
			break;
		case func_digitainteiro:
			write_func_digitainteiro();
			break;
		case func_digitaopcao:
			write_func_digitaopcao();
			break;
		case func_digitavalor:
			write_func_digitavalor();
			break;
		case func_digitaformato:
			write_func_digitaformato();
			break;
		case func_desligamodem:
			write_func_desligamodem();
			break;
		case func_pegacartaoevariavel:
			write_func_pegacartaoevariavel();
			break;
		case func_esperatecla:
			write_func_esperatecla();
			break;
		case func_espera:
			write_func_espera();
			break;
		case func_limpadisplay:
			write_func_limpadisplay();
			break;
		case func_paperfeed:
			write_func_paperfeed();
			break;
		case func_esperateclatimeout:
			write_func_esperateclatimeout();
			break;
		case func_string_getvaluebykey:
			write_func_string_getvaluebykey();
			break;
		case func_menu:
			write_func_menu();
			break;
		case func_learquivo:
			write_func_learquivo();
			break;
		case func_variavelintoperador:
			write_func_variavelintoperador();
			break;
		case func_ajustadatahora:
			write_func_ajustadatahora();
			break;
		case func_pegadatahora:
			write_func_pegadatahora();
			break;
		case func_verificapapelimpressora:
			write_func_verificapapelimpressora();
			break;
		case func_digitadecimal:
			write_func_digitadecimal();
			break;
		case func_operacaomatematica:
			write_func_operacaomatematica();
			break;
		case func_excluiarquivo:
			write_func_excluiarquivo();
			break;
		case func_imprimacodigodebarras:
			write_func_imprimacodigodebarras();
			break;
		case func_execute:
			write_func_execute();
			break;
		case comando_While:
			write_comando_While();
			break;
		case comando_EndWhile:
			write_comando_EndWhile();
			break;
		case comando_break:
			write_comando_break();
			break;
		case func_openserialport:
			write_func_openserialport();
			break;
		case func_readserialport:
			write_func_readserialport();
			break;
		case func_writeserialport:
			write_func_writeserialport();
			break;
		case func_closeserialport:
			write_func_closeserialport();
			break;
		case func_string_length:
			write_func_string_length();
			break;
		case comando_exit:
			write_comando_exit();
			break;
		case func_baixaarquivo:
			write_func_baixaarquivo();
			break;
		case func_diferencadatahora:
			write_func_diferencadatahora();
			break;
		case func_learquivobyindex:
			write_func_learquivobyindex();
			break;
		case func_mostrabitmap:
			write_func_mostrabitmap();
			break;
		case func_imprimabitmap:
			write_func_imprimabitmap();
			break;
		case func_letecla:
			write_func_letecla();
			break;
		case func_unzipfile:
			write_func_unzipfile();
			break;
		case func_conversaointeiro:
			write_func_conversaointeiro();
			break;
		case func_iso8583_iniciatabelacampos:
			write_func_iso8583_iniciatabelacampos();
			break;
		case func_iso8583_iniciamensagem:
			write_func_iso8583_iniciamensagem();
			break;
		case func_iso8583_analisamensagem:
			write_func_iso8583_analisamensagem();
			break;
		case func_iso8583_finalizamensagem:
			write_func_iso8583_finalizamensagem();
			break;
		case func_iso8583_inserecampo:
			write_func_iso8583_inserecampo();
			break;
		case func_iso8583_pegacampo:
			write_func_iso8583_pegacampo();
			break;
		case func_string_charat:
			write_func_string_charat();
			break;
		case func_string_trim:
			write_func_string_trim();
			break;
		case func_string_find:
			write_func_string_find();
			break;
		case func_string_replace:
			write_func_string_replace();
			break;
		case func_string_substring:
			write_func_string_substring();
			break;
		case func_string_elements:
			write_func_string_elements();
			break;
		case func_string_insertat:
			write_func_string_insertat();
			break;
		case func_string_replaceat:
			write_func_string_replaceat();
			break;
		case func_string_elementat:
			write_func_string_elementat();
			break;
		case func_string_removeat:
			write_func_string_removeat();
			break;
		case func_network_send:
			write_func_network_send();
			break;
		case func_network_receive:
			write_func_network_receive();
			break;
		case func_system_restart:
			write_func_system_restart();
			break;
		case func_filesystem_filesize:
			write_func_filesystem_filesize();
			break;
		case func_filesystem_space:
			write_func_filesystem_space();
			break;
		case func_filesystem_listfiles:
			write_func_filesystem_listfiles();
			break;
		case func_filesystem_renamefile:
			write_func_filesystem_renamefile();
			break;
		case func_convert_toint:
			write_func_convert_toint();
			break;
		case func_predial:
			write_func_predial();
			break;
		case func_network_checkgprssignal:
			write_func_network_checkgprssignal();
			break;
		case func_system_checkbattery:
			write_func_system_checkbattery();
			break;
		case func_network_ping:
			write_func_network_ping();
			break;
		case func_system_beep:
			write_func_system_beep();
			break;
		case func_system_readcard:
			write_func_system_readcard();
			break;
		case func_network_hostdisconnect:
			write_func_network_hostdisconnect();
			break;
		case func_iso8583_transactmessage:
			write_func_iso8583_transactmessage();
			break;
		case func_smartcard_cartaoinserido:
			write_func_smartcard_cartaoinserido();
			break;
		case func_smartcard_inicialeitor:
			write_func_smartcard_inicialeitor();
			break;
		case func_smartcard_transmitAPDU:
			write_func_smartcard_transmitAPDU();
			break;
		case func_smartcard_fechaleitor:
			write_func_smartcard_fechaleitor();
			break;
		case func_string_tohex:
			write_func_string_tohex();
			break;
		case func_string_fromhex:
			write_func_string_fromhex();
			break;
		case func_crypto_encryptdecrypt:
			write_func_crypto_encryptdecrypt();
			break;
		case func_system_gettouchscreen:
			write_func_system_gettouchscreen();
			break;
		case func_crypto_lrc:
			write_func_crypto_lrc();
			break;
		case func_crypto_xor:
			write_func_crypto_xor();
			break;
		case func_crypto_crc:
			write_func_crypto_crc();
			break;
		case func_system_info:
			write_func_system_info();
			break;
		case func_pinpad_open:
			write_func_pinpad_open();
			break;
		case func_pinpad_display:
			write_func_pinpad_display();
			break;
		case func_pinpad_getkey:
			write_func_pinpad_getkey();
			break;
		case func_pinpad_getpindukpt:
			write_func_pinpad_getpindukpt();
			break;
		case func_pinpad_loadipek:
			write_func_pinpad_loadipek();
			break;
		case func_pinpad_close:
			write_func_pinpad_close();
			break;
		case func_emv_open:
			write_func_emv_open();
			break;
		case func_emv_close:
			write_func_emv_close();
			break;
		case func_emv_loadtables:
			write_func_emv_loadtables();
			break;
		case func_emv_cleanstructures:
			write_func_emv_cleanstructures();
			break;
		case func_emv_finishtransaction:
			write_func_emv_finishtransaction();
			break;
		case func_emv_removecard:
			write_func_emv_removecard();
			break;
		case func_parseticket:
			write_func_parseticket();
			break;
		case func_menu_header:
			write_func_menu_header();
			break;
		case func_input_getvalue:
			write_func_input_getvalue();
			break;
		case func_file_open:
			write_func_file_open();
			break;
		case func_file_close:
			write_func_file_close();
			break;
		case func_file_read:
			write_func_file_read();
			break;
		case func_file_write:
			write_func_file_write();
			break;
		case func_string_pad:
			write_func_string_pad();
			break;
		case func_time_calculate:
			write_func_time_calculate();
			break;
		case func_system_inputtransaction:
			write_func_system_inputtransaction();
			break;
		case func_system_update:
			write_func_system_update();
			break;
		case func_system_qrcode:
			write_func_system_qrcode();
			break;
		case func_iso8583_transactmessagesubcampo:
			write_func_iso8583_transactmessagesubcampo();
			break;
		case func_network_start:
			write_func_network_start();
			break;
		case func_network_coapsend:
			write_func_network_coapsend();
			break;
		case func_network_coapreceive:
			write_func_network_coapreceive();
			break;
		case func_system_activate:
			write_func_system_activate();
			break;
		case func_pegacartao:
			// write_func_pegacartao();
			// break;
		default:
			printf("Comando nao encontrado: 0x%02X\n", function);
			free (buffer);
			fclose (dest_file);
			exit(4);
			break;
	}
}

void get_param(char * string)
{
	char aux[2];
	int string_len;

	memset(&aux,0,sizeof(aux));

	file_ptr++;

	string[0] = quotes_mark;

	while(buffer[file_ptr] != delimitador_fim_value)
	{
		sprintf(aux, "%c", buffer[file_ptr]);
		strcat(string, aux);
		file_ptr++;
	}

	string_len = strlen(string);
	string[string_len] = quotes_mark;
}

void go_to_next_command(void)
{
	while(buffer[file_ptr] != delimitador_fim_comando)
	{
		file_ptr++;
	}
}

void free_prams_values(void)
{
	memset(&param1,0,sizeof(param1));
	memset(&param2,0,sizeof(param2));
	memset(&param3,0,sizeof(param3));
	memset(&param4,0,sizeof(param4));
	memset(&param5,0,sizeof(param5));
	memset(&param6,0,sizeof(param6));
	memset(&param7,0,sizeof(param7));
	memset(&param8,0,sizeof(param8));
	memset(&write_buffer,0,sizeof(write_buffer));
}

void insert_tabs(void)
{
	int i;

	if(tab_index > 0)
	{
		for( i = 0 ; i < tab_index ; i ++ )
		{
			fwrite("\t", sizeof(char), strlen("\t"), dest_file);
		}
	}
}

void remove_jumper(void)
{
	while(buffer[file_ptr] != 0x0A)
		file_ptr++;
}