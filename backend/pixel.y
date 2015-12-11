/* 
 * Project: pixel.y
 * Author: Li Qian and Guo ZiHan
 * Data: 2015-12-10
 * Description:
 * This is our team's parser for Pixel Language
 * Written by Li Qian and Guo ZiHan
 * Part of the backend server
 * 2015 Fall Semester -- Compiling Practice
 */

%{
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

	static	char* GetName(char *nname);		  /* get the variable name */

	void yyerror (/*void *a, */const char *msg);
%}


/* 
* union is the return type
* Must be 32-bit type, thus our Interpreter should be compiled
* under 32-bit mode
*/
%union {
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
};

/* 
* Here is the collection of all the tokens
*/
/* the terminate token */
%token <str> allname	/* all the variable names */
%token <num> number 	/* the numbers */
%token <bstp> INT BOOL POINT LINE circle rect tree color /* these are BaseTypes */
%token TRUE FALSE		/* bool values */
%token IF ELSE WHILE 	/* for branch*/
%token draw func 	/* for the functions */
%token leftsma rightsma leftbig rightbig comma newline /* useful things... */
%token OR AND EQU DOT	/* some operations */

/* right and left control the priority */
%right GT GE LT LE EE /* > >= < <= == the relation operations */
%left PLUS MINUS 	  /* + - */
%left TIMES DIVIDE 	  /* * / */

/* the non-terminate token */
%type <lnode> line 				/* one single line */
%type <lsnode> lines input		/* collection of lines */
%type <childpair> treenode		/* one binary tree node */
%type <binvect> bintree 		/* represent the binary tree */
%type <expnode>  supernum expr 	/* expressions */
%type <varpairVect> varlist 	/* func define variable list */
%type <varPair> singlevar 		/* one single variable*/
%type <parampairVect> paramlist /* function call parameters */

/* start point is the "input" */
%start input

%%

/* input - the start point, and collect all the program codes */
input : lines { 
			$$ = $1; 
			root = $$;
			printf("input\n. root is 0x%x \n", root);
		}
	;
 
/* lines - transfer code into trees vector and skip the comment */
lines : line lines {
			/* the normal lines */
			$2->cmdlines->push_front($1);
			$$ = $2;
			//printf("lines $1 is: 0x%x\n", $$);
		}
	| {
			/* empty string mark the end */
			tmp_line = new std::list<line_node *>;
			$$ = new lines_node(tmp_line);
			//printf("empty\n");
		}
	;

/* line - each line of code */
line : newline {
			/* do nothing */
			printf("newline\n"); 
		}
	| allname EQU TRUE { 
			/* Bool type define, and value is TRUE. eg. a = true */
			tmp_var = new iBOOL("bool", 1);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU FALSE {
			/* Bool type define, and value is FALSE. eg. a = false */
			tmp_var = new iBOOL("bool", 0);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU number {
			/* int type define. eg. a = number */
			tmp_var = new iINT("int", $3);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU POINT leftsma number comma number comma allname rightsma { 
			/* point type define. eg. a = point(x, y, color_name) */
			tmp_var = new iPOINT("point", $5, $7, GetName($9));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU LINE leftsma number comma number comma number comma number comma allname rightsma { 
			/* line type define. eg. a = line(x, y, x1, y1, color_name) */
			tmp_var = new iLINE("line", $5, $7, $9, $11, GetName($13));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU circle leftsma number comma number comma number comma allname rightsma { 
			/* circle type define. eg. a = circle(x, y, r, color_name) */
			tmp_var = new iCIRCLE("circle", $5, $7, $9, GetName($11));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU rect leftsma number comma number comma number comma number comma allname rightsma {
	 		/* rectangle type define. eg. a = rect(x, y, w, h, color_name) */
	 		tmp_var = new iRECT("rect", $5, $7, $9, $11, GetName($13));
	 		$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU color leftsma number comma number comma number rightsma { 
			/* color type define. eg. yellow = color(r, g, b) */
			tmp_var = new BaseType;
			tmp_var->type = "color";
			tmp_var->cname = GetName($1);
			tmp_var->SetColor($5, $7, $9);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU tree leftsma number comma bintree /*rightsma in bintree*/ {
			/* tree type define. eg. a = tree(rootnum, (a, r, l)(r, r1, l1)...) */
			tmp_tree = new iTREE("tree", $5, TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			$$ = new def_node(GetName($1), tmp_tree);
		}
	| allname EQU tree leftsma number comma number comma number comma bintree {
			/* tree type define version 2. define the position
			* eg. a = tree(rootnum, x, y, (a, r, l)(r, r1, l1)...) 
			*/
			tmp_tree = new iTREE("tree", $5, $7, $9);
			tmp_tree->nodes = *tmp_map;
			$$ = new def_node(GetName($1), tmp_tree);
		}
	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { 
			/* if-else expression define
			* eg. if (expr) {...} else {...}
			* must contain if and else!
			*/
			//printf("define a IF-ELSE statement, the value of expr\n");
			$$ = new if_else_node($3, $6, $10);
		}
	| WHILE leftsma expr rightsma leftbig lines rightbig { 
			/* while loop define
			* eg. while (expr) {...}
			*/
			//printf("define a while statement, the value of expr\n");
			$$ = new while_node($3, $6);
		}
	| draw allname { 
			/* draw an object variable */
			$$ = new draw_node(GetName($2));
		}
	| allname EQU allname {
			/* variable copy assignment. eg. a = b */
			$$ = new equ_sts_node(GetName($1), GetName($3));
		}
	| allname DOT color EQU allname {
			/* change the color assignment. eg. a.color = blue */
			$$ = new equ_cts_node(GetName($1), GetName($5));
		}
	| allname DOT allname EQU expr {
			/* change the fields of variable. eg. a.x = expr */
	 		$$ = new equ_stn_node(GetName($1), GetName($3), $5);
	 	}
	| allname EQU func leftsma varlist leftbig lines rightbig {
			/* define a function
			* eg. foo = func(int a, point b, ... ) {...}
			*/
			//printf("define a func!\n");
			$$ = new def_func(GetName($1), *($5), $7);

	 	}
	| allname leftsma paramlist {
			/* call a function
			* eg. foo(a, b, c, ...)
			*/
			//printf("call a func\n");
			$$ = new call_node(GetName($1), *($3));
	 	}
	;

/* paramlist - a function call's parameters */
paramlist : allname comma paramlist {
			$$ = $3;
			$$->push_back(GetName($1));
		}
	| allname rightsma {
			$$ = new std::vector<std::string>;
			$$->push_back(GetName($1));
			//printf("a new paramlist!\n");
		}
	| rightsma {
			$$ = new std::vector<std::string>;
			//printf("empty paramlist!\n");
		}
	;


/* varlist - when define a function, it's variable list */
varlist : singlevar comma varlist {
			$$ = $3;
			$$->push_back(*($1));
		}
	| singlevar rightsma {
			$$ = new std::vector<std::pair<std::string, std::string> >;
			$$->push_back(*($1));
			printf("a new varlist!\n");
		}
	| rightsma {
			$$ = new std::vector<std::pair<std::string, std::string> >;
			printf("empty varlist!\n");
		}
	;

/* singlevar - represent a single variable */
singlevar : INT allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "int";
			$$->second = GetName($2);
		}
	| BOOL allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "bool";
			$$->second = GetName($2);
		}
	| POINT allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "point";
			$$->second = GetName($2);
		}
	| circle allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "circle";
			$$->second = GetName($2);
		}
	| rect allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "rect";
			$$->second = GetName($2);
		}
	| LINE allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "line";
			$$->second = GetName($2);
		}
	| color allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "color";
			$$->second = GetName($2);
		}
	| tree allname {
			$$ = new std::pair<std::string, std::string>;
			$$->first = "tree";
			$$->second = GetName($2);
		}
	;

/* bintree - input a sequence and transform to a tree 
* eg. (1, 2, 3)(2, 4, 5)... could represent a tree and no order
*/
bintree	: treenode bintree {
				$2->insert(*$1);
				$$ = $2;
				//printf("the map is %d, %d\n", (*$2)[$1->first].first, (*$2)[$1->first].second);
			}
		| rightsma /*empty*/{
				//printf("empty bintree\n");
				tmp_map = new std::map<int, std::pair<int, int> > ;	/* empty string*/
				$$ = tmp_map;
			}
		;

/* treenode - one single node for tree 
* eg (1, 2, 3) means node 1 has left child 2 and right child 3
*/
treenode : leftsma number comma number comma number rightsma {
				$$ = new std::pair<int, std::pair<int, int> >;
				$$->first = $2;
				$$->second = std::make_pair($4, $6);
				//printf("node is: (%d, %d, %d)\n", $2, $4, $6);
			}
		;

/* supernum - collection of int type 
* eg. a.x , 100 , dd(dd must be an int/bool type)
*/
supernum : allname DOT allname {
				$$ = new field_node(GetName($1), GetName($3));
			} 
 		| number {
 				$$ = new number_node($1);
 			} 
 		| allname {
 				$$ = new int_node(GetName($1));
 			}
 		;

/* expr - the expression define 
* now we support + - * / > >= < <= == operatiions
*/
expr : expr PLUS expr {
 				$$ = new plus_node($1, $3);
 			}
 		| expr MINUS expr {
 				$$ = new minus_node($1, $3);
 			}
 		| expr TIMES expr {
 				$$ = new times_node($1, $3);
 			}
 		| expr DIVIDE expr {
 				$$ = new divide_node($1, $3);
 			}
 		| expr GT expr {
 				$$ = new gt_node($1, $3);
 			}
 		| expr GE expr {
 				$$ = new ge_node($1, $3);
 			}
 		| expr LT expr {
 				$$ = new lt_node($1, $3);
 			}
 		| expr LE expr {
 				$$ = new le_node($1, $3);
 			}
 		| expr EE expr {
 				$$ = new ee_node($1, $3);
 			}
 		| leftsma expr rightsma {
 				$$ = $2;
 			}
 		| supernum {
 				$$ = $1;
 			}
 		;

%%

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
	fprintf(stderr, "Error at line %d, %s\n", yylineno, msg);
}

int main()
{ 
	//yy_switch_to_buffer(yy_scan_string((char *)YYPARSE_PARAM));
	// char buffer[100];
	// while(1) {
	// 	yyparse(buffer); 
	// 	root->evaluate();		 
	// }

	//return 0;
}






