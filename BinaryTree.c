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
        printf("%d\t",r->key);
        inorder(r->right);
    }
}
void preorder(Node *r)
{
    if(r!=NULL)
    {
        printf("%d\t",r->key);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(Node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d\t",r->key);
    }
}
int main()
{
    int flag=1,c,n;
    while(flag)
    {
        printf("Press 1 to insert nodes\nPress 2 to display the inorder traversal of binary tree\nPress 3 to display the  postorder traversal of binary tree\nPress 4 to display the  preorder traversal of binary tree\nPress 5 to exit");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element you want to insert\n");
                scanf("%d",&n);
                create(n);
                break;
            case 2:
                printf("The inorder traversal of binary tree is \n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                   printf("The postorder traversal of binary tree is \n");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("The preorder traversal of binary tree is \n");
                preorder(root);
                printf("\n");
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