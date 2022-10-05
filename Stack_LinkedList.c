# include<stdio.h>
# include<stdlib.h>
typedef struct List
{
    int key;
    struct List *next;
}Node;

Node *top=NULL;
void push(int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->next=top;
    top=x;
}
int pop()
{
    Node *x=top;
    if(top==NULL)
    {
        printf("Stack Underflow");
        return -1;
    }
    int k=x->key;
    top=top->next;
    x->next=NULL;
    free(x);
    return k;
}
void display()
{
    printf("\nCreated linked list is \n");
    Node *x=top;
    if(top == NULL)
    {
        printf("List is empty");
        return;
    }
    while(x!=NULL)
    {
        printf("%d\n",x->key);
        x=x->next;
    }
}
int main()
{
	int c,flag=1,n;
	while(flag)
	{
		printf("\nPress 1 for adding elements\nPress 2 for deleting elements\nPress 3 for displaying the elements\nPress 4 to exit ");
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
				display();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Wrong choice");		
						
		}
	}
}