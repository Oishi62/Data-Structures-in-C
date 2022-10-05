#include<stdio.h>
int partition(int a[],int l,int h)
{
    int pivot=a[l],down=l,up=h,temp;
    while(down<up)
    {
        while(pivot>=a[down])
            down++;
        while(pivot<a[up])
            up--;
        if(down<up)
        {
            temp=a[down];
            a[down]=a[up];
            a[up]=temp;
        }        
    }
    a[l]=a[up];
    a[up]=pivot;
    return up;
}

void quicksort_recursion(int a[],int l,int h)
{
    int p;
    if(l<h)
    {
        p=partition(a,l,h);
        quicksort_recursion(a,l,p-1);
        quicksort_recursion(a,p+1,h);
    }
}

int main()
{
    int n,i;
    printf("Enter the size of the array ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the array elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort_recursion(a,0,n-1);
    printf("\nThe sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
