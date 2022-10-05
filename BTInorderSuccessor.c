//Data structure exam question 2 practical

#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int key;
    struct Tree *left,*right;
}Node;

Node *root=NULL;
int a[50],i=0;
void create(int k)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->key=k;
    x->left=x->right=NULL;
    Node *p1=root,*p2;
    if(root == NULL)
    {
        root=x;
        return;
    }
    int ch;
    while(p1!=NULL)
    {
        p2=p1;
        printf("%d will be at the left or right subtree(0/1) of %d",k,p1->key);
        scanf("%d",&ch);
        if(ch==0)
            p1=p1->left;
        else
            p1=p1->right;    
    }
    if(ch==0)
        p2->left=x;
    else
        p2->right=x;
}
void inorder(Node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        a[i++]=r->key;
        inorder(r->right);
    }
}
int main()
{
    int flag=1,k;
    while(flag)
    {
        printf("\nEnter the key value ");
        scanf("%d",&k);
        if(k == 0)
        {
            flag=0;
            break;
        }
        create(k);
    }
    printf("\nEnter the key value whose inorder successor you want ");
    scanf("%d",&k);
    inorder(root);
    int g;
    for(g=0;g<i;g++)
    {
        if(a[g] == k && g != i-1)
            printf("\nThe inorder successor of %d is %d ",k,a[g+1]);
        if( a[g]==k && g==i-1)
            printf("\nThe inorder successor of %d is NULL ",k);
    }
    int f=0;
    for(g=0;g<i;g++)
    {
        if(a[g]==k)
        {
            f=1;
        }
    }
    if(f != 1)
        printf("Element is not present in the tree");
    return 0;
}