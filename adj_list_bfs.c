#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;
typedef struct queue
{
    int* arr;
    int size;
    int f;
    int r;
}queue;

/*------------------------------------------------------------*/
int isFull(queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q,int val)
{
    if(isFull(q))
    {
        printf("This queue is full. OVERFLOW");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("No element to dequeue");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

/*----------------------------------------------------------------*/
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


    int inDeg[6] = {2,1,1,1,1,0};
 

    queue* q=(queue*)(malloc(sizeof(queue)));
    q->size = 6;
    q->f=q->r = -1;
    q->arr = (int*)(malloc(6*sizeof(int)));

    int* visited = (int*)(calloc(6,sizeof(int)));

    enqueue(q,0);
    visited[0] = 1;
    while(!isEmpty(q))
    {
        int x = dequeue(q);
        printf("%d->",x);
        for(int i=0;i<inDeg[x];i++)
        {            
            if(visited[adj[x]->next->val]!=1 && adj[x]->next!=NULL)
            {
                enqueue(q,adj[x]->next->val);
               
                visited[adj[x]->next->val] = 1;
            }
            adj[x]->next = adj[x]->next->next;
        }
    }    
}