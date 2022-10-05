#include<stdio.h>

void merge(int a[],int lb,int mid,int ub,int n)
{
    int l1,l2,u1,u2,i,j,temp[n],k=lb;
    l1=lb;
    u1=mid;
    l2=mid+1;
    u2=ub;
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
    for(i=lb;i<=ub;i++)
        a[i]=temp[i];


}
void msort(int a[],int lb,int ub,int n)
{
    int mid,i;
    if(lb!=ub)
    {
        mid=(lb+ub)/2;
        msort(a,lb,mid,n);
        msort(a,mid+1,ub,n);
        merge(a,lb,mid,ub,n);
    }
}
void display(int a[],int n)
{
    int i;
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
    msort(a,0,n-1,n);
    display(a,n);
}