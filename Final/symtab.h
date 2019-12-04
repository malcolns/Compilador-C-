/*Tamanho limite da tabela hash
preferencialmente deve ser um número primo*/
#define HASH_TAM 101

/*Máximo tamanho para os tokens identificadores (ID)*/
#define MAXTOKENLEN 40

/*Tipos dos Tokens*/
#define NDEF 0
#define INT 1
#define FUNCTION 2

/*Variavel global para armazenar o escopo atual
mais facil o acesso para verificação nas funções*/
int cur_scope = 0;

/*Estrutura de um parâmetro de uma função*/
typedef struct Param{
	int par_tipo;
	char param_name[MAXTOKENLEN];					/*CONTINUAR DAQUI*/
	// to store value
	int ival; double fval; char *st_sval;
}Param;

/* a linked list of references (lineno's) for each variable */
typedef struct RefList{ 
    int lineno;
    struct RefList *next;
    int type;
}RefList;

// struct that represents a list node
typedef struct list_t{
	char st_name[MAXTOKENLEN];
    int st_size;
    int scope;
    RefList *lines;
	// to store value and sometimes more information
	int st_ival; double st_fval; char *st_sval;
	// type
    int st_type;
	int inf_type; // for arrays (info type) and functions (return type)
	// array stuff
	int *i_vals; double *f_vals; char **s_vals;
	int array_size;
	// function parameters
	Param *parameters;
	int num_of_pars;
	// pointer to next item in the list
	struct list_t *next;
}list_t;

/* the hash table */
static list_t **hash_table;

// Function Declarations
void init_hash_table(); // initialize hash table
unsigned int hash(char *key); // hash function 
void insert(char *name, int len, int type, int lineno); // insert entry
list_t *lookup(char *name); // search for entry
list_t *lookup_scope(char *name, int scope); // search for entry in scope
void hide_scope(); // hide the current scope
void incr_scope(); // go to next scope
void symtab_dump(FILE *of); // dump file