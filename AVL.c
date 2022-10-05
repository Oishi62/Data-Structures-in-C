#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
    int key;
    struct Tree *left,*right;
}Node;

Node *root=NULL;
Node *parent=NULL,*rightchild=NULL,*leftchild=NULL,*leftsubtree=NULL,*rightsubtree=NULL;

int height(Node* x)
{
    int l,h;
    if(x!=NULL)
    {
        l=height(x->left);
        h=height(x->right);
        if(l>h)
            return l+1;
        else
            return h+1;    
    }
    else
        return 0;
}

int balance_factor(Node* y)
{
    int lh,rh;
    if(y!=NULL)
    {
        lh=height(y->left);
        rh=height(y->right);
        return lh-rh;
    }
    else    
        return 0;
}

void RR(Node* node)
{
    if(parent == NULL)
        root=rightchild;
    else if(node == parent->right)
        parent->right=rightchild;
    else
        parent->left=rightchild;
    node->right=rightchild->left;
    rightchild->left=node;   
}

void LL(Node* node)
{
    if(parent == NULL)
        root=leftchild;
    else if(node == parent->right)
        parent->right=leftchild;
    else
        parent->left=leftchild;
    node->left=leftchild->right;
    leftchild->right=node;   
}

void RL(Node* node)
{
    if(parent == NULL)
        root=leftsubtree;
    else if(node == parent->right)
        parent->right=leftsubtree;
    else
        parent->left=leftsubtree;
    node->right=leftsubtree->left;
    rightchild->left=leftsubtree->right;
    leftsubtree->left=node;
    leftsubtree->right=rightchild; 
}

void LR(Node* node)
{
    if(parent == NULL)
        root=rightsubtree;
    else if(node == parent->right)
        parent->right=rightsubtree;
    else
        parent->left=rightsubtree;
    leftchild->right=rightsubtree->left;
    node->left=rightsubtree->right;
    rightsubtree->left=leftchild;
    rightsubtree->right=node; 
}

void search_key(int k)//To find the address of the parent of the unbalanced node
{
    Node *rt=root;
    while(rt!=NULL)
    {
        if(rt->key == k)
        {
            return;
        }
        if(k < rt->key)
        {
            parent=rt;
            rt=rt->left;
        }    
        else
        {
            parent=rt;
            rt=rt->right;    
        }       
    }
}

void postorder(Node *r,int k)
{
    int bf;
    if(r!=NULL)
    {
        postorder(r->left,k);
        postorder(r->right,k);
        bf=balance_factor(r);
        if(bf > 1 && k < r->left->key)//LL
        {
            search_key(r->key);
            leftchild=r->left;
            LL(r);
            return;
        }
        if(bf < -1 && k > r->right->key)//RR
        {
            search_key(r->key);
            rightchild=r->right;
            RR(r);
            return;
        }
        if(bf > 1 && k > r->left->key)//LR
        {
            search_key(r->key);
            leftchild=r->left;
            rightsubtree=leftchild->right;
            LR(r);
            return;
        }
        if(bf < -1 && k < r->right->key)//RL
        {
            search_key(r->key);
            rightchild=r->right;
            leftsubtree=rightchild->left;
            RL(r);
            return;
        }
    }
}

void insert(int k)
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
void preorder(Node *r)
{
    if(r!=NULL)
    {
        printf("%d\t",r->key);
        preorder(r->left);
        preorder(r->right);
    }
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

int main()
{
    int flag=1,c,a;
    while(flag)
    {
        printf("Press 1 to insert nodes\nPress 2 to display the inorder traversal of AVL tree\nPress 3 to display the preorder traversal of AVL tree\nPress 4 to exit ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the element you want to insert \n ");
                scanf("%d",&a);
                insert(a);
                postorder(root,a);
                break;
            case 2:
                printf("The inorder traversal of AVL tree is \n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("The preorder traversal of AVL tree is \n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("Wrong choice");           
        }
    }
    return 0;
}