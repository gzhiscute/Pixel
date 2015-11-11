%{
	#include <cstdio>
	#include <cstring>
	#include <string>
	#include <map>
	#include "lex.yy.c"

	void CreateINT(char *name);
	void CreateBOOL(char *name);
	void CreatePOINT(char *name, int x, int y, char *color);
	void CreateLINE(char *name, int x, int y, int x1, int y1, char *color);
	void CreateCIRCLE(char *name, int x, int y, int r, char *color);
	void CreateRECT(char *name, int x, int y, int w, int h, char *color);
	void CreateCOLOR(char *name, int r, int g, int b);
	void yyerror (const char *msg);
//	extern int yylex();
	
	class BaseType{
		protected:
			std::string type;
			char *color;
		public:
			virtual void Init(const std::string& _type, char *_color) {
				type = _type;
				color = _color;
			}
			virtual void Init(const std::string& _type, int _x, int _y, char *_color) {}
			virtual void Init(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {}
			virtual void Init(const std::string& _type, int _x, int _y, int _r, char *color) {}
			virtual void draw() {}
	};

	class iINT : public BaseType {
		public:
			void draw() {
			}
	};


	class iBOOL : public BaseType {
		public:
			void draw() {
			}
	};

	class iPOINT : public BaseType {
		protected:
			int x, y;
		public:
			void Init(const std::string& _type, int _x, int _y, char *_color) {
				BaseType::type = _type;
				BaseType::color = _color;
				x = _x;
				y = _y; 
			}
			void draw() {
				
			}
	};

	class iLINE : public BaseType {
		protected:
			int x, y, x1, y1;
		public:
			void Init(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {
				BaseType::type = _type;
				BaseType::color = _color;
				x = _x;
				y = _y;
				x1 = _x1;
				y1 = _y1;
			}

			void draw() {
			}
	};

	class iCIRCLE : public BaseType {
		protected:
			int x, y, r;
		public:
			void Init(const std::string& _type, int _x, int _y, int _r, char *_color) {
				BaseType::type = _type;
				BaseType::color = _color;
				x = _x;
				y = _y;
				r = _r;
			}
			
			void draw() {
			}
	};
			
	class iRECT : public BaseType {
		protected:
			int x, y, w, h;
		public:
			void Init(const std::string& _type, int _x, int _y, int _w, int _h, char *_color) {
				BaseType::type = _type;
				BaseType::color = _color;
				x = _x;
				y = _y;
				w = _w;
				h = _h;
			}
			
			void draw() {

			}
	};

	class ColorType {
		protected:
			int R, G, B;
		public:
			ColorType(int _r, int _g, int _b) {
				R = _r;
				G = _g;
				B = _b;
			}
	};

	std::map<std::string, BaseType *> vars;
	std::map<std::string, ColorType *> colors;

>>>>>>> master
%}

%token str name number cname INT BOOL point circle rect color text IF ELSE WHILE CONTINUE BREAK draw DELETE backgroud func TRUE FALSE relop call

%%

input	: lines
	| func name '(' defargs ')' '{' lines '}'
	;
 
lines : line lines
	| /* empty */
	;

line	: '\n'
	| INT name { CreateINT((char *)$2); }
	| BOOL name { CreateBOOL((char *)$2); }
	| point name '=' point '(' number ',' number ',' cname ')' { CreatePOINT((char *)$2, $6, $8, (char *)$10); }
	| line name '=' line '(' number ',' number ',' number ',' number ',' cname ')' { CreateLINE((char *)$2, $6, $8, $10, $12, (char *)$14); }
	| circle name '=' circle '(' number ',' number ',' number ',' cname ')' { CreateCIRCLE((char *)$2,$6, $8, $10, (char *)$12); }
	| rect name '=' rect '(' number ',' number ',' number ',' number ',' color ')' { CreateRECT((char *)$2, $6, $8, $10, $12, (char *)$14); }
	| color name '=' color '(' number ',' number ',' number ')' { CreateCOLOR((char *)$2, $6, $8, $10); }
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
void CreateINT(char *name) {
	BaseType *base_type = new iINT();
	base_type->Init("INT", NULL);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("INT variable %s is created.\n", name);
}

void CreateBOOL(char *name) {
	BaseType *base_type = new iBOOL();
	base_type->Init("BOOL", NULL);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("BOOL variable %s is created.\n", name);
}

void CreatePOINT(char *name, int x, int y, char *color) {
	BaseType *base_type = new iPOINT();
	base_type->Init("POINT", x, y, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("POINT variable %s is created. Location is (%d, %d). Color is %s.\n", name, x, y, color);
}

void CreateLINE(char *name, int x, int y, int x1, int y1, char *color) {
	BaseType *base_type = new iLINE();
	base_type->Init("LINE", x, y, x1, y1, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("LINE variable %s is created. Location is (%d, %d), (%d, %d). Color is %s.\n", name, x, y, x1, y1, color);
}

void CreateCIRCLE(char *name, int x, int y, int r, char *color) {
	BaseType *base_type = new iCIRCLE();
	base_type->Init("CIRCLE", x, y, r, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("CIRCLE variable %s is created. Location is (%d, %d). Radius is %d. Color is %s.\n", name, x, y, r, color);
}

void CreateRECT(char *name, int x, int y, int w, int h, char *color) {
	BaseType *base_type = new iRECT();
	base_type->Init("RECT", x, y, w, h, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	printf("RECT variable %s is created. Left_upper corner is (%d, %d). Width is %d. Length is %d. Color is %s.\n", name, x, y, w, h, color);
}

void CreateCOLOR(char *name, int r, int g, int b) {
	ColorType *color_type = new ColorType(r, g, b);
	colors.insert(std::pair<std::string, ColorType *>(name, color_type));
	printf("COLOR variable %s=(%d, %d, %d) is created.\n", name, r, g, b);
}

//void Draw(YYSTYPE name) {
//	std::map<std::string, BaseType *>::iterator var;
//	var = map.find(name);
//	var->second->draw();
//}

void yyerror (const char *msg)
{ printf("%s\n", msg);}

int main()
{ return yyparse(); }

