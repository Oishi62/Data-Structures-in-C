#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int key;
    struct Tree *left,*right;
}Node;

Node *root=NULL;
Node *n=NULL,*p=NULL,*s=NULL,*ps=NULL;

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
void search_key(int k)//To find the address of the node we want to delete and the address of it's parent
{
    Node *r=root;
    while(r!=NULL)
    {
        if(r->key == k)
        {
            n=r;
            return;
        }
        if(k < r->key)
        {
            p=r;
            r=r->left;
        }    
        else
        {
            p=r;
            r=r->right;     
        }       
    }
}

void inorder_succ()
{
    s=n->right;
    ps=n;
    while(s->left != NULL)
    {
        ps=s;
        s=s->left;
    }
}
void Case_A()//Deleting a node with 0 children
{
    if(p == NULL)
        root=NULL;
    else if(p->left == n)
        p->left=NULL;
    else
        p->right=NULL;        
}
void Case_B()//Deleting a node with 1 child
{
    Node *c;
    if(n->right != NULL)
        c=n->right;
    else
        c=n->left;    
    if(p == NULL)
        root=c;
    else if(p->left == n)
        p->left=c;
    else
        p->right=c;    
}
void Case_C()//Deleting a node with 2 children
{
    inorder_succ();
    int k=s->key;
    Node *h=n;
    if(s->right != NULL)
    {
        n=s;
        p=ps;
        Case_B();
    }
    else
    {
        n=s;p=ps;
        Case_A(); 
    }       
    h->key=k;
}
void nature_of_node()//To find whether the node to be deleted is leaf or half or full node
{
    if(n->left==NULL && n->right==NULL)//If the node to be deleted is leaf
        Case_A();
    else if((n->left!=NULL && n->right==NULL) || (n->left==NULL && n->right!=NULL))//If the node to be deleted is half
        Case_B();
    else if(n->left != NULL && n->right != NULL)//If the node to be deleted is full
        Case_C();    
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
    int flag=1,c,a;
    while(flag)
    {
        printf("Press 1 to insert nodes\nPress 2 to display the inorder traversal of binary search tree\nPress 3 to display the  postorder traversal of binary search tree\nPress 4 to display the  preorder traversal of binary search tree\nPress 5 to delete a node\nPress 6 to exit");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element you want to insert\n");
                scanf("%d",&a);
                create(a);
                break;
            case 2:
                printf("The inorder traversal of binary search tree is \n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                   printf("The postorder traversal of binary search tree is \n");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("The preorder traversal of binary search tree is \n");
                preorder(root);
                printf("\n");
                break; 
            case 5:
                printf("Enter the key value of the node you want to delete\n");
                scanf("%d",&a);
                search_key(a);
                if(n == NULL)
                    printf("The node is not present in the tree\n");
                else
                {
                    nature_of_node();
                    printf("The node is deleted\n");
                }    
                break;     
            case 6:
                flag=0;
                break;
            default:
                printf("Wrong choice");           
        }
    }
    return 0;
}