/*This pixel.flex -- the lexer*/
%option noyywrap

%{
#include <stdio.h>
#include "pixel.h"

%}

/* regular definitions */
delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
number  {digit}+
name	({letter}|_)({digit}|{letter}|_)*

%%
{ws}	{/* no action and no return */}
= 	{return EQU;}
"(" 	{return leftsma;}
")"	{return rightsma;}
{	{return leftbig;}
}	{return rightbig;}
,	{return comma;}
'\n'	{return newline;}
"||"	{return OR;}
&&	{return AND;}
int	{return INT;}
bool	{return BOOL;}
if	{return IF;}
else	{return ELSE;}
while	{return WHILE;}
continue	{return CONTINUE;}
break	{return BREAK;}
true	{return TRUE;}
false	{return FALSE;}
line	{return LINE;}
point	{return POINT;}
circle	{return circle;}
rect	{return rect;}
color	{return color;}
text	{return text;}
draw	{return draw;}
DELETE	{return DELETE;}
func	{return func;}
call	{return call;}
{number}	{yylval = atoi(yytext); return number;}
{name}		{yylval = (int)yytext; return name;}

%%
