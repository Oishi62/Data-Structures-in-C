#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

int stack[MAX],top=-1;
int admatrix[MAX][MAX];
int status[MAX];

void push(int n)
{
	if(top==MAX-1)
	{
	printf("\nOverflow");
	return;
	}
	stack[++top]=n;
}

int pop()
{
	if (top==-1)
	{
	printf("\nUnderflow");
	return -1;
	}
	return stack[top--];
}

void DFS(int n,int i)
{
	int j;
	push(i);

	while(top!=-1)
	{
		i = pop();
		status[i]=2;
		for(j=0;j<n;j++)
		{
			if(admatrix[i][j]==1 && status[j]==0)
			{
				push(j);
				status[j]=1;
			}
		}
		printf("%d  ",i);
	}
	for(i=0;i<n;i++)
	{
		if(status[i]==0)
		{
			printf("\n");
			DFS(n,i);
		}
	}
}

int main()
{
	int n,i,j,x;
	printf("\nTotal no. of vertices? ");
	scanf("%d",&n);
	printf("\nThe vertices are 0 to %d",(n-1));
	printf("\nEntering the edges: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nIs there an edge from %d to %d? Enter 1 for yes, 0 for no: ",i,j);
			scanf("%d",&x);
			if(x==1)
				admatrix[i][j]=1;
			else
				admatrix[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
		status[i]=0;
	printf("\nThe depth first traversal is: ");
	DFS(n,0);
}
