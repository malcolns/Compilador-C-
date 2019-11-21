%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "symtab.c"

	int lineno = 1; // initialize to 1

	void ret_print(char *token_type);

	void yyerror();
%}

%x COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}
print		[ -~]

ID 			{alpha}+{alnum}*
NUM	    	"0"|[0-9]{digit}*

%%

"//".*					{ printf("Comentário da linha %d\n", lineno); } 

"/*"				   	{ printf("Comentário da linha %d ", lineno); BEGIN(ML_COMMENT); }
<COMMENT>"*/" 		    { printf("até a linha %d\n", lineno); BEGIN(INITIAL); }
<COMMENT>[^*\n]+		
<COMMENT>"*"			
<COMMENT>"\n"		    { lineno += 1; }


"int"			    	{ ret_print("INT"); }
"if"			    	{ ret_print("IF"); }
"else"		        	{ ret_print("ELSE"); }
"while"                 { ret_print("WHILE"); }
"void"			        { ret_print("VOID"); }
"return"        		{ ret_print("RETURN"); }


"+" 					{ ret_print("ADD");   }
"-"                     { ret_print("SUB");   }
"*"						{ ret_print("MUL"); }
"/"						{ ret_print("DIV"); }
"=="    				{ ret_print("EQ"); }
"!="                    { ret_print("DIF"); }
">"             		{ ret_print("GREAT"); }
"<"                     { ret_print("LESS"); }
">="                    { ret_print("GEQ"); }
"<="                    { ret_print("LESSEQ"); }
"("				        { ret_print("LPAREN"); }
")"			        	{ ret_print("RPAREN"); }
"]"				        { ret_print("LBRACK"); }
"["				        { ret_print("RBRACK"); }
"{"				        { ret_print("LKEY"); }
"}"				        { ret_print("RKEY"); }
";"				        { ret_print("PTVIRG"); }
"."				        { ret_print("PT"); }
","				        { ret_print("VIRG"); }
"="				        { ret_print("ATRIB"); }


{ID} 			{ ret_print("ID"); }
{NUM}    		{ ret_print("NUM"); }

"\n"			{ lineno += 1; }
[ \t\r\f]+	    /*ignora espaçoes em branco*/

.				{ yyerror("Caractere não reconhecido"); }

%%

void ret_print(char *token_type){

	printf("leitura: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message){

	printf("Erro: \"%s\" linha %d. Token = %s\n", message, lineno, yytext);

	exit(1);
}

int main(int argc, char *argv[]){

	yyin = fopen("input.txt", "r"); /*Abertura arquivo de entrada*/

	yylex(); /*Chamada do analizador léxico*/

	fclose(yyin); /*Fechamento do arquivo de entrada*/

	return 0;
}