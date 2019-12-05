%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "symtab.h"
	#include "semantics.h"
	#include "ast.h"
	#include "parser.tab.h"
	extern FILE *yyin;
	extern FILE *yyout;
	extern char * yytext;
	int lineno = 1;
	void ret_print(char *token_type);
	void yyerror(char const *s);
%}

%x COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]

ID 			{alpha}+
ICONST		"0"|[0-9]{digit}*
%%

"//".*					{ /* printf("Começa de linha comentário na linha %d\n", lineno); */ } 

"/*"					{ /* printf("Começa comentário na linha %d ", lineno); */ BEGIN(COMMENT); }
<COMMENT>"*/" 		{ /* printf("termina na linha %d\n", lineno); */ BEGIN(INITIAL); }
<COMMENT>[^*\n]+		
<COMMENT>"*"			
<COMMENT>"\n"		{ lineno += 1; }

"int"			{ return INT; }
"if"			{ return IF; }
"else"			{ return ELSE; }
"while"			{ return WHILE; }
"void"			{ return VOID; }
"return"		{ return RETURN; }


"+"					    { yylval.val.ival = ADD; return ADDOP; }
"-"					    { yylval.val.ival = SUB; return ADDOP; }
"*"						{ return MULOP; }
"/"						{ return DIVOP; }
"||"					{ return OROP; }
"&&"					{ return ANDOP; }
"!"						{ return NOTOP; }
"=="				    { yylval.val.ival = EQUAL; return EQUOP; }
"!="				    { yylval.val.ival = NOT_EQUAL; return EQUOP; }
">"						{ yylval.val.ival = GREATER; return RELOP; }
"<"						{ yylval.val.ival = LESS; return RELOP; }
">="					{ yylval.val.ival = GREATER_EQUAL; return RELOP; }
"<="					{ yylval.val.ival = LESS_EQUAL; return RELOP; }


"("				{ return LPAREN; }
")"				{ return RPAREN; }
"]"				{ return RBRACK; }
"["				{ return LBRACK; }
"{"				{ return LBRACE; }
"}"				{ return RBRACE; }
";"				{ return SEMI; }
","				{ return COMMA; }
"="				{ return ASSIGN; }

{ID} 			{
					// insert identifier into symbol table
					insert(yytext, strlen(yytext), UNDEF, lineno);
					yylval.symtab_item = lookup(yytext);
					return ID;
				}

{ICONST} 		{ yylval.val.ival = atoi(yytext); return ICONST; }

"\n"			{ lineno += 1; }
[ \t\r\f]+		

.				{ yyerror("lexycal error"); }

%%

