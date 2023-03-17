#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int i)
{
    int size = i/2;
    for(int j=size;j>=0;j--)
    {
        int left = 2*j+1;
        int right = 2*j+2;
        while(arr[j]<arr[2*j+1] && (2*j+1)<i)
        {
            int x = arr[2*j+1];
            arr[2*j+1] = arr[j];
            arr[j]=x;
            j= 2*j+1;
        }
        if(arr[j]<arr[2*j+2] && (2*j+2)<i)
        {
            int x = arr[2*j+2];
            arr[2*j+2] = arr[j];
            arr[j] = x;
            j = 2*j+2;
        }
    }
}
void delete(int* heap,int* i,int pos)
{
    int x = heap[*i];
    heap[*i] = heap[pos];
    heap[pos] = x;
    int j = pos;
    while(j<*i+1)
    {
        if(heap[j]<heap[2*j+1] || heap[j]<heap[2*j+2])
        {
            if(heap[2*j+1]>heap[j*2+2])
            {
                int y = heap[2*j+1];
                heap[2*j+1] = heap[j];
                heap[j] = y;
                j = 2*j+1;
            }
            else{
                int y = heap[2*j+2];
                heap[2*j+2] = heap[j];
                heap[j] = y;
                j = 2*j+2;
            }
        }
        else
        {
            *i=*i-1;
            return;
        }
    }
    *i=*i-1;
}
void insert(int* heap,int* i,int val)
{
    heap[*i] = val;
    int x = *i;
    int j=(*i-1)/2;
    while(j>=0)
    {   
        if(x==0 && j==0)
        {   
            *i = *i+1;
            return;
        }
        else if(heap[j]<heap[x])
        {
            int xy = heap[x];
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
    *i = *i+1;
}
void print(int* heap,int* i)
{
    for(int j=0;j<(*i);j++)
    {
        printf("%d-",heap[j]);
    }
}
 
void main()
{
    int arr[10] = {0,1,9,8,7,2,3,4,6,5};
    int i =10;
    heapify(arr,i);
    insert(arr,&i,2);
    
}