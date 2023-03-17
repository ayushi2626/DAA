#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int val;
    int weight;
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
node* get_node(int value,int weight)
{
    node* n = (node*)(malloc(sizeof(node)));
    n->val = value;
    n->next = NULL;
    n->weight=weight;
    return n;
}
node* insert(node* head,int value,int weight)
{
    node* tmp = head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = get_node(value,weight);
    return head;
}

void main()
{
    node** adj = (node**)(malloc(6*sizeof(node*)));
    adj[0] = get_node(0,0);
    adj[0]->next = get_node(1,9); 
    adj[0]->next->next = get_node(2,2);
   

    adj[1] = get_node(1,0);
    adj[1] = insert(adj[1],3,-6);
    adj[1]= insert(adj[1],4,8);

    adj[2] = get_node(2,0);
    adj[2] = insert(adj[2],1,7);
    adj[2] = insert(adj[2],3,3);
    adj[2] = insert(adj[2],5,1);

    adj[3] = get_node(3,0);
    adj[3] = insert(adj[3],5,2);

    adj[4] = get_node(4,0);

    adj[5] = get_node(5,0);
    

    int inDeg[6] = {2,2,3,1,0,0};

    queue* q=(queue*)(malloc(sizeof(queue)));
    q->size = 6;
    q->f=q->r = -1;
    q->arr = (int*)(malloc(6*sizeof(int)));

    int* visited = (int*)(calloc(6,sizeof(int)));

    enqueue(q,0);
    visited[0] = 1;
    
    int inf = 1000;
    int dist[6] = {inf,inf,inf,inf,inf,inf};
    dist[0] = 0; /* starting node*/
    while(!isEmpty(q))
    {
        int x = dequeue(q);
        for(int i=0;i<inDeg[x];i++)
        {            
            if(visited[adj[x]->next->val]!=1 && adj[x]->next!=NULL)
            {
                enqueue(q,adj[x]->next->val);
                visited[adj[x]->next->val] = 1;
                if(dist[adj[x]->next->val] > (adj[x]->next->weight + dist[x]))
                {
                    dist[adj[x]->next->val] = adj[x]->next->weight + dist[x];
                }
            }
            if(visited[adj[x]->next->val]==1)
            {
                if(dist[adj[x]->next->val] > (adj[x]->next->weight + dist[x]))
                {
                    dist[adj[x]->next->val] = adj[x]->next->weight + dist[x];
                }
            }
            adj[x]->next = adj[x]->next->next;
        }
    } 
    for(int i=0;i<6;i++)
    {
        printf("%d-",dist[i]);
    } 
    
}