#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int size;
    int f;
    int r;
    int* arr;
}
queue;

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

void main()
{
    queue q;
    q.size = 7;
    q.f=q.r = 0;
    q.arr = (int*)malloc(q.size*(sizeof(int)));  

    /* BFS Implementation */ 
    /* Graph will be a matrix */
    int node;
    int i = 1; /* starting node */
    int visited[7] = {0,0,0,0,0,0,0}; 
    int a[7][7] = {
         {0,1,1,1,0,0,0},
          {1,0,0,1,0,0,0},
           {1,1,0,1,1,0,0},
           {1,0,1,0,1,0,0},
           {0,0,1,1,0,1,1},
           {0,0,0,0,1,0,0},
           {0,0,0,0,1,0,0}
    };
    printf("%d is the starting node\n",i);
    visited[i] = 1;
    enqueue(&q,i); /* add i to queue to explore */
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for(int j=0;j<7;j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                printf("%d->",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }

}