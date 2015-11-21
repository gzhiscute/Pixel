#include "utils.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

void DeletMulDef(std::string node_name)
{
	std::map<std::string, BaseType *>::iterator p = vars.find(node_name);
	if (p != vars.end()) 
		vars.erase(p);
}

void BaseType::SetColor(int _r, int _g, int _b) {
	r = _r;
	g = _g;
	b = _b;
}

iINT::iINT(const std::string& _type, int _val) {
	BaseType::type = _type;
	val = _val;
}


iBOOL::iBOOL(const std::string& _type, int _val) {
	BaseType::type = _type;
	val = _val;
}

iPOINT::iPOINT(const std::string& _type, int _x, int _y, char *_color) {
	BaseType::type = _type;
	BaseType::cname = _color;
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

iLINE::iLINE(const std::string& _type, int _x, int _y, int _x1, int _y1, char *_color) {
	BaseType::type = _type;
	BaseType::cname = _color;
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

iCIRCLE::iCIRCLE(const std::string& _type, int _x, int _y, int _r, char *_color) {
	BaseType::type = _type;
	BaseType::cname = _color;
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

iRECT::iRECT(const std::string& _type, int _x, int _y, int _w, int _h, char *_color) {
	BaseType::type = _type;
	BaseType::cname = _color;
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
	std::map<std::string, BaseType *>::iterator var;
	var = vars.find(node_name);
	if (var == vars.end()) {
		//printf("Can't draw %s: variable doesn't exist.\n", name);
		return;
	}

	std::map<std::string, BaseType *>::iterator _color;
	_color = vars.find(var->second->cname);
	if (_color == vars.end()) {
		//std::cout << "Can't find color variable " << var->second->color << "." << std::endl;
		return;
	}
	var->second->SetColor(_color->second->r, _color->second->g, _color->second->b);
	var->second->drawsvg();
}

lines_node::lines_node(std::list<line_node *> *_lines) {
	cmdlines = _lines;
}

void lines_node::evaluate() {
	std::list<line_node *>::iterator lineIter;
	for (lineIter = cmdlines->begin(); lineIter != cmdlines->end(); lineIter++) {
		(*lineIter)->evaluate();
	}
}
