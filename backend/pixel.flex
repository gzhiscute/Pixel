/*
* pixel.flex
* This is our team's lexer for Pixel Language
* Written by Li Qian and Guo ZiHan
* Part of the backend server
* 2015 Fall Semester -- Compiling Practice
*/
%option noyywrap

%{
#include <stdio.h>
#include "pixel.tab.h" /* tab.h contains the token number values produced by the parser */

%}

/* regular definitions */
delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
number  {digit}+
allname	({letter}|_)({digit}|{letter}|_)*  /* legal name must start with letter or underline */
cmt 	"#"[^#]*"#" 	/* we use #...comment...# as comment */

%%
{ws}	{/* no action and no return */}
{cmt}	{/* no action and no return */}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return TIMES;}
"/"	{return DIVIDE;}
"<" {return LT;}
">" {return GT;}
"<="	{return LE;}
">="	{return GE;}
"=="	{return EE;}
"=" 	{return EQU;}
"(" 	{return leftsma;}
")"	{return rightsma;}
"{"	{return leftbig;}
"}"	{return rightbig;}
","	{return comma;}
'\n'	{return newline;}
"||"	{return OR;}
&&	{return AND;}
int	{return INT;}
bool	{return BOOL;}
if	{return IF;}
else	{return ELSE;}
while	{return WHILE;}
true	{return TRUE;}
false	{return FALSE;}
line	{return LINE;}
point	{return POINT;}
circle	{return circle;}
rect	{return rect;}
color	{return color;}
draw	{return draw;}
func	{return func;}
call	{return call;}
tree	{return tree;}
"."		{return DOT;}
{number}	{yylval.num = atoi(yytext); return number;}
{allname}		{yylval.str = (char *)yytext; return allname;}

%%
