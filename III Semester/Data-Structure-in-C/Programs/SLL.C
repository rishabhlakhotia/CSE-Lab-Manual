#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
	{int data;
	 struct node *link;
	};
typedef struct node * NODE;
NODE first = NULL;

void insert_beg()
	{NODE temp;
	 temp = (NODE)malloc(sizeof(NODE));
	 printf("Enter the Element: ");
	 scanf("%d",&temp->data);
	 temp->link=NULL;
	 if(first==NULL)
		{first=temp;
		return;
		}
	 temp->link=first;
	 first=temp;
	}
void insert_end()
	{NODE cur,temp;
	temp = (NODE)malloc(sizeof(NODE));
	printf("Enter the element: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(first==NULL)
		{first=temp;
		return;
		}
	cur = first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	}

void display()
	{NODE cur;
	 if(first==NULL)
		{printf("List is Empty\n");
		return;
		}
	 printf("\nList Elements are: \n");
	 cur=first;
	 while(cur!=NULL)
		{printf("%d\t",cur->data);
		cur=cur->link;
		}
	 }

void main()
	{int ch;
	 clrscr();
	 for(;;)
		{printf("\n1: Insert Begining\t2: Insert End\t3: Display\tElse: Exit\n");
		 scanf("%d", &ch);
		 switch(ch)
			{case 1: insert_beg(); break;
			 case 2: insert_end(); break;
			 case 3: display(); break;
			 default: exit(0);
			}
		}
	}