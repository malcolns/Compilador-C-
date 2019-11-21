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

/*Verificar o que é: SEMI, INCR*/

%token INT IF ELSE WHILE BREAK VOID RETURN
%token ADDOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI COMM
%token ID ICONST FCONST CCONST STRING

%%

/*adicionar Funções*/

programa: declaracoes instucoes funcoes;

declaracoes: declaracoes declaracao | declaracao;

declaracao: tipo nome_var SEMI ;

tipo: INT | VOID;

nome_var: variavel | nome_var COMMA variavel;

variavel: ID | ID vetor;

vetor: vetor LBRACK ICONST RBRACK | LBRACK ICONST RBRACK ;

instucoes: instucoes instrucao | instrucao;

instrucao:
    if_instrucao | while_instrucao | atribuicao | BREAK SEMI | RETURN SEMI
;

if_instrucao: IF LPAREN expressao RPAREN bloco parte_elseif parte_else ;

parte_elseif: 
    parte_elseif ELSE IF LPAREN expressao RPAREN bloco |
    ELSE IF LPAREN expressao RPAREN bloco  |
    /* empty */
; 
parte_else: ELSE bloco | /* empty */ ; 

while_instrucao: WHILE LPAREN expressao RPAREN bloco ;

bloco: instrucao SEMI | LBRACE instucoes RBRACE ;

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
    sinal constante
;

sinal: ADDOP | /* empty */ ; 

constante: ICONST;

atribuicao: variavel expressao SEMI ; 


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

