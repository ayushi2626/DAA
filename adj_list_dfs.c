#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;
typedef struct stack
{
    int size;
    int top;
    int *arr;
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
void print_stack(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        printf("%d",arr[i]);
    }
}
/*-------------------------------------------------*/
node* get_node(int value)
{
    node* n = (node*)(malloc(sizeof(node)));
    n->val = value;
    n->next = NULL;
    return n;
}
node* insert(node* head,int value)
{
    node* tmp = head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = get_node(value);
    return head;
}
/*--------------------------------------------------*/

void main()
{
    node** adj = (node**)(malloc(6*sizeof(node*)));
    adj[0] = get_node(0);
    adj[0]->next = get_node(1);
    adj[0]->next->next = get_node(2);

    adj[1] = get_node(1);
    adj[1] = insert(adj[1],3);

    adj[2] = get_node(2);
    adj[2] = insert(adj[2],4);

    adj[3] = get_node(3);
    adj[3] = insert(adj[3],5);

    adj[4] = get_node(4);
    adj[4] = insert(adj[4],5);

    adj[5] = get_node(5);

    int outDeg[6] = {2,1,1,1,1,0};

    stack* st = (stack*)(malloc(sizeof(stack)));
    st->size = 6;
    st->top =  -1;
    st->arr = (int*)(malloc(sizeof(int)*6));

    int visited[6] = {0,0,0,0,0,0};

    push(st,0);
    visited[0] = 1;
    while(!isEmpty(st))
    {
        int x = pop(st);
        printf("%d->",x);
        for(int i=0;i<outDeg[x];i++)
        {
            if(visited[adj[x]->next->val]!=1 && adj[x]->next!=NULL)
            {
                push(st,adj[x]->next->val);
                visited[adj[x]->next->val] = 1;
            }
            adj[x]->next = adj[x]->next->next;
        }
    }
}