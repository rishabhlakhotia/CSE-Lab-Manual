#include<stdio.h>
#include<conio.h>
#include<math.h>

int stack[20],top=-1;

void push(int x)
{stack[++top]=x;}

int pop()
{return stack[top--];}

void main()
{       char s[20];
	int x,y,i;
	clrscr();
	printf("Enter the postfix Expression\n");
	gets(s);
	for(i=0;i<strlen(s); i++)
	{	if(isdigit(s[i]))
			push(s[i]-'0');
		else
		{	y=pop();
			x=pop();
			switch(s[i])
			{	case '+': push(x+y); break;
				case '-': push(x-y); break;
				case '*': push(x*y); break;
				case '/': push(x/y); break;
				case '$': push(pow(x,y)); break;
				default: printf("Illegal Operator");
			}
		}
	}
	printf("\nResult: %d",pop());
	getch();
}