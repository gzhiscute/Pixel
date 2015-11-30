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
     text = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     CONTINUE = 272,
     BREAK = 273,
     newline = 274,
     draw = 275,
     backgroud = 276,
     func = 277,
     TRUE = 278,
     FALSE = 279,
     relop = 280,
     call = 281,
     EQU = 282,
     DOT = 283,
     MINUS = 284,
     PLUS = 285,
     DIVIDE = 286,
     TIMES = 287,
     leftsma = 288,
     rightsma = 289,
     leftbig = 290,
     rightbig = 291,
     OR = 292,
     AND = 293,
     comma = 294
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
#define text 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define CONTINUE 272
#define BREAK 273
#define newline 274
#define draw 275
#define backgroud 276
#define func 277
#define TRUE 278
#define FALSE 279
#define relop 280
#define call 281
#define EQU 282
#define DOT 283
#define MINUS 284
#define PLUS 285
#define DIVIDE 286
#define TIMES 287
#define leftsma 288
#define rightsma 289
#define leftbig 290
#define rightbig 291
#define OR 292
#define AND 293
#define comma 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "pixel.y"
{
	int num;
	char *str;
	BaseType *bstp;
	line_node *lnode;
	lines_node *lsnode;
	exp_node *expnode;
	std::pair<int, std::pair<int, int> > *childpair;
	std::map<int, std::pair<int, int> > *binvect;
}
/* Line 1529 of yacc.c.  */
#line 138 "pixel.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

