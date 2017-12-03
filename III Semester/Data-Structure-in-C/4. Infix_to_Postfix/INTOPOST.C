/* Program to convert the given infix expression to a postfix expression */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

char stack[50];
int top = -1;

void push (char x) {
    stack[++top] = x;
}

int pop() {
    return (stack[top--]);
}


/* Function assigns priority to each Symbol encountered, with 2 being lowest and 4 being highest, 
 * 1 is a special case for parenthesis
 */
int prior (char x) {
    int p;
    if (x == '(' || x == '#') p = 1;
    if (x == '+' || x == '-') p = 2;
    if (x == '*' || x == '/') p = 3;
    if (x == '^' || x == '$') p = 4;
    return p;
}

void main () {
    char infix[20], postfix[20];
    int i, j=0, l;
    clrscr();
    /* Getting the infix expression */
    printf("Enter the infix expression: ");
    gets(infix);
    push ('#');
    /* Convert to postfix */
    l = strlen(infix);
    for (i=0; i<l; i++) {
        /* if numbers/characters are encountered, directly add them to the postfix */
	if (isalnum(infix[i]))
	    postfix[j++] = infix[i];
	/* if opening parenthesis is encountered, push it into the stack */
	else if (infix[i] == '(')
	    push(infix[i]);
	/* if closing parenthesis is encountered, pop all elements in the stack into the postfix
	 * till the opening parenthesis is not found and popped  */
	else if (infix[i] == ')') {
	    while (stack[top] != '(')
		postfix[j++] = pop();
	    pop();
	}
	/* if operators are encountered, check the priority, keep 
	 * popping if the priority of the top element of the stack 
	 * is greater than the priority of the current operator and 
	 * then push the operator into the stack */
	else {
	    while (prior(stack[top]) >= prior(infix[i]))
		postfix[j++] = pop();
	    push(infix[i]);
	}
    }
    /*Final step, Keep popping till you see your little marker that we used i.e the # sign!  */
    while (stack[top]!='#')
	postfix[j++] = pop();
    postfix[j] = '\0';
    /*You now have your postfix expression and can now print it */
    printf("\nPostfix expression is: ");
    puts(postfix);
    getch();
}
