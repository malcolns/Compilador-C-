#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"
#include "symtab.h"

/* current scope */
int cur_scope = 0;

/* flag variable for declaring */
int declare = 0; 

/* flag variable for function declaring */
int function_decl = 0; 

/* number of messages */
int num_of_msg = 0;

// Symbol Table Functions

void init_hash_table(){

	int i; 

	hash_table = malloc(SIZE * sizeof(list_t*));
	
	if(hash_table == NULL){

		printf("Erro ao alocar a tabela Hash!\n");

		exit(-1);
	}
	for(i = 0; i < SIZE; i++) 
		
		hash_table[i] = NULL;
}

/* Hash function */
unsigned int hash(char *key){

	unsigned int hashval = 0;
	
	for(;*key!='\0';key++) hashval += *key;

	hashval += key[0] % 11 + (key[0] << 3) - key[0];

	return hashval % SIZE;
}

void insert(char *name, int len, int type, int lineno){
	unsigned int hashval = hash(name);

	list_t *l = hash_table[hashval];
	
	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
	
	/* variable not yet in table */
	if (l == NULL){

		if(declare == 1){

			l = (list_t*) malloc(sizeof(list_t));

			strncpy(l->st_name, name, len);

			l->st_size = len;

			l->st_type = type;

			l->scope = cur_scope;

			l->lines = (RefList*) malloc(sizeof(RefList));

			l->lines->lineno = lineno;

			l->lines->next = NULL;
			
			/* add to hashtable */
			l->next = hash_table[hashval];

			hash_table[hashval] = l; 
		}
		else{

			/* add it to check it again later */
			l = (list_t*) malloc(sizeof(list_t));

			strncpy(l->st_name, name, len);

			l->st_size = len;

			l->st_type = type;

			l->scope = cur_scope;

			l->lines = (RefList*) malloc(sizeof(RefList));

			l->lines->lineno = lineno;

			l->lines->next = NULL;

			l->next = hash_table[hashval];

			hash_table[hashval] = l;
	
			/* Adding identifier to the revisit queue */
			add_to_queue(l, l->st_name, PARAM_CHECK);
		}
	}

	else{

		if(declare == 0){

			RefList *t = l->lines;

			while (t->next != NULL) t = t->next;
			
			t->next = (RefList*) malloc(sizeof(RefList));

			t->next->lineno = lineno;

			t->next->next = NULL;
		}
	
		else{
			
			if(l->scope == cur_scope){

				fprintf(stderr, "Declaração multipla de '%s', erro na linha %d\n", name, lineno);

 				exit(1);
			}

			
			else if(function_decl == 1){
				
				RefList *t = l->lines;

				while (t->next != NULL) t = t->next;
				
				
				t->next = (RefList*) malloc(sizeof(RefList));

				t->next->lineno = lineno;

				t->next->next = NULL;
			}
		
			else{
				
				l = (list_t*) malloc(sizeof(list_t));

				strncpy(l->st_name, name, len);

				l->st_size = len;

				l->st_type = type;

				l->scope = cur_scope;

				l->lines = (RefList*) malloc(sizeof(RefList));

				l->lines->lineno = lineno;

				l->lines->next = NULL;
				
				/* add to hashtable */
				l->next = hash_table[hashval];

				hash_table[hashval] = l; 
			}	
		}		
	}
}

list_t *lookup(char *name){ /* return symbol if found or NULL if not found */

	unsigned int hashval = hash(name);

	list_t *l = hash_table[hashval];

	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;

	return l;
}

void symtab_dump(FILE * of){  /* dump file */

  int i;
  fprintf(of,"------------ -------------- ------ ------------\n");

  fprintf(of,"Name         Type           Scope  Line Numbers\n");

  fprintf(of,"------------ -------------- ------ ------------\n");

  for (i=0; i < SIZE; ++i){ 

	if (hash_table[i] != NULL){ 

		list_t *l = hash_table[i];

		while (l != NULL){ 

			RefList *t = l->lines;

			fprintf(of,"%-13s",l->st_name);

			if (l->st_type == INT_TYPE)                fprintf(of,"%-15s","int");

			else if (l->st_type == VOID_TYPE)          fprintf(of,"%-15s","void");

			else if (l->st_type == ARRAY_TYPE){

				fprintf(of,"array of %d ", l->array_size);

				if (l->inf_type == INT_TYPE) 		   fprintf(of,"%-4s","int");

				else fprintf(of,"%-4s","undef");
			}

			else if (l->st_type == FUNCTION_TYPE){

				fprintf(of,"func ret ");

				if (l->inf_type == INT_TYPE) 		   fprintf(of,"%-6s","int");

				else if (l->inf_type  == VOID_TYPE)	   fprintf(of,"%-6s","void");

				else fprintf(of,"%-4s","undef");
			}

			else fprintf(of,"%-15s","undef"); // if UNDEF or 0

			fprintf(of,"  %d  ",l->scope);

			while (t != NULL){

				fprintf(of,"%4d ",t->lineno);

			t = t->next;

			}
			fprintf(of,"\n");

			l = l->next;
		}
    }
  }
}

// Type Functions

void set_type(char *name, int st_type, int inf_type){ 

	list_t *l = lookup(name);
	

	l->st_type = st_type;
	
	
	if(inf_type != UNDEF){
		l->inf_type = inf_type;
	}
}

int get_type(char *name){
	
	list_t *l = lookup(name);
	
	
	if(l->st_type == INT_TYPE){
		return l->st_type;
	}
	
	else{
		return l->inf_type;
	}
}

// Scope Management Functions

void hide_scope(){
	list_t *l;
	int i;

	for (i = 0; i < SIZE; i++){
		if(hash_table[i] != NULL){
			l = hash_table[i];
			
			while(l != NULL && l->scope == cur_scope){
				
				l = l->next;
			}
			
			hash_table[i] = l;
		}
	}
	cur_scope--;
}

void incr_scope(){ 
	cur_scope++;
}

// Function Declaration and Parameters

Param def_param(int par_type, char *param_name, int passing){ 
	Param param; 
	
	param.par_type = par_type;
	strcpy(param.param_name, param_name);
	param.passing = passing;	
	
	return param;
}

int func_declare(char *name, int ret_type, int num_of_pars, Param *parameters){ 

	list_t *l = lookup(name);
	
	if(l != NULL){
	
		if(l->st_type == UNDEF){

			l->st_type = FUNCTION_TYPE;
			
			l->inf_type = ret_type;
			
			l->num_of_pars = num_of_pars;
			l->parameters = parameters;
			
			return 0; 
		}
	
		else{
			fprintf(stderr, "Function %s already declared!\n", name);
			exit(1);
		}
	}
}

int func_param_check(char *name, int num_of_calls, int** par_types, int *num_of_pars){ // check parameters
	int i, j, type_1, type_2;
	
	list_t *l = lookup(name);
	

	for(i = 0 ; i < num_of_calls ; i++){
	
		if(l->num_of_pars != num_of_pars[i]){
			fprintf(stderr, "Function call of %s has wrong num of parameters!\n", name);
			exit(1);
		}
		
		for(j = 0; j < num_of_pars[i]; j++){
		
			type_1 = l->parameters[j].par_type; 
			
			type_2 = par_types[i][j]; 
			
			get_result_type(type_1, type_2, NONE);
			
		}
	}
	
	return 0;
}

// Revisit Queue Functions

void add_to_queue(list_t *entry, char *name, int type){ 
	revisit_queue *q;
	
	if(queue == NULL){
		q = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->entry = entry;
		q->st_name = name;
		q->revisit_type = type;
		q->next = NULL;

		if(type == PARAM_CHECK){
			q->num_of_calls = 0;
		}
		else if(type == ASSIGN_CHECK){
			q->num_of_assigns = 0;
		}

		queue = q;
	}

	else{
		q = queue;
		while(q->next != NULL) q = q->next;
		
		q->next = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->next->entry = entry;
		q->next->st_name = name;
		q->next->revisit_type = type;
		q->next->next = NULL;
		
		/* additional info */
		if(type == PARAM_CHECK){
			q->next->num_of_calls = 0;
		}
		else if(type == ASSIGN_CHECK){
			q->next->num_of_assigns = 0;
		}
	}		
}

revisit_queue *search_queue(char *name){
	revisit_queue *q;
	
	q = queue;
	while( (q != NULL) && (strcmp(q->st_name, name) != 0) ) q = q->next;
	
	return q;
}

revisit_queue *search_prev_queue(char *name){	
	revisit_queue *q;

	if(queue == NULL){
		return NULL;
	}	

	if( strcmp(queue->st_name, name) == 0 ){
		return NULL;
	}
	
	q = queue;
	while( (q != NULL) && (strcmp(q->next->st_name, name) != 0) ) q = q->next;
	
	return q;
}

int revisit(char *name){ 
	int i, type1, type2;

	revisit_queue *q = search_queue(name);
	revisit_queue *q2;
	
	if(q == NULL){
		return -1; 
	}
	
	switch(q->revisit_type){
		case PARAM_CHECK:			
			if(!func_param_check(name, q->num_of_calls, q->par_types, q->num_of_pars)){
				printf("Successful Parameter Check of %s\n", name);
			}
			
			q2 = search_prev_queue(name);
			if(q2 == NULL){ 
				queue = queue->next;
			}
			else{
				q2->next = q2->next->next;
			}
			
			break;
		case ASSIGN_CHECK:
			
			type1 = get_type(q->entry->st_name);
			for(i = 0; i < q->num_of_assigns; i++){
				type2 = expression_data_type(q->nodes[i]);
				
				
				get_result_type(
					type1,  
					type2,   
					NONE  
				);
			}
		

			q2 = search_prev_queue(name);
			if(q2 == NULL){ 
				queue = queue->next;
			}
			else{
				q2->next = q2->next->next;
			}
			
			break;
		/* ... */
	}
	
	return 0; 
}

void revisit_dump(FILE *of){
	int i;
	revisit_queue *q;
	q = queue;
	
	fprintf(of,"------------ -------------\n");
	fprintf(of,"Identifier   Revisit Type\n");
	fprintf(of,"------------ -------------\n");
  	while(q != NULL){
  		fprintf(of, "%-13s", q->st_name);
  		if(q->revisit_type == PARAM_CHECK){
  			fprintf(of,"%s","Parameter Check ");
  			fprintf(of,"for %d function calls",q->num_of_calls);
		}
		else if(q->revisit_type == ASSIGN_CHECK){
  			fprintf(of,"%s","Assignment Check ");
  			fprintf(of,"for %d assignments",q->num_of_assigns);
		}
		fprintf(of, "\n");
  		q = q->next;	
	}
}


/* String Messages */
void add_to_str_messages(char *str){
	
	if(num_of_msg == 0){
		str_messages = (char**) malloc(1*sizeof(char*));
	}
	else{
		str_messages = (char**) realloc(str_messages, (num_of_msg + 1)*sizeof(char*));
	}

	str_messages[num_of_msg] = (char*) malloc((strlen(str) + 1) * sizeof(char));

	strcpy(str_messages[num_of_msg], str);

	num_of_msg++;
}
