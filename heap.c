#include<stdio.h>
#include<stdlib.h>

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
void delete(int heap[],int* i,int pos)
{
    int x = heap[*i-1];
    heap[*i-1] = heap[pos];
    heap[pos] = x;
    int j = pos;
    *i=*i-1;
    while(j<*i && 2*j+1<*i && 2*j+2<*i)
    {
        
            if(heap[2*j+1]>heap[j*2+2] && heap[2*j+1]>heap[j])
            {
                int y = heap[2*j+1];
                heap[2*j+1] = heap[j];
                heap[j] = y;
                j = 2*j+1;
            }
            else if(heap[2*j+1]<heap[j*2+2] && heap[2*j+2]>heap[j])
            {
                int y = heap[2*j+2];
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
void print(int* heap,int* i)
{
    for(int j=0;j<(*i);j++)
    {
        printf("%d-",heap[j]);
    }
}
void main()
{   
    int n=0;
    printf("Enter the total heap size\n");
    scanf("%d",&n);
    int* heap=(int*)(calloc(n,sizeof(int)));
    int i=0;
    heap[i++] = 90;
    heap[i++] = 89;
    heap[i++] = 70;
    heap[i++] = 36;
    heap[i++] = 75;
    heap[i++] = 63;
    heap[i++] = 65;
    heap[i++] = 21;
    heap[i++] = 18;
    heap[i++] = 15;
    delete(heap,&i,0);
    print(heap,&i);
    printf("\n");
    int count=0;
    int c = i;
    for(int j=0;j<c;j++)
    {
        printf("%d-",heap[0]);
        delete(heap,&i,0);
    }
    printf("\n");
     
}