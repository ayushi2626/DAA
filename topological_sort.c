#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;
int graph[7][7] = {
    {0,1,1,1,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int count = 0;
int visited[7] = {0,0,0,0,0,0,0};

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

void push(stack *q,int val)
{
    if(isFull(q))
    {
        printf("This queue is full. OVERFLOW");
        exit(0);
    }
    else{
        q->top++;
        q->arr[q->top] = val;   
    }
}

int pop(stack *q)
{
    if(isEmpty(q))
    {
        printf("No element to dequeue");
        return -1;
    }
    else{
        int a = q->arr[q->top];
        q->top--;
        return a;    
    }
}

void DFS(int i,int* arr)
{   
    visited[i] = 1;
    for(int j=0;j<=6;j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {   
            DFS(j,arr);
        }
    }
    arr[count++] = i;
}  

void main()
{
    int *arr = (int*)malloc(7*sizeof(int));
    for(int i=0;i<=6;i++)
    {      
        if(visited[i]==0)
        {
            DFS(i,arr);
        }
    }
    for(int i=6;i>=0;i--)
    {
        printf("%d->",arr[i]);
    }
    free(arr);
}