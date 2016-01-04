/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     EQU = 283,
     DOT = 284,
     EE = 285,
     OR = 286,
     AND = 287,
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
#define EQU 283
#define DOT 284
#define EE 285
#define OR 286
#define AND 287
#define LE 288
#define LT 289
#define GE 290
#define GT 291
#define MINUS 292
#define PLUS 293
#define DIVIDE 294
#define TIMES 295




/* Copy the first part of user declarations.  */
#line 12 "pixel.y"

	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include <vector>
	#include <memory.h>
	#include <ctime>
	#include <list>
	#include "utils.h"  /*Header file for AST*/
	#include "lex.yy.c" /* yylex file*/
	
	/* use YYPARSE_PARAM to receive parameter in yyparse*/
	#define YYPARSE_PARAM parm
	#define RANDNUM 26

	/* the root of the abstract syntax tree */	
	lines_node *root;

	static	std::list<line_node *> *tmp_line; /*store the temporary line*/	
	static	BaseType *tmp_var;				  /*store the temporary variable*/
	static	iTREE *tmp_tree;				  /*store the temporary tree*/
	static	iPOLYGON *tmp_poly;				  /*store the temporary polygon*/
	static	std::map<int, std::pair<int, int> > *tmp_map;
	static	std::vector<std::pair<int, int> > *tmp_polypoints;
	static	std::pair<int, std::pair<int, int> > *tmp_pair;
	static 	std::string *tmp_varname;
	static 	char tmpbuf[1000];

	extern	std::map<std::string, BaseType *> vars;	 /* save all the variables */
	extern int yylineno;
	extern std::string errors;
	extern std::string ans;

	static char* GetName(char *nname);			/* get the variable name */
	static std::string RandName();				/* generate random name*/

	extern void DeletMulDef(std::string node_name);	/* delete multi definition */

	void yyerror (/*void *a, */const char *msg);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 236 "pixel.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "pixel.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    19,    23,
      34,    49,    62,    77,    85,    97,   108,   116,   128,   140,
     148,   151,   155,   161,   167,   176,   180,   183,   185,   194,
     196,   198,   200,   202,   211,   224,   235,   248,   254,   264,
     270,   280,   284,   287,   289,   293,   296,   298,   301,   304,
     307,   310,   313,   316,   319,   322,   325,   328,   330,   338,
     341,   344,   350,   354,   356,   358,   362,   366,   370,   374,
     378,   382,   386,   390,   394,   398,   402,   406
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    43,    -1,    -1,    27,
      -1,     3,    28,    14,    -1,     3,    28,    15,    -1,     3,
      28,     4,    -1,     3,    28,     7,    22,     4,    26,     4,
      26,    45,    23,    -1,     3,    28,     8,    22,     4,    26,
       4,    26,     4,    26,     4,    26,    45,    23,    -1,     3,
      28,     9,    22,     4,    26,     4,    26,     4,    26,    45,
      23,    -1,     3,    28,    10,    22,     4,    26,     4,    26,
       4,    26,     4,    26,    45,    23,    -1,     3,    28,    13,
      22,    45,    26,    52,    -1,     3,    28,    13,    22,     4,
      26,     4,    26,    45,    26,    52,    -1,     3,    28,    12,
      22,     4,    26,     4,    26,     4,    23,    -1,     3,    28,
      11,    22,     4,    26,    50,    -1,     3,    28,    11,    22,
       4,    26,     4,    26,     4,    26,    50,    -1,    16,    22,
      55,    23,    24,    43,    25,    17,    24,    43,    25,    -1,
      18,    22,    55,    23,    24,    43,    25,    -1,    19,    46,
      -1,     3,    28,     3,    -1,     3,    29,    12,    28,    45,
      -1,     3,    29,     3,    28,    55,    -1,     3,    28,    20,
      22,    48,    24,    43,    25,    -1,     3,    22,    47,    -1,
      21,    45,    -1,     3,    -1,    12,    22,     4,    26,     4,
      26,     4,    23,    -1,    45,    -1,    14,    -1,    15,    -1,
       4,    -1,     7,    22,     4,    26,     4,    26,    45,    23,
      -1,     8,    22,     4,    26,     4,    26,     4,    26,     4,
      26,    45,    23,    -1,     9,    22,     4,    26,     4,    26,
       4,    26,    45,    23,    -1,    10,    22,     4,    26,     4,
      26,     4,    26,     4,    26,    45,    23,    -1,    11,    22,
       4,    26,    50,    -1,    11,    22,     4,    26,     4,    26,
       4,    26,    50,    -1,    13,    22,    45,    26,    52,    -1,
      13,    22,     4,    26,     4,    26,    45,    26,    52,    -1,
      46,    26,    47,    -1,    46,    23,    -1,    23,    -1,    49,
      26,    48,    -1,    49,    23,    -1,    23,    -1,     5,     3,
      -1,     6,     3,    -1,     7,     3,    -1,     9,     3,    -1,
      10,     3,    -1,     8,     3,    -1,    12,     3,    -1,    11,
       3,    -1,    13,     3,    -1,    51,    50,    -1,    23,    -1,
      22,     4,    26,     4,    26,     4,    23,    -1,    53,    52,
      -1,    53,    23,    -1,    22,     4,    26,     4,    23,    -1,
       3,    29,     3,    -1,     4,    -1,     3,    -1,    55,    38,
      55,    -1,    55,    37,    55,    -1,    55,    40,    55,    -1,
      55,    39,    55,    -1,    55,    30,    55,    -1,    55,    36,
      55,    -1,    55,    35,    55,    -1,    55,    34,    55,    -1,
      55,    33,    55,    -1,    55,    32,    55,    -1,    55,    31,
      55,    -1,    22,    55,    23,    -1,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   127,   133,   142,   147,   152,   157,   162,
     167,   172,   177,   182,   188,   193,   201,   207,   215,   223,
     230,   234,   238,   242,   246,   254,   261,   271,   274,   286,
     289,   297,   305,   313,   321,   329,   337,   345,   354,   365,
     373,   385,   389,   394,   402,   406,   411,   418,   423,   428,
     433,   438,   443,   448,   453,   458,   468,   473,   483,   492,
     496,   504,   516,   519,   522,   530,   533,   536,   539,   542,
     545,   548,   551,   554,   557,   560,   563,   566
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "allname", "number", "INT", "BOOL",
  "POINT", "LINE", "circle", "rect", "tree", "color", "polygon", "TRUE",
  "FALSE", "IF", "ELSE", "WHILE", "draw", "func", "background", "leftsma",
  "rightsma", "leftbig", "rightbig", "comma", "newline", "EQU", "DOT",
  "EE", "OR", "AND", "LE", "LT", "GE", "GT", "MINUS", "PLUS", "DIVIDE",
  "TIMES", "$accept", "input", "lines", "line", "anomycolor", "anomyparam",
  "paramlist", "varlist", "singlevar", "bintree", "treenode", "polypoints",
  "singlepoint", "supernum", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    47,    47,    47,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    50,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     3,     3,    10,
      14,    12,    14,     7,    11,    10,     7,    11,    11,     7,
       2,     3,     5,     5,     8,     3,     2,     1,     8,     1,
       1,     1,     1,     8,    12,    10,    12,     5,     9,     5,
       9,     3,     2,     1,     3,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     7,     2,
       2,     5,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     5,     0,     2,     4,
       0,     0,     0,     0,     0,    27,    32,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    29,    20,    26,     1,
       3,    43,     0,    25,    21,     8,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,     0,    64,    63,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,    23,    22,    62,
      76,     4,    69,    75,    74,    73,    72,    71,    70,    66,
      65,    68,    67,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,    52,    50,    51,    54,    53,    55,     4,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    37,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    13,     0,    44,     0,
      19,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,    60,    59,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,    33,
       0,     0,     0,     0,     0,    28,     0,     0,     9,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,    38,
       0,    40,    61,     0,     0,     0,    17,    14,    18,     0,
      35,     0,     0,     0,    11,     0,     0,     0,    58,     0,
       0,    34,    36,    10,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    26,    32,    33,   115,   116,   171,
     172,   176,   177,    51,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
       0,    28,    -7,     1,   229,    40,  -146,    17,  -146,     0,
      26,   119,    42,     2,     2,  -146,  -146,     9,    31,    41,
      44,    68,    74,    75,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,    25,  -146,  -146,  -146,    87,    88,    89,    90,
      92,    93,    94,  -146,  -146,    97,    30,    96,    91,  -146,
       2,  -146,   122,   140,   113,   117,   131,   132,   133,   134,
       8,  -146,    26,   136,   137,   138,   139,   142,   143,    10,
      95,     2,    40,   141,   176,   124,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   125,   155,   156,
     157,   158,   159,   161,   162,   163,  -146,   164,   165,   166,
     167,   169,   170,   171,   174,   147,   198,   199,   200,   202,
     214,   215,   216,   218,  -146,   144,    36,   231,  -146,  -146,
    -146,     0,   241,   213,    48,    55,    55,    55,    55,   -30,
     -30,  -146,  -146,     0,   160,   219,   220,   221,     3,   223,
     224,   145,   225,   226,   227,   230,    38,   251,   253,   145,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,     0,
    -146,    95,   197,   234,   256,   257,   258,   259,   260,   283,
    -146,  -146,    24,   262,   263,   286,  -146,    46,   265,   266,
     267,   268,   269,  -146,   270,   271,  -146,   273,  -146,   148,
    -146,    40,   295,   296,   297,   298,   277,  -146,   300,    40,
     279,  -146,  -146,    40,   302,   303,   304,   305,   306,    40,
    -146,   287,   146,   288,   289,   290,   291,   308,   299,   292,
     309,   301,   293,   294,   307,   310,   311,   312,     0,  -146,
     317,    40,   319,    24,   313,  -146,   145,   314,  -146,   321,
      40,   322,    24,  -146,   145,   315,   316,   318,   320,  -146,
     323,  -146,  -146,   324,   325,   326,  -146,  -146,  -146,    40,
    -146,    40,   328,    40,  -146,    40,   330,   331,  -146,   332,
     333,  -146,  -146,  -146,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,    -8,  -146,    -5,   327,   104,   168,  -146,  -144,
    -146,  -145,  -146,  -146,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      28,    30,   183,     1,   186,    48,    49,   168,    53,    85,
      86,    15,    94,    15,   103,    13,     2,    29,     3,     4,
      22,     5,    22,    14,    50,   169,   170,     6,   197,    15,
      16,    54,   202,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   182,    15,    74,    46,   169,   170,    61,    31,
      10,    62,    22,    55,    47,    95,    11,    12,    71,   160,
     169,   170,   161,    56,   104,   117,    57,   118,   175,   201,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    79,    80,    81,    82,    83,    84,    85,    86,   249,
      58,   251,    83,    84,    85,    86,    59,    60,   256,   257,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    63,
      64,    65,    66,   162,    67,    68,    69,    88,   114,    70,
      73,    89,    34,    35,    72,   163,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    90,    91,    92,    93,    45,
      97,    98,    99,   100,   119,    75,   101,   102,   121,   133,
     150,   187,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   164,   211,    96,   175,   159,   229,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   134,   135,   136,   137,   138,   212,   139,   140,   141,
     142,   143,   144,   145,   219,   146,   147,   148,   221,   120,
     149,   151,   152,   153,   227,   154,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   155,   156,   157,
     245,   158,   189,   165,   166,   167,   247,   173,   174,   178,
     179,   180,    15,    16,   181,   254,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    78,    79,    80,    81,    82,
      83,    84,    85,    86,   266,   184,   267,   185,   269,   190,
     270,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   191,   192,   193,   194,   195,   196,   198,   199,
     200,   203,   204,   205,   206,   207,   208,   209,   210,   213,
     214,   215,   216,   217,   218,   220,   222,   223,   224,   225,
     226,   228,   234,   237,   230,   231,   232,   233,   236,   239,
     240,   246,   235,   248,   238,   253,   255,   262,     0,   188,
       0,    27,     0,   241,   243,     0,   242,   252,   244,   250,
     258,   260,   259,     0,     0,     0,   261,     0,   264,     0,
     263,   268,   265,   271,   272,   273,   274
};

static const yytype_int16 yycheck[] =
{
       5,     9,   146,     3,   149,     3,     4,     4,    14,    39,
      40,     3,     4,     3,     4,    22,    16,     0,    18,    19,
      12,    21,    12,    22,    22,    22,    23,    27,   172,     3,
       4,    22,   177,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     4,     3,    50,     3,    22,    23,    23,    23,
      22,    26,    12,    22,    12,    60,    28,    29,    28,    23,
      22,    23,    26,    22,    69,    71,    22,    72,    22,    23,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    33,    34,    35,    36,    37,    38,    39,    40,   233,
      22,   236,    37,    38,    39,    40,    22,    22,   242,   244,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    22,
      22,    22,    22,   121,    22,    22,    22,     4,    23,    22,
      29,     4,     3,     4,    28,   133,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,     4,     4,     4,    20,
       4,     4,     4,     4,     3,    23,     4,     4,    24,    24,
       3,   159,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    23,     4,    17,    62,    22,    24,    23,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    26,    26,    26,    26,    26,   191,    26,    26,    26,
      26,    26,    26,    26,   199,    26,    26,    26,   203,    23,
      26,     3,     3,     3,   209,     3,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     3,     3,     3,
     228,     3,    25,     4,     4,     4,   231,     4,     4,     4,
       4,     4,     3,     4,     4,   240,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   259,     4,   261,     4,   263,    25,
     265,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    26,    26,    26,    26,    26,     4,    26,    26,
       4,    26,    26,    26,    26,    26,    26,    26,    25,     4,
       4,     4,     4,    26,     4,    26,     4,     4,     4,     4,
       4,    24,     4,     4,    26,    26,    26,    26,    26,    26,
      26,     4,    23,     4,    23,     4,     4,     4,    -1,   161,
      -1,     4,    -1,    26,    23,    -1,    26,    23,    26,    26,
      25,    23,    26,    -1,    -1,    -1,    26,    -1,    23,    -1,
      26,    23,    26,    23,    23,    23,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    16,    18,    19,    21,    27,    42,    43,    44,
      22,    28,    29,    22,    22,     3,     4,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    45,    46,    45,     0,
      43,    23,    46,    47,     3,     4,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    20,     3,    12,     3,     4,
      22,    54,    55,    55,    22,    22,    22,    22,    22,    22,
      22,    23,    26,    22,    22,    22,    22,    22,    22,    22,
      22,    28,    28,    29,    55,    23,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    23,     4,     4,
       4,     4,     4,     4,     4,    45,    47,     4,     4,     4,
       4,     4,     4,     4,    45,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    23,    48,    49,    55,    45,     3,
      23,    24,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    24,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
       3,     3,     3,     3,     3,     3,     3,     3,     3,    24,
      23,    26,    43,    43,     4,     4,     4,     4,     4,    22,
      23,    50,    51,     4,     4,    22,    52,    53,     4,     4,
       4,     4,     4,    50,     4,     4,    52,    43,    48,    25,
      25,    26,    26,    26,    26,    26,     4,    50,    26,    26,
       4,    23,    52,    26,    26,    26,    26,    26,    26,    26,
      25,    17,    45,     4,     4,     4,     4,    26,     4,    45,
      26,    45,     4,     4,     4,     4,     4,    45,    24,    23,
      26,    26,    26,    26,     4,    23,    26,     4,    23,    26,
      26,    26,    26,    23,    26,    43,     4,    45,     4,    50,
      26,    52,    23,     4,    45,     4,    50,    52,    25,    26,
      23,    26,     4,    26,    23,    26,    45,    45,    23,    45,
      45,    23,    23,    23,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
   srand(time(NULL));
  yy_switch_to_buffer(yy_scan_string((char *)YYPARSE_PARAM));
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 119 "pixel.y"
    { 
			(yyval.lsnode) = (yyvsp[(1) - (1)].lsnode); 
			root = (yyval.lsnode);
			printf("input\n. root is 0x%x \n", root);
		;}
    break;

  case 3:
#line 127 "pixel.y"
    {
			/* the normal lines */
			(yyvsp[(2) - (2)].lsnode)->cmdlines->push_front((yyvsp[(1) - (2)].lnode));
			(yyval.lsnode) = (yyvsp[(2) - (2)].lsnode);
			//printf("lines $1 is: 0x%x\n", $$);
		;}
    break;

  case 4:
#line 133 "pixel.y"
    {
			/* empty string mark the end */
			tmp_line = new std::list<line_node *>;
			(yyval.lsnode) = new lines_node(tmp_line);
			//printf("empty\n");
		;}
    break;

  case 5:
#line 142 "pixel.y"
    {
			/* do nothing */
			printf("newline\n"); 
			(yyval.lnode) = NULL;
		;}
    break;

  case 6:
#line 147 "pixel.y"
    { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 7:
#line 152 "pixel.y"
    {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 8:
#line 157 "pixel.y"
    {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", (yyvsp[(3) - (3)].num));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 9:
#line 162 "pixel.y"
    { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (char *)((yyvsp[(9) - (10)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (10)].str)), tmp_var);
		;}
    break;

  case 10:
#line 167 "pixel.y"
    { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), (char *)((yyvsp[(13) - (14)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 11:
#line 172 "pixel.y"
    { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (12)].str)), tmp_var);
		;}
    break;

  case 12:
#line 177 "pixel.y"
    {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), (char *)((yyvsp[(13) - (14)].astring))->c_str());
	 		(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 13:
#line 182 "pixel.y"
    {
			tmp_poly = new iPOLYGON("polygon", 0, 0, (char *)((yyvsp[(5) - (7)].astring))->c_str());
			tmp_poly->points = *tmp_polypoints;
			printf("a new polygon!\n");
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (7)].str)), tmp_poly);
		;}
    break;

  case 14:
#line 188 "pixel.y"
    { 
			tmp_poly = new iPOLYGON("polygon", (yyvsp[(5) - (11)].num), (yyvsp[(7) - (11)].num), (char *)((yyvsp[(9) - (11)].astring))->c_str());
			tmp_poly->points = *tmp_polypoints;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (11)].str)), tmp_poly);
		;}
    break;

  case 15:
#line 193 "pixel.y"
    { 
			/* color type define. eg. yellow = color(r, g, b) */
			tmp_var = new BaseType;
			tmp_var->type = "color";
			tmp_var->cname = GetName((yyvsp[(1) - (10)].str));
			tmp_var->SetColor((yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (yyvsp[(9) - (10)].num));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (10)].str)), tmp_var);
		;}
    break;

  case 16:
#line 201 "pixel.y"
    {
			/* tree type define. eg. a = tree(rootnum, (a, r, l)(r, r1, l1)...) */
			tmp_tree = new iTREE("tree", (yyvsp[(5) - (7)].num), TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (7)].str)), tmp_tree);
		;}
    break;

  case 17:
#line 207 "pixel.y"
    {
			/* tree type define version 2. define the position
			* eg. a = tree(rootnum, x, y, (a, r, l)(r, r1, l1)...) 
			*/
			tmp_tree = new iTREE("tree", (yyvsp[(5) - (11)].num), (yyvsp[(7) - (11)].num), (yyvsp[(9) - (11)].num));
			tmp_tree->nodes = *tmp_map;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (11)].str)), tmp_tree);
		;}
    break;

  case 18:
#line 215 "pixel.y"
    { 
			/* if-else expression define
			* eg. if (expr) {...} else {...}
			* must contain if and else!
			*/
			//printf("define a IF-ELSE statement, the value of expr\n");
			(yyval.lnode) = new if_else_node(yylineno, (yyvsp[(3) - (11)].expnode), (yyvsp[(6) - (11)].lsnode), (yyvsp[(10) - (11)].lsnode));
		;}
    break;

  case 19:
#line 223 "pixel.y"
    { 
			/* while loop define
			* eg. while (expr) {...}
			*/
			//printf("define a while statement, the value of expr\n");
			(yyval.lnode) = new while_node(yylineno, (yyvsp[(3) - (7)].expnode), (yyvsp[(6) - (7)].lsnode));
		;}
    break;

  case 20:
#line 230 "pixel.y"
    { 
			/* draw an object variable */
			(yyval.lnode) = new draw_node(yylineno, (char *)((yyvsp[(2) - (2)].astring))->c_str());
		;}
    break;

  case 21:
#line 234 "pixel.y"
    {
			/* variable copy assignment. eg. a = b */
			(yyval.lnode) = new equ_sts_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
		;}
    break;

  case 22:
#line 238 "pixel.y"
    {
			/* change the color assignment. eg. a.color = blue */
			(yyval.lnode) = new equ_cts_node(yylineno, GetName((yyvsp[(1) - (5)].str)), (char *)((yyvsp[(5) - (5)].astring))->c_str());
		;}
    break;

  case 23:
#line 242 "pixel.y"
    {
			/* change the fields of variable. eg. a.x = expr */
	 		(yyval.lnode) = new equ_stn_node(yylineno, GetName((yyvsp[(1) - (5)].str)), GetName((yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].expnode));
	 	;}
    break;

  case 24:
#line 246 "pixel.y"
    {
			/* define a function
			* eg. foo = func(int a, point b, ... ) {...}
			*/
			//printf("define a func!\n");
			(yyval.lnode) = new def_func(yylineno, GetName((yyvsp[(1) - (8)].str)), *((yyvsp[(5) - (8)].varpairVect)), (yyvsp[(7) - (8)].lsnode));

	 	;}
    break;

  case 25:
#line 254 "pixel.y"
    {
			/* call a function
			* eg. foo(a, b, c, ...)
			*/
			//printf("call a func\n");
			(yyval.lnode) = new call_node(yylineno, GetName((yyvsp[(1) - (3)].str)), *((yyvsp[(3) - (3)].parampairVect)));
	 	;}
    break;

  case 26:
#line 261 "pixel.y"
    {
			/* change the background color
			* eg. background color(r,g,b)
			* or background red
			*/
			(yyval.lnode) = new back_node(yylineno, (char *)((yyvsp[(2) - (2)].astring))->c_str());
		;}
    break;

  case 27:
#line 271 "pixel.y"
    {
			(yyval.astring) = new std::string(GetName((yyvsp[(1) - (1)].str)));
		;}
    break;

  case 28:
#line 274 "pixel.y"
    { 
			/* color type define. eg. yellow = color(r, g, b) */
			tmp_var = new BaseType;
			tmp_var->type = "color";
			tmp_var->SetColor((yyvsp[(3) - (8)].num), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].num));
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 29:
#line 286 "pixel.y"
    {
			(yyval.astring) = (yyvsp[(1) - (1)].astring);
		;}
    break;

  case 30:
#line 289 "pixel.y"
    { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 31:
#line 297 "pixel.y"
    {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 32:
#line 305 "pixel.y"
    {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", (yyvsp[(1) - (1)].num));
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 33:
#line 313 "pixel.y"
    { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", (yyvsp[(3) - (8)].num), (yyvsp[(5) - (8)].num), (char *)((yyvsp[(7) - (8)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 34:
#line 321 "pixel.y"
    { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", (yyvsp[(3) - (12)].num), (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 35:
#line 329 "pixel.y"
    { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", (yyvsp[(3) - (10)].num), (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (char *)((yyvsp[(9) - (10)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 36:
#line 337 "pixel.y"
    {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", (yyvsp[(3) - (12)].num), (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
	 		tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 37:
#line 345 "pixel.y"
    {
			/* tree type define. eg. a = tree(rootnum, (a, r, l)(r, r1, l1)...) */
			tmp_tree = new iTREE("tree", (yyvsp[(3) - (5)].num), TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_tree));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 38:
#line 354 "pixel.y"
    {
			/* tree type define version 2. define the position
			* eg. a = tree(rootnum, x, y, (a, r, l)(r, r1, l1)...) 
			*/
			tmp_tree = new iTREE("tree", (yyvsp[(3) - (9)].num), (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].num));
			tmp_tree->nodes = *tmp_map;
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_tree));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 39:
#line 365 "pixel.y"
    {
			tmp_poly = new iPOLYGON("polygon", 0, 0, (char *)((yyvsp[(3) - (5)].astring))->c_str());
			tmp_poly->points = *tmp_polypoints;
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_poly));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 40:
#line 373 "pixel.y"
    { 
			tmp_poly = new iPOLYGON("polygon", (yyvsp[(3) - (9)].num), (yyvsp[(5) - (9)].num), (char *)((yyvsp[(7) - (9)].astring))->c_str());
			tmp_poly->points = *tmp_polypoints;
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_poly));
			(yyval.astring) = tmp_varname;			
		;}
    break;

  case 41:
#line 385 "pixel.y"
    {
			(yyval.parampairVect) = (yyvsp[(3) - (3)].parampairVect);
			(yyval.parampairVect)->push_back(*((yyvsp[(1) - (3)].astring)));
		;}
    break;

  case 42:
#line 389 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			(yyval.parampairVect)->push_back(*((yyvsp[(1) - (2)].astring)));
			//printf("a new paramlist!\n");
		;}
    break;

  case 43:
#line 394 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			//printf("empty paramlist!\n");
		;}
    break;

  case 44:
#line 402 "pixel.y"
    {
			(yyval.varpairVect) = (yyvsp[(3) - (3)].varpairVect);
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (3)].varPair)));
		;}
    break;

  case 45:
#line 406 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (2)].varPair)));
			printf("a new varlist!\n");
		;}
    break;

  case 46:
#line 411 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			printf("empty varlist!\n");
		;}
    break;

  case 47:
#line 418 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "int";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 48:
#line 423 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "bool";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 49:
#line 428 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "point";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 50:
#line 433 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "circle";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 51:
#line 438 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "rect";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 52:
#line 443 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "line";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 53:
#line 448 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "color";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 54:
#line 453 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "tree";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 55:
#line 458 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "polygon";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 56:
#line 468 "pixel.y"
    {
				(yyvsp[(2) - (2)].binvect)->insert(*(yyvsp[(1) - (2)].childpair));
				(yyval.binvect) = (yyvsp[(2) - (2)].binvect);
				//printf("the map is %d, %d\n", (*$2)[$1->first].first, (*$2)[$1->first].second);
			;}
    break;

  case 57:
#line 473 "pixel.y"
    {
				//printf("empty bintree\n");
				tmp_map = new std::map<int, std::pair<int, int> > ;	/* empty string*/
				(yyval.binvect) = tmp_map;
			;}
    break;

  case 58:
#line 483 "pixel.y"
    {
				(yyval.childpair) = new std::pair<int, std::pair<int, int> >;
				(yyval.childpair)->first = (yyvsp[(2) - (7)].num);
				(yyval.childpair)->second = std::make_pair((yyvsp[(4) - (7)].num), (yyvsp[(6) - (7)].num));
				//printf("node is: (%d, %d, %d)\n", $2, $4, $6);
			;}
    break;

  case 59:
#line 492 "pixel.y"
    {
				(yyvsp[(2) - (2)].polyvect)->push_back(*(yyvsp[(1) - (2)].polysingle));
				(yyval.polyvect) = (yyvsp[(2) - (2)].polyvect);
			;}
    break;

  case 60:
#line 496 "pixel.y"
    {
				tmp_polypoints = new std::vector<std::pair<int, int> >;
				(yyval.polyvect) = tmp_polypoints;
				(yyval.polyvect)->push_back(*(yyvsp[(1) - (2)].polysingle));
			;}
    break;

  case 61:
#line 504 "pixel.y"
    {
				(yyval.polysingle) = new std::pair<int, int>;
				(yyval.polysingle)->first = (yyvsp[(2) - (5)].num);
				(yyval.polysingle)->second = (yyvsp[(4) - (5)].num);
			;}
    break;

  case 62:
#line 516 "pixel.y"
    {
				(yyval.expnode) = new field_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
			;}
    break;

  case 63:
#line 519 "pixel.y"
    {
 				(yyval.expnode) = new number_node(yylineno, (yyvsp[(1) - (1)].num));
 			;}
    break;

  case 64:
#line 522 "pixel.y"
    {
 				(yyval.expnode) = new int_node(yylineno, GetName((yyvsp[(1) - (1)].str)));
 			;}
    break;

  case 65:
#line 530 "pixel.y"
    {
 				(yyval.expnode) = new plus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 66:
#line 533 "pixel.y"
    {
 				(yyval.expnode) = new minus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 67:
#line 536 "pixel.y"
    {
 				(yyval.expnode) = new times_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 68:
#line 539 "pixel.y"
    {
 				(yyval.expnode) = new divide_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 69:
#line 542 "pixel.y"
    {
 				(yyval.expnode) = new ee_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 70:
#line 545 "pixel.y"
    {
 				(yyval.expnode) = new gt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 71:
#line 548 "pixel.y"
    {
 				(yyval.expnode) = new ge_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 72:
#line 551 "pixel.y"
    {
 				(yyval.expnode) = new lt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 73:
#line 554 "pixel.y"
    {
 				(yyval.expnode) = new le_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 74:
#line 557 "pixel.y"
    {
				(yyval.expnode) = new and_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
			;}
    break;

  case 75:
#line 560 "pixel.y"
    {
				(yyval.expnode) = new or_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
			;}
    break;

  case 76:
#line 563 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(2) - (3)].expnode);
 			;}
    break;

  case 77:
#line 566 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(1) - (1)].expnode);
 			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2367 "pixel.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 571 "pixel.y"


/* GetName - could get a variable name from the whole string */
char *GetName(char *nname) {
	for (int i = 0; ; ++i) {
		if (((nname[i] <= 'z') && (nname[i] >='a'))
		||  ((nname[i] <= 'Z') && (nname[i] >='A'))
		||  ((nname[i] <='9') && (nname[i] >='0'))
		||   (nname[i] == '_'));
		else {
			nname[i] = 0;
			break;
		}
	}
	return nname;
}

std::string RandName() {
	int len = RANDNUM;
	char randname[RANDNUM];
	int i;
	for (i = 0; i < len; ++i)
		randname[i] = 'A'+rand()%26;
	randname[i] = '\0';
	std::string randans(randname);
	randans += "__";

	for (i = 0; i < len; ++i)
		randname[i] = 'a'+rand()%26;
	randname[i] = '\0';
	randans += std::string(randname);
	printf("the random name is : %s\n", randans.c_str());
	return randans;
}

/* yyerror - output error information */
void yyerror(/*void *a, */const char *msg)
{
	char *tmp;
	tmp = (char*)calloc(256, sizeof(char));
	sprintf(tmp, "[ERROR] line %d: %s\n", yylineno, msg);
	errors += tmp;
	free(tmp);
	//fprintf(stderr, "Error at line %d, %s\n", yylineno, msg);
}









