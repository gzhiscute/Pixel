/*This pixel.flex -- the lexer*/
%option noyywrap

%{
#include <stdio.h>
#include "pixel.tab.h"

%}

/* regular definitions */
delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
number  {digit}+
cname	RED|GREEN|BLUE|YELLOW
name	({letter}|_)({digit}|{letter}|_)*

%%
{ws}	{/* no action and no return */}
int		{return INT;}
bool	{return BOOL;}
if		{return IF;}
else	{return ELSE;}
while	{return WHILE;}
continue	{return CONTINUE;}
break	{return BREAK;}
true	{return TRUE;}
false	{return FALSE;}
point	{return point;}
circle	{return circle;}
rect	{return rect;}
color	{return color;}
text	{return text;}
draw	{return draw;}
delete	{return delete;}
func	{return func;}
call	{return call;}
{number}	{yylval = atoi(yytext); printf("%d\n", number);}
{cname}		{yylval = (int)yytext; return cname;}
{name}		{yylval = (int)yytext; return name;}

%%
