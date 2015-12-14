/* 
 * Project: utils.cpp
 * Author: Li Qian and Guo ZiHan
 * Data: 2015-12-10
 * Description:
 * This is our team's AST utils implemenetations for Pixel Language
 * Written by Li Qian and Guo ZiHan
 * Part of the backend server
 * 2015 Fall Semester -- Compiling Practice
 */

#ifndef __COMPILER_PIXEL_BACKEND__
	#include "utils.h"
#endif

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <time.h>

// ans: ans string which is transmitted to server.
// errors: error string which is transmitted to server.
// vars: varibles.
// funcs: functions.
// TreeBottomLength: the length between two bottom nodes of tree.
// DrawWidth: the width of display window.
// DrawHeight: the height of display window.
// TreeYLength: the height between two layers of tree.
std::string ans;
std::string errors;
std::map<std::string, BaseType *> vars;
std::map<std::string, def_func *> funcs;
int TreeBottomLength = 60;
int DrawWidth = 240;
int DrawHeight = 500;
int TreeYLength = 30;
extern int yylineno;

// Transfer strings (like "x", "int") to corresponding integer for switch
// statements.
int StringToInt(std::string s) {
	if (!s.compare("x"))
		return 0;
	else if (!s.compare("y"))
		return 1;
	else if (!s.compare("x1"))
		return 2;
	else if (!s.compare("y1"))
		return 3;
	else if (!s.compare("r"))
		return 4;
	else if (!s.compare("val"))
		return 5;
	else if (!s.compare("w"))
		return 6;
	else if (!s.compare("h"))
		return 7;
	else if (!s.compare("int"))
		return 8;
	else if (!s.compare("bool"))
		return 9;
	else if (!s.compare("point"))
		return 10;
	else if (!s.compare("line"))
		return 11;
	else if (!s.compare("circle"))
		return 12;
	else if (!s.compare("rect"))
		return 13;
	else if (!s.compare("tree"))
		return 14;
	else if (!s.compare("R"))
		return 15;
	else if (!s.compare("G"))
		return 16;
	else if (!s.compare("B"))
		return 17;
	return -1;
}

// Delete multiple definitions in vars.
void DeletMulDef(std::string node_name)
{
	std::map<std::string, BaseType *>::iterator p = vars.find(node_name);
	if (p != vars.end()) 
		vars.erase(p);
}

// Delete multiple definitions in funcs.
void DeletMulFunc(std::string node_name) {
	std::map<std::string, def_func *>::iterator p = funcs.find(node_name);
	if (p != funcs.end())
		funcs.erase(p);
}

void BaseType::SetBaseVars(const std::string& _type, char *_color) {
	type = _type;
	if (_color != NULL) cname = _color;
}

void BaseType::SetColor(int _r, int _g, int _b) {
	r = _r;
	g = _g;
	b = _b;
}

void BaseType::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 15 : r = right; break;
		case 16	: g = right; break;
		case 17 : b = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

iINT::iINT(const std::string& _type, int _val) {
	BaseType::SetBaseVars(_type, NULL);
	val = _val;
}

void iINT::drawsvg(int _pos) {
	char *tmp;
	tmp = (char*)calloc(256, sizeof(char));
	sprintf(tmp, "[ERROR] line %d: can't print a INT.\n", _pos);
	errors += tmp;
	free(tmp);
}

void iINT::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 5 : val = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos,
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

iBOOL::iBOOL(const std::string& _type, int _val) {
	BaseType::SetBaseVars(_type, NULL);
	val = _val;
}

void iBOOL::drawsvg(int _pos) {
	char *tmp;
	tmp = (char*)calloc(256, sizeof(char));
	sprintf(tmp, "[ERROR] line %d: can't print a BOOL.\n", _pos);
	errors += tmp;
	free(tmp);
}

void iBOOL::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 5 : val = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());	
			errors += tmp;
			free(tmp);
	}
}

iPOINT::iPOINT(const std::string& _type, int _x, int _y, char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y; 
}

void iPOINT::drawsvg(int _pos) {
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>", x, y, BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iPOINT::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

void iPOINT::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iPOINT::GetField(std::string var_name, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
				var_name.c_str());
			errors += tmp;
			free(tmp);
			return -1;
	}
}

iLINE::iLINE(const std::string& _type, int _x, int _y, int _x1, int _y1, 
		     char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	x1 = _x1;
	y1 = _y1;
}

void iLINE::drawsvg(int _pos) {
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp,"<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>", x, y, x1, y1, 
			BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iLINE::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 2 : x1 = right; break;
		case 3 : y1 = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

void iLINE::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iLINE::GetField(std::string var_name, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 2 : return this->x1;
		case 3 : return this->y1;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
			return -1;
	}
}

iCIRCLE::iCIRCLE(const std::string& _type, int _x, int _y, int _r, 
				 char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	r = _r;
}

void iCIRCLE::drawsvg(int _pos) {
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>",x, y, r, BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iCIRCLE::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 4 : r = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

void iCIRCLE::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iCIRCLE::GetField(std::string var_name, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 4 : return this->r;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
			return -1;
	}
}

iRECT::iRECT(const std::string& _type, int _x, int _y, int _w, int _h, 
	char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

void iRECT::drawsvg(int _pos) {
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>", x-w/2, y-h/2, w, h, BaseType::r, 
			BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iRECT::ChangeField(std::string var_name, int right, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 6 : w = right; break;
		case 7 : h = right; break;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
	}
}

void iRECT::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iRECT::GetField(std::string var_name, int _pos) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 6 : return this->w;
		case 7 : return this->h;
		default : 
			char *tmp;
			tmp = (char*)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: %s is invalid.\n", _pos, 
					var_name.c_str());
			errors += tmp;
			free(tmp);
			return -1;
	}
}

iTREE::iTREE(const std::string& _type, int _rt, int _tx, int _ty) {
	BaseType::type = _type;
	binroot = _rt;
	treex = _tx;
	treey = _ty;
}

bool iTREE::CalcDep(int p, int *Max, int dep, std::set<int> *vis, int _pos) {
	// Checks if p has been visited.
	std::set<int>::iterator vised = vis->find(p);
	if (vised != vis->end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: there is a circle in tree.\n", _pos);
		errors += tmp;
		free(tmp);
		return 0;
	}
	vis->insert(p);

	// Calcs the max depth.
	(*Max) = std::max((*Max), dep);
	// Finds p from input.
	std::map<int, std::pair<int, int> >::iterator node = nodes.find(p);
	if (node == nodes.end()) return 1;
	if (node->second.first) 
		if (!CalcDep(node->second.first, Max, dep+1, vis, _pos))
			return 0;
	if (node->second.second) 
		if (!CalcDep(node->second.second, Max, dep+1, vis, _pos))
			return 0;
	return 1;
}

void iTREE::DrawTree(int p, int x, int y, int dep, int _pos) {
	int xlength = 0;
	// Finds p from input.
	std::map<int, std::pair<int, int> >::iterator node = nodes.find(p);
	if (node != nodes.end()) {
		// Calcs x coordinate of node.
		if (node->second.first || node->second.second)
			xlength = TreeBottomLength*(1<<dep)/2;

		// Draws line which connects node and its left son.
		if (node->second.first) {
			BaseType *line1 = new iLINE("LINE", x, y, x-xlength, 
										y+TreeYLength, NULL);
			line1->SetColor(0, 0, 0);
			line1->drawsvg(_pos);
			DrawTree(node->second.first, x-xlength, y+TreeYLength, dep-1, 
					 _pos);
		}
		// Draws line which connects node and its right son.
		if (node->second.second) {
			BaseType *line2 = new iLINE("LINE", x, y, x+xlength, 
										y+TreeYLength, NULL);
			line2->SetColor(0, 0, 0);
			line2->drawsvg(_pos);
			DrawTree(node->second.second, x+xlength, y+TreeYLength, dep-1, 
					 _pos);
		}
	}

	// Creates a circle instance and draw node.
	BaseType *cir = new iCIRCLE("CIRCLE", x, y, TreeR, NULL);
	cir->SetColor(rand()%256, rand()%256, rand()%256);
	cir->drawsvg(_pos);
	// Prints node number.
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<text x=\"%d\" y=\"%d\" font-family=\"Times New Roman\" font-size=\"12\" fill=\"white\">%d</text>", x-4, y+4, p);
	ans += tmp;
	free(tmp);
}

void iTREE::drawsvg(int _pos) {
	std::set<int> vis;
	vis.clear();
	int Max = 0;
	if (!CalcDep(binroot, &Max, 0, &vis, _pos)) {
		return;
	}
	TreeBottomLength = DrawWidth / ((1<<Max));
	TreeYLength = (DrawHeight - treey) / Max - 10;
	DrawTree(binroot, TreeBottomLength*((1<<Max)-1)/2+treex, treey, Max-1, 
		     _pos);
}

def_node::def_node(int _pos, std::string _name, BaseType *_base_type) {
	pos = _pos;
	node_name = _name;
	base_type = _base_type;
}

void def_node::evaluate() {
	DeletMulDef(node_name);
	vars.insert(std::pair<std::string, BaseType *>(node_name, base_type));
}

def_func::def_func(int _pos, std::string _name, 
				   std::vector<std::pair<std::string, std::string> > _params,
				   lines_node *_right) {
	pos = _pos;
	func_name = _name;
	params.clear();
	for (std::vector<std::pair<std::string, std::string> >::iterator 
		 iter = _params.begin(); iter != _params.end(); ++iter) 
		params.push_back(*iter);
	right = _right;
}

void def_func::evaluate() {
	DeletMulFunc(func_name);
	funcs.insert(std::pair<std::string, def_func *>(func_name, this));
}

draw_node::draw_node(int _pos, std::string _name) {
	pos = _pos;
	node_name = _name;
}

void draw_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var;
	var = vars.find(node_name);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: can't draw %s, variable doesn't exist.\n", pos, node_name.c_str());
		errors += tmp;
		free(tmp);
		return;
	}

	if (var->second->cname != "") {
		std::map<std::string, BaseType *>::iterator _color;
		_color = vars.find(var->second->cname);
		if (_color == vars.end()) {
			char *tmp;
			tmp = (char *)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] lint %d: can't draw %s, color variable doesn't exist.\n", pos, node_name.c_str());
			errors += tmp;
			free(tmp);
			return;
		}
		var->second->SetColor(_color->second->r, _color->second->g,
				      		  _color->second->b);
	}
	var->second->drawsvg(pos);
}

equ_sts_node::equ_sts_node(int _pos, std::string _left, std::string _right) {
	pos = _pos;
	left = _left;
	right = _right;
}

void equ_sts_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(right);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: %s doesn't exist.\n", pos, 
				right.c_str());
		errors += tmp;
		free(tmp);
		return;
	}
	
	BaseType *p;
	switch (StringToInt(var->second->type)) {
		case 8 :
			p = new iINT("int", var->second->GetVal()); break;
		case 9 :
			p = new iBOOL("bool", var->second->GetVal()); break;
		case 10 :
			p = new iPOINT("point", var->second->GetX(), var->second->GetY(),
				       	   NULL);
			break;
		case 11 :
			p = new iLINE("line", var->second->GetX(), var->second->GetY(), 
				    	  var->second->GetX1(), var->second->GetY1(), NULL);
			break;
		case 12 :
			p = new iCIRCLE("circle", var->second->GetX(), 
							var->second->GetY(), var->second->GetR(), NULL);
			break;
		case 13 :
			p = new iRECT("rect", var->second->GetX(), var->second->GetY(), 
				      	  var->second->GetW(), var->second->GetH(), NULL);
			break;
		default : 
			char *tmp;
			tmp = (char *)calloc(256, sizeof(char));
			sprintf(tmp, "[ERROR] line %d: variable type is invalid.\n", pos);
			errors += tmp;
			free(tmp);
			return;
	}
	p->cname = var->second->cname;
	vars.insert(std::pair<std::string, BaseType *>(left, p));
}

equ_stn_node::equ_stn_node(int _pos, std::string _left, std::string _var_name,
			   			   exp_node *_right) {
	pos = _pos;
	left = _left;
	var_name = _var_name;
	right = _right;
}

void equ_stn_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] lint %d: %s doesn't exist.\n", pos, 
				left.c_str());
		errors += tmp;
		free(tmp);
		return;
	}
	int ret = right->evaluate();
	var->second->ChangeField(var_name, ret, pos);
}

equ_cts_node::equ_cts_node(int _pos, std::string _left, std::string _right) {
	pos = _pos;
	left = _left;
	right = _right;
}

void equ_cts_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: %s doesn't exist.\n", pos, 
				left.c_str());
		errors += tmp;
		free(tmp);
		return;
	}
	var->second->ChangeColor(right);
}

lines_node::lines_node(std::list<line_node *> *_lines) {
	cmdlines = _lines;
}

void lines_node::evaluate() {
	std::list<line_node *>::iterator lineIter;
	for (lineIter = cmdlines->begin(); lineIter != cmdlines->end(); 
		 lineIter++) {
		(*lineIter)->evaluate();
	}
}

operator_node::operator_node(int _pos, exp_node *L, exp_node *R) {
	pos = _pos;
	left = L;
	right = R;
}

field_node::field_node(int _pos, std::string _left, std::string _var_name) {
	pos = _pos;
	left = _left;
	var_name = _var_name;
}

int field_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: %s doesn't exist.\n", pos, 
				left.c_str());
		errors += tmp;
		free(tmp);
		return -1;
	}
	if (var->second->type == "int" || var->second->type == "bool")
		return var->second->GetVal();
	return var->second->GetField(var_name, pos);
}

number_node::number_node(int _pos, int _num) {
	pos = _pos;
	num = _num;
}

int number_node::evaluate() {
	return num;
}

int_node::int_node(int _pos, std::string _var_name) {
	pos = _pos;
	var_name = _var_name;
}

int int_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(var_name);
	if (var == vars.end()) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] lint %d: %s doesn't exist.\n", pos, 
				var_name.c_str());
		errors += tmp;
		free(tmp);
		return -1;
	}
	if ((var->second->type != "int") && (var->second->type != "bool")) {
		char *tmp;
		tmp = (char *)calloc(256, sizeof(char));
		sprintf(tmp, "[ERROR] line %d: %s is not an interger or a boolean.\n",
				pos, var_name.c_str());
		errors += tmp;
		free(tmp);
		return -1;
	}
	return var->second->GetVal();
}

plus_node::plus_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int plus_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum + rightnum;
	return num;
}

minus_node::minus_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int minus_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum - rightnum;
	return num;
}

times_node::times_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int times_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum * rightnum;
	return num;
}

divide_node::divide_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int divide_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	if (rightnum) {
		num = leftnum / rightnum;
		return num;		
	}
	else {
		printf("[ERROR] line %d: divide zero!\n", pos);
		return -1;
	}

	return num;
}

gt_node::gt_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int gt_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum > rightnum;
	return num;
}

ge_node::ge_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int ge_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum >= rightnum;
	return num;
}

lt_node::lt_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int lt_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum < rightnum;
	return num;
}

le_node::le_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L,R) {}

int le_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum <= rightnum;
	return num;
}

ee_node::ee_node(int _pos, exp_node *L, exp_node *R) 
	: operator_node(_pos, L, R) {}

int ee_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = (leftnum == rightnum);
	return num;
}

while_node::while_node(int _pos, exp_node *_left, lines_node *_right) {
	pos = _pos;
	left = _left;
	right = _right;
}

void while_node::evaluate() {
	std::map<std::string, BaseType *> before;
	before.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin();
	     varIter != vars.end(); ++varIter)
		before.insert(*varIter);
	
	while (left->evaluate()) 
		right->evaluate();
	
	std::map<std::string, BaseType *> after;
	after.clear();
	std::map<std::string, BaseType *>::iterator var;
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin(); 
	     varIter != vars.end(); ++varIter) {
		var = before.find(varIter->first);
		if (var != before.end())
			after.insert(*varIter);
	}
	vars.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = after.begin(); 
	     varIter != after.end(); ++varIter) 
		vars.insert(*varIter);
}

if_else_node::if_else_node(int _pos, exp_node *_left, lines_node *_tr, 
						   lines_node *_fr) {
	pos = _pos;
	left = _left;
	true_right = _tr;
	false_right = _fr;
}

void if_else_node::evaluate() {
	std::map<std::string, BaseType *> before;
	before.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin();
	     varIter != vars.end(); ++varIter)
		before.insert(*varIter);

	if (left->evaluate())
		true_right->evaluate();
	else
		false_right->evaluate();

	std::map<std::string, BaseType *> after;
	after.clear();
	std::map<std::string, BaseType *>::iterator var;
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin(); 
	     varIter != vars.end(); ++varIter) {
		var = before.find(varIter->first);
		if (var != before.end())
			after.insert(*varIter);
	}
	vars.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = after.begin(); 
	     varIter != after.end(); ++varIter) 
		vars.insert(*varIter);
}

call_node::call_node(int _pos, std::string _name, 
					 std::vector<std::string> _params) {
	pos = _pos;
	node_name = _name;
	params.clear();
	for (std::vector<std::string>::iterator iter = _params.begin(); 
	     iter != _params.end(); ++iter)
		params.push_back(*iter);
}

void call_node::evaluate() {
	std::map<std::string, def_func *>::iterator p = funcs.find(node_name);
	if (p == funcs.end()) return;
	def_func *func = p->second;

	if (func->params.size() != params.size()) return;
	for (int i = params.size()-1; i >= 0; --i) {
		std::map<std::string, BaseType *>::iterator btp = vars.find(params[i]);
		if (btp == vars.end()) return;
		if (func->params[i].first != btp->second->type) return;
	}

	std::map<std::string, BaseType *> before;
	before.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin(); 
	     varIter != vars.end(); ++varIter) 
		before.insert(*varIter);
	for (int i = params.size()-1; i >= 0; --i) {
		std::map<std::string, BaseType *>::iterator btp = vars.find(params[i]);
		vars.insert(std::pair<std::string, BaseType *>(func->params[i].second, 
							       					   btp->second));
	}

	std::map<std::string, def_func *> before_func;
	before_func.clear();
	for (std::map<std::string, def_func *>::iterator funcIter = funcs.begin(); 
	     funcIter != funcs.end(); ++funcIter) 
		before_func.insert(*funcIter);

	func->right->evaluate();

	std::map<std::string, BaseType *> after;
	after.clear();
	std::map<std::string, BaseType *>::iterator var;
	for (std::map<std::string, BaseType *>::iterator varIter = vars.begin(); 
	     varIter != vars.end(); ++varIter) {
		var = before.find(varIter->first);
		if (var != before.end())
			after.insert(*varIter);			
	}
	vars.clear();
	for (std::map<std::string, BaseType *>::iterator varIter = after.begin(); 
	     varIter != after.end(); ++varIter)
		vars.insert(*varIter);

	std::map<std::string, def_func *> after_func;
	after_func.clear();
	std::map<std::string, def_func *>::iterator funcvar;
	for (std::map<std::string, def_func *>::iterator funcIter = funcs.begin(); 
	     funcIter != funcs.end(); ++funcIter) {
		funcvar = before_func.find(funcIter->first);
		if (funcvar != before_func.end())
			after_func.insert(*funcIter);			
	}
	funcs.clear();
	for (std::map<std::string, def_func *>::iterator funcIter = after_func.begin(); 
	     funcIter != after_func.end(); ++funcIter)
		funcs.insert(*funcIter);
}
