%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
    extern int yylex();
    void yyerror();
%}

%union
{
    int valor_inteiro;
    //Tlista* item_lista;
}

/* Definições dos Tokens */

%token <valor_inteiro> INT IF ELSE WHILE BREAK VOID RETURN
%token <valor_inteiro> ADDOP MULOP DIVOP OROP ANDOP NOTOP EQUOP RELOP
%token <valor_inteiro> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI COMMA ASSIGN
%token <valor_inteiro> ID
%token <valor_inteiro> ICONST

%left LPAREN RPAREN LBRACK RBRACK
%right NOTOP INCR REFER
%left MULOP DIVOP
%left ADDOP
%left RELOP
%left EQUOP
%left OROP
%left ANDOP
%right ASSIGN
%left COMMA

%%

/*adicionar Funções*/

programa: declaracoes instrucoes RETURN SEMI funcoes_opcional;

declaracoes: declaracoes declaracao | declaracao;

declaracao: tipo nome_var SEMI ;

declaracoes_opcional: declaracoes | /* vazio */;

tipo: INT | VOID;

nome_var: nome_var COMMA variavel | nome_var COMMA inicializarcao | variavel | inicializarcao;

inicializarcao: variave_inicial | vetor_inicial;

variave_inicial: ID ASSIGN constante;

vetor_inicial: ID vetor ASSIGN LBRACE valores RBRACE;

valores : valores COMMA constante | constante;

variavel: ID | ID vetor;

vetor: vetor LBRACK expressao RBRACK | LBRACK expressao RBRACK ;

/* Função -------------------------------------------------------------------------------------- */

funcoes_opcional: funcoes | /* vazio */;

funcoes: funcoes funcao | funcao;

funcao: funcao_cabecalho funcao_bloco;

funcao_cabecalho: tipo_retorno ID LPAREN parametros_opcional RPAREN;

tipo_retorno: tipo;

funcao_bloco: LBRACE declaracoes_opcional instucoes_opcional return_opcional RBRACE;

return_opcional: RETURN expressao SEMI | /* vazio */;

parametros_opcional: parametros | /* vazio */;

parametros: parametros COMMA  parametro | parametro;

parametro: tipo variavel;

    /*Tem potencial pra ser reduntante*/

funcao_chamada: ID LPAREN parametros_chamada RPAREN;

parametros_chamada: parametro_chamada | /* vazio */;

parametro_chamada: parametro_chamada COMMA expressao | expressao;

/* Instruções ---------------------------------------------------------------------------------- */

instrucoes: instrucoes instrucao | instrucao;

instucoes_opcional: instrucoes | /* vazio */;

instrucao: if_instrucao | while_instrucao | atribuicao | BREAK SEMI | funcao_chamada SEMI;

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

bloco: instrucao SEMI | LBRACE instrucoes RBRACE ;

/* Expressão ----------------------------------------------------------------------------------- */

expressao:
    expressao ADDOP expressao |
    expressao MULOP expressao |
    expressao DIVOP expressao |
    expressao OROP expressao |
    expressao ANDOP expressao |
    NOTOP expressao |
    expressao EQUOP expressao |
    expressao RELOP expressao |
    LPAREN expressao RPAREN |
    variavel |
    sinal constante |
    funcao_chamada
;

sinal: ADDOP | /* vazio */ ; 

constante: ICONST {printf("---%d---\n", yylval.valor_inteiro);};

atribuicao: variavel ASSIGN expressao SEMI ; 


%%
/*
void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}
*/
int main (int argc, char *argv[]){

    // parsing
    int flag;
    yyin = fopen(argv[1], "r");
    flag = yyparse();
    fclose(yyin);
    
    return flag;
}
