#include<stdio.h>
#define size 10
int a[size];
int main()
{
	void display();
	int inputElement();
	int linearSearch(int);
	void selectionSort();
	int binarySearch(int);
	int i,e,m,f,n;
	printf("Enter the array elements ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	display();
	e=inputElement();
	if((m=linearSearch(e))!=-1)
		printf("\nElement found at index %d",m);
	else
		printf("\nElement not found ");	
	selectionSort();
	display();	
	f=inputElement();
	if((n=binarySearch(f))!=-1)
		printf("\nElement found at index %d",n);
	else
		printf("\nElement not found ");
	return 0;	
}
void display()
{
	printf("\n");
	int j;
	for(j=0;j<size;j++) 
		printf("%d ",a[j]);
}
int inputElement()
{
	int k;
	printf("\nEnter an element to be searched ");
	scanf("%d",&k);
	return k;
}
int linearSearch(int element)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==element)
			return i;
	}
	return -1;
}
void selectionSort()
{
	int i,j,t;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int binarySearch(int element)
{
	int l=0,h=size-1,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(element==a[mid])
			return mid;
		if(element<a[mid])
			h=mid-1;
		else
			l=mid+1;		
	}
	return -1;
}
