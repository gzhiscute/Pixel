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
     TRUE = 268,
     FALSE = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     draw = 273,
     func = 274,
     background = 275,
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
//#define func 274
#define background 275
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
	static	std::map<int, std::pair<int, int> > *tmp_map;
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
#line 58 "pixel.y"
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
/* Line 193 of yacc.c.  */
#line 229 "pixel.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 242 "pixel.cpp"

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  237

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    19,    23,
      34,    49,    62,    77,    88,    96,   108,   120,   128,   131,
     135,   141,   147,   156,   160,   163,   165,   174,   176,   178,
     180,   182,   191,   204,   215,   228,   234,   244,   248,   251,
     253,   257,   260,   262,   265,   268,   271,   274,   277,   280,
     283,   286,   289,   291,   299,   303,   305,   307,   311,   315,
     319,   323,   327,   331,   335,   339,   343,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    42,    -1,    -1,    26,
      -1,     3,    29,    13,    -1,     3,    29,    14,    -1,     3,
      29,     4,    -1,     3,    29,     7,    21,     4,    25,     4,
      25,    44,    22,    -1,     3,    29,     8,    21,     4,    25,
       4,    25,     4,    25,     4,    25,    44,    22,    -1,     3,
      29,     9,    21,     4,    25,     4,    25,     4,    25,    44,
      22,    -1,     3,    29,    10,    21,     4,    25,     4,    25,
       4,    25,     4,    25,    44,    22,    -1,     3,    29,    12,
      21,     4,    25,     4,    25,     4,    22,    -1,     3,    29,
      11,    21,     4,    25,    49,    -1,     3,    29,    11,    21,
       4,    25,     4,    25,     4,    25,    49,    -1,    15,    21,
      52,    22,    23,    42,    24,    16,    23,    42,    24,    -1,
      17,    21,    52,    22,    23,    42,    24,    -1,    18,    45,
      -1,     3,    29,     3,    -1,     3,    30,    12,    29,    44,
      -1,     3,    30,     3,    29,    52,    -1,     3,    29,    19,
      21,    47,    23,    42,    24,    -1,     3,    21,    46,    -1,
      20,    44,    -1,     3,    -1,    12,    21,     4,    25,     4,
      25,     4,    22,    -1,    44,    -1,    13,    -1,    14,    -1,
       4,    -1,     7,    21,     4,    25,     4,    25,    44,    22,
      -1,     8,    21,     4,    25,     4,    25,     4,    25,     4,
      25,    44,    22,    -1,     9,    21,     4,    25,     4,    25,
       4,    25,    44,    22,    -1,    10,    21,     4,    25,     4,
      25,     4,    25,     4,    25,    44,    22,    -1,    11,    21,
       4,    25,    49,    -1,    11,    21,     4,    25,     4,    25,
       4,    25,    49,    -1,    45,    25,    46,    -1,    45,    22,
      -1,    22,    -1,    48,    25,    47,    -1,    48,    22,    -1,
      22,    -1,     5,     3,    -1,     6,     3,    -1,     7,     3,
      -1,     9,     3,    -1,    10,     3,    -1,     8,     3,    -1,
      12,     3,    -1,    11,     3,    -1,    50,    49,    -1,    22,
      -1,    21,     4,    25,     4,    25,     4,    22,    -1,     3,
      30,     3,    -1,     4,    -1,     3,    -1,    52,    37,    52,
      -1,    52,    36,    52,    -1,    52,    39,    52,    -1,    52,
      38,    52,    -1,    52,    35,    52,    -1,    52,    34,    52,
      -1,    52,    33,    52,    -1,    52,    32,    52,    -1,    52,
      31,    52,    -1,    21,    52,    22,    -1,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   116,   122,   131,   135,   140,   145,   150,
     155,   160,   165,   170,   178,   184,   192,   200,   207,   211,
     215,   219,   223,   231,   238,   248,   251,   263,   266,   274,
     282,   290,   298,   306,   314,   322,   331,   346,   350,   355,
     363,   367,   372,   379,   384,   389,   394,   399,   404,   409,
     414,   424,   429,   439,   450,   453,   456,   464,   467,   470,
     473,   476,   479,   482,   485,   488,   491,   494
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "allname", "number", "INT", "BOOL",
  "POINT", "LINE", "circle", "rect", "tree", "color", "TRUE", "FALSE",
  "IF", "ELSE", "WHILE", "draw", "func", "background", "leftsma",
  "rightsma", "leftbig", "rightbig", "comma", "newline", "OR", "AND",
  "EQU", "DOT", "EE", "LE", "LT", "GE", "GT", "MINUS", "PLUS", "DIVIDE",
  "TIMES", "$accept", "input", "lines", "line", "anomycolor", "anomyparam",
  "paramlist", "varlist", "singlevar", "bintree", "treenode", "supernum",
  "expr", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     3,     3,    10,
      14,    12,    14,    10,     7,    11,    11,     7,     2,     3,
       5,     5,     8,     3,     2,     1,     8,     1,     1,     1,
       1,     8,    12,    10,    12,     5,     9,     3,     2,     1,
       3,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     7,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     5,     0,     2,     4,
       0,     0,     0,     0,     0,    25,    30,     0,     0,     0,
       0,     0,     0,    28,    29,    27,    18,    24,     1,     3,
      39,     0,    23,    19,     8,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     0,    56,    55,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    21,    20,    54,    66,
       4,    65,    64,    63,    62,    61,    58,    57,    60,    59,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    48,    46,    47,    50,
      49,     4,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    35,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,    40,     0,    17,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,    31,     0,     0,
       0,     0,     0,    26,     9,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    36,     0,     0,     0,     0,    15,
      16,     0,    33,     0,     0,     0,    11,     0,     0,     0,
      53,     0,     0,    32,    34,    10,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    31,    32,   104,   105,   153,
     154,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -130
static const yytype_int16 yypact[] =
{
       0,   -17,   -11,    -2,   164,     2,  -130,    57,  -130,     0,
      20,   146,     4,    32,    32,  -130,  -130,    37,    40,    41,
      43,    44,    45,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,   -16,  -130,  -130,  -130,    46,    47,    48,    49,    50,
      52,  -130,  -130,    53,    30,    60,    61,  -130,    32,  -130,
      72,    91,    73,    74,    86,    88,    89,    92,  -130,    20,
      93,    94,    95,    96,    97,   110,    38,    32,     2,   112,
     109,    98,    32,    32,    32,    32,    32,    32,    32,    32,
      32,   111,    51,    70,   107,   113,   114,   126,  -130,   127,
     136,   138,   139,   141,   144,   115,   116,   117,   132,   133,
     134,   186,   187,  -130,   168,   -14,   148,  -130,  -130,  -130,
       0,   148,   148,   148,   148,   148,    13,    13,  -130,  -130,
       0,   188,   189,   191,   192,    17,   193,   194,   195,   196,
     198,    33,   199,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,     0,  -130,    38,   180,   181,   182,   183,   184,   185,
     190,   202,  -130,  -130,    19,   200,   201,   203,   204,   205,
     206,  -130,   207,   197,  -130,   100,  -130,     2,   208,   209,
     210,   213,   211,  -130,   215,     2,   219,   220,   223,   229,
     230,  -130,   212,   216,   214,   217,   218,   221,   233,   222,
     225,   224,   226,   227,   228,   232,     0,  -130,   236,     2,
     237,    19,   231,  -130,  -130,   241,     2,   244,    19,  -130,
     234,   235,   239,   238,  -130,   246,   240,   242,   243,  -130,
    -130,     2,  -130,     2,   245,     2,  -130,     2,   247,   248,
    -130,   249,   250,  -130,  -130,  -130,  -130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,    -8,  -130,    -5,   251,    58,    68,  -130,  -129,
    -130,  -130,     8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    29,   161,     1,    10,    15,    58,    44,   142,    59,
      13,   143,    11,    12,    22,     2,    45,     3,     4,    14,
       5,   150,    51,    15,    16,   173,     6,    17,    18,    19,
      20,    21,    22,    23,    24,    46,    47,   160,   151,   152,
     151,   152,    30,    95,    96,    97,    98,    99,   100,   101,
     102,    79,    80,    48,   151,   152,    70,    28,    52,    67,
     103,    53,    54,   107,    55,    56,    57,    60,    61,    62,
      63,    64,   214,    65,    66,   106,   121,    82,    83,   219,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    68,
      84,    69,    85,    86,    71,   122,    87,    89,    90,    91,
      92,    93,   144,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   145,    81,    94,   108,   182,    88,   133,   134,
     135,   110,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   109,   123,   163,   120,   136,   137,   138,   124,   125,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    33,
      34,   126,   127,    35,    36,    37,    38,    39,    40,    41,
      42,   128,   183,   129,   130,    43,   131,    15,    16,   132,
     190,    17,    18,    19,    20,    21,    22,    23,    24,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   210,   139,
     140,   141,   146,   147,   212,   148,   149,   155,   156,   157,
     158,   217,   159,   162,   165,   166,   172,   167,   168,   169,
     170,   164,   184,   185,   186,   171,   228,   187,   229,   189,
     231,   181,   232,   191,   192,   174,   175,   193,   176,   177,
     178,   179,   180,   194,   195,   196,   188,   202,   197,   198,
     211,   213,   199,   200,   203,   216,   201,   204,   218,   205,
     224,   206,   207,   208,   209,    26,   215,     0,   220,     0,
     221,   222,     0,   223,   226,   225,     0,   230,   227,   233,
     234,   235,   236
};

static const yytype_int16 yycheck[] =
{
       5,     9,   131,     3,    21,     3,    22,     3,    22,    25,
      21,    25,    29,    30,    12,    15,    12,    17,    18,    21,
      20,     4,    14,     3,     4,   154,    26,     7,     8,     9,
      10,    11,    12,    13,    14,     3,     4,     4,    21,    22,
      21,    22,    22,     5,     6,     7,     8,     9,    10,    11,
      12,    38,    39,    21,    21,    22,    48,     0,    21,    29,
      22,    21,    21,    68,    21,    21,    21,    21,    21,    21,
      21,    21,   201,    21,    21,    67,    25,     4,     4,   208,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    29,
       4,    30,     4,     4,    22,    25,     4,     4,     4,     4,
       4,     4,   110,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   120,    22,     4,     3,    16,    59,     3,     3,
       3,    23,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    22,    25,   141,    23,     3,     3,     3,    25,    25,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
       4,    25,    25,     7,     8,     9,    10,    11,    12,    13,
      14,    25,   167,    25,    25,    19,    25,     3,     4,    25,
     175,     7,     8,     9,    10,    11,    12,    13,    14,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   196,     3,
       3,    23,     4,     4,   199,     4,     4,     4,     4,     4,
       4,   206,     4,     4,    24,    24,     4,    25,    25,    25,
      25,   143,     4,     4,     4,    25,   221,     4,   223,     4,
     225,    24,   227,     4,     4,    25,    25,     4,    25,    25,
      25,    25,    25,     4,     4,    23,    25,     4,    22,    25,
       4,     4,    25,    25,    22,     4,    25,    22,     4,    25,
       4,    25,    25,    25,    22,     4,    25,    -1,    24,    -1,
      25,    22,    -1,    25,    22,    25,    -1,    22,    25,    22,
      22,    22,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    15,    17,    18,    20,    26,    41,    42,    43,
      21,    29,    30,    21,    21,     3,     4,     7,     8,     9,
      10,    11,    12,    13,    14,    44,    45,    44,     0,    42,
      22,    45,    46,     3,     4,     7,     8,     9,    10,    11,
      12,    13,    14,    19,     3,    12,     3,     4,    21,    51,
      52,    52,    21,    21,    21,    21,    21,    21,    22,    25,
      21,    21,    21,    21,    21,    21,    21,    29,    29,    30,
      52,    22,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    22,     4,     4,     4,     4,     4,     4,    46,     4,
       4,     4,     4,     4,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    22,    47,    48,    52,    44,     3,    22,
      23,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      23,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,     3,     3,     3,     3,     3,     3,     3,
       3,    23,    22,    25,    42,    42,     4,     4,     4,     4,
       4,    21,    22,    49,    50,     4,     4,     4,     4,     4,
       4,    49,     4,    42,    47,    24,    24,    25,    25,    25,
      25,    25,     4,    49,    25,    25,    25,    25,    25,    25,
      25,    24,    16,    44,     4,     4,     4,     4,    25,     4,
      44,     4,     4,     4,     4,     4,    23,    22,    25,    25,
      25,    25,     4,    22,    22,    25,    25,    25,    25,    22,
      42,     4,    44,     4,    49,    25,     4,    44,     4,    49,
      24,    25,    22,    25,     4,    25,    22,    25,    44,    44,
      22,    44,    44,    22,    22,    22,    22
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
#line 108 "pixel.y"
    { 
			(yyval.lsnode) = (yyvsp[(1) - (1)].lsnode); 
			root = (yyval.lsnode);
			printf("input\n. root is 0x%x \n", root);
		;}
    break;

  case 3:
#line 116 "pixel.y"
    {
			/* the normal lines */
			(yyvsp[(2) - (2)].lsnode)->cmdlines->push_front((yyvsp[(1) - (2)].lnode));
			(yyval.lsnode) = (yyvsp[(2) - (2)].lsnode);
			//printf("lines $1 is: 0x%x\n", $$);
		;}
    break;

  case 4:
#line 122 "pixel.y"
    {
			/* empty string mark the end */
			tmp_line = new std::list<line_node *>;
			(yyval.lsnode) = new lines_node(tmp_line);
			//printf("empty\n");
		;}
    break;

  case 5:
#line 131 "pixel.y"
    {
			/* do nothing */
			printf("newline\n"); 
		;}
    break;

  case 6:
#line 135 "pixel.y"
    { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 7:
#line 140 "pixel.y"
    {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 8:
#line 145 "pixel.y"
    {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", (yyvsp[(3) - (3)].num));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 9:
#line 150 "pixel.y"
    { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (char *)((yyvsp[(9) - (10)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (10)].str)), tmp_var);
		;}
    break;

  case 10:
#line 155 "pixel.y"
    { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), (char *)((yyvsp[(13) - (14)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 11:
#line 160 "pixel.y"
    { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (12)].str)), tmp_var);
		;}
    break;

  case 12:
#line 165 "pixel.y"
    {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), (char *)((yyvsp[(13) - (14)].astring))->c_str());
	 		(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 13:
#line 170 "pixel.y"
    { 
			/* color type define. eg. yellow = color(r, g, b) */
			tmp_var = new BaseType;
			tmp_var->type = "color";
			tmp_var->cname = GetName((yyvsp[(1) - (10)].str));
			tmp_var->SetColor((yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (yyvsp[(9) - (10)].num));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (10)].str)), tmp_var);
		;}
    break;

  case 14:
#line 178 "pixel.y"
    {
			/* tree type define. eg. a = tree(rootnum, (a, r, l)(r, r1, l1)...) */
			tmp_tree = new iTREE("tree", (yyvsp[(5) - (7)].num), TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (7)].str)), tmp_tree);
		;}
    break;

  case 15:
#line 184 "pixel.y"
    {
			/* tree type define version 2. define the position
			* eg. a = tree(rootnum, x, y, (a, r, l)(r, r1, l1)...) 
			*/
			tmp_tree = new iTREE("tree", (yyvsp[(5) - (11)].num), (yyvsp[(7) - (11)].num), (yyvsp[(9) - (11)].num));
			tmp_tree->nodes = *tmp_map;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (11)].str)), tmp_tree);
		;}
    break;

  case 16:
#line 192 "pixel.y"
    { 
			/* if-else expression define
			* eg. if (expr) {...} else {...}
			* must contain if and else!
			*/
			//printf("define a IF-ELSE statement, the value of expr\n");
			(yyval.lnode) = new if_else_node(yylineno, (yyvsp[(3) - (11)].expnode), (yyvsp[(6) - (11)].lsnode), (yyvsp[(10) - (11)].lsnode));
		;}
    break;

  case 17:
#line 200 "pixel.y"
    { 
			/* while loop define
			* eg. while (expr) {...}
			*/
			//printf("define a while statement, the value of expr\n");
			(yyval.lnode) = new while_node(yylineno, (yyvsp[(3) - (7)].expnode), (yyvsp[(6) - (7)].lsnode));
		;}
    break;

  case 18:
#line 207 "pixel.y"
    { 
			/* draw an object variable */
			(yyval.lnode) = new draw_node(yylineno, (char *)((yyvsp[(2) - (2)].astring))->c_str());
		;}
    break;

  case 19:
#line 211 "pixel.y"
    {
			/* variable copy assignment. eg. a = b */
			(yyval.lnode) = new equ_sts_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
		;}
    break;

  case 20:
#line 215 "pixel.y"
    {
			/* change the color assignment. eg. a.color = blue */
			(yyval.lnode) = new equ_cts_node(yylineno, GetName((yyvsp[(1) - (5)].str)), (char *)((yyvsp[(5) - (5)].astring))->c_str());
		;}
    break;

  case 21:
#line 219 "pixel.y"
    {
			/* change the fields of variable. eg. a.x = expr */
	 		(yyval.lnode) = new equ_stn_node(yylineno, GetName((yyvsp[(1) - (5)].str)), GetName((yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].expnode));
	 	;}
    break;

  case 22:
#line 223 "pixel.y"
    {
			/* define a function
			* eg. foo = func(int a, point b, ... ) {...}
			*/
			//printf("define a func!\n");
			(yyval.lnode) = new def_func(yylineno, GetName((yyvsp[(1) - (8)].str)), *((yyvsp[(5) - (8)].varpairVect)), (yyvsp[(7) - (8)].lsnode));

	 	;}
    break;

  case 23:
#line 231 "pixel.y"
    {
			/* call a function
			* eg. foo(a, b, c, ...)
			*/
			//printf("call a func\n");
			(yyval.lnode) = new call_node(yylineno, GetName((yyvsp[(1) - (3)].str)), *((yyvsp[(3) - (3)].parampairVect)));
	 	;}
    break;

  case 24:
#line 238 "pixel.y"
    {
			/* change the background color
			* eg. background color(r,g,b)
			* or background red
			*/
			(yyval.lnode) = new back_node(yylineno, (char *)((yyvsp[(2) - (2)].astring))->c_str());
		;}
    break;

  case 25:
#line 248 "pixel.y"
    {
			(yyval.astring) = new std::string(GetName((yyvsp[(1) - (1)].str)));
		;}
    break;

  case 26:
#line 251 "pixel.y"
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

  case 27:
#line 263 "pixel.y"
    {
			(yyval.astring) = (yyvsp[(1) - (1)].astring);
		;}
    break;

  case 28:
#line 266 "pixel.y"
    { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 29:
#line 274 "pixel.y"
    {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 30:
#line 282 "pixel.y"
    {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", (yyvsp[(1) - (1)].num));
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 31:
#line 290 "pixel.y"
    { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", (yyvsp[(3) - (8)].num), (yyvsp[(5) - (8)].num), (char *)((yyvsp[(7) - (8)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 32:
#line 298 "pixel.y"
    { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", (yyvsp[(3) - (12)].num), (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 33:
#line 306 "pixel.y"
    { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", (yyvsp[(3) - (10)].num), (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), (char *)((yyvsp[(9) - (10)].astring))->c_str());
			tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 34:
#line 314 "pixel.y"
    {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", (yyvsp[(3) - (12)].num), (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), (char *)((yyvsp[(11) - (12)].astring))->c_str());
	 		tmp_varname = new std::string(RandName());
			DeletMulDef(*tmp_varname);
			vars.insert(std::pair<std::string, BaseType *>(*tmp_varname, tmp_var));
			(yyval.astring) = tmp_varname;
		;}
    break;

  case 35:
#line 322 "pixel.y"
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

  case 36:
#line 331 "pixel.y"
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

  case 37:
#line 346 "pixel.y"
    {
			(yyval.parampairVect) = (yyvsp[(3) - (3)].parampairVect);
			(yyval.parampairVect)->push_back(*((yyvsp[(1) - (3)].astring)));
		;}
    break;

  case 38:
#line 350 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			(yyval.parampairVect)->push_back(*((yyvsp[(1) - (2)].astring)));
			//printf("a new paramlist!\n");
		;}
    break;

  case 39:
#line 355 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			//printf("empty paramlist!\n");
		;}
    break;

  case 40:
#line 363 "pixel.y"
    {
			(yyval.varpairVect) = (yyvsp[(3) - (3)].varpairVect);
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (3)].varPair)));
		;}
    break;

  case 41:
#line 367 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (2)].varPair)));
			printf("a new varlist!\n");
		;}
    break;

  case 42:
#line 372 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			printf("empty varlist!\n");
		;}
    break;

  case 43:
#line 379 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "int";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 44:
#line 384 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "bool";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 45:
#line 389 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "point";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 46:
#line 394 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "circle";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 47:
#line 399 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "rect";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 48:
#line 404 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "line";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 49:
#line 409 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "color";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 50:
#line 414 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "tree";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 51:
#line 424 "pixel.y"
    {
				(yyvsp[(2) - (2)].binvect)->insert(*(yyvsp[(1) - (2)].childpair));
				(yyval.binvect) = (yyvsp[(2) - (2)].binvect);
				//printf("the map is %d, %d\n", (*$2)[$1->first].first, (*$2)[$1->first].second);
			;}
    break;

  case 52:
#line 429 "pixel.y"
    {
				//printf("empty bintree\n");
				tmp_map = new std::map<int, std::pair<int, int> > ;	/* empty string*/
				(yyval.binvect) = tmp_map;
			;}
    break;

  case 53:
#line 439 "pixel.y"
    {
				(yyval.childpair) = new std::pair<int, std::pair<int, int> >;
				(yyval.childpair)->first = (yyvsp[(2) - (7)].num);
				(yyval.childpair)->second = std::make_pair((yyvsp[(4) - (7)].num), (yyvsp[(6) - (7)].num));
				//printf("node is: (%d, %d, %d)\n", $2, $4, $6);
			;}
    break;

  case 54:
#line 450 "pixel.y"
    {
				(yyval.expnode) = new field_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
			;}
    break;

  case 55:
#line 453 "pixel.y"
    {
 				(yyval.expnode) = new number_node(yylineno, (yyvsp[(1) - (1)].num));
 			;}
    break;

  case 56:
#line 456 "pixel.y"
    {
 				(yyval.expnode) = new int_node(yylineno, GetName((yyvsp[(1) - (1)].str)));
 			;}
    break;

  case 57:
#line 464 "pixel.y"
    {
 				(yyval.expnode) = new plus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 58:
#line 467 "pixel.y"
    {
 				(yyval.expnode) = new minus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 59:
#line 470 "pixel.y"
    {
 				(yyval.expnode) = new times_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 60:
#line 473 "pixel.y"
    {
 				(yyval.expnode) = new divide_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 61:
#line 476 "pixel.y"
    {
 				(yyval.expnode) = new gt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 62:
#line 479 "pixel.y"
    {
 				(yyval.expnode) = new ge_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 63:
#line 482 "pixel.y"
    {
 				(yyval.expnode) = new lt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 64:
#line 485 "pixel.y"
    {
 				(yyval.expnode) = new le_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 65:
#line 488 "pixel.y"
    {
 				(yyval.expnode) = new ee_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 66:
#line 491 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(2) - (3)].expnode);
 			;}
    break;

  case 67:
#line 494 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(1) - (1)].expnode);
 			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2228 "pixel.cpp"
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


#line 499 "pixel.y"


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
	sprintf(tmp, "[ERROR] line %d: %s\n", yylineno-1, msg);
	errors += tmp;
	free(tmp);
	//fprintf(stderr, "Error at line %d, %s\n", yylineno, msg);
}









