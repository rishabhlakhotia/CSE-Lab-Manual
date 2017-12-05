#include<stdio.h>
#define size 5
void qinsert(int,int*,int[]);
void qdelete(int*,int*,int[]);
void qdisplay(int,int,int[]);
void main()
{ 	int q[size],item,ch,front=0,rear=-1;
	clrscr();
	while(1)
		{printf("\n1: Insert\t2: Delete\t3: Display\tElse: Exit\n");
		scanf("%d",&ch);
		switch(ch)
			{ case 1: printf("Enter Element: ");
				  scanf("%d",&item);
				  qinsert(item,&rear,q); break;
			  case 2: qdelete(&front,&rear,q); break;
			  case 3: qdisplay(front,rear,q); break;
			  default:printf("Invalid Operation");
				  getch();
				  exit(0);
			}
		}
	}
void qinsert(int item, int *rear, int q[])
	{ if(*rear==size-1)
		printf("Queue is full\n");
	  else {
			*rear = *rear + 1;
	     q[*rear] = item;
		}
	}
void qdelete(int *front, int *rear, int q[])
	{ if(*front>*rear)
		printf("Queue is empty\n");
	  else
		{printf("The Deleted element is %d",q[*front]);
	       *front = &front + 1;
		}
	}
void qdisplay(int front, int rear, int q[])
	{int i;
	if(front>rear)
		printf("Queue is empty");
	else
		{for(i=front; i<=rear; i++)
			printf("Queue[%d] = %d\n",i,q[i]);
		}
	}
