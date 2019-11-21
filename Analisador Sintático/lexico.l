 /*
  Lexycal Analyzer for C-
  Luiz Felipe Raveduti Zafiro - RA:120513
  Malcoln R. T. Soares        - RA:111817
  Compilers
  Computer Engineering
  Feredal University of São Paulo - Brazil
 */

%{
    #include <stdio.h>
    #include <stdlib.h>

    #define ID      320
    #define IF      321
    #define ELSE    322
    #define DIF     323
    #define WHILE   324
    #define RETURN  325
    #define LBRACK  326
    #define RBRACK  327
    #define LPAR    328
    #define RPAR    329
    #define LKEY    330
    #define RKEY    331
    #define COM     332
    #define SCOL    333
    #define PLUS    334
    #define EQUAL   335
    #define LESS    336
    #define GREAT   337
    #define MIN     338
    #define MUL     339
    #define SLASH   340
    #define TAB     341
    #define EEQUAL  342
    #define COL     343
    #define END     344
    #define ERR     345
    #define NUM     346
    #define GEQ     347
    #define INT     348
    #define LEQ     349
    #define VOID    350
    #define COMENTA 351
    #define COMENTB 352
    #define NXTLINE 353
    #define SPACE   354

    extern YYSTYPE yylval;
    void abrirArq();
%}

COMM1 [/]
COMM2 [*]
DIGIT [0-9]
LETTER [a-zA-Z]

%%
{COMM1}{COMM2}                  return COMENTA;
{COMM2}{COMM1}                  return COMENTB;
"if"                            return IF;
"else"                          return ELSE;
"while"                         return WHILE;
"int"                           return INT;
"void"                          return VOID;
"return"                        return RETURN;
"+"                             return PLUS;
"-"                             return MIN;
"*"                             return MUL;
"/"                             return SLASH;
";"                             return SCOL;
","                             return COM;
"!="                            return DIF;
"("                             return LPAR;
")"                             return RPAR;
"["                             return LBRACK;
"]"                             return RBRACK;
"{"                             return LKEY;
"}"                             return RKEY;
"="                             return EQUAL;
"=="                            return EEQUAL;
"<"                             return LESS;
">"                             return GREAT;
"<="                            return LEQ;
">="                            return GEQ;
[\t]+                           return TAB;
[\n]+                           return NXTLINE;
[ ]+                            return SPACE;
{DIGIT}+                        return NUM;
{LETTER}({LETTER}|{DIGIT})*     return ID;
"."                             return ERR;
{DIGIT}({DIGIT}|{LETTER})*{LETTER}({DIGIT}|{LETTER})*     return ERR;
.                               return ERR;
<<EOF>>                         return END;
%%



void abrirArq()
{
  yyin = fopen("entrada.txt", "r");
}