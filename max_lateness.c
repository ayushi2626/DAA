#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
    int s;
    int f;   /* f is deadline*/
    char* name;
    int start;
}job;

job* get_job(int start,int finish,char n[])
{
    job* x = (job*)(malloc(sizeof(job)));
    x->s = start;
    x->f = finish;
    x->name = n;
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
        if(left[i]->f <= right[j]->f)
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
void main()
{
    job** list = (job**)(malloc(sizeof(job*)*6));
    int i=0;
    list[i++] = get_job(3,6,"job1");
    list[i++] = get_job(2,8,"job2");   /* first one is length, deadline is d*/
    list[i++] = get_job(1,9,"job3");
    list[i++] = get_job(4,9,"job4");
    list[i++] = get_job(3,14,"job5");
    list[i++] = get_job(2,15,"job6");

    merge_sort(list,0,i-1);
    int s_t=0;
    for(int j=0;j<i;j++)
    {
        job* x = list[j];
        if(j==0)
        {
            x->start = s_t;
            s_t+= x->s;
        }
        else
        {
            if((x->f - s_t) >=x->s)
            {
                x->start = s_t;
                s_t+=x->s;
            }  
            else
            {
                x->start =0;
            }
        }
    }
    for(int k=0;k<i;k++)
    {
        printf("%d ",list[k]->start);
    }
}