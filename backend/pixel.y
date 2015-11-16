/*
	memset(vars);
	memset(ans);
*/
%{
	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include "lex.yy.c"
	
	#define YYPARSE_PARAM pram
	std::string ans;

	class BaseType{
		protected:
			std::string type;
		public:
			std::string color;
			int r, g, b;
			void SetColor(int _r, int _g, int _b) {
				r = _r;
				g = _g;
				b = _b;
			}
			virtual void Init(const std::string& _type, int _val) {}
			virtual void Init(const std::string& _type, char *_color) {
				type = _type;
				color = _color;
			}
			virtual void Init(const std::string& _type, int _r, int _g, int _b) {
				type = _type;
				SetColor(_r, _g, _b);
			}
			virtual void Init(const std::string& _type, int _x, int _y, char *_color) {}
			virtual void Init(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {}
			virtual void Init(const std::string& _type, int _x, int _y, int _r, char *color) {}
			virtual void draw() {}
	};
	std::map<std::string, BaseType *> vars;
	
	class iINT : public BaseType {
		protected:
			int val;
		public:
			void Init(const std::string& _type, int _val) {
				BaseType::type = _type;
				val = _val;
			}
			void draw() {
				//printf("ERROR: can't draw a INT.\n");
			}
	};


	class iBOOL : public BaseType {
		protected:
			int val;
		public:
			void Init(const std::string& _type, int _val) {
				BaseType::type = _type;
				val = _val;
			}
			void draw() {
				//printf("ERROR: can't draw a BOOL.\n");
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
				//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, x, y, BaseType::r, BaseType::g, BaseType::b);
				char *tmp;
				tmp = (char *)calloc(256, sizeof(char));
				sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>", x, y, BaseType::r, BaseType::g, BaseType::b);	
				ans += tmp;
				free(tmp);
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
				//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>\n</svg>\n", x, y, x1, y1, BaseType::r, BaseType::g, BaseType::b);
				char *tmp;
				tmp = (char *)calloc(256, sizeof(char));
				sprintf(tmp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>", x, y, x1, y1, BaseType::r, BaseType::g, BaseType::b);
				ans += tmp;
				free(tmp);
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
				//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, r, BaseType::r, BaseType::g, BaseType::b);
				char *tmp;
				tmp = (char *)calloc(256, sizeof(char));
				sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>", x, y, r, BaseType::r, BaseType::g, BaseType::b);
				ans += tmp;
				free(tmp);
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
				//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x/2, y/2, w, h, BaseType::r, BaseType::g, BaseType::b);
				char *tmp;
				tmp = (char *)calloc(256, sizeof(char));
				sprintf(tmp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>", x/2, y/2, w, h, BaseType::r, BaseType::g, BaseType::b);
				ans += tmp;
				free(tmp);
			}
	};

	void MultipleDef(char *name);
	char* GetName(char *name);
	void CreateINT(char *name, int _val);
	void CreateBOOL(char *name, int _val);
	void CreatePOINT(char *name, int x, int y, char *color);
	void CreateLINE(char *name, int x, int y, int x1, int y1, char *color);
	void CreateCIRCLE(char *name, int x, int y, int r, char *color);
	void CreateRECT(char *name, int x, int y, int w, int h, char *color);
	void CreateCOLOR(char *name, int r, int g, int b);
	void Draw(char *name);
	void yyerror (const char *msg);
//	extern int yylex();
%}

%token str name number INT BOOL POINT LINE circle rect color text IF ELSE WHILE CONTINUE BREAK draw backgroud func TRUE FALSE relop call EQU leftsma rightsma leftbig rightbig newline OR AND comma
%%

input	: lines
	| func name leftsma defargs rightsma leftbig lines rightbig
	;
 
lines : line lines
	| /* empty */
	;

line	: newline
	| name EQU TRUE{ CreateBOOL(GetName((char *)$1), 1); }
	| name EQU FALSE { CreateBOOL(GetName((char *)$1), 0);}
	| name EQU number { CreateINT(GetName((char *)$1), $3);}
	| name EQU POINT leftsma number comma number comma name rightsma { CreatePOINT(GetName((char *)$1), $5, $7, GetName((char *)$9)); }
	| name EQU LINE leftsma number comma number comma number comma number comma name rightsma { CreateLINE(GetName((char *)$1), $5, $7, $9, $11, GetName((char *)$13)); }
	| name EQU circle leftsma number comma number comma number comma name rightsma { CreateCIRCLE(GetName((char *)$1),$5, $7, $9, GetName((char *)$11)); }
	| name EQU rect leftsma number comma number comma number comma number comma name rightsma { CreateRECT(GetName((char *)$1), $5, $7, $9, $11, GetName((char *)$13)); }
	| name EQU color leftsma number comma number comma number rightsma { CreateCOLOR(GetName((char *)$1), $5, $7, $9); }
	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { /*printf("define a if statement, the value of expr is %d\n", $3); */ }
	| WHILE leftsma expr rightsma leftbig lines rightbig { //printf("define a while statement, the value of expr is %d\n", $3); 
	}
	| CONTINUE { //printf("define a continue\n"); 
	}
	| draw name { Draw(GetName((char *)$2)); }
	| call name leftsma callargs rightsma { //printf("define a function call"); 
	}
	;

defargs	: name comma defargs
	| /* empty */
	;

callargs	: name comma callargs
		| number comma callargs
		| /* empty */
		;
		
expr	: boolexpr { $$ = $1; }
	| relexpr
	;
	
relexpr	: name relop name
	;
		
boolexpr	: boolexpr_term boolexpr_
		| /* empty */
		;

boolexpr_	: OR boolexpr_term boolexpr_
		| AND boolexpr_term boolexpr_
		| /* empty */
		
			 
boolexpr_term	: name
		| TRUE
		| FALSE
		| leftsma boolexpr rightsma
		;

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
void MultipleDef(char *name) {
	std::map<std::string, BaseType *>::iterator p = vars.find(name);
	if (p != vars.end()) 
		vars.erase(p);
}

char *GetName(char *name) {
	for (int i = 0; ; ++i) {
		if (((name[i] <= 'z') && (name[i] >='a'))
		||  ((name[i] <= 'Z') && (name[i] >='A'))
		||  ((name[i] <='9') && (name[i] >='0'))
		||   (name[i] == '_'));
		else {
			name[i] = 0;
			break;
		}
	}
	return name;
}

void CreateINT(char *name, int val) {
	MultipleDef(name);
	BaseType *base_type = new iINT();
	base_type->Init("INT", val);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("INT variable %s is created.\n", name);
}

void CreateBOOL(char *name, int val) {
	MultipleDef(name);
	BaseType *base_type = new iBOOL();
	base_type->Init("BOOL", val);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("BOOL variable %s is created.\n", name);
}

void CreatePOINT(char *name, int x, int y, char *color) {
	MultipleDef(name);
	BaseType *base_type = new iPOINT();
	base_type->Init("POINT", x, y, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("POINT variable %s is created. Location is (%d, %d). Color is %s.\n", name, x, y, color);
}

void CreateLINE(char *name, int x, int y, int x1, int y1, char *color) {
	MultipleDef(name);
	BaseType *base_type = new iLINE();
	base_type->Init("LINE", x, y, x1, y1, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("LINE variable %s is created. Location is (%d, %d), (%d, %d). Color is %s.\n", name, x, y, x1, y1, color);
}

void CreateCIRCLE(char *name, int x, int y, int r, char *color) {
	MultipleDef(name);
	BaseType *base_type = new iCIRCLE();
	base_type->Init("CIRCLE", x, y, r, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("CIRCLE variable %s is created. Location is (%d, %d). Radius is %d. Color is %s.\n", name, x, y, r, color);
}

void CreateRECT(char *name, int x, int y, int w, int h, char *color) {
	MultipleDef(name);
	BaseType *base_type = new iRECT();
	base_type->Init("RECT", x, y, w, h, color);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("RECT variable %s is created. Left_upper corner is (%d, %d). Width is %d. Length is %d. Color is %s.\n", name, x, y, w, h, color);
}

void CreateCOLOR(char *name, int r, int g, int b) {
	MultipleDef(name);
	BaseType *base_type = new BaseType();
	base_type->Init("COLOR", r, g, b);
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("COLOR variable %s=(%d, %d, %d) is created.\n", name, r, g, b);
}

void Draw(char *name) {
	std::map<std::string, BaseType *>::iterator var;
	var = vars.find(name);
	if (var == vars.end()) {
		//printf("Can't draw %s: variable doesn't exist.\n", name);
		return;
	}

	std::map<std::string, BaseType *>::iterator p;
	p = vars.find(var->second->color);
	if (p == vars.end()) {
		//std::cout << "Can't find color variable " << var->second->color << "." << std::endl;
		return;
	}
	var->second->SetColor(p->second->r, p->second->g, p->second->b);
	var->second->draw();
}

//void yyerror (const char *msg)
//{ printf("%s\n", msg);}

int main()
{ 
	
	return yyparse(pram); 

}

