#include<stdio.h>
#include<conio.h>
void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low,c[100];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=mid)
		c[k++]=a[i++];
	while(j<=high)
		c[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=c[i];
}

void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
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
	mergesort(a,start,end);
	printf("Array after sorting::\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
getch();
}
