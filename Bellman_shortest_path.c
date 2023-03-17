#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int val;
    int weight;
    struct node* next;
}node;
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
/*------------------------------------------------------------------------------------------*/

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
    adj[3] = insert(adj[3],5,-2);

    adj[4] = get_node(4,0);

    adj[5] = get_node(5,0);
    

    int outDeg[6] = {2,2,3,1,0,0};
    int inf = 1000;
    int dist[6]= {0,inf,inf,inf,inf,inf};

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<outDeg[i];j++)
        {
            if(adj[i]->next!=NULL)
            {
                if(dist[adj[i]->next->val] > (adj[i]->next->weight + dist[i]))
                {
                    dist[adj[i]->next->val] = adj[i]->next->weight + dist[i];
                }
            }
            adj[i]->next = adj[i]->next->next;
        }
    }
    for(int i=0;i<6;i++)
    {
        printf("%d-",dist[i]);
    }
}