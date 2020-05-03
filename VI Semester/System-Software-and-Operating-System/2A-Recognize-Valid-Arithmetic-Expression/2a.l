/*
2A) Lex program to recognize a valid arithmetic expression and to recognize
identifiers and operators present and print them separately.
*/
%{
int a[]={0,0,0,0},valid=1,opnd=0,top=-1,i;
%}
%x oper
%%
(“(“[a-zA-Z0-9]+)+	{BEGIN oper;opnd++;}
<oper>”+”		{if(valid) {valid=0;i=0;} else ext();}
<oper>”-”		{if(valid) {valid=0;i=1;} else ext();}
<oper>”*”		{if(valid) {valid=0;i=2;} else ext();}
<oper>”/”		{if(valid) {valid=0;i=3;} else ext();}
<oper>”(“		{top++;}
<oper>”)”		{top--;}
<oper>[a-zA-Z0-9]+	{opnd++;if(valid==0) {valid=1;a[i]++;} else ext();}
<oper>”\n”		{if(valid==1&&top==-1) {printf(“\nValid expression\n”); return 0;} else ext(); }
•\n			ext();
%%
ext()
{
	printf(“\nInvalid expression\n”);
	exit(0);
}
main()
{
	printf(“\nEnteran arithmetic expression\n”);
	yylex();
	printf(“\nNumber of operands = %d\n”,opnd);
	printf(“\nNumber of + = %d\n
		Number of - = %d\n
		Number of * = %d\n
		Number of / = %d\n”,a[0],a[1],a[2],a[3]);
}
/*
}
How to run above program
$   lex 2a.l
$   cc lex.yy.c
$   ./a.out
Input & Output:
Enter an arithmetic expression
a+b*c/d
^d
Valid expression
Operands are:
 a      b    c     d
operators are:
+      *    /     
$ ./a.out
Enter an arithmetic expression
a++b**
^d
 Invalid expression
*/