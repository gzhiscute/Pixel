/* 
* utils.h
* This is our team's AST utils header for Pixel Language
* Written by Li Qian and Guo ZiHan
* Part of the backend server
* 2015 Fall Semester -- Compiling Practice
*/

#ifndef __COMPILER_PIXEL_BACKEND__
#define __COMPILER_PIXEL_BACKEND__

#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>

#define TreeR 10

int StringToInt(std::string s);

class BaseType{
	public:
		std::string type;
		std::string cname;
		int r, g, b;
		BaseType() {type = cname = "", r = g = b = 0; }
		void SetColor(int _r, int _g, int _b);
		void SetBaseVars(const std::string& _type, char *_color);
		virtual void drawsvg() {}
		virtual void ChangeField(std::string var_name, int right);
		virtual void ChangeColor(std::string colorstr) {}
		virtual int GetField(std::string var_name) {}
		virtual int GetVal() {}
		virtual int GetX() {}
		virtual int GetY() {}
		virtual int GetX1() {}
		virtual int GetY1() {}
		virtual int GetR() {}
		virtual int GetW() {}
		virtual int GetH() {}
};

class iINT : public BaseType {
	protected:
		int val;
	public:
		iINT(const std::string& _type, int _val);
		void drawsvg() {
			//printf("ERROR: can't draw a INT.\n");
		}
		void ChangeField(std::string var_name, int right);
		int GetVal() { return val; }
};


class iBOOL : public BaseType {
	protected:
		int val;
	public:
		iBOOL(const std::string& _type, int _val);
		void drawsvg() {
			//printf("ERROR: can't draw a BOOL.\n");
		}
		void ChangeField(std::string var_name, int right);
		int GetVal() { return val; }
};

class iPOINT : public BaseType {
	protected:
		int x, y;
	public:
		iPOINT(const std::string& _type, int _x, int _y, char *_color);
		void drawsvg();
		void ChangeField(std::string var_name, int right);
		void ChangeColor(std::string colorstr);
		int GetField(std::string var_name);
		int GetX() { return x; }
		int GetY() { return y; }
};

class iLINE : public BaseType {
	protected:
		int x, y, x1, y1;
	public:
		iLINE(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color);
		void drawsvg(); 
		void ChangeField(std::string var_name, int right);
		void ChangeColor(std::string colorstr);
		int GetField(std::string var_name);
		int GetX() { return x; }
		int GetY() { return y; }
		int GetX1() { return x1; }
		int GetY1() { return y1; }
};

class iCIRCLE : public BaseType {
	protected:
		int x, y, r;
	public:
		iCIRCLE(const std::string& _type, int _x, int _y, int _r, char *_color);
		void drawsvg();
		void ChangeField(std::string var_name, int right);
		void ChangeColor(std::string colorstr);
		int GetField(std::string var_name);
		int GetX() { return x; }
		int GetY() { return y; }
		int GetR() { return r; }
};
		
class iRECT : public BaseType {
	protected:
		int x, y, w, h;
	public:
		iRECT(const std::string& _type, int _x, int _y, int _w, int _h, char *_color);
		void drawsvg();
		void ChangeField(std::string var_name, int right);
		void ChangeColor(std::string colorstr);
		int GetField(std::string var_name);
		int GetX() { return x; }
		int GetY() { return y; }
		int GetW() { return w; }
		int GetH() { return h; }
};

class iTREE : public BaseType {
	public:
		int binroot, treex, treey;
		std::map<int, std::pair<int, int> > nodes;
		void drawsvg();
		iTREE(const std::string& _type, int _rt, int _tx, int _ty);
	private:
		bool CalcDep(int p, int *Max, int dep, std::set<int> *vis);
		void DrawTree(int p, int x, int y, int dep);
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

// allname EQU allname
class equ_sts_node : public line_node {
	protected:
		std::string left;
		std::string right;
	public:
		equ_sts_node(std::string _left, std::string _right);
		void evaluate();
};

class exp_node {
	public:
		int num;
		virtual int evaluate() = 0;
};

class operator_node : public exp_node {
	public:
		exp_node *left;
		exp_node *right;
		operator_node(exp_node *L, exp_node *R);
};

class field_node : public exp_node {
	protected:
		std::string left;
		std::string var_name;
	public:
		field_node(std::string _left, std::string _var_name);
		int evaluate();
};

class number_node : public exp_node {
	public:
		number_node(int _num);
		int evaluate();
};

class int_node : public exp_node {
	protected:
		std::string var_name;
	public:
		int_node(std::string _var_name);
		int evaluate();
};

class plus_node : public operator_node {
	public:
		plus_node(exp_node *L, exp_node *R);
		int evaluate();
};

class minus_node : public operator_node {
	public:
		minus_node(exp_node *L, exp_node *R);
		int evaluate();
};

class times_node : public operator_node {
	public:
		times_node(exp_node *L, exp_node *R);
		int evaluate();
};

class  divide_node : public operator_node {
	public:
		 divide_node(exp_node *L, exp_node *R);
		 int evaluate();
};

class  gt_node : public operator_node {
	public:
		 gt_node(exp_node *L, exp_node *R);
		 int evaluate();
};

class  ge_node : public operator_node {
	public:
		 ge_node(exp_node *L, exp_node *R);
		 int evaluate();
};

class  lt_node : public operator_node {
	public:
		 lt_node(exp_node *L, exp_node *R);
		 int evaluate();
};

class  le_node : public operator_node {
	public:
		 le_node(exp_node *L, exp_node *R);
		 int evaluate();
};

class ee_node : public operator_node {
	public:
		ee_node(exp_node *L, exp_node *R);
		int evaluate();
};

// allname dot vara EQU number
class equ_stn_node : public line_node {
	protected:
		std::string left;
		std::string var_name;
		exp_node *right;
	public:
		equ_stn_node(std::string _left, std::string _var_name, exp_node *_right);
		void evaluate();
};

// allname dot colorstr EQU allname
class equ_cts_node : public line_node {
	protected:
		std::string left;
		std::string right;
	public:
		equ_cts_node(std::string _left, std::string _right);
		void evaluate();
};

class lines_node {
	public:
		std::list<line_node *> *cmdlines;

		lines_node(std::list<line_node *> *_lines);
		void evaluate();
};

class while_node : public line_node {
	public:
		exp_node *left;
		lines_node *right;

		while_node(exp_node *_left, lines_node *_right);
		void evaluate();
};

class if_else_node : public line_node {
	public:
		exp_node *left;
		lines_node *true_right;
		lines_node *false_right;

		if_else_node(exp_node *_left, lines_node *_tr, lines_node *_fr);
		void evaluate();
};

class def_func : public line_node {
	public:
		std::string func_name;
		std::vector<std::pair<std::string, std::string> > params;
		lines_node *right;
		def_func(std::string _name, std::vector<std::pair<std::string, std::string> > _params, lines_node *_right);
		void evaluate();
};

class call_node : public line_node {
	public:
		std::string node_name;
		std::vector<std::string> params;
		call_node(std::string _name, std::vector<std::string> _params);
		void evaluate();
};

#endif /* __COMPILER_PIXEL_BACKEND__ */	
