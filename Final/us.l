%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	//#include "symtab.c" // Tabela de Simbolos

	#include "us.tab.h"

	extern FILE *yyin;
    extern FILE *yyout;

	int lineno = 1; // initialize to 1
	void ret_print(char *token_type);
	void yyerror();
%}

%x COMMENT

ALPHA 		[a-z]
DIGIT 		[0-9]
ID 			{ALPHA}+
ICONST	 	{DIGIT}+

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
"break"					{ return BREAK; }

"+"|"-"      			{ return ADDOP; }
"*"	     				{ return MULOP; }
"/"	     				{ return DIVOP; }
"||"         			{ return OROP; }
"&&"	     			{ return ANDOP; }
"!"	     				{ return NOTOP; }
"=="|"!="    			{ return EQUOP; }
">"|"<"|">="|"<="      	{ return RELOP; }

"("				        { return LPAREN; }
")"			        	{ return RPAREN; }
"]"				        { return RBRACK; }
"["				        { return LBRACK; }
"{"				        { return LBRACE; }
"}"				        { return RBRACE; }
";"				        { return SEMI; }
","				        { return COMMA; }
"="				        { return ASSIGN; }


{ID}					{ /* insert(yytext, strlen(yytext), UNDEF, lineno); */ }
{ICONST}   				{ yylval.valor_inteiro = atoi(yytext); return ICONST; }

"\n"			{ lineno += 1; }
[ \t\r\f]+	    {/*ignora espaçoes em branco*/}

.				{ yyerror("Caractere não reconhecido"); }

%%

void ret_print(char *token_type){
   printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message){
   printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
   exit(1);
}
/*
int main(int argc, char *argv[]){
   yyin = fopen(argv[1], "r");
   yylex();
   fclose(yyin);
   return 0;
}
*/