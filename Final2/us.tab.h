/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_US_TAB_H_INCLUDED
# define YY_YY_US_TAB_H_INCLUDED
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
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    OROP = 268,
    ANDOP = 269,
    NOTOP = 270,
    EQUOP = 271,
    EQ = 272,
    DIF = 273,
    GREAT = 274,
    LESS = 275,
    GEQ = 276,
    LESSEQ = 277,
    LPAREN = 278,
    RPAREN = 279,
    LBRACK = 280,
    RBRACK = 281,
    LKEY = 282,
    RKEY = 283,
    PTVIRG = 284,
    VIRG = 285,
    ATRIB = 286,
    ID = 287,
    NUM = 288,
    INCR = 289,
    REFER = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "us.y" /* yacc.c:1909  */

    int valor_inteiro;
    list_t* item_lista;

#line 95 "us.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_US_TAB_H_INCLUDED  */
