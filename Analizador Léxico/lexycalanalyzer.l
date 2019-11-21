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

int line = 0;

int main(){

  int token, i, *buf;
  FILE *f_in, *f_out;
 
  buf = (int *)calloc(1000, sizeof(int));

  f_in = fopen("sort.txt", "r");

  if(f_in == NULL) printf("Error\n");

  f_out = fopen("OUT.txt", "w");

  if(f_out == NULL) printf("Error\n");

  yyin = f_in;

  i = 0;
  while ((token=yylex())!=END)
  {
    buf[i] = token;
    i++;
  }

  i = 0;
  while (buf[i] != 0)
  {
    switch(buf[i])
    {
      case IF: fprintf(f_out, "%s", "IF "); break;
      case ELSE: fprintf(f_out, "%s", "ELSE "); break;
      case GEQ: fprintf(f_out, "%s", "GEQ "); break;
      case LEQ: fprintf(f_out, "%s", "LEQ "); break;
      case WHILE: fprintf(f_out, "%s", "WHILE "); break;
      case INT: fprintf(f_out, "%s", "INT "); break;
      case VOID: fprintf(f_out, "%s", "VOID "); break;
      case DIF: fprintf(f_out, "%s", "DIF "); break;
      case EEQUAL: fprintf(f_out, "%s", "EEQUAL "); break;
      case RETURN: fprintf(f_out, "%s", "RETURN "); break;
      case PLUS: fprintf(f_out, "%s", "PLUS "); break;
      case MIN: fprintf(f_out, "%s", "MIN "); break;
      case MUL: fprintf(f_out, "%s", "MUL "); break;
      case SLASH: fprintf(f_out, "%s", "SLASH "); break;
      case SCOL: fprintf(f_out, "%s", "SCOL "); break;
      case COM: fprintf(f_out, "%s", "COM "); break;
      case COL: fprintf(f_out, "%s", "COL "); break;
      case LPAR: fprintf(f_out, "%s", "LPAR "); break;
      case RPAR: fprintf(f_out, "%s", "RPAR "); break;
      case LBRACK: fprintf(f_out, "%s", "LBRACK "); break;
      case RBRACK: fprintf(f_out, "%s", "RBRACK "); break;
      case LKEY: fprintf(f_out, "%s", "LKEY "); break;
      case RKEY: fprintf(f_out, "%s", "RKEY "); break;
      case EQUAL: fprintf(f_out, "%s", "EQUAL "); break;
      case LESS: fprintf(f_out, "%s", "LESS "); break;
      case GREAT: fprintf(f_out, "%s", "GREAT "); break;
      case ID: fprintf(f_out, "%s", "ID "); break;
      case NUM: fprintf(f_out, "%s", "NUM "); break;
      case NXTLINE:
        line++; 
        fprintf(f_out, "\n");
      break;
      case ERR: fprintf(f_out, "ERR, in line %d ", line); break;
      case SPACE: break;
      case TAB: break;
      case COMENTA: 
        while(buf[i] != COMENTB){
          if(buf[i] == NXTLINE)
            line++;
          i++;
        }
      break;
    }
    i++;
  }

    fclose(f_in);

    fclose(f_out);

    return(0);
}