#include <stdio.h>
#define size 50

int adj[size][size];
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
void create(int n)
{
    int e,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Is there an edge between %d and %d?(0/1) ",i+1,j+1);
            scanf("%d",&e);
            adj[i][j]=e;
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
        for(i=0;i<n;i++)
        {
            if(adj[queue[front]-1][i] == 1 && visited[i]==0)
            {
                insert(i+1);
                visited[i]=1;
            }
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
    printf("Enter the start vertex for the graph ");
    scanf("%d",&v);
    printf("The BFS traversal is:- \n");
    BFS(n,v);
    return 0;
}