#include<stdio.h>
#define size 50

int rear=-1,queue[size];
int main()
{
	void insert(int);
	int delete();
	void displayQueue();
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
				insert(n);
				break;
			case 2:
				if((n=delete())!=-1)
					printf("The element %d is popped out",n);
                    printf("\n");
				break;	
			case 3:
				displayQueue();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Wrong choice");		
						
		}
	}
}
void insert(int e)
{
	if(rear==size-1)
	{
		printf("The queue is full\n");
		return;
	}
	queue[++rear]=e;
}    
int delete()
{
    int e,i;
	if(rear==-1)
	{
		printf("The queue is empty\n");
		return -1;
	}
	e=queue[0];
    for(i=0;i<rear;i++)
    {
        queue[i]=queue[i+1];
    }
    rear--;
    return e;        
}
void displayQueue()
{
	int i;
	if(rear==-1)
	{
		printf("The queue is empty\n");
		return;
	}
	for(i=0;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
		
}
