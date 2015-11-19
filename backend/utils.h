#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

class BaseType{
	protected:
		std::string type;
	public:
		std::string color;
		int r, g, b;
		void SetColor(int _r, int _g, int _b) {}
		virtual void Init(const std::string& _type, int _val) {}
		virtual void Init(const std::string& _type, char *_color) {}
		virtual void Init(const std::string& _type, int _r, int _g, int _b) {}
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
		void Init(const std::string& _type, int _val) {}
		void draw() {
			//printf("ERROR: can't draw a INT.\n");
		}
};


class iBOOL : public BaseType {
	protected:
		int val;
	public:
		void Init(const std::string& _type, int _val) {}
		void draw() {
			//printf("ERROR: can't draw a BOOL.\n");
		}
};

class iPOINT : public BaseType {
	protected:
		int x, y;
	public:
		void Init(const std::string& _type, int _x, int _y, char *_color) {}
		void draw() {}
};

class iLINE : public BaseType {
	protected:
		int x, y, x1, y1;
	public:
		void Init(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {}

		void draw() {}
};

class iCIRCLE : public BaseType {
	protected:
		int x, y, r;
	public:
		void Init(const std::string& _type, int _x, int _y, int _r, char *_color) {}
		
		void draw() {}
};
		
class iRECT : public BaseType {
	protected:
		int x, y, w, h;
	public:
		void Init(const std::string& _type, int _x, int _y, int _w, int _h, char *_color) {}
		
		void draw() {}
};

class line_node {
	public:
		virtual void evaluate() = 0;
};

class def_node : public line_node {
	public:
		std::string name;
		BaseType *base_type;

		void evaluate();
};

class draw_node : public line_node {
	public:
		std::string name;

		void evaluate();
};

class lines_node {
	public:
		list<line_node *> *lines;

		lines_node(list<line_node *> *_lines);
		void evaluate();
};
		
		
