
%{
	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include "utils.h"
	#include "lex.yy.c" /* yylex file*/
	/*Header file for AST*/

	lines_node *root;	/* the root of the abstract syntax tree*/
	std::list<line_node *> *tmp_line; /*store the temporary line*/	
	BaseType *tmp_var;	/*store the temporary variable*/

	char* GetName(char *nname);
	void yyerror (const char *msg);
%}


/* union is the return type */
%union {
	int num;
	char *str;
	BaseType *bstp;
	line_node *lnode;
	lines_node *lsnode;
};

// %parse-param {void *Buff}

%token <str> allname
%token <num> number
%token <bstp> INT BOOL POINT LINE circle rect
%token color text IF ELSE WHILE CONTINUE BREAK newline
%token draw backgroud func TRUE FALSE relop call EQU
%token leftsma rightsma leftbig rightbig OR AND comma expr
%type <lnode> line 
%type <lsnode> lines input
/*
%token str name number INT BOOL POINT LINE circle rect color text 
IF ELSE WHILE CONTINUE BREAK draw backgroud func TRUE FALSE relop 
call EQU leftsma rightsma leftbig rightbig newline OR AND comma
*/

%%

input	: lines { 
				$$ = $1; 
				root = $$;
			}
//	| func name leftsma defargs rightsma leftbig lines rightbig
	;
 
lines : lines newline /*empty line*/
		{
			$$ = $1;
		}

	| 	lines line newline{ 
			$$ = $1;
			$1->cmdlines->push_front($2); 
		}
	| /* empty */
		{ 	
			tmp_line = new std::list<line_node *>;	/* empty string*/
			$$ = new lines_node(tmp_line);
		}
	;

line	: allname EQU TRUE { 
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
	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { /*printf("define a if statement, the value of expr is %d\n", $3); */ }
	| WHILE leftsma expr rightsma leftbig lines rightbig { //printf("define a while statement, the value of expr is %d\n", $3); 
	}
	| CONTINUE { //printf("define a continue\n"); 
	}
	| draw allname { 
			$$ = new draw_node(GetName($2));
		}
//	| call name leftsma callargs rightsma { //printf("define a function call"); 
//	}
	;

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

void yyerror(const char *msg)
{
}

int main()
{ 
	//yy_switch_to_buffer(yy_scan_string((char *)YYPARSE_PARAM));
	//return yyparse(YYPARSE_PARAM); 
	return 0;
}

