#include<stdio.h>

void merge_sort(int a[],int n)
{
    int size=1,l1,k=0,u1,u2,l2,i,j;
    int temp[n];
    while(size<n)
    {
        l1=0;
        k=0;
        while(l1+size<n)
        {
            l2=l1+size;
            u1=l2-1;
            u2=(u1+size)<n?(u1+size):(n+1);
            for(i=l1,j=l2;i<=u1 && j<=u2;k++)
            {
                if(a[i]<a[j])
                    temp[k]=a[i++];
                else
                    temp[k]=a[j++];

            }
            while(i<=u1)
                temp[k++]=a[i++];
            while(j<=u2)
                temp[k++]=a[j++];
            l1=u2+1;        
        }
        for(i=l1;i<n;i++,k++)
            temp[k]=a[i];
        for(i=0;i<n;i++)
            a[i]=temp[i];
        size=size*2;        
    }
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
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
    merge_sort(a,n);
}