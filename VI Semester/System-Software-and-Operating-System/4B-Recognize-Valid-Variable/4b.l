/* Program to recognize a valid variable,
which starts with a letter, followed by any number of letters or digits.
*/
%{
#include ”y.tab.h”
%}
%%
[a-z]	return L;
[0-9] 	return D;
%%
