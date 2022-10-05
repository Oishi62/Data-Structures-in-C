#include <stdio.h>
#include <string.h>
int top = -1;
void push(int stack[],int e)
{
    stack[++top] = e;
}

int pop(int stack[])
{
    return stack[top--];
}
void reverse(char s[50],int stack[50])
{
    char s2[50];
    int i;
    for(int i=0; i<strlen(s);i++)
    {
        push(stack,s[i]);
    }
    for(i=0;i<strlen(s);i++)
    {
        s2[i]=pop(stack);
    }
    s2[i]='\0';
    printf("%s",s2);
}
int main()
{
    int stack[50];
    char s1[50];
    //char s2[50];
     printf("Enter the expression : ");
    scanf("%[^\n]s",s1);
    reverse(s1,stack);
}
