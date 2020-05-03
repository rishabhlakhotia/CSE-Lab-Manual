/* 1 A) Program to count the number of characters, words, spaces and lines
from a given input file.
*/
{ 
#include<stdio.h> 
int wc=0, cc=0, lc=0, bc=0; 
char infile[25]; 
%} 
 
word [^” “\t\n0-9]+ 
eol [\n] 
spc [^a-zA-Z0-9” “\t\n]+ 
 
%% 
{spc}   {cc+=yyleng;} 
{word}  {wc++;cc+=yyleng;} 
{eol}   {lc++;cc++;} 
[“ “]   {bc++;cc++;} 
[\t]    {bc+=8;cc++;} 
•       {cc++;} 
%% 
int yywrap(void) 
{ 
} 
int main() 
{ 
        printf("\nRead the input file\n"); 
        scanf("%s",infile); 
        yyin=fopen(infile,"r"); 
        yylex(); 
        fclose(yyin); 
        printf("Number of characters =%d\n",cc); 
        printf("Number of words = %d\n",wc); 
        printf("Number of spaces = %d\n",bc); 
        printf("Number of lines = %d\n",lc); 
return 0; 
} 

/*
How to run above program
$   lex 1a.l            //=> generates lex.yy.c file
$   cc lex.yy.c           //=> generates y.tab.c and y.tab.h(file of token definitions)
$   ./a.out 
Input: 
$. /a.out 
Enter the file name
ABC.txt
Output: 
Number of characters=56
Number of words=9
Number of spaces=8
Number of lines=1
*/