// Program to sort USN 
#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,n;
	// Structure of student 
	struct stud
	{	int USN, sem;
		char name[30];
	}s[10],t;
	clrscr();
	// Retrieving info of students 
	printf("Enter the number of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("Enter details of Student %d\n", i+1);
		printf("USN: ");
		scanf("%d",&s[i].USN);
		printf("Name: ");
		scanf("%s",&s[i].name);
		printf("Sem: ");
		scanf("%d",&s[i].sem);
	}
	// Bubble sort with USN 
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	{ if(s[j].USN>s[j+1].USN)
		{	t=s[j];
			s[j]=s[j+1];
			s[j+1]=t;
		}
	}
	// Printing student info 
	printf("\nUSN\tSEM\tNAME\n");
	for(i=0;i<n;i++)
	{	printf("%d\t%d\t%s\n",s[i].USN,s[i].sem,s[i].name); }
	getch();
}
