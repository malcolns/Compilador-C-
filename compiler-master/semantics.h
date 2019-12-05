/* token types */
#define UNDEF 0
#define INT_TYPE 1
#define FUNCTION_TYPE 2
#define VOID_TYPE 3
#define ARRAY_TYPE 4
#define STR_TYPE 5

/* operator types */
#define NONE 0	
#define ARITHM_OP 1 // ADDOP, MULOP, DIVOP (+, -, *, /)
#define NOT_OP 2    // NOTOP (!)
#define REL_OP 3    // RELOP (>, <, >=, <=)
#define EQU_OP 4    // EQUOP (==, !=)

int get_result_type (int type_1, int type_2, int op_type);

void type_error(int type_1, int type_2, int op_type);      
