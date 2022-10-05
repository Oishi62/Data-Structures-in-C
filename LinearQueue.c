#include<stdio.h>
#define SIZE 5

int front=-1,rear=-1,queue[SIZE];
int main()
{
	void insert();
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
				insert();
				break;
			case 2:
				if((n=delete())!=-1)
					printf("The element %d is popped out",n);
                    printf("\n");
				break;	
			case 3:
				displayQueue();
				printf("\n");
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Wrong choice");		
						
		}
	}	
}
void insert()
{
	int n;
	
	if(rear==SIZE-1)
	{
		printf("The queue is full\n");
		return;
	}
	printf("Enter the element you want to add ");
	scanf("%d",&n);
	queue[++rear]=n;
    if(front==-1)
        front=0;
}
int delete()
{
    int e;
	if(front==-1)
	{
		printf("The queue is empty\n");
		return -1;
	}
	e=queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
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
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
		
}
