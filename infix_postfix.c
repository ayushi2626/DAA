#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct stack
{
    int size;
    int top;
    char* arr;
}stack;

int isFull(stack *q)
{
    if(q->top==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(stack *q)
{
    if(q->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *q,char val)
{
    if(isFull(q))
    {
        printf("This stack is full. OVERFLOW");
    }
    else{
        q->top++;
        q->arr[q->top] = val;   
    }
}

char pop(stack *q)
{   
    if(isEmpty(q))
    {
        return -1;
    }
    else{
        int a = q->arr[q->top];
        q->top--;
        return a;    
    }
}
void print_stack(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        printf("%d",arr[i]);
    }
}

int pre(char ch)
{
    if(ch=='*' || ch=='/') return 3;
    if(ch=='^') return 4;
    if(ch=='+' || ch=='-') return 2;
    if(ch=='(') return 1;
}
void postfix(char* exp, stack* st,int size)
{
    for(int i=0;(i<size && !isFull(st));i++)
    {   
        if(isalnum(*(exp+i)))
        {
            printf("%c",*(exp+i));
        }
        else
        {
            if(*(exp+i)=='(')
            {
                push(st,*(exp+i));
                
            }
            else if(*(exp+i)==')')
            {
                while(st->arr[st->top]!='(' && !isEmpty(st))
                {   
                    char y = pop(st);
                    printf("%c",y);
                }
                char y = pop(st);
              
            }
            else if(pre(*(exp+i))>pre(st->arr[st->top]))
            {
                push(st,*(exp+i));
                 
            }
            else if(pre(*(exp+i))<=pre(st->arr[st->top]))
            {   
                while(pre(*(exp+i))<=pre(st->arr[st->top]) && !isEmpty(st))
                {   
                    char x = pop(st);
                    printf("%c",x);
                }
                push(st,*(exp+i));
             
            }
            else 
            {
                printf("Sorry aborting");
            }
        }
    }
    while(!isEmpty(st))
    {
        char x = pop(st);
        printf("%c",x);
    }
}

void pfexp(char* exp,stack* st,int size,char* result)
{   
    int j=0;
    for(int i=0;(i<size && !isFull(st));i++)
    {   
        if(isalnum(*(exp+i)))
        {
            result[j++] = *(exp+i);
        }
        else
        {
            if(*(exp+i)=='(')
            {
                push(st,*(exp+i));
                
            }
            else if(*(exp+i)==')')
            {
                while(st->arr[st->top]!='(' && !isEmpty(st))
                {   
                    char y = pop(st);
                    result[j++] = y;
                }
                char y = pop(st);
              
            }
            else if(pre(*(exp+i))>pre(st->arr[st->top]))
            {
                push(st,*(exp+i));
                 
            }
            else if(pre(*(exp+i))<=pre(st->arr[st->top]))
            {   
                while(pre(*(exp+i))<=pre(st->arr[st->top]) && !isEmpty(st))
                {   
                    char x = pop(st);
                    result[j++] = x;
                }
                push(st,*(exp+i));
             
            }
            else 
            {
                continue;
            }
        }
    }
    while(!isEmpty(st) && st->top!=0)
    {
        char x = pop(st);
        result[j++]= x;
    }
    result[j] = '\0';
}
void main()
{
    char exp[] = "5+4+3";
    int s = 5;
    stack* st = (stack*)(malloc(sizeof(stack)));
    st->arr = (char*)(malloc(sizeof(char)*s));
    st->size = s;
    st->top=-1;
    push(st,'(');
    char result[s];
    pfexp(exp,st,s,result);
    stack* st1 = (stack*)(malloc(sizeof(stack)));
    st1->arr = (char*)(malloc(sizeof(char)*s));
    st1->size = s;
    st1->top=-1;
    int x = evaluate(result,st1,s);
    printf("%d",x);
}