
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

	lines_node *root;	/* the root of the abstract syntax tree*/
	static	std::list<line_node *> *tmp_line; /*store the temporary line*/	
	static	BaseType *tmp_var;	/*store the temporary variable*/
	static	iTREE *tmp_tree;
	static	std::map<int, std::pair<int, int> > *tmp_map;
	static	std::pair<int, std::pair<int, int> > *tmp_pair;
	static	char* GetName(char *nname);
	void yyerror (/*void *a, */const char *msg);
%}


/* union is the return type */
%union {
	int num;
	char *str;
	BaseType *bstp;
	line_node *lnode;
	lines_node *lsnode;
	std::pair<int, std::pair<int, int> > *childpair;
	std::map<int, std::pair<int, int> > *binvect;
};

 //%parse-param {void *Buff} 

%token <str> allname
%token <num> number
%token <bstp> INT BOOL POINT LINE circle rect tree
%token color text IF ELSE WHILE CONTINUE BREAK newline
%token draw backgroud func TRUE FALSE relop call EQU DOT
%token leftsma rightsma leftbig rightbig OR AND comma expr
%token colname
%type <lnode> line 
%type <lsnode> lines input
%type <childpair> treenode
%type <binvect> bintree

/*
%token str name number INT BOOL POINT LINE circle rect color text 
IF ELSE WHILE CONTINUE BREAK draw backgroud func TRUE FALSE relop 
call EQU leftsma rightsma leftbig rightbig newline OR AND comma
*/
%start input

%%

input	: lines { 
				$$ = $1; 
				root = $$;
				printf("input\n. root is 0x%x", root);
			}
//	| func name leftsma defargs rightsma leftbig lines rightbig
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
		}//
	;

line	: newline {printf("newline\n")}
	|allname EQU TRUE { 
				tmp_var = new iBOOL("bool", 1);
				$$ = new def_node(GetName($1), tmp_var);
			}
	| allname EQU FALSE { 
			tmp_var = new iBOOL("bool", 1);
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
			tmp_tree = new iTREE("tree", $5);
			tmp_tree->nodes = *tmp_map;
			//tmp_var = tmp_tree;
			$$ = new def_node(GetName($1), tmp_tree);
		}
	/*| allname EQU tree leftsma number comma number comma number comma bintree *//* add location information */
//	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { /*printf("define a if statement, the value of expr is %d\n", $3); */ }
	//| WHILE leftsma boolexpr rightsma leftbig lines rightbig { //printf("define a while statement, the value of expr is %d\n", $3); 
	
	//}
	| CONTINUE { //printf("define a continue\n"); 
	}
	| draw allname { 
			$$ = new draw_node(GetName($2));
		}
		/* add '=' operation */
	| allname EQU allname {
			/* a = b */
			$$ = new equ_sts_node(GetName($1), GetName($3));
		}
	 | allname DOT allname EQU number {
	 		
	 		$$ = new equ_stn_node(GetName($1), GetName($3), $5);
	 	}
	| allname DOT color EQU allname {
		/* a.cname = 'red' */
		$$ = new equ_cts_node(GetName($1), GetName($5));
		}
	// | allname DOT allname EQU expr {

	// 	}

//	| call name leftsma callargs rightsma { //printf("define a function call"); 
//	}
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

// supernum : allname DOT allname 
// 		| number 
// 		| allname
// 		;
		
// expr : 	supernum PLUS expr
// 		| supernum
// 		;

// boolexpr : supernum relop supernum
// 		 ;
// defargs	: name comma defargs
// 	| /* empty */
// 	;

// callargs	: name comma callargs
// 		| number comma callargs
// 		| /* empty */
// 		;
		
// expr	: boolexpr { $$ = $1; }
// 	| relexpr
// 	;
	
// relexpr	: name relop name
// 	;
		
// boolexpr	: boolexpr_term boolexpr_
// 		| /* empty */
// 		;

// boolexpr_	: OR boolexpr_term boolexpr_
// 		| AND boolexpr_term boolexpr_
// 		| /* empty */
		
			 
// boolexpr_term	: name
// 		| TRUE
// 		| FALSE
// 		| leftsma boolexpr rightsma
// 		;

//relexpr	: relexpr OR relexpr_ { printf("define a relexpr with ||\n"); } 
//		| relexpr AND relexpr_ { printf("define a relexpr with &&\n"); }
//		| leftsma relexpr rightsma { printf("define a relexpr with ()\n"); }
//		| TRUE { printf("define a relexpr with true\n"); }
//		| FALSE { printf("define a relexpr with false\n"); }
//		;

//relexpr_	: name { printf("define a relexpr_ name\n"); }
//			| TRUE { printf("define a relexpr_ true\n"); }
//			| FALSE { printf("define a relexpr_ false\n"); }
//			;

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

	return 0;
	//return 0;
}

// int fun(int a, int b, int c) {
	

// }





