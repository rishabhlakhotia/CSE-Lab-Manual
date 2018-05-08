#include<stdio.h>
#include<conio.h>
int partition(int a[],int start,int end)
{
	int i,temp;
	int pivot=a[end];
	int pindex=start;
	for(i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[pindex];
	a[pindex]=a[end];
	a[end]=temp;
	return pindex;
}
void quicksort(int a[],int start,int end)
{
	if(start<end)
	{
		int pi=partition(a,start,end);
		quicksort(a,start,pi-1);
		quicksort(a,pi+1,end);
	}
}
void main()
{
	int i,start,end,n,a[50];
	clrscr();
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	start=0;
	end=n-1;
	quicksort(a,start,end);
	printf("Array after sorting::\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
getch();
}
