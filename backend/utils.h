#ifndef __COMPILER_PIXEL_BACKEND__
#define __COMPILER_PIXEL_BACKEND__

#include <string>
#include <map>
#include <list>

class BaseType{
	public:
		std::string type;
		std::string cname;
		int r, g, b;
		void SetColor(int _r, int _g, int _b); 
		virtual void drawsvg() {}
};


class iINT : public BaseType {
	protected:
		int val;
	public:
		iINT(const std::string& _type, int _val);
		void drawsvg() {
			//printf("ERROR: can't draw a INT.\n");
		}
};


class iBOOL : public BaseType {
	protected:
		int val;
	public:
		iBOOL(const std::string& _type, int _val);
		void drawsvg() {
			//printf("ERROR: can't draw a BOOL.\n");
		}
};

class iPOINT : public BaseType {
	protected:
		int x, y;
	public:
		iPOINT(const std::string& _type, int _x, int _y, char *_color);
		void drawsvg();
};

class iLINE : public BaseType {
	protected:
		int x, y, x1, y1;
	public:
		iLINE(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color);
		void drawsvg(); 
};

class iCIRCLE : public BaseType {
	protected:
		int x, y, r;
	public:
		iCIRCLE(const std::string& _type, int _x, int _y, int _r, char *_color);
		void drawsvg();
};
		
class iRECT : public BaseType {
	protected:
		int x, y, w, h;
	public:
		iRECT(const std::string& _type, int _x, int _y, int _w, int _h, char *_color);
		void drawsvg();
};

class line_node {
	public:
		virtual void evaluate() {}
};

class def_node : public line_node {
	protected:
		std::string node_name;
		BaseType *base_type;
	public:
		def_node(std::string node_name, BaseType *base_type);
		void evaluate();
};

class draw_node : public line_node {
	protected:
		std::string node_name;
	public:
		draw_node(std::string node_name);
		void evaluate();
};

class lines_node {
	public:
		std::list<line_node *> *cmdlines;

		lines_node(std::list<line_node *> *_lines);
		void evaluate();
};

		
#endif /* __COMPILER_PIXEL_BACKEND__ */	
