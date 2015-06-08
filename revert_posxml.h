#define PARAM_SIZE 30

//byte codes
#define delimitador_fim_value						0x0A
#define delimitador_fim_comando						0x0D
#define comando_chamafuncao							0x67
#define comando_funcao								0x6C
#define comando_variavelint							0x6D
#define comando_variavelstr							0x3E
#define comando_substring							0x3C
#define comando_stringtoint							0x61
#define comando_inttostring							0x62
#define comando_IF									0x49
#define comando_EndIF								0x45
#define func_display								0x64
#define func_imprima								0x70
#define func_imprimagrande							0x50
#define func_digitainteiro							0x69
#define func_digitaopcao							0x6F
#define func_digitavalor							0x79
#define func_digitaformato							0x66
#define func_preconexao								0x53
#define func_desligamodem							0x44
#define func_pegacartao								0x63
#define func_pegacartaoevariavel  					0x6B
#define func_esperatecla							0x75
#define	func_espera									0x43
#define func_limpadisplay							0x48
#define func_paperfeed    							0x68
#define func_esperateclatimeout      				0x55
#define func_string_getvaluebykey					0x4B
#define func_menu									0x4C
#define func_editaarquivo							0x41
#define func_learquivo								0x42
#define func_variavelintoperador					0x47
#define func_ajustadatahora							0x4A
#define func_pegadatahora							0x6E
#define func_verificapapelimpressora				0x4E
#define func_digitadecimal							0x73
#define func_somastring								0x74
#define func_operacaomatematica						0x54
#define func_excluiarquivo							0x78
#define func_imprimacodigodebarras					0x58
#define func_execute								0x6A
#define comando_EndFuncao							0x72
#define comando_While								0x56
#define comando_EndWhile							0x76
#define comando_break								0x5A
#define func_openserialport							0x59
#define func_readserialport							0x77
#define func_writeserialport						0x57
#define func_closeserialport						0x21
#define func_string_length							0x40
#define comando_exit								0x31
#define func_baixaarquivo							0x34
#define func_diferencadatahora						0x37
#define func_learquivobyindex						0x25
#define func_mostrabitmap							0x38
#define func_imprimabitmap							0x39
#define func_letecla								0x2F
#define func_unzipfile								0x5c
#define comando_Else								0x2C
#define func_conversaointeiro						0x01
#define func_iso8583_iniciatabelacampos				0x02
#define func_iso8583_iniciamensagem					0x03
#define func_iso8583_analisamensagem				0x05
#define func_iso8583_finalizamensagem				0x06
#define func_iso8583_inserecampo					0x07
#define func_iso8583_pegacampo						0x08
#define func_string_charat							0x09
#define func_string_trim							0x0B
#define func_string_find							0x0C
#define func_string_replace							0x0E
#define func_string_substring						0x0F
#define func_string_elements						0x10
#define func_string_insertat						0x11
#define func_string_replaceat						0x12
#define func_string_elementat						0x13
#define func_string_removeat						0x14
#define func_network_send							0x15
#define func_network_receive						0x16
#define func_system_restart							0x17
#define func_filesystem_filesize					0x19
#define func_filesystem_space						0x1A
#define func_filesystem_listfiles					0x1B
#define func_filesystem_renamefile    				0x8A
#define func_convert_toint							0x1D
#define func_predial								0x23
#define func_network_checkgprssignal				0x24
#define func_system_checkbattery					0x27
#define func_network_ping							0x4F
#define func_system_beep							0x51
#define func_system_readcard						0x26
#define func_network_hostdisconnect					0x65
#define func_iso8583_transactmessage				0x3B
#define func_smartcard_cartaoinserido				0x7C
#define func_smartcard_inicialeitor					0x3D
#define func_smartcard_transmitAPDU					0x2E
#define func_smartcard_fechaleitor					0x32
#define func_string_tohex							0x30
#define func_string_fromhex							0x3F
#define func_crypto_encryptdecrypt					0x7B
#define func_system_gettouchscreen					0x87
#define func_crypto_lrc								0x7D
#define func_crypto_xor								0x5E
#define func_crypto_crc								0x5F
#define func_system_info							0x60
#define func_pinpad_open							0x1C
#define func_pinpad_display							0x28
#define func_pinpad_getkey							0x29
#define func_pinpad_getpindukpt						0x2A
#define func_pinpad_loadipek						0x2B
#define func_pinpad_close							0x7E
#define func_emv_open								0x2D
#define func_emv_close								0x22
#define func_emv_loadtables							0x5D
#define func_emv_settimeout							0x1E
#define func_emv_cleanstructures					0x1F
#define func_emv_adddata							0x88
#define func_emv_getinfo							0x35
#define func_emv_inittransaction					0x20
#define func_emv_processtransaction					0x3A
#define func_emv_finishtransaction					0x5B
#define func_emv_removecard							0x71
#define func_parseticket							0x80
#define func_menu_header							0x81
#define func_input_getvalue							0x82
#define func_file_open								0x83
#define func_file_close								0x84
#define func_file_read								0x85
#define func_file_write								0x86
#define func_string_pad								0x89
#define func_time_calculate							0x90
#define func_system_inputtransaction				0x91
#define func_system_backlight						0x92
#define func_system_update							0x93
#define func_system_qrcode							0x94
#define func_iso8583_transactmessagesubcampo		0x95
#define func_network_start							0x96
#define func_network_coapsend						0x97
#define func_network_coapreceive					0x98
#define func_system_activate      					0x99

#define quotes_mark '"'

int tab_index = 0;
char * buffer;
FILE * dest_file;
long int file_ptr=0;
char header_buff[] = {
	'<','a','p','l','i','c','a','t','i','v','o','p','o','s','x','m','l',' ',
	'x','m','l','n','s','=','"', 'h','t','t','p',':','/','/','t','e','m','p',
	'u','r','i','.','o','r','g','/','p','o','s','x','m','l','.','x','s','d',
	'"','>','\n','\t','<','p','a','g','i','n','a',' ','n','o','m','e','=','"'
	,'p','r','i','n','c','i','p','a','l','"','>','\n'};

char bottom_buff[] = {
	'\n','\t','<','/','p','a','g','i','n','a','>','\n','<','/','a','p',
	'l','i','c','a','t','i','v','o','p','o','s','x','m','l','>'};

char write_buffer[1024];
char param1[PARAM_SIZE];
char param2[PARAM_SIZE];
char param3[PARAM_SIZE];
char param4[PARAM_SIZE];
char param5[PARAM_SIZE];
char param6[PARAM_SIZE];
char param7[PARAM_SIZE];
char param8[PARAM_SIZE];

void write_var_int(void);
void write_var_str(void);
void write_sys_backlight(void);
void write_com_chamafuncao(void);
void write_com_funcao(void);
void write_com_endfuncao(void);
void write_com_if(void);
void write_com_endif(void);
void write_com_else(void);
void write_emv_settimeout(void);
void write_int_to_string(void);
void write_soma_string(void);
void write_imprima(void);
void write_emv_adddata(void);
void write_emv_inittransaction(void);
void write_emv_getinfo(void);
void write_emv_processtransaction(void);
void write_editaarquivo(void);
void write_preconexao(void);
void write_comando_substring(void);
void write_comando_stringtoint(void);
void write_func_display(void);
void write_func_imprimagrande(void);
void write_func_digitainteiro(void);
void write_func_digitaopcao(void);
void write_func_digitavalor(void);
void write_func_digitaformato(void);
void write_func_desligamodem(void);
void write_func_pegacartao(void);
void write_func_pegacartaoevariavel(void);
void write_func_esperatecla(void);
void write_func_espera(void);
void write_func_limpadisplay(void);
void write_func_paperfeed(void);
void write_func_esperateclatimeout(void);
void write_func_string_getvaluebykey(void);
void write_func_menu(void);
void write_func_learquivo(void);
void write_func_variavelintoperador(void);
void write_func_ajustadatahora(void);
void write_func_pegadatahora(void);
void write_func_verificapapelimpressora(void);
void write_func_digitadecimal(void);
void write_func_operacaomatematica(void);
void write_func_excluiarquivo(void);
void write_func_imprimacodigodebarras(void);
void write_func_execute(void);
void write_comando_While(void);
void write_comando_EndWhile(void);
void write_comando_break(void);
void write_func_openserialport(void);
void write_func_readserialport(void);
void write_func_writeserialport(void);
void write_func_closeserialport(void);
void write_func_string_length(void);
void write_comando_exit(void);
void write_func_baixaarquivo(void);
void write_func_diferencadatahora(void);
void write_func_learquivobyindex(void);
void write_func_mostrabitmap(void);
void write_func_imprimabitmap(void);
void write_func_letecla(void);
void write_func_unzipfile(void);
void write_func_conversaointeiro(void);
void write_func_iso8583_iniciatabelacampos(void);
void write_func_iso8583_iniciamensagem(void);
void write_func_iso8583_analisamensagem(void);
void write_func_iso8583_finalizamensagem(void);
void write_func_iso8583_inserecampo(void);
void write_func_iso8583_pegacampo(void);
void write_func_string_charat(void);
void write_func_string_trim(void);
void write_func_string_find(void);
void write_func_string_replace(void);
void write_func_string_substring(void);
void write_func_string_elements(void);
void write_func_string_insertat(void);
void write_func_string_replaceat(void);
void write_func_string_elementat(void);
void write_func_string_removeat(void);
void write_func_network_send(void);
void write_func_network_receive(void);
void write_func_system_restart(void);
void write_func_filesystem_filesize(void);
void write_func_filesystem_space(void);
void write_func_filesystem_listfiles(void);
void write_func_filesystem_renamefile(void);
void write_func_convert_toint(void);
void write_func_predial(void);
void write_func_network_checkgprssignal(void);
void write_func_system_checkbattery(void);
void write_func_network_ping(void);
void write_func_system_beep(void);
void write_func_system_readcard(void);
void write_func_network_hostdisconnect(void);
void write_func_iso8583_transactmessage(void);
void write_func_smartcard_cartaoinserido(void);
void write_func_smartcard_inicialeitor(void);
void write_func_smartcard_transmitAPDU(void);
void write_func_smartcard_fechaleitor(void);
void write_func_string_tohex(void);
void write_func_string_fromhex(void);
void write_func_crypto_encryptdecrypt(void);
void write_func_system_gettouchscreen(void);
void write_func_crypto_lrc(void);
void write_func_crypto_xor(void);
void write_func_crypto_crc(void);
void write_func_system_info(void);
void write_func_pinpad_open(void);
void write_func_pinpad_display(void);
void write_func_pinpad_getkey(void);
void write_func_pinpad_getpindukpt(void);
void write_func_pinpad_loadipek(void);
void write_func_pinpad_close(void);
void write_func_emv_open(void);
void write_func_emv_close(void);
void write_func_emv_loadtables(void);
void write_func_emv_cleanstructures(void);
void write_func_emv_finishtransaction(void);
void write_func_emv_removecard(void);
void write_func_parseticket(void);
void write_func_menu_header(void);
void write_func_input_getvalue(void);
void write_func_file_open(void);
void write_func_file_close(void);
void write_func_file_read(void);
void write_func_file_write(void);
void write_func_string_pad(void);
void write_func_time_calculate(void);
void write_func_system_inputtransaction(void);
void write_func_system_update(void);
void write_func_system_qrcode(void);
void write_func_iso8583_transactmessagesubcampo(void);
void write_func_network_start(void);
void write_func_network_coapsend(void);
void write_func_network_coapreceive(void);
void write_func_system_activate(void);


void get_param(char * string);
void go_to_next_command(void);
void free_prams_values(void);
void write_buff_func(unsigned char function);
void insert_tabs(void);
void remove_jumper(void);