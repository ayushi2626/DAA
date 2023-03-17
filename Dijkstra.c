#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    int to;
    struct node* next;
}node;
typedef struct node_v
{
    int val;
    int weight;
    struct node_v* next;
}node_v;

void insert(node** heap,int* i,node* v)
{
    heap[*i] = v;
    int x = *i;
    int j=(*i-1)/2;
    while(j>=0)
    {   
        if(x==0 && j==0)
        { 
            *i=*i+1;  
            return;
        }
        else if(heap[j]->val>heap[x]->val)
        {
            node* xy = heap[x];
            heap[x] = heap[j];
            heap[j] = xy;
            x = j;
            j = (j-1)/2;
        }
        else
        {   
            *i=*i+1;
            return;
        }
    }
    *i=*i+1;
}

void delete(node** heap,int* i,int pos)
{
    node* x = heap[*i-1];
    heap[*i-1] = heap[pos];
    heap[pos] = x;
    int j = pos;
    *i=*i-1;
    while(j<*i && 2*j+1<*i && 2*j+2<*i)
    {
        
            if(heap[2*j+1]->val<heap[j*2+2]->val && heap[2*j+1]->val<heap[j]->val)
            {
                node* y = heap[2*j+1];
                heap[2*j+1] = heap[j];
                heap[j] = y;
                j = 2*j+1;
            }
            else if(heap[2*j+1]->val<heap[j*2+2]->val && heap[2*j+2]->val<heap[j]->val)
            {
                node* y = heap[2*j+2];
                heap[2*j+2] = heap[j];
                heap[j] = y;
                j = 2*j+2;
            }
         
            else
            {
                return;
            }
    }
}
node* get_node(int f,int dist)
{
    node* x = (node*)(malloc(sizeof(node)));
    x->to = f;
    x->val = dist;
    x->next = NULL;
    return x;
}
node_v* get_v(int val,int weight)
{
    node_v* x=(node_v*)(malloc(sizeof(node_v)));
    x->val = val;
    x->weight = weight;
    x->next = NULL;
    return x;
}
node_v* insert_v(node_v* h,int val,int dist)
{
    node_v* tmp = h;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = get_v(val,dist);
    return h;
}
int isEmpty(node** pq,int i)
{
    if(i<=0) return 1;
    else return 0;
}
void main()
{
    node** pq = (node**)(malloc(sizeof(node*)*20));
    
    node_v** adj = (node_v**)(malloc(6*sizeof(node_v*)));
    adj[0] = get_v(0,0);
    adj[0]->next = get_v(1,1); 
    adj[0]->next->next = get_v(2,5);
    adj[0]->next->next->next = get_v(3,2);
    adj[0]->next->next->next->next = get_v(5,7);
   

    adj[1] = get_v(1,0);
    adj[1] = insert_v(adj[1],3,9);
    adj[1]= insert_v(adj[1],4,4);

    adj[2] = get_v(2,0);
    adj[2] = insert_v(adj[2],3,8);
    adj[2] = insert_v(adj[2],5,1);

    adj[3] = get_v(3,0);

    adj[4] = get_v(4,0);

    adj[5] = get_v(5,0);

    int outDeg[6] = {4,2,2,0,0,0};
    int dist[6] = {100,100,100,100,100,100};
    dist[0] = 0;
    int i=0;
    insert(pq,&i,get_node(0,0));
    int visited[6] = {0,0,0,0,0,0};
    while(!isEmpty(pq,i))
    {   
             
            node* x = pq[0];
            visited[x->to]=1;
            delete(pq,&i,0);
            node_v* y = adj[x->to];
            for(int k=0;k<outDeg[x->to];k++)
            {   
                if(y->next!=NULL)
                {   
                    if(y->next->weight+dist[x->to]<dist[y->next->val] && x->val<y->next->weight+dist[x->to])
                    {
                        dist[y->next->val] = y->next->weight+dist[x->to];
                        insert(pq,&i,get_node(y->next->val,dist[y->next->val]));
                    }
                    y->next=y->next->next;
                }
            
        }
    }
    for(int i=0;i<6;i++)
    {
        printf("%d->",dist[i]);
    }
}