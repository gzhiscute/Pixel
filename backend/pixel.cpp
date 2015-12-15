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
//#define func 274
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




/* Copy the first part of user declarations.  */
#line 12 "pixel.y"

	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include <vector>
	#include "utils.h"  /*Header file for AST*/
	#include "lex.yy.c" /* yylex file*/
	
	/* use YYPARSE_PARAM to receive parameter in yyparse*/
	#define YYPARSE_PARAM parm

	/* the root of the abstract syntax tree */	
	lines_node *root;

	static	std::list<line_node *> *tmp_line; /*store the temporary line*/	
	static	BaseType *tmp_var;				  /*store the temporary variable*/
	static	iTREE *tmp_tree;				  /*store the temporary tree*/
	static	std::map<int, std::pair<int, int> > *tmp_map;
	static	std::pair<int, std::pair<int, int> > *tmp_pair;

	extern	std::map<std::string, BaseType *> vars;	 /* save all the variables */
	extern int yylineno;
	extern std::string errors;

	static	char* GetName(char *nname);		  /* get the variable name */

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
#line 49 "pixel.y"
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
/* Line 193 of yacc.c.  */
#line 217 "pixel.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "pixel.cpp"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    19,    23,
      34,    49,    62,    77,    88,    96,   108,   120,   128,   131,
     135,   141,   147,   156,   160,   164,   167,   169,   173,   176,
     178,   181,   184,   187,   190,   193,   196,   199,   202,   205,
     207,   215,   219,   221,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    42,    41,    -1,    -1,    25,
      -1,     3,    28,    13,    -1,     3,    28,    14,    -1,     3,
      28,     4,    -1,     3,    28,     7,    20,     4,    24,     4,
      24,     3,    21,    -1,     3,    28,     8,    20,     4,    24,
       4,    24,     4,    24,     4,    24,     3,    21,    -1,     3,
      28,     9,    20,     4,    24,     4,    24,     4,    24,     3,
      21,    -1,     3,    28,    10,    20,     4,    24,     4,    24,
       4,    24,     4,    24,     3,    21,    -1,     3,    28,    12,
      20,     4,    24,     4,    24,     4,    21,    -1,     3,    28,
      11,    20,     4,    24,    46,    -1,     3,    28,    11,    20,
       4,    24,     4,    24,     4,    24,    46,    -1,    15,    20,
      49,    21,    22,    41,    23,    16,    22,    41,    23,    -1,
      17,    20,    49,    21,    22,    41,    23,    -1,    18,     3,
      -1,     3,    28,     3,    -1,     3,    29,    12,    28,     3,
      -1,     3,    29,     3,    28,    49,    -1,     3,    28,    19,
      20,    44,    22,    41,    23,    -1,     3,    20,    43,    -1,
       3,    24,    43,    -1,     3,    21,    -1,    21,    -1,    45,
      24,    44,    -1,    45,    21,    -1,    21,    -1,     5,     3,
      -1,     6,     3,    -1,     7,     3,    -1,     9,     3,    -1,
      10,     3,    -1,     8,     3,    -1,    12,     3,    -1,    11,
       3,    -1,    47,    46,    -1,    21,    -1,    20,     4,    24,
       4,    24,     4,    21,    -1,     3,    29,     3,    -1,     4,
      -1,     3,    -1,    49,    36,    49,    -1,    49,    35,    49,
      -1,    49,    38,    49,    -1,    49,    37,    49,    -1,    49,
      34,    49,    -1,    49,    33,    49,    -1,    49,    32,    49,
      -1,    49,    31,    49,    -1,    49,    30,    49,    -1,    20,
      49,    21,    -1,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   105,   111,   120,   124,   129,   134,   139,
     144,   149,   154,   159,   167,   173,   181,   189,   196,   200,
     204,   208,   212,   220,   230,   234,   239,   247,   251,   256,
     263,   268,   273,   278,   283,   288,   293,   298,   308,   313,
     323,   334,   337,   340,   348,   351,   354,   357,   360,   363,
     366,   369,   372,   375,   378
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "allname", "number", "INT", "BOOL",
  "POINT", "LINE", "circle", "rect", "tree", "color", "TRUE", "FALSE",
  "IF", "ELSE", "WHILE", "draw", "func", "leftsma", "rightsma", "leftbig",
  "rightbig", "comma", "newline", "OR", "AND", "EQU", "DOT", "EE", "LE",
  "LT", "GE", "GT", "MINUS", "PLUS", "DIVIDE", "TIMES", "$accept", "input",
  "lines", "line", "paramlist", "varlist", "singlevar", "bintree",
  "treenode", "supernum", "expr", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     3,     3,    10,
      14,    12,    14,    10,     7,    11,    11,     7,     2,     3,
       5,     5,     8,     3,     3,     2,     1,     3,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       7,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     5,     0,     2,     4,     0,
       0,     0,     0,     0,    18,     1,     3,     0,    26,    23,
      19,     8,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,     0,    43,    42,     0,    54,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    21,    20,    41,    53,     4,    52,    51,    50,    49,
      48,    45,    44,    47,    46,     4,     0,     0,     0,     0,
       0,     0,    30,    31,    32,    35,    33,    34,    37,    36,
       4,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    14,     0,     0,     0,    27,     0,    17,     0,
       0,     0,     0,     0,     0,    38,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     9,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    15,     0,
      16,     0,    11,     0,     0,     0,     0,    40,    10,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    19,    79,    80,   122,   123,    36,
      37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -122
static const yytype_int16 yypact[] =
{
       0,   -15,   -14,   -11,     9,  -122,    21,  -122,     0,     1,
     109,     8,     4,     4,  -122,  -122,  -122,    -5,  -122,  -122,
    -122,  -122,    12,    15,    19,    20,    31,    32,  -122,  -122,
      33,    26,    27,    28,  -122,     4,  -122,    29,    48,  -122,
       1,    25,    52,    54,    64,    66,    67,   124,     4,    69,
      70,    73,    53,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    68,  -122,    50,    65,    71,    72,    74,    75,
      85,    88,    89,    90,    94,    97,    98,   111,  -122,    93,
       7,   116,  -122,  -122,  -122,     0,   116,   116,   116,   116,
     116,    -4,    -4,  -122,  -122,     0,   120,   121,   122,   123,
       6,   133,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
       0,  -122,   124,   117,   118,   115,   119,   131,   132,   134,
     138,  -122,  -122,    17,   135,   137,  -122,    60,  -122,   141,
     153,   157,   158,   159,   140,  -122,   161,  -122,   144,   146,
     145,   147,   148,   149,   164,   154,     0,  -122,   166,   171,
     172,    17,   155,  -122,   160,   156,   163,   162,  -122,   173,
    -122,   175,  -122,   178,   167,   168,   169,  -122,  -122,  -122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,    -8,  -122,   142,    79,  -122,  -121,  -122,  -122,
     -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      16,    38,   135,     1,    17,     9,    12,    33,    34,    13,
     119,    31,    14,    10,    11,     2,    39,     3,     4,    40,
      32,    15,    18,    51,    35,     5,   120,   121,   111,    64,
     158,   112,    41,    60,    61,    42,    81,   120,   121,    43,
      44,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      52,    45,    46,    47,    48,    49,    65,    50,    66,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    67,    62,
      68,    69,    82,    83,    96,    85,   138,   113,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   114,   102,    97,
      95,   103,   104,   105,    84,    98,    99,   106,   100,   101,
     107,   108,   125,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    20,    21,   109,   110,    22,    23,    24,    25,
      26,    27,    28,    29,   115,   116,   117,   118,    30,    70,
      71,    72,    73,    74,    75,    76,    77,   124,   154,   129,
     127,   128,   134,   130,   139,    78,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   131,   132,   140,   133,   136,
     137,   141,   142,   143,   144,   145,   146,   147,   152,   148,
     155,   149,   150,   151,   156,   153,   157,   164,   165,   159,
     161,   166,    63,   160,   162,     0,   163,     0,   167,   168,
     169,   126
};

static const yytype_int16 yycheck[] =
{
       8,    13,   123,     3,     3,    20,    20,     3,     4,    20,
       4,     3,     3,    28,    29,    15,    21,    17,    18,    24,
      12,     0,    21,    35,    20,    25,    20,    21,    21,     4,
     151,    24,    20,    37,    38,    20,    48,    20,    21,    20,
      20,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      21,    20,    20,    20,    28,    28,     4,    29,     4,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     4,    21,
       4,     4,     3,     3,    24,    22,    16,    85,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    95,     3,    24,
      22,     3,     3,     3,    21,    24,    24,     3,    24,    24,
       3,     3,   110,    30,    31,    32,    33,    34,    35,    36,
      37,    38,     3,     4,     3,    22,     7,     8,     9,    10,
      11,    12,    13,    14,     4,     4,     4,     4,    19,     5,
       6,     7,     8,     9,    10,    11,    12,     4,   146,    24,
      23,    23,     4,    24,     3,    21,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    24,    24,     4,    24,    24,
      23,     4,     4,     4,    24,     4,    22,    21,     4,    24,
       4,    24,    24,    24,     3,    21,     4,     4,     3,    24,
      24,     3,    40,    23,    21,    -1,    24,    -1,    21,    21,
      21,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    15,    17,    18,    25,    40,    41,    42,    20,
      28,    29,    20,    20,     3,     0,    41,     3,    21,    43,
       3,     4,     7,     8,     9,    10,    11,    12,    13,    14,
      19,     3,    12,     3,     4,    20,    48,    49,    49,    21,
      24,    20,    20,    20,    20,    20,    20,    20,    28,    28,
      29,    49,    21,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    21,    43,     4,     4,     4,     4,     4,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    21,    44,
      45,    49,     3,     3,    21,    22,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    22,    24,    24,    24,    24,
      24,    24,     3,     3,     3,     3,     3,     3,     3,     3,
      22,    21,    24,    41,    41,     4,     4,     4,     4,     4,
      20,    21,    46,    47,     4,    41,    44,    23,    23,    24,
      24,    24,    24,    24,     4,    46,    24,    23,    16,     3,
       4,     4,     4,     4,    24,     4,    22,    21,    24,    24,
      24,    24,     4,    21,    41,     4,     3,     4,    46,    24,
      23,    24,    21,    24,     4,     3,     3,    21,    21,    21
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
#line 97 "pixel.y"
    { 
			(yyval.lsnode) = (yyvsp[(1) - (1)].lsnode); 
			root = (yyval.lsnode);
			printf("input\n. root is 0x%x \n", root);
		;}
    break;

  case 3:
#line 105 "pixel.y"
    {
			/* the normal lines */
			(yyvsp[(2) - (2)].lsnode)->cmdlines->push_front((yyvsp[(1) - (2)].lnode));
			(yyval.lsnode) = (yyvsp[(2) - (2)].lsnode);
			//printf("lines $1 is: 0x%x\n", $$);
		;}
    break;

  case 4:
#line 111 "pixel.y"
    {
			/* empty string mark the end */
			tmp_line = new std::list<line_node *>;
			(yyval.lsnode) = new lines_node(tmp_line);
			//printf("empty\n");
		;}
    break;

  case 5:
#line 120 "pixel.y"
    {
			/* do nothing */
			printf("newline\n"); 
		;}
    break;

  case 6:
#line 124 "pixel.y"
    { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 7:
#line 129 "pixel.y"
    {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 8:
#line 134 "pixel.y"
    {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", (yyvsp[(3) - (3)].num));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (3)].str)), tmp_var);
		;}
    break;

  case 9:
#line 139 "pixel.y"
    { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].num), GetName((yyvsp[(9) - (10)].str)));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (10)].str)), tmp_var);
		;}
    break;

  case 10:
#line 144 "pixel.y"
    { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), GetName((yyvsp[(13) - (14)].str)));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 11:
#line 149 "pixel.y"
    { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", (yyvsp[(5) - (12)].num), (yyvsp[(7) - (12)].num), (yyvsp[(9) - (12)].num), GetName((yyvsp[(11) - (12)].str)));
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (12)].str)), tmp_var);
		;}
    break;

  case 12:
#line 154 "pixel.y"
    {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", (yyvsp[(5) - (14)].num), (yyvsp[(7) - (14)].num), (yyvsp[(9) - (14)].num), (yyvsp[(11) - (14)].num), GetName((yyvsp[(13) - (14)].str)));
	 		(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (14)].str)), tmp_var);
		;}
    break;

  case 13:
#line 159 "pixel.y"
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
#line 167 "pixel.y"
    {
			/* tree type define. eg. a = tree(rootnum, (a, r, l)(r, r1, l1)...) */
			tmp_tree = new iTREE("tree", (yyvsp[(5) - (7)].num), TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			(yyval.lnode) = new def_node(yylineno, GetName((yyvsp[(1) - (7)].str)), tmp_tree);
		;}
    break;

  case 15:
#line 173 "pixel.y"
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
#line 181 "pixel.y"
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
#line 189 "pixel.y"
    { 
			/* while loop define
			* eg. while (expr) {...}
			*/
			//printf("define a while statement, the value of expr\n");
			(yyval.lnode) = new while_node(yylineno, (yyvsp[(3) - (7)].expnode), (yyvsp[(6) - (7)].lsnode));
		;}
    break;

  case 18:
#line 196 "pixel.y"
    { 
			/* draw an object variable */
			(yyval.lnode) = new draw_node(yylineno, GetName((yyvsp[(2) - (2)].str)));
		;}
    break;

  case 19:
#line 200 "pixel.y"
    {
			/* variable copy assignment. eg. a = b */
			(yyval.lnode) = new equ_sts_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
		;}
    break;

  case 20:
#line 204 "pixel.y"
    {
			/* change the color assignment. eg. a.color = blue */
			(yyval.lnode) = new equ_cts_node(yylineno, GetName((yyvsp[(1) - (5)].str)), GetName((yyvsp[(5) - (5)].str)));
		;}
    break;

  case 21:
#line 208 "pixel.y"
    {
			/* change the fields of variable. eg. a.x = expr */
	 		(yyval.lnode) = new equ_stn_node(yylineno, GetName((yyvsp[(1) - (5)].str)), GetName((yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].expnode));
	 	;}
    break;

  case 22:
#line 212 "pixel.y"
    {
			/* define a function
			* eg. foo = func(int a, point b, ... ) {...}
			*/
			//printf("define a func!\n");
			(yyval.lnode) = new def_func(yylineno, GetName((yyvsp[(1) - (8)].str)), *((yyvsp[(5) - (8)].varpairVect)), (yyvsp[(7) - (8)].lsnode));

	 	;}
    break;

  case 23:
#line 220 "pixel.y"
    {
			/* call a function
			* eg. foo(a, b, c, ...)
			*/
			//printf("call a func\n");
			(yyval.lnode) = new call_node(yylineno, GetName((yyvsp[(1) - (3)].str)), *((yyvsp[(3) - (3)].parampairVect)));
	 	;}
    break;

  case 24:
#line 230 "pixel.y"
    {
			(yyval.parampairVect) = (yyvsp[(3) - (3)].parampairVect);
			(yyval.parampairVect)->push_back(GetName((yyvsp[(1) - (3)].str)));
		;}
    break;

  case 25:
#line 234 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			(yyval.parampairVect)->push_back(GetName((yyvsp[(1) - (2)].str)));
			//printf("a new paramlist!\n");
		;}
    break;

  case 26:
#line 239 "pixel.y"
    {
			(yyval.parampairVect) = new std::vector<std::string>;
			//printf("empty paramlist!\n");
		;}
    break;

  case 27:
#line 247 "pixel.y"
    {
			(yyval.varpairVect) = (yyvsp[(3) - (3)].varpairVect);
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (3)].varPair)));
		;}
    break;

  case 28:
#line 251 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			(yyval.varpairVect)->push_back(*((yyvsp[(1) - (2)].varPair)));
			printf("a new varlist!\n");
		;}
    break;

  case 29:
#line 256 "pixel.y"
    {
			(yyval.varpairVect) = new std::vector<std::pair<std::string, std::string> >;
			printf("empty varlist!\n");
		;}
    break;

  case 30:
#line 263 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "int";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 31:
#line 268 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "bool";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 32:
#line 273 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "point";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 33:
#line 278 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "circle";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 34:
#line 283 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "rect";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 35:
#line 288 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "line";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 36:
#line 293 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "color";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 37:
#line 298 "pixel.y"
    {
			(yyval.varPair) = new std::pair<std::string, std::string>;
			(yyval.varPair)->first = "tree";
			(yyval.varPair)->second = GetName((yyvsp[(2) - (2)].str));
		;}
    break;

  case 38:
#line 308 "pixel.y"
    {
				(yyvsp[(2) - (2)].binvect)->insert(*(yyvsp[(1) - (2)].childpair));
				(yyval.binvect) = (yyvsp[(2) - (2)].binvect);
				//printf("the map is %d, %d\n", (*$2)[$1->first].first, (*$2)[$1->first].second);
			;}
    break;

  case 39:
#line 313 "pixel.y"
    {
				//printf("empty bintree\n");
				tmp_map = new std::map<int, std::pair<int, int> > ;	/* empty string*/
				(yyval.binvect) = tmp_map;
			;}
    break;

  case 40:
#line 323 "pixel.y"
    {
				(yyval.childpair) = new std::pair<int, std::pair<int, int> >;
				(yyval.childpair)->first = (yyvsp[(2) - (7)].num);
				(yyval.childpair)->second = std::make_pair((yyvsp[(4) - (7)].num), (yyvsp[(6) - (7)].num));
				//printf("node is: (%d, %d, %d)\n", $2, $4, $6);
			;}
    break;

  case 41:
#line 334 "pixel.y"
    {
				(yyval.expnode) = new field_node(yylineno, GetName((yyvsp[(1) - (3)].str)), GetName((yyvsp[(3) - (3)].str)));
			;}
    break;

  case 42:
#line 337 "pixel.y"
    {
 				(yyval.expnode) = new number_node(yylineno, (yyvsp[(1) - (1)].num));
 			;}
    break;

  case 43:
#line 340 "pixel.y"
    {
 				(yyval.expnode) = new int_node(yylineno, GetName((yyvsp[(1) - (1)].str)));
 			;}
    break;

  case 44:
#line 348 "pixel.y"
    {
 				(yyval.expnode) = new plus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 45:
#line 351 "pixel.y"
    {
 				(yyval.expnode) = new minus_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 46:
#line 354 "pixel.y"
    {
 				(yyval.expnode) = new times_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 47:
#line 357 "pixel.y"
    {
 				(yyval.expnode) = new divide_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 48:
#line 360 "pixel.y"
    {
 				(yyval.expnode) = new gt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 49:
#line 363 "pixel.y"
    {
 				(yyval.expnode) = new ge_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 50:
#line 366 "pixel.y"
    {
 				(yyval.expnode) = new lt_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 51:
#line 369 "pixel.y"
    {
 				(yyval.expnode) = new le_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 52:
#line 372 "pixel.y"
    {
 				(yyval.expnode) = new ee_node(yylineno, (yyvsp[(1) - (3)].expnode), (yyvsp[(3) - (3)].expnode));
 			;}
    break;

  case 53:
#line 375 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(2) - (3)].expnode);
 			;}
    break;

  case 54:
#line 378 "pixel.y"
    {
 				(yyval.expnode) = (yyvsp[(1) - (1)].expnode);
 			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2015 "pixel.cpp"
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


#line 383 "pixel.y"


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

void yyerror(/*void *a, */const char *msg)
{
	char *tmp;
	tmp = (char*)calloc(256, sizeof(char));
	sprintf(tmp, "[ERROR] line %d: %s\n", yylineno-1, msg);
	errors += tmp;
	free(tmp);
	//fprintf(stderr, "Error at line %d, %s\n", yylineno, msg);
}







