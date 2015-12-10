/* 
 * Project: utils.h
 * Author: Li Qian and Guo ZiHan
 * Data: 2015-12-10
 * Description:
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

// Radius of tree node.
#define TreeR 10

// Base class for various types.
// type: varible's type.
// cname: varible's name.
// r, g, b: color parameters.
// Get method: Get the value of member varibles.
// Set method: Easy way to set the value for member varibles.
// drawsvg: draw shapes.
// Change method: Recognize different member varibles and change the value of member varibles.
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

// Type Int
// val: varible value.
class iINT : public BaseType {
	protected:
		int val;
	public:
		iINT(const std::string& _type, int _val);
		void drawsvg();
		void ChangeField(std::string var_name, int right);
		int GetVal() { return val; }
};

// Type BOOL
// val: varible value.
class iBOOL : public BaseType {
	protected:
		int val;
	public:
		iBOOL(const std::string& _type, int _val);
		void drawsvg();
		void ChangeField(std::string var_name, int right);
		int GetVal() { return val; }
};

// Type POINT
// x, y: horizontal and vertical coordinates of point.
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

// Type LINE
// x, y: horizontal and vertical coordinates of start point.
// x1, y1: horizontal and vertical coordinates of end point.
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

// Type CIRCLE
// x, y: horizontal and vertical coordinates of center point.
// r: radius of circle.
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
	
// Type RECTANGLE
// x, y: horizontal and vertical coordinates of left upper corner.
// w, h: width and height length of this rectangle.
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

// Type TREE
// binroot: root of tree.
// treex, treey: horizontal and vertical coordinates of root.
// nodes: nodes of tree. format: <nodei, pair<nodei's left son, nodei's right son> >.
// CalcDep: calc the depth of tree.
// DrawTree: draw a tree from the root.
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

// Class for line in pixel.y.
class line_node {
	public:
		virtual void evaluate() {}
};

// Class for definition statements.
class def_node : public line_node {
	protected:
		std::string node_name;
		BaseType *base_type;
	public:
		def_node(std::string node_name, BaseType *base_type);
		void evaluate();
};

// Class for draw statement.
class draw_node : public line_node {
	protected:
		std::string node_name;
	public:
		draw_node(std::string node_name);
		void evaluate();
};

// Class for "allname EQU allname" statement.
class equ_sts_node : public line_node {
	protected:
		std::string left;
		std::string right;
	public:
		equ_sts_node(std::string _left, std::string _right);
		void evaluate();
};

// Class for expression statement.
// num is the return value of expressions.
class exp_node {
	public:
		int num;
		virtual int evaluate() = 0;
};

// Base class for operation statement.
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

// Class for "allname dot vara EQU number" statement.
class equ_stn_node : public line_node {
	protected:
		std::string left;
		std::string var_name;
		exp_node *right;
	public:
		equ_stn_node(std::string _left, std::string _var_name, exp_node *_right);
		void evaluate();
};

// Class for "allname dot colorstr EQU allname" statment.
class equ_cts_node : public line_node {
	protected:
		std::string left;
		std::string right;
	public:
		equ_cts_node(std::string _left, std::string _right);
		void evaluate();
};

// Class for lines in pixel.y.
class lines_node {
	public:
		std::list<line_node *> *cmdlines;

		lines_node(std::list<line_node *> *_lines);
		void evaluate();
};

// Class for while statement.
class while_node : public line_node {
	public:
		exp_node *left;
		lines_node *right;

		while_node(exp_node *_left, lines_node *_right);
		void evaluate();
};

// Class for if-else statement.
class if_else_node : public line_node {
	public:
		exp_node *left;
		lines_node *true_right;
		lines_node *false_right;

		if_else_node(exp_node *_left, lines_node *_tr, lines_node *_fr);
		void evaluate();
};

// Class for function definition.
// right is the contents of a function.
class def_func : public line_node {
	public:
		std::string func_name;
		std::vector<std::pair<std::string, std::string> > params;
		lines_node *right;
		def_func(std::string _name, 
			 std::vector<std::pair<std::string, std::string> > _params, 
			 lines_node *_right);
		void evaluate();
};

// Class for calling a function.
class call_node : public line_node {
		std::vector<std::string> params;
		call_node(std::string _name, std::vector<std::string> _params);
		void evaluate();
};

#endif /* __COMPILER_PIXEL_BACKEND__ */	
