# include<stdio.h>
# include<stdlib.h>
typedef struct List
{
    int roll;
    char name[20];
    double per;
    struct List *next;
}Node;

Node *head=NULL;

void append(int k,char n[20],double p)
{
    Node *x=(Node *)malloc(sizeof(Node));
    x->roll=k;
    int i;
    for(i=0;i<=19;i++)
    {
        x->name[i]=n[i];
    }
    x->per=p;
    x->next=NULL;
    Node *y=head;
    if(head==NULL)
    {
        head=x;
        return;
    }
    while(y->next != NULL)
        y=y->next;
    y->next= x;
    return;    
}
void highest_Marks()
{
    Node *x=head;
    int max_roll=x->roll;
    double max=x->per;
    while(x != NULL)
    {
        if(max < x->per)
        {
            max= x->per;
            max_roll=x->roll;
        }
        x=x->next;
    }
    printf("\nThe roll number of the student who secured the maximum marks is %d",max_roll);
}
int main()
{
    int r,flag=1;
    char n[20];
    double p;
    while(flag)
    {
        printf("\nEnter the roll number of the student ");
        scanf("%d",&r);
        if(r==0)
        {
            flag=0;
            break;
        }
        printf("\nEnter the name of the student ");
        scanf(" %[^\n]s",n);
        printf("\nEnter the marks in percentage of the student ");
        scanf("%lf",&p);
        append(r,n,p);
    }
    highest_Marks();
    return 0;   
}