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
     leftsma = 275,
     rightsma = 276,
     leftbig = 277,
     rightbig = 278,
     comma = 279,
     newline = 280,
     OR = 281,
     AND = 282,
     EQU = 283,
     DOT = 284,
     EE = 285,
     LE = 286,
     LT = 287,
     GE = 288,
     GT = 289,
     MINUS = 290,
     PLUS = 291,
     DIVIDE = 292,
     TIMES = 293
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
#define leftsma 275
#define rightsma 276
#define leftbig 277
#define rightbig 278
#define comma 279
#define newline 280
#define OR 281
#define AND 282
#define EQU 283
#define DOT 284
#define EE 285
#define LE 286
#define LT 287
#define GE 288
#define GT 289
#define MINUS 290
#define PLUS 291
#define DIVIDE 292
#define TIMES 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 55 "pixel.y"
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
	std::string *astring;
}
/* Line 1529 of yacc.c.  */
#line 140 "pixel.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

