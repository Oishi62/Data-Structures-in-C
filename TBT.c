#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int key;
    struct Tree *left,*right;
    int lbit,rbit;
}Node;

Node *root=NULL;

void create_firstnode(int k)
{
    root=(Node *)malloc(sizeof(Node));
    root->key=k;
    root->left=root->right=NULL; 
    root->lbit=root->rbit=1;
    return;
}
Node* insucc(Node* x)
{
    Node* temp;
    temp=x->right;
    if(x->rbit != 1)
    {
        while(temp->lbit != 1)
            temp=temp->left;
    }        
    return temp;    
    
}
Node* predec(Node* x)
{
    Node* temp;
    temp=x->left;
    if(x->lbit != 1)
    {
        while(temp->rbit != 1)
            temp=temp->right;    
    }
    return temp;
}
void inorder()
{
    Node* temp=root;
    if(!root)
        printf("The tree is empty\n");
    while(temp->lbit != 1)
    {
        temp=temp->left;
    }
    temp->left=root; //resolving the left dangling pointer
    while(temp)
    {
        printf("%d ",temp->key);//printing the inorder traversals
        temp=insucc(temp);
    }
    Node* t=root;
    while(t->rbit != 1)
    {
        t=t->right;
    }
    t->right=root;//resolving the right dangling pointer

    
}
void insertRight(Node* s,int k)
{
    Node *r=(Node *)malloc(sizeof(Node));
    r->key=k;
    r->left=r->right=NULL; 
    r->lbit=r->rbit=1;
    Node* temp;
    r->right=s->right;
    r->rbit=s->rbit;
    r->left=s;
    r->lbit=1;
    s->right=r;
    s->rbit=0;
    if(r->rbit != 1)
    {
        temp=insucc(r);
        temp->left=r;
    }
}
void insertLeft(Node* s,int k)
{
    Node *r=(Node *)malloc(sizeof(Node));
    r->key=k;
    r->left=r->right=NULL; 
    r->lbit=r->rbit=1;
    Node* temp;
    r->left=s->left;
    r->lbit=s->lbit;
    r->right=s;
    r->rbit=1;
    s->left=r;
    s->lbit=0;
    if(r->lbit != 1)
    {
        temp=predec(r);
        temp->right=r;
    }
}
int main()
{
int flag=1,c,n;
int ch;
printf("Insert one node\nEnter the element you want to insert\n");
scanf("%d",&n);
create_firstnode(n);
    while(flag)
    {
        printf("Press 1 to insert nodes\nPress 2 to display the inorder traversal of binary tree\nPress 3 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf(" Enter the element you want to insert\n");
                scanf("%d",&n);
                Node *p1=root,*p2;
                while(p1!=NULL)
                {
                    p2=p1;
                    printf("%d will be at the left or right subtree(0/1) of %d ",n,p1->key);
                    scanf("%d",&ch);
                    if(ch==0)
                        {
                            if(p1->lbit != 1)
                                p1=p1->left;
                            else
                                break;    
                        }
                    else
                        {
                            if(p1->rbit != 1)
                                p1=p1->right;
                            else
                                break; 
                        }   
                }
                if(ch==0)
                    insertLeft(p2,n);
                else
                    insertRight(p2,n);
                break;
            case 2:
                printf("The inorder traversal of binary tree is \n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                flag=0;
                break;
            default:
                printf("Wrong choice");           
        }
    }
    return 0;
}
