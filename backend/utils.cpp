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
		case 5 : val = right;
		default : return;
	}
}

iBOOL::iBOOL(const std::string& _type, int _val) {
	BaseType::SetBaseVars(_type, NULL);
	val = _val;
}

void iBOOL::ChangeField(std::string var_name, int right) {
	switch (StringToInt(var_name)) {
		case 5 : val = right;
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
		case 0 : x = right;
		case 1 : y = right;
		default : return;
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
		case 0 : x = right;
		case 1 : y = right;
		case 2 : x1 = right;
		case 3 : y1 = right;
		default : return;
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
		case 0 : x = right;
		case 1 : y = right;
		case 4 : r = right;
		default : return;
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
		case 0 : x = right;
		case 1 : y = right;
		case 6 : w = right;
		case 7 : h = right;
		default : return;
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
	if (node == nodes.end()) return;
	
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
			p = new iINT(*(var->second));
		case 9 :
			p = new iBOOL(*(var->second));
		case 10 :
			p = new iPOINT(*(var->second));
		case 11 :
			p = new iLINE(*(var->second));
		case 12 :
			p = new iCIRCLE(*(var->second));
		case 13 :
			p = new iRECT(*(var->second));
		case 14 :
			p = new iTREE(*(var->second));
		default : return;
	}
	vars.insert(std::pair<std::string, BaseType *>(left, p));
}

equ_stn_node::equ_stn_node(std::string _left, std::string _var_name, int _right) {
	left = _left;
	var_name = _var_name;
	right = _right;
}

void equ_stn_node::evaluate() {
	std::map<std::string, BaseType *>::iterator var = vars.find(left);
	if (var == vars.end()) return;

	var->second->ChangeField(var_name, right);
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
