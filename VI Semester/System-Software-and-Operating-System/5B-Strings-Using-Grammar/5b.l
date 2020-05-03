/* Program to recognize strings aaab,abbb,ab and a using the grammar (anbn,n>=0).
*/
%{
#include”y.tab.h”
%}
%%
a  return  A;
b  return  B;
\n return yytext[0];
•  returnyytext[0];
%%
/*
Grammar:  for a^n b^n     n >= 0
S -> a S b | Epsilon

For a^m b^n      n, m >= 0
S -> a S b | aS | Sb | Epsilon | a | b

*/
