# include<stdio.h>
# include<stdlib.h>
typedef struct List
{
    int key;
    struct List *next;
}Node;

Node *head=NULL;
void insert(int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->next=NULL;
    Node *y=head;
    if(head==NULL)
    {
        head=x;
        return;
    }
    while(y->next != NULL)
        y=y->next;
    y->next= x;
    return;    
}
int delete()
{
    Node *x=head;
    if(head==NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int k=x->key;
    head=head->next;
    x->next=NULL;
    free(x);
    return k;
}
void display()
{
    printf("\nCreated linked list is \n");
    Node *x=head;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    while(x!=NULL)
    {
        printf("%d\t",x->key);
        x=x->next;
    }
}
int main()
{
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
				display();
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