%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	/*Tabela de simbolos*/
	#include "symtab.h"
	#include "us.tab.h"
	extern FILE *yyin;
	extern FILE *yyout;

	int lineno = 1; // initialize to 1

	void ret_print(char *token_type);
	void yyerror(int a);

	/*Para comunicação com os arquivos externos*/

%}

%x COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}

ID 			{alpha}+
NUM	    	"0"|[0-9]{digit}*

%%

"//".*					{ printf("Comentário da linha %d\n", lineno); } 

"/*"				   	{ printf("Comentário da linha %d ", lineno); BEGIN(COMMENT); }
<COMMENT>"*/" 		    { printf("até a linha %d\n", lineno); BEGIN(INITIAL); }
<COMMENT>[^*\n]+		
<COMMENT>"*"			
<COMMENT>"\n"		    { lineno += 1; }


"int"			    	{ return INT; }
"if"			    	{ return IF; }
"else"		        	{ return ELSE; }
"while"                 { return WHILE; }
"void"			        { return VOID; }
"return"        		{ return RETURN; }


"+" 					{ return ADD; }
"-"                     { return SUB; }
"*"						{ return MUL; }
"/"						{ return DIV; }

"=="    				{ return EQ; }
"!="                    { return DIF; }
">"             		{ return GREAT; }
"<"                     { return LESS; }
">="                    { return GEQ; }
"<="                    { return LESSEQ; }

"&&"                    { return OROP; }
"||"                    { return ANDOP; }
"!"                    	{ return NOTOP; }


"("				        { return LPAREN; }
")"			        	{ return RPAREN; }
"]"				        { return RBRACK; }
"["				        { return LBRACK; }
"{"				        { return LKEY; }
"}"				        { return RKEY; }
";"				        { return PTVIRG; }

","				        { return VIRG; }
"="				        { return ATRIB; }


{ID} 			{ 
					/*insere os identificadores na tabela de simbolos de forma coerente*/
					insert(yytext, strlen(yytext), NDEF, lineno);
					yylval.item_lista = lookup(yytext);
					return ID; 
				}

{NUM}    		{ return NUM; }

"\n"			{ lineno += 1; }
[ \t\r\f]+	    /*ignora espaçoes em branco*/

.				{  yyerror(0); }

%%
/*
void ret_print(char *token_type){

	printf("leitura: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(){

	printf("ERRO %s: %s LINHA: %d\n", yytext, lineno);
	exit(1);
}*/
/*
int main(int argc, char *argv[]){

	/*Inicializacao da tabela de simbolos*/
	//init_hash_table();

	/*Abertura do arquivo de entrada para leitura*/
	//yyin = fopen("input.txt", "r;

	/*Chamada do analizador léxico*/
	//yylex();

	/*Fechamento do arquivo de entrada*/
	//fclose(yyin);

	/*Abertura do arqiuvo de saída que conterá a tabela de simbolos*/
	//yyout = fopen("table_out.txt", "w;

	/*Realiza a escrita da tabela no arquivo*/
	//symtab_dump(yyout);

	/*Fechamento do arquivo de saida da tabela de simbolos*/
	//fclose(yyout);

	//return 0;
//}
