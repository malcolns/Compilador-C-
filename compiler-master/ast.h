
typedef enum Node_Type {
	BASIC_NODE,  
	CONST_NODE,
	DECLARATIONS, 
	DECL_NODE,    
	STATEMENTS,   
	IF_NODE,      
	ELSIF_NODE,    
	WHILE_NODE,   
	ASSIGN_NODE,  
	SIMPLE_NODE,  
	FUNC_CALL,    
	CALL_PARAMS,  
	ARITHM_NODE,  
	REL_NODE,     
	EQU_NODE,     
	REF_NODE,	  
	FUNC_DECLS,   
	FUNC_DECL,    
	RET_TYPE,     
	DECL_PARAMS,  
	RETURN_NODE,  
}Node_Type;

typedef enum Arithm_op{

	ADD,  // + 

	SUB,  // - 

	MUL,  // *

	DIV , // / 

	DEC, // -- 
	
}Arithm_op;


typedef enum Rel_op{

	GREATER,        // > 

	LESS,           // < 

	GREATER_EQUAL,  // >=

	LESS_EQUAL     // <= 

}Rel_op;

typedef enum Equ_op{

	EQUAL,    // == 

	NOT_EQUAL // != 

}Equ_op;

typedef struct AST_Node{

	enum Node_Type type; 
	
	struct AST_Node *left;  

	struct AST_Node *right; 

}AST_Node;

typedef struct AST_Node_Declarations{

	enum Node_Type type; 

	struct AST_Node **declarations;

	int declaration_count;

}AST_Node_Declarations;

typedef struct AST_Node_Decl{

	enum Node_Type type; 

	int data_type;
	
	list_t **names;

	int names_count;

}AST_Node_Decl;

typedef struct AST_Node_Const{

	enum Node_Type type; 
	
	int const_type;
	
	Value val;

}AST_Node_Const;

typedef struct AST_Node_Statements{

	enum Node_Type type; 
	
	struct AST_Node **statements;

	int statement_count;

}AST_Node_Statements;

typedef struct AST_Node_If{

	enum Node_Type type; 
	
	struct AST_Node *condition;
	
	struct AST_Node *if_branch;
	
	struct AST_Node **elsif_branches;

	int elseif_count;
	
	struct AST_Node *else_branch;

}AST_Node_If;

typedef struct AST_Node_Elsif{

	enum Node_Type type;
	
	struct AST_Node *condition;
	
	struct AST_Node *elsif_branch;

}AST_Node_Elsif;


typedef struct AST_Node_While{

	enum Node_Type type;
	
	struct AST_Node *condition;

	struct AST_Node *while_branch;

}AST_Node_While;

typedef struct AST_Node_Assign{

	enum Node_Type type; 
	
	list_t *entry;
	
	int ref;
	
	struct AST_Node *assign_val;

}AST_Node_Assign;

typedef struct AST_Node_Simple{

	enum Node_Type type; 
	
	int statement_type;

}AST_Node_Simple;

typedef struct AST_Node_Incr{

	enum Node_Type type; 
	
	list_t *entry;
	
	int incr_type;
	
	int pf_type;

}AST_Node_Incr;

typedef struct AST_Node_Func_Call{

	enum Node_Type type;
	
	list_t *entry;
	
	int g_index;
	
	AST_Node **params;

	int num_of_pars;

}AST_Node_Func_Call;

typedef struct AST_Node_Call_Params{

	enum Node_Type type;

	AST_Node **params;

	int num_of_pars;

}AST_Node_Call_Params;


typedef struct AST_Node_Arithm{

	enum Node_Type type; 

	struct AST_Node *left;  

	struct AST_Node *right; 
	
	int data_type;
	
	enum Arithm_op op;
	
	int g_index;
}AST_Node_Arithm;

typedef struct AST_Node_Rel{

	enum Node_Type type; 
	
	struct AST_Node *left;  

	struct AST_Node *right; 

	int data_type;
	
	enum Rel_op op;
	
	int g_index;
}AST_Node_Rel;

typedef struct AST_Node_Equ{
	enum Node_Type type; 
	
	struct AST_Node *left;  
	
	struct AST_Node *right; 

	int data_type;

	enum Equ_op op;
	
	int g_index;

}AST_Node_Equ;

typedef struct AST_Node_Ref{

	enum Node_Type type; 
	
	list_t *entry;
	
	int ref;

}AST_Node_Ref;

/* Functions */
typedef struct AST_Node_Func_Declarations{

	enum Node_Type type; 

	struct AST_Node **func_declarations;

	int func_declaration_count;
	
}AST_Node_Func_Declarations;

typedef struct AST_Node_Func_Decl{

	enum Node_Type type;
	
	int ret_type;
	
	int pointer; 
	
	list_t *entry;

	struct AST_Node *declarations;

	struct AST_Node *statements;

	struct AST_Node *return_node;

}AST_Node_Func_Decl;

typedef struct AST_Node_Ret_Type{
	enum Node_Type type; 
	
	int ret_type;
	
	int pointer;

}AST_Node_Ret_Type;

typedef struct AST_Node_Decl_Params{
	enum Node_Type type; 
	
	// parameters
	Param *parameters;
	int num_of_pars;
}AST_Node_Decl_Params;

typedef struct AST_Node_Return{
	enum Node_Type type; 
	
	int ret_type;
	
	struct AST_Node *ret_val;
}AST_Node_Return;

/* Static AST Structures */
static AST_Node* main_decl_tree; /* main function's declarations AST Tree */
static AST_Node* main_func_tree; /* main function's statements AST Tree */
static AST_Node* opt_func_tree; /* optional functions AST Tree */

/* The basic node */
AST_Node *new_ast_node(Node_Type type, AST_Node *left, AST_Node *right); 	 // simple nodes

/* Declarations */
AST_Node *new_declarations_node(AST_Node **declarations, int declaration_count, AST_Node *declaration);
AST_Node *new_ast_decl_node(int data_type, list_t **names, int names_count); // declaration
AST_Node *new_ast_const_node(int const_type, Value val);					 // constant

/* Statements */
AST_Node *new_statements_node(AST_Node **statements, int statement_count, AST_Node *statement);
AST_Node *new_ast_if_node(AST_Node *condition, AST_Node *if_branch, AST_Node **elsif_branches, 
	int elseif_count, AST_Node *else_branch);
AST_Node *new_ast_elsif_node(AST_Node *condition, AST_Node *elsif_branch);
AST_Node *new_ast_while_node(AST_Node *condition, AST_Node *while_branch);
AST_Node *new_ast_assign_node(list_t *entry, int ref, AST_Node *assign_val);
AST_Node *new_ast_simple_node(int statement_type);							 // continue or break
AST_Node *new_ast_incr_node(list_t *entry, int incr_type, int pf_type);      // increment decrement
AST_Node *new_ast_func_call_node(list_t *entry, AST_Node **params, int num_of_pars); // function call
AST_Node *new_ast_call_params_node(AST_Node **params, int num_of_pars, AST_Node *param);

/* Expressions */
AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_ref_node(list_t *entry, int ref);
int expression_data_type(AST_Node *node);                                    // returns the data type of an expression
int getGraphIndex(AST_Node *node);

/* Functions */
AST_Node *new_func_declarations_node(AST_Node **func_declarations, int func_declaration_count, AST_Node *func_declaration);
AST_Node *new_ast_func_decl_node(int ret_type, int pointer, list_t *entry);
AST_Node *new_ast_ret_type_node(int ret_type, int pointer);                  // function return type
AST_Node *new_ast_decl_params_node(Param *parameters, int num_of_pars, Param param);
AST_Node *new_ast_return_node(int ret_type, AST_Node *ret_val);				 // function return

/* Tree Traversal */
void ast_print_node(AST_Node *node);	// print information of node
void ast_traversal(AST_Node *node);		// percorre a arvore
