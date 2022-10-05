# include<stdio.h>
# include<stdlib.h>

typedef struct List
{
    int key;
    struct List *next,*prev;
}Node;

Node *head=NULL;

void append(int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->next=NULL;
    Node *y=head;
    if(head==NULL)
    {
        head=x;
        x->prev=NULL;
        return;
    }
    while(y->next != NULL)
        y=y->next;
    y->next= x;
    x->prev=y;
    return;    
}
void insert_first(int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->next=head;
    x->prev=NULL;
    head->prev=x;
    head=x;
}
void insert_intermediate(int i,int k)
{
    int c=1;
    Node *x=head;
    Node *y=(Node *)malloc(sizeof(Node));
    y->key=k;
    if(head==NULL)
    {
        printf("The previous node is null, element can't be inserted");
        return;
    }
    while(x!=NULL)
    {
        c++;
        if(c==i)
        {
            y->next=x->next;
            x->next=y;
            y->prev=x;
            y->next->prev=y;
            return;
        }
        x=x->next;
    }
}
int delete_first()
{
    Node *x=head;
    int k=x->key;
    head=x->next;
    x->next=NULL;
    head->prev=NULL;
    free(x);
    return k;
}
int delete_last()
{
    Node *x=head;
    int k;
    while(x->next->next!=NULL)
        x=x->next;
    k=x->next->key;
    x->next->prev=NULL;
    free(x->next);
    x->next=NULL;    
    return k;    
}
int delete_intermediate(int i)
{
    int c=1,k;
    Node *x=head;
    Node *y=head->next;
    if(head==NULL)
    {
        printf("The previous node is null, element can't be inserted");
        return -1;
    }
    while(x!=NULL)
    {
        c++;
        if(c==i)
        {
            
            k=y->key;
            x->next=y->next;
            y->next->prev=y->prev;
            y->next=NULL;
            y->prev=NULL;
            free(y);
            return k;
        }
        x=y;
        y=y->next;
    }
    return -1;
}
void display_reverse()
{
    printf("\nThe reversed linked list is \n");
    Node *x=head;
    while(x->next!=NULL)
        x=x->next;
    while(x!=NULL)
    {
        printf("%d\t",x->key);
        x=x->prev;
    }
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
       int c,flag=1,n,position,counter=0;
       while(flag)
       {
           printf("Press 1 for appending elements\nPress 2 for inserting elements at the beginning\nPress 3 for inserting at the specific intermediate position\nPress 4 for deleting the first element\nPress 5 to delete the last element\nPress 6 to delete element at a given position\nPress 7 to display the linked list\nPress 8 to reverse display the linked list\nPress 9 to exit ");
           scanf("%d",&c);
           switch(c)
		   {
                case 1: 
                
                    printf("\nEnter the element you want to append to the list ");
                    scanf("%d",&n);
                    append(n);
                    counter++;
                    break;
                case 2:
                    printf("\nEnter the element you want to insert at the beginning of the list ");
                    scanf("%d",&n);
                    insert_first(n);
                    counter++;
                    break;	
                case 3:
                    printf("\nEnter the position you want to insert the element ");
                    scanf("%d",&position);
                    printf("\nEnter the element you want to insert at that position ");
                    scanf("%d",&n);
                    if(position == 1)
                    {
                        insert_first(n);
                        counter++;
                    }
                    else if(position == counter+1)
                    {
                        append(n);
                        counter++;
                    }
                    else if(position > counter+1)
                        printf("\nInvalid intermediate position\n");
                    else
                    {
                        insert_intermediate(position,n);
                        counter++;
                    }
                    break;                
                case 4:
                    n=delete_first();
                    printf("\n%d is deleted from the list\n",n);
                    counter--;
                    break;
                case 5:
                    n=delete_last();
                    printf("\n%d is deleted from the list\n",n);
                    counter--;
                    break;
                case 6:
                    printf("\nEnter the position of the element you want to delete ");
                    scanf("%d",&position);
                    if(position == 1)
                    {
                        n=delete_first();
                        printf("\n%d is deleted from the list\n",n);
                        counter--;
                    }
                    else if(position == counter)
                    {
                        n=delete_last();
                        printf("\n%d is deleted from the list\n",n);
                        counter--;
                    }
                    else if(position > counter)
                        printf("\nInvalid intermediate position\n");
                    else
                    {
                        n=delete_intermediate(position);
                        if(n != -1)
                            printf("\n%d is deleted from the list\n",n);
                        counter--;
                    }
                    break;                
                case 7:
                    display();
                    break;
                case 8:
                    display_reverse();
                    display();
                    break;    
                case 9:
                    flag=0;
                    break;    
                default:
                    printf("Wrong choice");		
						
		   }
       }
}