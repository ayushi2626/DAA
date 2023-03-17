#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int front;
    int rear;
    int* arr;
    int size;
}node;

void enqueue(node* q,int val)
{
    q->arr[++(q->rear)] = val;
}

void print(node* q)
{
    for(int i=0;i<q->size;i++)
    {
        printf("%d",q->arr[i]);
    }
}
void main()
{
    node* c = (node)(malloc(sizeof(node)));
    c->front = -1;
    c->rear = -1;
    c->size = 15;
    enqueue(c,45);
}