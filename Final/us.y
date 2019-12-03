%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    extern int lineno;
    extern int yylex();
    void yyerror();
%}

/* Definições dos Tokens */


%token INT IF ELSE WHILE BREAK VOID RETURN
%token ADDOP MULOP DIVOP OROP ANDOP NOTOP EQUOP RELOP
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI COMMA ASSIGN
%token ID ICONST 

%%

/*adicionar Funções*/

programa: declaracoes instrucoes RETURN SEMI funcoes;

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

constante: ICONST;

atribuicao: variavel ASSIGN expressao SEMI ; 


%%

int main()
{
  cout << "\nParser em execução...\n";
  abrirArq();
  return yyparse();
}

void yyerror(char * msg)
{
  extern char* yytext;
  cout << msg << ": " << yytext << yylval << yychar << endl;
}

