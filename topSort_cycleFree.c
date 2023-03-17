#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;
node* get_node(int val)
{
    node* x = (node*)(malloc(sizeof(node)));
    x->val = val;
    x->next  = NULL;
    return x;
}
node* insert(node* head,int val)
{
    node* tmp = head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = get_node(val);
    return head;
}
int length(node* head)
{
    int i=0;
    node* tmp = head;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        i++;
    }
    return i;
}
 
void main()
{
    node** graph = (node**)(malloc(sizeof(node*)*6));
    graph[0] = get_node(0);
    graph[1]  = get_node(1);
    graph[2]  = get_node(2);
    graph[3]  = get_node(3);
    graph[4]  = get_node(4);
    graph[5]  = get_node(5);
     

    /*creating the outgoing list*/
    graph[0] = insert(graph[0],1);
    graph[0] = insert(graph[0],5);

    graph[1] = insert(graph[1],2);
 
    graph[2] = insert(graph[2],3);

    graph[3] = insert(graph[3],4); 

    graph[4] = insert(graph[4],2);
     
    
    
    node* topsorted = get_node(-1);
     
    node* l=topsorted;
    /*inDegree array*/
    int inDegree[6] = {0,1,2,1,1,1};
    int* topSort = (int*)(calloc(6,sizeof(int)));
    int k=-1;
    for(int i=0;i<6;i++)
    {
        if(inDegree[i]==0)
        {
            topSort[++k]=i;
            l = insert(l,i);
            
        }
    }
    int c=k;
    int i=0;
    
    while(c!=6 && i<6)
    {
        while(graph[topSort[i]]->next!=NULL)
        {
            int n = graph[topSort[i]]->next->val;
            inDegree[n]--;
            if(inDegree[n]==0)
            {
                topSort[++k] = n;
                l=insert(l,n);
                
            }
            graph[topSort[i]]->next= graph[topSort[i]]->next->next;
        }
        i++;
    }
    node* tmp = topsorted->next;
    int len = length(topsorted);
    if(len<6)
    {
        for(int i=0;i<6;i++)
        {
            if(inDegree[i]!=0)
            printf("%d->",i);
            
        }
    }
    else{
        node* tmp=topsorted;
        for(int i=0;i<6;i++)
        {
            printf("%d->",tmp->val);
            tmp=tmp->next;
            
        }
    }
        
}