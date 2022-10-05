#include <stdio.h>
void bubblesort(int a[],int size)
{
    int i,j,t,flag=1;
    for(i=0;i<size-1 && flag;i++)
    {
        flag=0;
        for(j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag=1;                
            }
        }
    }
}
void insertionsort(int a[],int size)
{
    int i,j,t;
    for(i=1;i<size;i++)
    {
        t=a[i];
        for(j=i-1;j>=0 && t<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
}
void shellSort(int a[], int size) 
{
    int t,g,j;
    for (g = size / 2; g > 0; g /= 2) 
    {
        for (int i = g; i < size; i++) 
        {
            t = a[i];
            for (j = i-g; j >=0 && a[j] > t; j -= g) 
            {
                a[j+g] = a[j];
            }
            a[j+g] = t;
        }
    }
}
void print(int a[],int size)
{
    for(int i=0;i<size;i++)
    printf("%d\n",a[i]);
}
int main(int argc, char const *argv[])
{
    int n,c,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter 1 for bubble sort\nEnter 2 for insertion sort\nEnter 3 for shell sort\n");
    scanf("%d",&c);
    if(c==1)
    {
        bubblesort(a,n);
        print(a,n);
    }
    else if(c==2)
    {
        insertionsort(a,n);
        print(a,n);
    }
    else if(c==3)
    {
        shellSort(a,n);
        print(a,n);
    }
    else
        printf("Wrong choice");
    return 0;
}
