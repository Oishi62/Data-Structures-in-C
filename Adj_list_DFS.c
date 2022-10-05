#include <stdio.h>
#include <stdlib.h>

#define size 50

typedef struct List
{
    int key;
    struct List *next;
}Node;

Node root[50];


int visited[size];
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
    for(i=0;i<n;i++)
        visited[i]=0;
}

void DFS(int v,int n)
{
	visited[v-1]=1;
	printf("%d ",v);
    Node y=root[v-1];
    Node *x=y.next;
	while(x!=NULL)
	{
		if(visited[x->key-1]== 0)
			DFS(x->key,n);
        else
            x=x->next;
	}

}
int main()
{
	int n,v,i;
	printf("Enter the number of vertices ");
	scanf("%d",&n);
	create(n);
	printf("Enter the start vertex for the DFS traversal ");
	scanf("%d",&v);
	printf("The DFS traversal is: -\n");
	DFS(v,n);
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			DFS(i+1,n);
		}
	}
	return 0;
}
