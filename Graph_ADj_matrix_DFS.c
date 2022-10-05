#include <stdio.h>
#include <stdlib.h>

#define size 50

int adj[size][size];
int visited[size];
void create(int n)
{
	int e,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Is there an edge between %d and %d?(0/1)",i+1,j+1);
			scanf("%d",&e);
			adj[i][j]=e;
		}
	}
	for(i=0;i<n;i++)
		visited[i]=0;
}
void DFS(int v,int n)
{
	int i;
	visited[v-1]=1;
	printf("%d ",v);
	for(i=0;i<n;i++)
	{
		if(adj[v-1][i]==1 && visited[i]== 0)
			DFS(i+1,n);
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
