/* Program to recognize the grammar (anb, n>=10).
*/
%{
#include”y.tab.h”
%}
%%
a  return  A;
b  return  B;
\n return yytext[0];
•  return yytext[0];
%%
