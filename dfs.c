#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;
int graph[7][7] = {
    {0,1,0,0,1,0,0},
    {0,0,1,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0},
    {0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,1,0,0}
};
int graphrev[7][7] = 
{
    {0,0,0,0,0,0,0},
    {1,0,0,1,0,0,0},
    {0,1,0,0,0,0,0},
    {0,0,1,0,0,0,0},
    {1,0,0,0,0,0,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0}
};
int visited[7] = {0,0,0,0,0,0,0};
int visited2[7] = {0,0,0,0,0,0,0};
int dfs[7] = {0,0,0,0,0,0,0};
int k=0;
int count=0;

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

void DFS(int i)
{
    int j;  
    visited[i] = 1;
    for(j=0;j<7;j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
    dfs[k++] = i;
}
void DFS2(int i)
{
    int j;
    visited2[i] = 1;
    for(j=0;j<7;j++)
    {
        if(graphrev[i][j]==1 && !visited2[j])
        {
            DFS2(j);
        }
    }
}
void main()
{
     
    printf("The starting node is: 0\n");
    int i=0;
     
    DFS(i);
    for(int i=6;i>=0;i--)
    {
        int c = dfs[i];
        if(visited2[c]==0)
        {
            DFS2(c);
            count++;
        }
    }
    printf("%d",count);
}