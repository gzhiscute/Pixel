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
     polygon = 268,
     TRUE = 269,
     FALSE = 270,
     IF = 271,
     ELSE = 272,
     WHILE = 273,
     draw = 274,
     func = 275,
     background = 276,
     leftsma = 277,
     rightsma = 278,
     leftbig = 279,
     rightbig = 280,
     comma = 281,
     newline = 282,
     OR = 283,
     AND = 284,
     EQU = 285,
     DOT = 286,
     EE = 287,
     LE = 288,
     LT = 289,
     GE = 290,
     GT = 291,
     MINUS = 292,
     PLUS = 293,
     DIVIDE = 294,
     TIMES = 295
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
#define polygon 268
#define TRUE 269
#define FALSE 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define draw 274
#define func 275
#define background 276
#define leftsma 277
#define rightsma 278
#define leftbig 279
#define rightbig 280
#define comma 281
#define newline 282
#define OR 283
#define AND 284
#define EQU 285
#define DOT 286
#define EE 287
#define LE 288
#define LT 289
#define GE 290
#define GT 291
#define MINUS 292
#define PLUS 293
#define DIVIDE 294
#define TIMES 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 61 "pixel.y"
{
	int num;
	char *str;
	BaseType *bstp;
	line_node *lnode;
	lines_node *lsnode;
	exp_node *expnode;
	std::pair<int, std::pair<int, int> > *childpair;
	std::map<int, std::pair<int, int> > *binvect;
	std::pair<int, int>	*polysingle;
	std::vector<std::pair<int, int> > *polyvect;
	std::vector<std::pair<std::string, std::string> > *varpairVect;
	std::pair<std::string, std::string> *varPair;
	std::vector<std::string> *parampairVect;
	std::string *astring;
}
/* Line 1529 of yacc.c.  */
#line 146 "pixel.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

