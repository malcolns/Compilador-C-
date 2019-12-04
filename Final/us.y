%{
    #include "symtab.c"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
    extern int yylex();
    void yyerror(int a);

%}

%union
{
    int valor_inteiro;
    list_t* item_lista;
}

/* Definições dos Tokens */

%token <valor_inteiro> INT IF ELSE WHILE VOID RETURN
%token <valor_inteiro> ADD SUB MUL DIV OROP ANDOP NOTOP EQUOP EQ DIF GREAT LESS GEQ LESSEQ
%token <valor_inteiro> LPAREN RPAREN LBRACK RBRACK LKEY RKEY PTVIRG VIRG ATRIB
%token <item_lista> ID
%token <valor_inteiro> NUM

%left LPAREN RPAREN LBRACK RBRACK
%right NOTOP INCR REFER
%left MUL DIV
%left ADD SUB
%left DIF GREAT LESS GEQ LESSEQ
%left EQ
%left OROP
%left ANDOP
%right ATRIB
%left VIRG

%start programa

%%


/* Inicio -------------------------------------------------------------------------------------- */

programa: declaracoes {} funcoes;

/* Declarações --------------------------------------------------------------------------------- */

declaracoes: declaracoes declaracao | declaracao;

declaracao: {declare = 1;} tipo_NVoid nome_var {declare = 0;} PTVIRG ;

declaracoes_opcional: declaracoes | /* vazio */;

tipo: INT | VOID;

tipo_NVoid: INT;

nome_var: nome_var VIRG variavel | nome_var VIRG inicializarcao | variavel | inicializarcao;

inicializarcao: variave_inicial | vetor_inicial;

variave_inicial: ID ATRIB constante;

vetor_inicial: ID vetor ATRIB LKEY valores RKEY;

valores : valores VIRG constante | constante;

variavel: ID | ID vetor;

vetor: vetor LBRACK expressao RBRACK | LBRACK expressao RBRACK ;

/* Função -------------------------------------------------------------------------------------- */

funcoes_opcional: funcoes | /* vazio */;

funcoes: funcoes funcao | funcao;

funcao: {incr_scope();} funcao_cabecalho bloco {/*hide_scope();*/};

funcao_cabecalho: tipo ID LPAREN parametros_opcional RPAREN;

return_opcional: RETURN expressao PTVIRG | /* vazio */;

parametros_opcional: parametros | VOID | /* vazio */;

parametros: parametros VIRG  parametro | parametro;

parametro: {declare = 1;} tipo_NVoid variavel_parametro {declare = 0;};

variavel_parametro: ID | ID colchetes_parametro | ID LBRACK RBRACK ;

colchetes_parametro: colchetes_parametro LBRACK NUM RBRACK | LBRACK NUM RBRACK;

funcao_chamada: ID LPAREN parametros_chamada RPAREN;

parametros_chamada: parametro_chamada | /* vazio */;

parametro_chamada: parametro_chamada VIRG expressao | expressao;

/* Instruções ---------------------------------------------------------------------------------- */

instrucoes: instrucoes instrucao | instrucao;

instucoes_opcional: instrucoes | /* vazio */;

instrucao: if_instrucao | while_instrucao | atribuicao PTVIRG | funcao_chamada PTVIRG;

/* IF, ELSE IF, ELSE --------------------------------------------------------------------------- */

if_instrucao: 
    IF LPAREN expressao RPAREN bloco parte_elseif parte_else | 
    IF LPAREN expressao RPAREN bloco parte_else
;

parte_elseif: 
    parte_elseif ELSE IF LPAREN expressao RPAREN bloco |
    ELSE IF LPAREN expressao RPAREN bloco 
; 

parte_else: ELSE bloco | /* vazio */ ; 

/* While --------------------------------------------------------------------------------------- */

while_instrucao: WHILE LPAREN expressao RPAREN bloco ;

/* Escopo -------------------------------------------------------------------------------------- */

bloco: LKEY declaracoes_opcional instucoes_opcional return_opcional RKEY ;

/* Expressão ----------------------------------------------------------------------------------- */

expressao:
    expressao ADD expressao |
    expressao SUB expressao |
    expressao MUL expressao |
    expressao DIV expressao |

    expressao EQ expressao |
    expressao DIF expressao |
    expressao GREAT expressao |
    expressao LESS expressao |
    expressao GEQ expressao |
    expressao LESSEQ expressao |

    expressao OROP expressao |
    expressao ANDOP expressao |
    NOTOP expressao |  
    
    LPAREN expressao RPAREN |

    variavel |
    sinal constante |
    funcao_chamada
;

sinal: SUB | /* vazio */ ; 

constante: NUM;

atribuicao: variavel ATRIB expressao; 


%%

void yyerror (int a)
{
    if(a == 0)
    {
        printf("ERRO LEXICO: %s LINHA: %d\n", yytext, lineno);
        exit(1);
    } 
    

  fprintf(stderr, "Syntax error na linha %d\n", lineno);
  exit(1);
}

int main (int argc, char *argv[]){

	// initialize symbol table
	init_hash_table();

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!");
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);
	
	return flag;
}
