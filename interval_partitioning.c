#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
    int s;
    int f;
    int class;
    char* name;
}job;

job* get(int s1,int f1,char name1[])
{
    job* x=(job*)(malloc(sizeof(job)));
    x->s = s1;
    x->f = f1;
    x->name = name1;
    return x;
}
void merge(job** arr,int p,int q,int r)
{   
    int n1 = q-p+1;
    int n2 = r-q;

    job** left = (job**)(malloc(sizeof(job*)*n1));
    job** right = (job**)(malloc(sizeof(job*)*n2));

    for(int i=0;i<n1;i++)
    {
        left[i] = arr[p+i];
    }

    for(int i=0;i<n2;i++)
    {
        right[i] = arr[q+1+i];
    }

    int i,j,k;
    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2)
    {
        if(left[i]->s <= right[j]->s)
        {
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=left[i++];
    }
    while(j<n2)
    {
        arr[k++] = right[j++];
    }
  
}
void merge_sort(job** arr, int l, int r)
{
    if(l<r)
    {
        int m = (r+l)/2;

        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int insert(job** heap,int* i,job* val)
{
    heap[*i] = val;
    int x = *i;
    int j=(*i-1)/2;
    while(j>=0)
    {   
        if(x==0 && j==0)
        {   
            *i = *i+1;
            return x;
        }
        else if(heap[j]->f>heap[x]->f)
        {
            job* xy = heap[x];
            heap[x] = heap[j];
            heap[j] = xy;
            x = j;
            j = (j-1)/2;
        }
        else
        {
            *i=*i+1;
            return x;
        }
    } 
    *i = *i+1;
}
void delete(job** heap,int* i,int pos)
{
    job* x = heap[*i-1];
    heap[*i-1] = heap[pos];
    heap[pos] = x;
    int j = pos;
    *i=*i-1;
    while(j<*i && 2*j+1<*i && 2*j+2<*i)
    {
        
            if(heap[2*j+1]->f<heap[j*2+2]->f && heap[2*j+1]->f<heap[j]->f)
            {
                job* y = heap[2*j+1];
                heap[2*j+1] = heap[j];
                heap[j] = y;
                j = 2*j+1;
            }
            else if(heap[2*j+1]->f>heap[j*2+2]->f && heap[2*j+2]->f<heap[j]->f)
            {
                job* y = heap[2*j+2];
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
    job** list = (job**)(malloc(sizeof(job*)*10));
    int i=0;
    list[i++] = get(0,3,"job1");
    list[i++] = get(0,7,"job2");
    list[i++] = get(0,3,"job3");
    list[i++] = get(4,7,"job4");
    list[i++] = get(4,10,"job5");
    list[i++]= get(8,11,"job6");
    list[i++] = get(8,11,"job7");
    list[i++] = get(10,15,"job8");
    list[i++] = get(12,15,"job9");
    list[i++] = get(12,15,"job10");
    /*sorting the list in increasing order of starting time*/
    merge_sort(list,0,9);
    
    int class[i];
    job** h=(job**)(malloc(sizeof(job*)*i));
    int c=0;
    int k=0;
    int in[i];
    int ind=0;
    int max = list[i-1]->f;
    for(int j=0;j<i;j++)
    {
        job* x = list[j];
        if(j==0)
        {
            int index = insert(heap,&k,x);
            in[ind++] = index;
            x->class = c+1;
        }
        else{
            int prev = list[j-1]->class;
            int tmp = j-1;
            while(tmp>=0)
            {
                if(x->s < list[tmp]->f)
                {   
                    int index = insert(heap,&k,x);
                    in[ind++] = index;
                    x->class = c+1;
                }
                else{
                    if(list[tmp]->f + (x->f - x->s)<max)
                    {
                        x->class = list[tmp]->class;
                        in[ind++] = 
                    }
                }
            }

        }
    }       
    
}