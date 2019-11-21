%{
  #include "us.tab.h"
  #include "globals.h"
  #include "util.h"
  #include "scan.h"

  extern YYSTYPE yylval;
  void abrirArq();

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
  //#define NUM     346
  #define GEQ     347
  #define INT     348
  #define LEQ     349
  #define VOID    350
  #define COMENTA 351
  #define COMENTB 352
  #define NXTLINE 353
  #define SPACE   354

  #define RELOP   355
  #define FATOP   356
  #define STDOP   357

  char tokenString[MAXTOKENLEN+1];
%}

ws [ \t]+
letter [A-Za-z]
digit [0-9]

newline \n

id {letter}+
number {digit}+



%%

"if"                            return IF;
"else"                          return ELSE;
"while"                         return WHILE;
"int"                           return INT;
"void"                          return VOID;
"return"                        return RETURN;
";"                             return SCOL;
","                             return COM;
"("                             return LPAR;
")"                             return RPAR;
"["                             return LBRACK;
"]"                             return RBRACK;
"{"                             return LKEY;
"}"                             return RKEY;
"="                             return EQUAL;

{number}                        {return NUM;}
{identifier}                    {return ID;}

{ws}                            {}
{newline}                       {lineno++;}

"+"                             {yylval = PLUS; return (STDOP);}
"-"                             {yylval = MIN; return (STDOP);}
"*"                             {yylval = MUL; return (FATOP);}
"/"                             {yylval = SLASH; return (FATOP);}

"!="                            {yylval = DIF; return (RELOP);}
"=="                            {yylval = EEQUAL; return (RELOP);}
"<"                             {yylval = LESS; return (RELOP);}
">"                             {yylval = GREAT; return (RELOP);}
"<="                            {yylval = LEQ; return (RELOP);}
">="                            {yylval = GEQ; return (RELOP);}

"/*"                            { 
                                  char c;
                                  do
                                  {
                                    
                                    do
                                    { c = input();
                                      if (c == EOF) break;
                                      if (c == '\n') lineno++;
                                    } while (c != '*');
                                    
                                    c = input();
                                      if (c == EOF) break;
                                      if (c == '\n') lineno++;
                                  } while(c != '/');
                                }

.                               { return ERRO; }
%%

int installID()
{
  
}

int installNum()
{

}

void abrirArq()
{
  yyin = fopen("entrada.txt", "r");
}
	
TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}
