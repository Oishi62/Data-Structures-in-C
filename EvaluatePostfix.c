#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int top = -1;
void push(int stack[],int e)
{
    stack[++top] = e;
}

int pop(int stack[])
{
    return stack[top--];
}
int main()
{
    int stack[50];
    char exp[50];
    char *n;
    int a,b,c,num;
    printf("Enter the expression : ");
    scanf("%s",exp);
    n = exp;
    if(strlen(exp)==1)
    {
        printf("Wrong Postfix expression");
        exit(0);
    }
    while(*n != '\0')
    {
        if(isdigit(*n))
        {
            num = *n - 48;
            push(stack,num);
        }
        else
        {
            if(top>=1)
            {
                a = pop(stack);
                b = pop(stack);
                switch(*n)
                {
                    case '+':
                    {
                        c = a + b;
                        break;
                    }
                    case '-':
                    {
                        c = b - a;
                        break;
                    }
                    case '*':
                    {
                        c = b * a;
                        break;
                    }
                    case '/':
                    {
                        if(a!=0)
                        {
                            c = b / a;
                            break;
                        }
                        else if(a==0)
                        {
                            printf("Wrong expression can't be divided by 0");
                            exit(0);
                        }
                    }
                    case '$':
                    {
                        c=(int)pow(b,a);
                        break;
                    }
                }
                push(stack,c);
            }
            else
            {
                printf("Wrong Postfix expression");
                exit(0);
            }
        }
        n++;
    }
    if(top==0)
        printf("\nThe result of expression %s  =  %d\n\n",exp,pop(stack));
    else
        printf("Wrong Postfix expression");    
    return 0;
}

