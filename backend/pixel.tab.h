/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     allname = 258,
     number = 259,
     INT = 260,
     BOOL = 261,
     POINT = 262,
     LINE = 263,
     circle = 264,
     rect = 265,
     tree = 266,
     color = 267,
     TRUE = 268,
     FALSE = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     draw = 273,
     func = 274,
     call = 275,
     leftsma = 276,
     rightsma = 277,
     leftbig = 278,
     rightbig = 279,
     comma = 280,
     newline = 281,
     OR = 282,
     AND = 283,
     EQU = 284,
     DOT = 285,
     EE = 286,
     LE = 287,
     LT = 288,
     GE = 289,
     GT = 290,
     MINUS = 291,
     PLUS = 292,
     DIVIDE = 293,
     TIMES = 294
   };
#endif
/* Tokens.  */
#define allname 258
#define number 259
#define INT 260
#define BOOL 261
#define POINT 262
#define LINE 263
#define circle 264
#define rect 265
#define tree 266
#define color 267
#define TRUE 268
#define FALSE 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define draw 273
#define func 274
#define call 275
#define leftsma 276
#define rightsma 277
#define leftbig 278
#define rightbig 279
#define comma 280
#define newline 281
#define OR 282
#define AND 283
#define EQU 284
#define DOT 285
#define EE 286
#define LE 287
#define LT 288
#define GE 289
#define GT 290
#define MINUS 291
#define PLUS 292
#define DIVIDE 293
#define TIMES 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "pixel.y"
{
	int num;
	char *str;
	BaseType *bstp;
	line_node *lnode;
	lines_node *lsnode;
	exp_node *expnode;
	std::pair<int, std::pair<int, int> > *childpair;
	std::map<int, std::pair<int, int> > *binvect;
	std::vector<std::pair<std::string, std::string> > *varpairVect;
	std::pair<std::string, std::string> *varPair;
	std::vector<std::string> *parampairVect;
}
/* Line 1529 of yacc.c.  */
#line 141 "pixel.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

