#include<stdio.h>
#define size 50

int top=-1,stack[size];
int main()
{
	void push(int);
	int pop();
	void displayStack();
	int c,flag=1,n;
	while(flag)
	{
		printf("Press 1 for adding elements\nPress 2 for deleting elements\nPress 3 for displaying the elements\nPress 4 to exit ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: 
			
				printf("Enter the element you want to add ");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				if((n=pop())!=-1)
					printf("The element %d is popped out",n);
				break;	
			case 3:
				displayStack();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Wrong choice");		
						
		}
	}
}
void push(int e)
{
	if(top==size-1)
	{
		printf("The stack is full\n");
		return;
	}
	else
		stack[++top]=e;
}
int pop()
{
	if(top==-1)
	{
		printf("The stack is empty\n");
		return -1;
	}
	else
		return stack[top--];
}
void displayStack()
{
	int i;
	if(top==-1)
	{
		printf("The stack is empty\n");
		return;
	}
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
		
}
