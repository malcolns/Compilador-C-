/* maximum size of hash table */
#define SIZE 211

/* maximum size of tokens-identifiers */
#define MAXTOKENLEN 40

/* how parameter is passed */
#define BY_VALUE 1
#define BY_REFER 2

/* Types of values that we can have */
typedef union Value{
	int ival;
	double fval;
	char cval;
	char *sval;
}Value;

/* parameter struct */
typedef struct Param{

	int par_type;

	char param_name[MAXTOKENLEN];

	Value val;

	int passing; 
}Param;

typedef struct RefList{ 

    int lineno;

    struct RefList *next;

}RefList;

typedef struct list_t{
	
	char st_name[MAXTOKENLEN];
	
    int st_size;

    int scope;

    RefList *lines;

	Value val;

    int st_type;
	
	int g_index;

	int reg_name;

	int inf_type;

	Value *vals;

	int array_size;

	Param *parameters;

	int num_of_pars;

	struct list_t *next;

}list_t;

typedef struct revisit_queue{

	list_t *entry;
	
	char *st_name;
	
	int revisit_type;
	
	int **par_types;

	int *num_of_pars;

	int num_of_calls;
	
	void **nodes;

	int num_of_assigns;
	
	struct revisit_queue *next;

}revisit_queue;

#define PARAM_CHECK 1  
#define ASSIGN_CHECK 2 


static list_t **hash_table;

static revisit_queue *queue;

static char **str_messages;

void init_hash_table(); 

unsigned int hash(char *key);

void insert(char *name, int len, int type, int lineno); 

list_t *lookup(char *name);

void symtab_dump(FILE *of);

void set_type(char *name, int st_type, int inf_type); 

int get_type(char *name); 

void hide_scope(); 

void incr_scope(); 

Param def_param(int par_type, char *param_name, int passing);

int func_declare(char *name, int ret_type, int num_of_pars, Param *parameters); 

int func_param_check(char *name, int num_of_calls, int** par_types, int *num_of_pars); 

void add_to_queue(list_t *entry, char *name, int type); 

revisit_queue *search_queue(char *name); 

revisit_queue *search_prev_queue(char *name);

int revisit(char *name);

void revisit_dump(FILE *of);

void add_to_str_messages(char *str);
