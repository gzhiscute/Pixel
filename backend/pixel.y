/* pixel.y this is our teams' parser*/
%{
	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include <vector>
	#include "utils.h"
	#include "lex.yy.c" /* yylex file*/
	/*Header file for AST*/

	#define YYPARSE_PARAM parm

	lines_node *root;	/* the root of the abstract syntax tree*/
	static	std::list<line_node *> *tmp_line; /*store the temporary line*/	
	static	BaseType *tmp_var;	/*store the temporary variable*/
	static	iTREE *tmp_tree;
	static	std::map<int, std::pair<int, int> > *tmp_map;
	static	std::pair<int, std::pair<int, int> > *tmp_pair;
	static	char* GetName(char *nname);
	extern	std::map<std::string, BaseType *> vars;
	void yyerror (/*void *a, */const char *msg);
%}


/* union is the return type */
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

 //%parse-param {void *Buff} 

%token <str> allname
%token <num> number
%token <bstp> INT BOOL POINT LINE circle rect tree
%token color text IF ELSE WHILE CONTINUE BREAK newline
%token draw backgroud func TRUE FALSE call EQU DOT
%right GT GE LT LE EE/*> >= < <= ==*/
%left PLUS MINUS
%left TIMES DIVIDE
%token leftsma rightsma leftbig rightbig OR AND comma
%type <lnode> line 
%type <lsnode> lines input
%type <childpair> treenode
%type <binvect> bintree
%type <expnode>  supernum expr
%type <varpairVect> varlist
%type <varPair> singlevar
%type <parampairVect> paramlist

%start input

%%

input	: lines { 
				$$ = $1; 
				root = $$;
				printf("input\n. root is 0x%x", root);
			}
	;
 
lines : line lines {
			$2->cmdlines->push_front($1);
			$$ = $2;
			printf("lines $1 is: 0x%x\n", $$);
		}
	| {
			tmp_line = new std::list<line_node *>;	/* empty string*/
			$$ = new lines_node(tmp_line);
			printf("empty\n");
		}
	;

line	: newline {printf("newline\n"); }
	| allname EQU TRUE { 
				tmp_var = new iBOOL("bool", 1);
				$$ = new def_node(GetName($1), tmp_var);
			}
	| allname EQU FALSE { 
			tmp_var = new iBOOL("bool", 0);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU number {
			tmp_var = new iINT("int", $3);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU POINT leftsma number comma number comma allname rightsma { 
			tmp_var = new iPOINT("point", $5, $7, GetName($9));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU LINE leftsma number comma number comma number comma number comma allname rightsma { 
			tmp_var = new iLINE("line", $5, $7, $9, $11, GetName($13));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU circle leftsma number comma number comma number comma allname rightsma { 
			tmp_var = new iCIRCLE("circle", $5, $7, $9, GetName($11));
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU rect leftsma number comma number comma number comma number comma allname rightsma {
	 		tmp_var = new iRECT("rect", $5, $7, $9, $11, GetName($13));
	 		$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU color leftsma number comma number comma number rightsma { 
			tmp_var = new BaseType;
			tmp_var->type = "color";
			tmp_var->cname = GetName($1);
			tmp_var->SetColor($5, $7, $9);
			$$ = new def_node(GetName($1), tmp_var);
		}
	| allname EQU tree leftsma number comma bintree /*rightsma*/ {
			printf("newtree!!\n");
			tmp_tree = new iTREE("tree", $5, TreeR, TreeR);
			tmp_tree->nodes = *tmp_map;
			//tmp_var = tmp_tree;
			$$ = new def_node(GetName($1), tmp_tree);
		}
	| allname EQU tree leftsma number comma number comma number comma bintree {
			tmp_tree = new iTREE("tree", $5, $7, $9);
			tmp_tree->nodes = *tmp_map;
			$$ = new def_node(GetName($1), tmp_tree);
		}
	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { 
			printf("define a IF-ELSE statement, the value of expr\n");
			$$ = new if_else_node($3, $6, $10);
		}
	| WHILE leftsma expr rightsma leftbig lines rightbig { 
			
			printf("define a while statement, the value of expr\n");
			$$ = new while_node($3, $6);
		}
	| draw allname { 
			$$ = new draw_node(GetName($2));
		}
		/* add '=' operation */
	| allname EQU allname {
			/* a = b */
			$$ = new equ_sts_node(GetName($1), GetName($3));
		}
	| allname DOT color EQU allname {
		/* a.cname = 'red' */
			$$ = new equ_cts_node(GetName($1), GetName($5));
		}
	| allname DOT allname EQU expr {
	 		$$ = new equ_stn_node(GetName($1), GetName($3), $5);
	 	}
	| allname EQU func leftsma varlist leftbig lines rightbig {
			printf("define a func!\n");
			$$ = new def_func(GetName($1), *($5), $7);

	 	}
	| call allname leftsma paramlist {
			printf("call a func\n");
			$$ = new call_node(GetName($2), *($4));
	 	}
	;

paramlist : allname comma paramlist {
			$$ = $3;
			$$->push_back(GetName($1));
		}
	| allname rightsma {
			$$ = new std::vector<std::string>;
			$$->push_back(GetName($1));
			printf("a new paramlist!\n");
		}
	| rightsma {
			$$ = new std::vector<std::string>;
			printf("empty paramlist!\n");
		}
	;

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

/* bintree is the sequence of parameters */
/* e.g (2, 3)(0, 4) means node 1 has left child 2, and right child 3*/
/* and node 2 has only left child 4*/
/* if one of the child is <= 0 then set child to 0, no child */
/* to avoid loop, we think children number must larger than parent's */
bintree	: treenode bintree {
				printf("empty bintree2\n");
				//(*$2)[$1->first] = $1->second; //don't use insert!! coz may fail!!
				//(*$2)[$1->second.first] = std::make_pair(0,0); //tmp leaf
				//(*$2)[$1->second.second] = std::make_pair(0,0);
				$2->insert(*$1);
				$$ = $2;
				printf("the map is %d, %d\n", (*$2)[$1->first].first, (*$2)[$1->first].second);
			}
		| rightsma /*empty*/{
				printf("empty bintree\n");
				tmp_map = new std::map<int, std::pair<int, int> > ;	/* empty string*/
				$$ = tmp_map;
			}
		;

treenode : leftsma number comma number comma number rightsma {
				printf("empty bintree3\n");
				$$ = new std::pair<int, std::pair<int, int> >;
				$$->first = $2;
				$$->second = std::make_pair($4, $6);
				printf("node is: (%d, %d, %d)\n", $2, $4, $6);
			}
		;

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
}

int main()
{ 
	//yy_switch_to_buffer(yy_scan_string((char *)YYPARSE_PARAM));
	// char buffer[100];
	// while(1) {
	// 	yyparse(buffer); 
	// 	root->evaluate();		 
	// }

//	return 0;
	//return 0;
}

// int fun(int a, int b, int c) {
	

// }





