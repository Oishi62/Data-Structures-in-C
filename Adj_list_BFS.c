# include<stdio.h>
# include<stdlib.h>
#define size 50
typedef struct List
{
    int key;
    struct List *next;
}Node;

Node root[50];


int front=-1,rear=-1,queue[size];
void insert(int v)
{
	//int n;
	
	if(rear==size-1)
	{
		printf("The queue is full\n");
		return;
	}
	//printf("Enter the element you want to add ");
	//scanf("%d",&n);
	queue[++rear]=v;
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

Node insert_end(Node head,int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->next=NULL;
    //Node *y=head;
    if(head.next==NULL)
    {
        head.next=x;
        return head;
    }
    Node *y=head.next;
    while(y->next != NULL)
        y=y->next;
    y->next= x;
    return head;    
}


void create(int n)
{
    int i,c,v;
    for(i=0;i<n;i++)
    {
        root[i].key=i+1;
        root[i].next=NULL;
    }
    for(i=0;i<n;i++)
    {
        while(1)
        {
            printf("Is there an edge from the vertex %d?(0/1) ",i+1);
            scanf("%d",&c);
            if(c==1)
            {
                printf("What is that vertex? ");
                scanf("%d",&v);
                root[i]=insert_end(root[i],v);
            }
            else if(c==0)
                break;
        }
    }

}

void BFS(int n,int v)
{
    int visited[n],i,a;
    for(i=0;i<n;i++)
        visited[i]=0;
    insert(v);
    visited[v-1]=1;
    while(front != -1)
    {
        Node y=root[queue[front]-1];
        Node *x=y.next;
        while(x!=NULL)
        {
            if(visited[x->key-1]==0)
            {
                insert(x->key);
                visited[x->key-1]=1;
            }
            x=x->next;
        }
        a=delete();
        printf("%d \t",a);
        if(front == -1)
        {
            for(i=0;i<n;i++)
            {
                if(visited[i]==0)
                {
                    insert(i+1);
                    visited[i]=1;
                }
            }
        }
    }
}


int main()
{
    int n,v;
    printf("Enter the number of vertices ");
    scanf("%d",&n);
    create(n);
    printf("Enter the starting vertex ");
    scanf("%d",&v);
    BFS(n,v);
    return 0;
}