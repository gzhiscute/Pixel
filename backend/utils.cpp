#ifndef __COMPILER_PIXEL_BACKEND__
	#include "utils.h"
#endif

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <time.h>

std::string ans;
std::map<std::string, BaseType *> vars;

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
	return -1;
}

void DeletMulDef(std::string node_name)
{
	std::map<std::string, BaseType *>::iterator p = vars.find(node_name);
	if (p != vars.end()) 
		vars.erase(p);
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

iINT::iINT(const std::string& _type, int _val) {
	BaseType::SetBaseVars(_type, NULL);
	val = _val;
}

void iINT::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 5 : val = right; break;
		default : return;
	}
}

iBOOL::iBOOL(const std::string& _type, int _val) {
	BaseType::SetBaseVars(_type, NULL);
	val = _val;
}

void iBOOL::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 5 : val = right; break;
		default : return;
	}
}

iPOINT::iPOINT(const std::string& _type, int _x, int _y, char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y; 
}

void iPOINT::drawsvg() {
	//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, x, y, BaseType::r, BaseType::g, BaseType::b);
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"2\" style=\"fill:rgb(%d,%d,%d)\"/>", x, y, BaseType::r, BaseType::g, BaseType::b);	
	ans += tmp;
	free(tmp);
}

void iPOINT::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		default : return;
	}
}

void iPOINT::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iPOINT::GetField(std::string var_name) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		default : printf("invalid field!\n");
				return -1;
	}
}

iLINE::iLINE(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	x1 = _x1;
	y1 = _y1;
}

void iLINE::drawsvg() {
	//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>\n</svg>\n", x, y, x1, y1, BaseType::r, BaseType::g, BaseType::b);
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(%d,%d,%d);stroke-width:2\"/>", x, y, x1, y1, BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iLINE::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 2 : x1 = right; break;
		case 3 : y1 = right; break;
		default : return;
	}
}

void iLINE::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iLINE::GetField(std::string var_name) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 2 : return this->x1;
		case 3 : return this->y1;
		default : printf("invalid field!\n");
				return -1;
	}
}

iCIRCLE::iCIRCLE(const std::string& _type, int _x, int _y, int _r, char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	r = _r;
}

void iCIRCLE::drawsvg() {
	//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x, y, r, BaseType::r, BaseType::g, BaseType::b);
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>", x, y, r, BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iCIRCLE::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 4 : r = right; break;
		default : return;
	}
}
void iCIRCLE::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iCIRCLE::GetField(std::string var_name) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 4 : return this->r;
		default : printf("invalid field!\n");
				return -1;
	}
}

iRECT::iRECT(const std::string& _type, int _x, int _y, int _w, int _h, char *_color) {
	BaseType::SetBaseVars(_type, _color);
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

void iRECT::drawsvg() {
	//printf("<?xml version=\"1.0\" standalone=\"yes\"?>\n<svg width=\"100%%\" height=\"100%%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>\n</svg>\n", x/2, y/2, w, h, BaseType::r, BaseType::g, BaseType::b);
	char *tmp;
	tmp = (char *)calloc(256, sizeof(char));
	sprintf(tmp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d)\"/>", (x-w)/2, (y-h)/2, w, h, BaseType::r, BaseType::g, BaseType::b);
	ans += tmp;
	free(tmp);
}

void iRECT::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 0 : x = right; break;
		case 1 : y = right; break;
		case 6 : w = right; break;
		case 7 : h = right; break;
		default : return;
	}
}

void iRECT::ChangeColor(std::string colorstr) {
	this->cname = colorstr;
}

int iRECT::GetField(std::string var_name) {
	switch (StringToInt(var_name)) {
		case 0 : return this->x;
		case 1 : return this->y;
		case 6 : return this->w;
		case 7 : return this->h;
		default : printf("invalid field!\n");
				return -1;
	}
}

iTREE::iTREE(const std::string& _type, int _rt) {
	BaseType::type = _type;
	binroot = _rt;
//	printf("create a tree! root: 0x%x\n", binroot);
}

bool iTREE::CalcDep(int p, int *Max, int dep, std::set<int> *vis) {
	std::set<int>::iterator vised = vis->find(p);
	if (vised != vis->end()) return 0;
	vis->insert(p);

	(*Max) = std::max((*Max), dep);
	std::map<int, std::pair<int, int> >::iterator node = nodes.find(p);
	if (node == nodes.end()) return 1;
	if (node->second.first) 
		if (!CalcDep(node->second.first, Max, dep+1, vis))
			return 0;
	if (node->second.second) 
		if (!CalcDep(node->second.second, Max, dep+1, vis))
			return 0;
	return 1;
}

void iTREE::DrawTree(int p, int x, int y, int dep) {
	
	int xlength = 0;
	std::map<int, std::pair<int, int> >::iterator node = nodes.find(p);
	if (node != nodes.end()) {
		if (node->second.first || node->second.second)
			xlength = TreeBottomLength*(1<<dep)/2;

		if (node->second.first) {
			BaseType *line1 = new iLINE("LINE", x, y, x-xlength, y+TreeYLength, NULL);
			line1->SetColor(0, 0, 0);
			line1->drawsvg();
			DrawTree(node->second.first, x-xlength, y+TreeYLength, dep-1);
		}
		if (node->second.second) {
			BaseType *line2 = new iLINE("LINE", x, y, x+xlength, y+TreeYLength, NULL);
			line2->SetColor(0, 0, 0);
			line2->drawsvg();
			DrawTree(node->second.second, x+xlength, y+TreeYLength, dep-1);
		}
	}

	BaseType *cir = new iCIRCLE("CIRCLE", x, y, TreeR, NULL);
	cir->SetColor(rand()%256, rand()%256, rand()%256);
	cir->drawsvg();
}

void iTREE::drawsvg() {
	std::set<int> vis;
	vis.clear();
	int Max = 0;
	if (!CalcDep(binroot, &Max, 0, &vis)) {
		return;
	}
	DrawTree(binroot, TreeBottomLength*((1<<Max)-1)/2+2*TreeR, 2*TreeR, Max-1);
}

def_node::def_node(std::string _name, BaseType *_base_type) {
	node_name = _name;
	base_type = _base_type;
}

void def_node::evaluate() {
	DeletMulDef(node_name);
	vars.insert(std::pair<std::string, BaseType *>(node_name, base_type));
}

draw_node::draw_node(std::string _name) {
	node_name = _name;
}

void draw_node::evaluate() {
	printf("In draw_node\n");

	std::map<std::string, BaseType *>::iterator var;
	var = vars.find(node_name);
	if (var == vars.end()) {
		//printf("Can't draw %s: variable doesn't exist.\n", name);
		return;
	}

	if (var->second->cname != "") {
		std::map<std::string, BaseType *>::iterator _color;
		_color = vars.find(var->second->cname);
		if (_color == vars.end()) {
			//std::cout << "Can't find color variable " << var->second->color << "." << std::endl;
			return;
		}
		var->second->SetColor(_color->second->r, _color->second->g, _color->second->b);
	}
	var->second->drawsvg();
}

equ_sts_node::equ_sts_node(std::string _left, std::string _right) {
	left = _left;
	right = _right;
}

void equ_sts_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(right);
	if (var == vars.end()) return;
	
	BaseType *p;
	switch (StringToInt(var->second->type)) {
		case 8 :
			p = new iINT("int", var->second->GetVal()); break;
		case 9 :
			p = new iBOOL("bool", var->second->GetVal()); break;
		case 10 :
			p = new iPOINT("point", var->second->GetX(), var->second->GetY(), NULL);
			break;
		case 11 :
			p = new iLINE("line", var->second->GetX(), var->second->GetY(), var->second->GetX1(), var->second->GetY1(), NULL);
			break;
		case 12 :
			p = new iCIRCLE("circle", var->second->GetX(), var->second->GetY(), var->second->GetR(), NULL);
			break;
		case 13 :
			p = new iRECT("rect", var->second->GetX(), var->second->GetY(), var->second->GetW(), var->second->GetH(), NULL);
			break;
		default : return;
	}
	p->cname = var->second->cname;
	vars.insert(std::pair<std::string, BaseType *>(left, p));
}

equ_stn_node::equ_stn_node(std::string _left, std::string _var_name, exp_node *_right) {
	left = _left;
	var_name = _var_name;
	right = _right;
}

void equ_stn_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) return;
	int ret = right->evaluate();
	var->second->ChangeField(var_name, ret);
}

equ_cts_node::equ_cts_node(std::string _left, std::string _right) {
	left = _left;
	right = _right;
}

void equ_cts_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) return;
	var->second->ChangeColor(right);
}

lines_node::lines_node(std::list<line_node *> *_lines) {
	cmdlines = _lines;
}

void lines_node::evaluate() {
	std::list<line_node *>::iterator lineIter;
	for (lineIter = cmdlines->begin(); lineIter != cmdlines->end(); lineIter++) {
		(*lineIter)->evaluate();
		printf("~~%s\n", ans.c_str());
	}
}

operator_node::operator_node(exp_node *L, exp_node *R) {
	left = L;
	right = R;
}

field_node::field_node(std::string _left, std::string _var_name) {
	left = _left;
	var_name = _var_name;
}

int field_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) {
		printf("no such name\n");
		return -1;
	}
	return var->second->GetField(var_name);
}

number_node::number_node(int _num) {
	num = _num;
}

int number_node::evaluate() {
	return num;
}

int_node::int_node(std::string _var_name) {
	var_name = _var_name;
}

int int_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(var_name);
	if (var == vars.end()) {
		printf("no such name\n");
		return -1;
	}
	if (var->second->type != "int") {
		printf("invalid name\n");
		return -1;
	}
	return var->second->GetVal();
}

plus_node::plus_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

int plus_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum + rightnum;
	return num;
}

minus_node::minus_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

int minus_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum - rightnum;
	return num;
}

times_node::times_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

int times_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	num = leftnum * rightnum;
	return num;
}

divide_node::divide_node(exp_node *L, exp_node *R) : operator_node(L,R) {}

int divide_node::evaluate() {
	int leftnum, rightnum;
	leftnum = left->evaluate();
	rightnum = right->evaluate();
	if (rightnum) {
		num = leftnum / rightnum;
		return num;		
	}
	else {
		printf("divide zero!\n");
		return -1;
	}

	return num;
}
