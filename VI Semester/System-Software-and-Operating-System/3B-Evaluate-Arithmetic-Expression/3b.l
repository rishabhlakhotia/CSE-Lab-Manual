/* Program to evaluate an arithmetic expression involving operators +,-,*,/
*/
%{
#include”y.tab.h”
#include<stdlib.h”
%}
%%
[0-9]+	{yylval=atoi(yytext);return NUM;}
[\t]	;
\n	return 0;
• 	return yytext[0];
%%
