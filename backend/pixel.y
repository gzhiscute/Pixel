%{
	#include <stdio.h>
	#include <string.h>

	void yyerror (const char *msg);
//	extern int yylex();
%}

%token str name number cname INT BOOL point circle rect color text IF ELSE WHILE CONTINUE BREAK draw delete backgroud func TRUE FALSE relop call

%%

input	: lines
		| func name '(' defargs ')' '{' lines '}'
		;
 
lines : line lines
		| /* empty */
		;

line	: '\n'
		| INT name { printf("define an int variable %s\n", $2); }
		| BOOL name { printf("define a bool variable %s\n", $2); }
		| point name '=' point '( ' number ',' number ',' cname ')' { printf("define a point variable %s: loc=(%d, %d), color=%s\n", $2, $6, $8, $10); } 
		| line name '=' line '(' number ',' number ',' number ',' number ',' cname ')' { printf("define a line variable %s: loc=(%d, %d), (%d, %d), color=%s\n", $2, $6, $8, $10, $12, $14); }
		| circle name '=' circle '(' number ',' number ',' number ',' cname ')' { printf("define a circle variable %s: loc=(%d, %d), r=%d, color=%s\n", $2, $6, $8, $10, $12); }
		| rect name '=' rect '(' number ',' number ',' number ',' number ',' color ')' { printf("define a rect variable %s: loc=(%d, %d), (%d, %d), color=%s\n", $2, $6, $8, $10, $12); }
		| color name '=' color '(' number ',' number ',' number ')' { printf("define a color variable %s = (%d, %d, %d)\n", $2, $6, $8, $10); }
		| IF '(' expr ')' '{' lines '}' ELSE '{' lines '}' { printf("define a if statement, the value of expr is %d\n", $3); }
		| WHILE '(' expr ')' '{' lines '}' { printf("define a while statement, the value of expr is %d\n", $3); }
		| CONTINUE { printf("define a continue\n"); }
		| draw name { printf("define a draw statement"); }
		| call name '(' callargs ')' { printf("define a function call"); }
		;

defargs	: name ',' defargs
		| /* empty */
		;

callargs	: name ',' callargs
			| number ',' callargs
			| /* empty */
			;
		
expr	: boolexpr
		| relexpr
		;
	
relexpr	: name relop name
		;
		
boolexpr	: boolexpr_term boolexpr_
			| /* empty */
			;

boolexpr_	: '||' boolexpr_term boolexpr_
			| '&&' boolexpr_term boolexpr_
			| /* empty */
			;
			 
boolexpr_term	: name
				| TRUE
				| FALSE
				| '(' boolexpr ')'
				;

//relexpr	: relexpr '||' relexpr_ { printf("define a relexpr with ||\n"); } 
//		| relexpr '&&' relexpr_ { printf("define a relexpr with &&\n"); }
//		| '(' relexpr ')' { printf("define a relexpr with ()\n"); }
//		| TRUE { printf("define a relexpr with true\n"); }
//		| FALSE { printf("define a relexpr with false\n"); }
//		;

//relexpr_	: name { printf("define a relexpr_ name\n"); }
//			| TRUE { printf("define a relexpr_ true\n"); }
//			| FALSE { printf("define a relexpr_ false\n"); }
//			;

%%
#include "lex.yy.c"

void yyerror (const char *msg)
{ printf("%s\n", msg);}

int main()
{ return yyparse(); }

