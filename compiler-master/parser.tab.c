/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include "semantics.c"
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
//	#include "code_generation.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;

	extern FILE *yyout;
	
	extern char * yytext;
	extern int lineno;

	extern int yylex();

	void yyerror();
	
	// for declarations
	void add_to_names(list_t *entry);

	list_t **names;

	int nc = 0;
	
	// for the initializations of arrays
	void add_to_vals(Value val);

	Value *vals;

	int vc = 0;
	
	// for else ifs
	void add_elseif(AST_Node *elsif);

	AST_Node **elsifs;

	int elseif_count = 0;
	
	// for functions
	AST_Node_Func_Decl *temp_function;

#line 112 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    VOID = 262,
    RETURN = 263,
    ADDOP = 264,
    MULOP = 265,
    OROP = 266,
    DIVOP = 267,
    ANDOP = 268,
    NOTOP = 269,
    EQUOP = 270,
    RELOP = 271,
    LPAREN = 272,
    RPAREN = 273,
    LBRACK = 274,
    RBRACK = 275,
    LBRACE = 276,
    RBRACE = 277,
    SEMI = 278,
    COMMA = 279,
    ASSIGN = 280,
    ID = 281,
    ICONST = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "parser.y" /* yacc.c:355  */

	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;
	
	// for arrays
	int array_size;
	
	// for parameters
	Param par;

#line 199 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   109,   116,   121,   127,   127,   127,   149,
     150,   153,   157,   161,   165,   171,   172,   185,   193,   201,
     202,   205,   214,   229,   234,   243,   248,   255,   259,   263,
     267,   274,   280,   287,   292,   300,   306,   312,   318,   325,
     329,   333,   337,   341,   345,   349,   353,   360,   363,   411,
     419,   477,   482,   492,   497,   516,   521,   527,   527,   537,
     538,   537,   562,   569,   574,   580,   585,   591,   591,   608,
     611,   616,   622,   627,   633,   638
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "IF", "ELSE", "WHILE", "VOID",
  "RETURN", "ADDOP", "MULOP", "OROP", "DIVOP", "ANDOP", "NOTOP", "EQUOP",
  "RELOP", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "SEMI", "COMMA", "ASSIGN", "ID", "ICONST", "$accept", "program", "$@1",
  "declarations", "declaration", "$@2", "$@3", "type", "names", "variable",
  "array", "init", "var_init", "array_init", "values", "statements",
  "statement", "if_statement", "else_if", "optional_else",
  "while_statement", "tail", "expression", "constant", "assigment",
  "function_call", "call_params", "call_param", "functions", "function",
  "$@4", "function_head", "$@5", "$@6", "return_type",
  "parameters_optional", "parameters", "parameter", "$@7", "function_tail",
  "declarations_optional", "statements_optional", "return_optional", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,  -102,  -102,     7,  -102,  -102,  -102,  -102,   -12,    44,
    -102,  -102,    16,    24,  -102,  -102,  -102,  -102,  -102,    35,
      12,    11,    36,    32,   -12,    48,    12,  -102,  -102,    52,
      33,    62,    64,    57,  -102,  -102,  -102,  -102,    67,  -102,
    -102,  -102,    12,  -102,     6,    78,    71,    33,  -102,    33,
      33,    33,    33,    33,  -102,    36,  -102,    83,    85,    51,
      84,     6,  -102,  -102,  -102,    89,    93,    98,  -102,  -102,
     125,    90,    94,    37,  -102,  -102,   133,   138,    70,  -102,
      33,    33,  -102,    38,  -102,  -102,  -102,    33,    97,   104,
    -102,    33,  -102,    36,    81,    95,  -102,   125,    30,  -102,
     108,   112,  -102,    12,   125,  -102,   107,   107,  -102,  -102,
    -102,   103,     6,   127,  -102,  -102,   119,  -102,     5,    13,
     134,  -102,  -102,   129,  -102,    22,  -102,    33,   135,   105,
      33,   107,   115,  -102,   107,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     6,     1,    57,     0,    57,
      56,    59,    15,     7,    13,    14,    19,    20,    55,     0,
       0,     0,     0,    16,     0,     0,    71,    58,    62,     0,
       0,     0,    47,     0,    45,    46,    47,    21,     0,    11,
      12,     8,    70,     5,    73,     0,     0,    52,    18,     0,
       0,     0,     0,     0,    17,     0,     4,     0,     0,    15,
       0,    72,    26,    27,    28,     0,     0,    75,    60,    44,
      54,     0,    51,    39,    40,    41,    42,    43,     0,    24,
       0,     0,    16,     0,    25,    29,    30,     0,     0,    67,
      50,     0,    22,     0,     0,     0,    49,    48,     0,    69,
       0,    63,    66,     0,    53,    23,     0,     0,    74,    61,
      67,     0,     0,    36,    37,    65,    15,    68,     0,     0,
      36,    32,    38,     0,    35,     0,    31,     0,     0,     0,
       0,     0,     0,    34,     0,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,   -13,  -102,  -102,   -18,  -102,    -8,
     132,   130,  -102,  -102,  -102,    39,   -57,  -102,  -102,    40,
    -102,  -101,   -29,   -19,  -102,   -36,  -102,  -102,  -102,   144,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,    45,  -102,  -102,
    -102,  -102,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     7,    42,     4,     8,    25,     5,    13,    60,
      82,    15,    16,    17,    78,    61,    62,    63,   120,   121,
      64,   124,    33,    34,    65,    35,    71,    72,     9,    10,
      11,    19,    20,    89,    29,   100,   101,   102,   103,    27,
      44,    67,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    46,    28,    37,    84,   113,   114,     6,    66,    57,
      57,    58,    58,    43,    12,     1,    39,   123,    70,     2,
      73,    74,    75,    76,    77,    66,   128,   122,    30,    56,
     133,    59,    59,   135,   112,    21,    79,    31,    32,    49,
      50,    22,    51,   112,    -3,    52,    53,    50,    24,    51,
      30,    94,    95,   108,    97,    30,    26,    38,    98,    31,
      36,    84,   104,    36,    59,    36,    49,    50,    47,    51,
      21,    41,    52,    53,   105,    96,    66,    54,    45,    47,
      49,    50,    66,    51,    48,   111,    52,    53,    55,    69,
      49,    50,    92,    51,    93,    68,    52,    53,   129,   106,
      80,   132,    81,   117,    49,    50,    87,    51,    90,    83,
      52,    53,    85,   107,    49,    50,    86,    51,    91,    99,
      52,    53,   -64,   131,    49,    50,   109,    51,   112,   116,
      52,    53,   119,   134,    49,    50,   110,    51,    21,   125,
      52,    53,    49,    50,    23,    51,   127,    49,    50,    53,
      51,   118,   130,    18,    40,   115,     0,     0,     0,     0,
     126
};

static const yytype_int16 yycheck[] =
{
       8,    30,    20,    22,    61,   106,   107,     0,    44,     4,
       4,     6,     6,    26,    26,     3,    24,     4,    47,     7,
      49,    50,    51,    52,    53,    61,     4,    22,    17,    42,
     131,    26,    26,   134,    21,    19,    55,    26,    27,     9,
      10,    25,    12,    21,     0,    15,    16,    10,    24,    12,
      17,    80,    81,    23,    83,    17,    21,    25,    87,    26,
      27,   118,    91,    27,    26,    27,     9,    10,    17,    12,
      19,    23,    15,    16,    93,    83,   112,    20,    26,    17,
       9,    10,   118,    12,    20,   103,    15,    16,    21,    18,
       9,    10,    22,    12,    24,    17,    15,    16,   127,    18,
      17,   130,    17,   111,     9,    10,     8,    12,    18,    25,
      15,    16,    23,    18,     9,    10,    23,    12,    24,    22,
      15,    16,    18,    18,     9,    10,    18,    12,    21,    26,
      15,    16,     5,    18,     9,    10,    24,    12,    19,     5,
      15,    16,     9,    10,    12,    12,    17,     9,    10,    16,
      12,   112,    17,     9,    24,   110,    -1,    -1,    -1,    -1,
     120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    29,    32,    35,     0,    30,    33,    56,
      57,    58,    26,    36,    37,    39,    40,    41,    57,    59,
      60,    19,    25,    38,    24,    34,    21,    67,    35,    62,
      17,    26,    27,    50,    51,    53,    27,    51,    25,    37,
      39,    23,    31,    32,    68,    26,    50,    17,    20,     9,
      10,    12,    15,    16,    20,    21,    32,     4,     6,    26,
      37,    43,    44,    45,    48,    52,    53,    69,    17,    18,
      50,    54,    55,    50,    50,    50,    50,    50,    42,    51,
      17,    17,    38,    25,    44,    23,    23,     8,    70,    61,
      18,    24,    22,    24,    50,    50,    37,    50,    50,    22,
      63,    64,    65,    66,    50,    51,    18,    18,    23,    18,
      24,    35,    21,    49,    49,    65,    26,    37,    43,     5,
      46,    47,    22,     4,    49,     5,    47,    17,     4,    50,
      17,    18,    50,    49,    18,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    30,    29,    31,    31,    33,    34,    32,    35,
      35,    36,    36,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    52,
      53,    54,    54,    55,    55,    56,    56,    58,    57,    60,
      61,    59,    62,    63,    63,    64,    64,    66,    65,    67,
      68,    68,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     0,     0,     5,     1,
       1,     3,     3,     1,     1,     1,     2,     3,     3,     1,
       1,     3,     6,     3,     1,     2,     1,     1,     1,     2,
       2,     7,     6,     7,     6,     2,     0,     5,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     3,     3,
       4,     1,     0,     3,     1,     2,     1,     0,     3,     0,
       0,     7,     1,     1,     0,     3,     1,     0,     3,     5,
       1,     0,     1,     0,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 109 "parser.y" /* yacc.c:1646  */
    { main_decl_tree = (yyvsp[0].node); ast_traversal((yyvsp[0].node)); }
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "parser.y" /* yacc.c:1646  */
    { opt_func_tree = (yyvsp[0].node); ast_traversal((yyvsp[0].node)); }
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Declarations *temp = (AST_Node_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_declarations_node(temp->declarations, temp->declaration_count, (yyvsp[0].node));
	}
#line 1411 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 1419 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "parser.y" /* yacc.c:1646  */
    { declare = 1; }
#line 1425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "parser.y" /* yacc.c:1646  */
    { declare = 0; }
#line 1431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 128 "parser.y" /* yacc.c:1646  */
    {
		int i;
		(yyval.node) = new_ast_decl_node((yyvsp[-4].data_type), names, nc);
		nc = 0;
		
		AST_Node_Decl *temp = (AST_Node_Decl*) (yyval.node);
		
		// declare types of the names
		for(i=0; i < temp->names_count; i++){
			// variable
			if(temp->names[i]->st_type == UNDEF){
				set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
			}
			// array
			else if(temp->names[i]->st_type == ARRAY_TYPE){
				set_type(temp->names[i]->st_name, ARRAY_TYPE, temp->data_type);
			}
		}
	}
#line 1455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.data_type) = INT_TYPE;   }
#line 1461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.data_type) = VOID_TYPE;  }
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 154 "parser.y" /* yacc.c:1646  */
    {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 162 "parser.y" /* yacc.c:1646  */
    {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "parser.y" /* yacc.c:1646  */
    { 
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 173 "parser.y" /* yacc.c:1646  */
    {
		if(declare == 1){
			(yyvsp[-1].symtab_item)->st_type = ARRAY_TYPE;
			(yyvsp[-1].symtab_item)->array_size = (yyvsp[0].array_size);
			(yyvsp[-1].symtab_item)->vals = NULL;
			(yyval.symtab_item) = (yyvsp[-1].symtab_item);
		}		
	}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "parser.y" /* yacc.c:1646  */
    {
		// if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "parser.y" /* yacc.c:1646  */
    {
		// set array_size for declaration purposes
		(yyval.array_size) = (yyvsp[-1].val).ival;
	}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "parser.y" /* yacc.c:1646  */
    { 
	AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
	(yyvsp[-2].symtab_item)->val = temp->val;
	(yyvsp[-2].symtab_item)->st_type = temp->const_type;
	(yyval.symtab_item) = (yyvsp[-2].symtab_item);
}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 215 "parser.y" /* yacc.c:1646  */
    {
	// $2 contains array_size
	if((yyvsp[-4].array_size) != vc){
	    fprintf(stderr, "Array init at %d doesn't contain the right amount of values!\n", lineno);
		exit(1);
	}
	(yyvsp[-5].symtab_item)->st_type = ARRAY_TYPE;
	(yyvsp[-5].symtab_item)->vals = vals;
	(yyvsp[-5].symtab_item)->array_size = (yyvsp[-4].array_size);
	(yyval.symtab_item) = (yyvsp[-5].symtab_item);
	vc = 0;
}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Statements *temp = (AST_Node_Statements*) (yyvsp[-1].node);
		(yyval.node) = new_statements_node(temp->statements, temp->statement_count, (yyvsp[0].node));
	}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_statements_node(NULL, 0, (yyvsp[0].node));
	}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 256 "parser.y" /* yacc.c:1646  */
    { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 260 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 264 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 268 "parser.y" /* yacc.c:1646  */
    { 
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 275 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_if_node((yyvsp[-4].node), (yyvsp[-2].node), elsifs, elseif_count, (yyvsp[0].node));
		elseif_count = 0;
		elsifs = NULL;
	}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 281 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_if_node((yyvsp[-3].node), (yyvsp[-1].node), NULL, 0, (yyvsp[0].node));
	}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "parser.y" /* yacc.c:1646  */
    {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "parser.y" /* yacc.c:1646  */
    {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 301 "parser.y" /* yacc.c:1646  */
    {
		/* else exists */
		(yyval.node) = (yyvsp[0].node);
	}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 306 "parser.y" /* yacc.c:1646  */
    {
		/* no else */
		(yyval.node) = NULL;
	}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 313 "parser.y" /* yacc.c:1646  */
    {
	(yyval.node) = new_ast_while_node((yyvsp[-2].node), (yyvsp[0].node));
}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 319 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.node) = (yyvsp[-1].node); /* just pass information */
}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 326 "parser.y" /* yacc.c:1646  */
    { 
	    (yyval.node) = new_ast_arithm_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 330 "parser.y" /* yacc.c:1646  */
    {
	    (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 334 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 338 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_equ_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 342 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_rel_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 346 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 350 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node); /* no sign */
	}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 354 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[0].val));  }
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 364 "parser.y" /* yacc.c:1646  */
    {
	AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[-2].symtab_item);
	(yyval.node) = new_ast_assign_node(temp->entry, temp->ref, (yyvsp[0].node));
	
	/* find datatypes */
	int type1 = get_type(temp->entry->st_name);
	int type2 = expression_data_type((yyvsp[0].node));
	
	/* the last function will give us information about revisits */
	
	/* contains revisit => add assignment-check to revisit queue */
	if(cont_revisit == 1){	
		/* search if entry exists */
		revisit_queue *q = search_queue(temp->entry->st_name);
		if(q == NULL){
			add_to_queue(temp->entry, temp->entry->st_name, ASSIGN_CHECK);
			q = search_queue(temp->entry->st_name);	
		}
		
		/* setup structures */
		if(q->num_of_assigns == 0){ /* first node */
			q->nodes = (void**) malloc(sizeof(void*));
		}
		else{ /* general case */
			q->nodes = (void**) realloc(q->nodes, (q->num_of_assigns + 1) * sizeof(void*));
		}
		
		/* add info of assignment */
		q->nodes[q->num_of_assigns] = (void*) (yyvsp[0].node);
		
		/* increment number of assignments */
		q->num_of_assigns++;
		
		/* reset revisit flag */
		cont_revisit = 0;
		
		printf("Assignment revisit for %s at line %d\n", temp->entry->st_name, lineno);
	}
	else{ /* no revisit */
		/* check assignment semantics */
		get_result_type(
			type1,       /*  variable datatype  */
			type2,       /* expression datatype */
			NONE  /* checking compatibility only (no operator) */
		);
	}
}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 412 "parser.y" /* yacc.c:1646  */
    {
	(yyvsp[-2].symtab_item) = (yyvsp[0].symtab_item);
}
#line 1846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 420 "parser.y" /* yacc.c:1646  */
    {
	AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-1].node);
	(yyval.node) = new_ast_func_call_node((yyvsp[-3].symtab_item), temp->params, temp->num_of_pars);	
	
	/* add information to revisit queue entry (if one exists) */
	revisit_queue *q = search_queue((yyvsp[-3].symtab_item)->st_name);
	if(q != NULL){
		/* setup structures */
		if(q->num_of_calls == 0){ /* first call */
			q->par_types = (int**) malloc(sizeof(int*));
			q->num_of_pars = (int*) malloc(sizeof(int));
		}
		else{ /* general case */
			q->par_types = (int**) realloc(q->par_types, (q->num_of_calls + 1) * sizeof(int*));
			q->num_of_pars = (int*) realloc(q->num_of_pars, (q->num_of_calls + 1) * sizeof(int));
		}
		
		/* add info of function call */
		q->num_of_pars[q->num_of_calls] = temp->num_of_pars;
		q->par_types[q->num_of_calls] = (int*) malloc(temp->num_of_pars * sizeof(int));
		/* get the types of the parameters */
		int i;
		for(i = 0; i < temp->num_of_pars; i++){
			/* get datatype of parameter-expression */
			q->par_types[q->num_of_calls][i] = expression_data_type(temp->params[i]);
		}
		
		/* increment number of calls */
		q->num_of_calls++;
	}
	else{
		/* function declared before call */
		if((yyvsp[-3].symtab_item)->st_type == FUNCTION_TYPE){
			/* check number of parameters */
			if((yyvsp[-3].symtab_item)->num_of_pars != temp->num_of_pars){
				fprintf(stderr, "Function call of %s has wrong num of parameters!\n", (yyvsp[-3].symtab_item)->st_name);
				exit(1);
			}
			/* check if parameters are compatible */
			int i;
			for(i = 0; i < temp->num_of_pars; i++){
				/* type of parameter in function declaration */
				int type_1 = expression_data_type(temp->params[i]);
				
				/* type of parameter in function call*/
				int type_2 = (yyvsp[-3].symtab_item)->parameters[i].par_type;
				
				/* check compatibility for function call */
				get_result_type(type_1, type_2, NONE);
				/* error occurs automatically in the function */
			}
		}
	}
}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 478 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 482 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Call_Params *temp = malloc (sizeof (AST_Node_Call_Params));
		temp->type = CALL_PARAMS;
		temp->params = NULL;
		temp->num_of_pars = 0;
		(yyval.node) = (AST_Node*)temp;
	}
#line 1925 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 493 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-2].node);
		(yyval.node) = new_ast_call_params_node(temp->params, temp->num_of_pars, (yyvsp[0].node));
	}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 498 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_call_params_node(NULL, 0, (yyvsp[0].node));
	}
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 517 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Func_Declarations *temp = (AST_Node_Func_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_func_declarations_node(temp->func_declarations, temp->func_declaration_count, (yyvsp[0].node));
	}
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 522 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_func_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 527 "parser.y" /* yacc.c:1646  */
    { incr_scope(); }
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 528 "parser.y" /* yacc.c:1646  */
    { 
	/* perform revisit */
	revisit(temp_function->entry->st_name);

	hide_scope();
	(yyval.node) = (AST_Node *) temp_function;
}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 537 "parser.y" /* yacc.c:1646  */
    { function_decl = 1; }
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 538 "parser.y" /* yacc.c:1646  */
    { 
		function_decl = 0;
		
		AST_Node_Ret_Type *temp = (AST_Node_Ret_Type *) (yyvsp[-2].node);
		temp_function = (AST_Node_Func_Decl *) new_ast_func_decl_node(temp->ret_type, temp->pointer, (yyvsp[-1].symtab_item));
		temp_function->entry->st_type = FUNCTION_TYPE;
		temp_function->entry->inf_type = temp->ret_type;
	}
#line 1996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 547 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].node) != NULL){
			AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-1].node);
			
			temp_function->entry->parameters = temp->parameters;
			temp_function->entry->num_of_pars = temp->num_of_pars;
		}
		else{
			temp_function->entry->parameters = NULL;
			temp_function->entry->num_of_pars = 0;
		}		
	}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 563 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_ret_type_node((yyvsp[0].data_type), 0);
	}
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 570 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 574 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = NULL;
	}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 581 "parser.y" /* yacc.c:1646  */
    {
		AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-2].node);
		(yyval.node) = new_ast_decl_params_node(temp->parameters, temp->num_of_pars, (yyvsp[0].par));
	}
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 586 "parser.y" /* yacc.c:1646  */
    {
		(yyval.node) = new_ast_decl_params_node(NULL, 0, (yyvsp[0].par));
	}
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 591 "parser.y" /* yacc.c:1646  */
    { declare = 1; }
#line 2060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 592 "parser.y" /* yacc.c:1646  */
    { 
	declare = 0;
	
	// set type of symbol table entry	
	if((yyvsp[0].symtab_item)->st_type == UNDEF){ /* "simple" type */
		set_type((yyvsp[0].symtab_item)->st_name, (yyvsp[-1].data_type), UNDEF); 
	}
	else if((yyvsp[0].symtab_item)->st_type == ARRAY_TYPE){ /* array  */
		set_type((yyvsp[0].symtab_item)->st_name, ARRAY_TYPE, (yyvsp[-1].data_type));
	}
	
	/* define parameter */
	(yyval.par) = def_param((yyvsp[-1].data_type), (yyvsp[0].symtab_item)->st_name, 0);
}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 612 "parser.y" /* yacc.c:1646  */
    {
		temp_function->declarations = (yyvsp[0].node);
	}
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 616 "parser.y" /* yacc.c:1646  */
    {
		temp_function->declarations = NULL;
	}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 623 "parser.y" /* yacc.c:1646  */
    {
		temp_function->statements = (yyvsp[0].node);
	}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 627 "parser.y" /* yacc.c:1646  */
    {
		temp_function->statements = NULL;
	}
#line 2111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 634 "parser.y" /* yacc.c:1646  */
    {
		temp_function->return_node = new_ast_return_node(temp_function->ret_type, (yyvsp[-1].node));
	}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 638 "parser.y" /* yacc.c:1646  */
    {
		temp_function->return_node = NULL;
	}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2131 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 643 "parser.y" /* yacc.c:1906  */


void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d %s\n", lineno, yytext);
  exit(1);
}

void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;		
	}
}

void add_to_vals(Value val){
	// first entry
	if(vc == 0){
		vc = 1;
		vals = (Value *) malloc(1 * sizeof(Value));
		vals[0] = val;
	}
	// general case
	else{
		vc++;
		vals = (Value *) realloc(vals, vc * sizeof(Value));
		vals[vc - 1] = val;
	}
}

void add_elseif(AST_Node *elsif){
	// first entry
	if(elseif_count == 0){
		elseif_count = 1;
		elsifs = (AST_Node **) malloc(1 * sizeof(AST_Node));
		elsifs[0] = elsif;
	}
	// general case
	else{
		elseif_count++;
		elsifs = (AST_Node **) realloc(elsifs, elseif_count * sizeof(AST_Node));
		elsifs[elseif_count - 1] = elsif;
	}
}

int main (int argc, char *argv[]){
	
	// initialize symbol table
	init_hash_table();
	
	// initialize revisit queue
	queue = NULL;
	
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!\n");
	
	/* remove print from revisit queue */
	revisit_queue *q = search_prev_queue("print");
	if(q == NULL){ /* special case: first entry */
		if(queue != NULL){ /* check if queue not empty */
			queue = queue->next;
		}
	}
	else{
		q->next = q->next->next;
	}
	
	/* perform the remaining checks (assignments) */
	if(queue != NULL){
		revisit_queue *cur;
		cur = queue;
		while(cur != NULL){
			if(cur->revisit_type == ASSIGN_CHECK){
				revisit(cur->st_name);
			}
			cur = cur->next;
		}
	}
	
	/* if still not empty => warning */
	if(queue != NULL){
		printf("Warning! Something in the revisit queue has not been checked yet!\n");
	}
	
	/* declare function type of "print" */
	func_declare("print", VOID_TYPE, 1, NULL);
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);
	
	// revisit queue dump
	yyout = fopen("revisit_dump.out", "w");
	revisit_dump(yyout);
	fclose(yyout);
	
	// code generation
	//printf("\nGenerating code...\n");
	//generate_code();
	
	return flag;
}
