%{
	#include <cstdio>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <map>
	#include "lex.yy.c"
	
	char* ToLower(char* color);

	class BaseType{
		protected:
			std::string type;
		public:
			std::string color;
			int r, g, b;
			void SetColorName(char *_color) {
				color = _color;
//				for (int i = 0; _color[i] ; ++i);
//				color = calloc(i+3, sizeof(char));
//				for (int i = 0; _color[i]; ++i)
//					color[i] = _color[i];
			}
			void SetColor(int _r, int _g, int _b) {
				r = _r;
				g = _g;
				b = _b;
			}
			virtual void Init(const std::string& _type, char *_color) {
				type = _type;
				SetColorName(_color);
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
		public:
			void draw() {
				//printf("ERROR: can't draw a INT.\n");
			}
	};


	class iBOOL : public BaseType {
		public:
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
				printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, x, y, BaseType::r, BaseType::g, BaseType::b);	
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
				printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>\n</svg>\n", x, y, x1, y1, BaseType::r, BaseType::g, BaseType::b);
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
				printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, r, BaseType::r, BaseType::g, BaseType::b);
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
				printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", 512-x/2, 384-y/2, w, h, BaseType::r, BaseType::g, BaseType::b);
			}
	};

	bool MultipleDef(char *name, BaseType *base_type);
	char* GetName(char *name);
	void CreateINT(char *name);
	void CreateBOOL(char *name);
	void CreatePOINT(char *name, int x, int y, char *color);
	void CreateLINE(char *name, int x, int y, int x1, int y1, char *color);
	void CreateCIRCLE(char *name, int x, int y, int r, char *color);
	void CreateRECT(char *name, int x, int y, int w, int h, char *color);
	void CreateCOLOR(char *name, int r, int g, int b);
	void Draw(char *name);
	void yyerror (const char *msg);
//	extern int yylex();

%}

%token str name number INT BOOL POINT LINE circle rect color text IF ELSE WHILE CONTINUE BREAK draw DELETE backgroud func TRUE FALSE relop call EQU leftsma rightsma leftbig rightbig newline OR AND comma
%%

input	: lines
	| func name leftsma defargs rightsma leftbig lines rightbig
	;
 
lines : line lines
	| /* empty */
	;

line	: newline
	| INT name { CreateINT((char *)$2); }
	| BOOL name { CreateBOOL((char *)$2); }
	| POINT name EQU POINT leftsma number comma number comma name rightsma { CreatePOINT(GetName((char *)$2), $6, $8, GetName((char *)$10)); }
	| LINE name EQU LINE leftsma number comma number comma number comma number comma name rightsma { CreateLINE(GetName((char *)$2), $6, $8, $10, $12, GetName((char *)$14)); }
	| circle name EQU circle leftsma number comma number comma number comma name rightsma { CreateCIRCLE(GetName((char *)$2),$6, $8, $10, GetName((char *)$12)); }
	| rect name EQU rect leftsma number comma number comma number comma number comma name rightsma { CreateRECT(GetName((char *)$2), $6, $8, $10, $12, GetName((char *)$14)); }
	| color name EQU color leftsma number comma number comma number rightsma { CreateCOLOR(GetName((char *)$2), $6, $8, $10); }
	| IF leftsma expr rightsma leftbig lines rightbig ELSE leftbig lines rightbig { //printf("define a if statement, the value of expr is %d\n", $3); 
	}
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
		
expr	: boolexpr
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
bool MultipleDef(char *name) {
	std::map<std::string, BaseType *>::iterator p = vars.find(name);
	if (p != vars.end()) {
		//printf("Can't create variable %s: Multiple definition.\n", name);
		return 1;
	} else 
		return 0;
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

void CreateINT(char *name) {
	BaseType *base_type = new iINT();
	base_type->Init("INT", NULL);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("INT variable %s is created.\n", name);
}

void CreateBOOL(char *name) {
	BaseType *base_type = new iBOOL();
	base_type->Init("BOOL", NULL);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("BOOL variable %s is created.\n", name);
}

void CreatePOINT(char *name, int x, int y, char *color) {
	BaseType *base_type = new iPOINT();
	base_type->Init("POINT", x, y, color);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("POINT variable %s is created. Location is (%d, %d). Color is %s.\n", name, x, y, color);
}

void CreateLINE(char *name, int x, int y, int x1, int y1, char *color) {
	BaseType *base_type = new iLINE();
	base_type->Init("LINE", x, y, x1, y1, color);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("LINE variable %s is created. Location is (%d, %d), (%d, %d). Color is %s.\n", name, x, y, x1, y1, color);
}

void CreateCIRCLE(char *name, int x, int y, int r, char *color) {
	BaseType *base_type = new iCIRCLE();
	base_type->Init("CIRCLE", x, y, r, color);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("CIRCLE variable %s is created. Location is (%d, %d). Radius is %d. Color is %s.\n", name, x, y, r, color);
}

void CreateRECT(char *name, int x, int y, int w, int h, char *color) {
	BaseType *base_type = new iRECT();
	base_type->Init("RECT", x, y, w, h, color);
	if (MultipleDef(name)) return;
	vars.insert(std::pair<std::string, BaseType *>(name, base_type));
	//printf("RECT variable %s is created. Left_upper corner is (%d, %d). Width is %d. Length is %d. Color is %s.\n", name, x, y, w, h, color);
}

void CreateCOLOR(char *name, int r, int g, int b) {
	BaseType *base_type = new BaseType();
	base_type->Init("COLOR", r, g, b);
	if (MultipleDef(name)) return;
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

void yyerror (const char *msg)
{ printf("%s\n", msg);}

int main()
{ return yyparse(); }

