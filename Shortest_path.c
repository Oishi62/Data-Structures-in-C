#include <stdio.h>
#define size 50

int adj[size][size];
int path[size][size];
void create(int n)
{
    int e,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("What is the weight between %d and %d?(0/1) ",i+1,j+1);
            scanf("%d",&e);
            adj[i][j]=e;
        }
    }
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    		path[i][j]=adj[i][j];
	}
}


void shortest_path(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				path[i][j]=path[i][j] < (path[i][k]+path[k][j])? path[i][j]:(path[i][k]+path[k][j]);
			}
		}
	}
}

int main()
{
    int n,i,j;
    printf("Enter the number of vertices ");
    scanf("%d",&n);
    create(n);
    shortest_path(n);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    		printf("%d ",path[i][j]);
    	printf("\n");
	}
    return 0;
}
