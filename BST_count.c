#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int key;
    struct Tree *left,*right;
}Node;

Node *root=NULL;

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
        if(k < p1->key)
            p1=p1->left;
        else
            p1=p1->right;      
    }
    if(k < p2->key)
        p2->left=x;
    else
        p2->right=x;
}
int count_nodes(Node *r)
{
    int count=0;
    if(r == NULL)
        return 0;
    count=count+ count_nodes(r->left)+ count_nodes(r->right);
    return count+1;   
}
int count_leafnodes(Node *r)
{
    int count=0;
    if(r == NULL)
        return 0;
    if( r->left == NULL && r->right == NULL)
        count++;
    count=count+ count_leafnodes(r->left)+ count_leafnodes(r->right);
    return count;    
}
int search_key(Node *r,int k)
{
    while(r!=NULL)
    {
        if(r->key == k)
            return 1;
        if(k < r->key)
            r=r->left;
        else
            r=r->right;        
    }
    return 0;
}
int main()
{
    int flag=1,c,n,h;
    while(flag)
    {
        printf("Press 1 to insert nodes\nPress 2 to display the number of nodes in the binary search tree\nPress 3 to display the number of leaf nodes in the binary search tree\nPress 4 to search a given element in the binary search tree\nPress 5 to exit");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element you want to insert\n");
                scanf("%d",&n);
                create(n);
                break;
            case 2:
                h=count_nodes(root);
                printf("The total number of nodes in the given binary search tree is %d \n",h);
                break;
            case 3:
                h=count_leafnodes(root);
                printf("The total number of leaf nodes in this binary search tree is %d \n",h);
                break;
            case 4:
                printf("Enter the element you want to search\n");
                scanf("%d",&n);
                h=search_key(root,n);
                if(h==1)
                    printf("Element found\n");
                else
                    printf("Search unsuccessful\n");    
                break;  
            case 5:
                flag=0;
                break;
            default:
                printf("Wrong choice");           
        }
    }
    return 0;
}