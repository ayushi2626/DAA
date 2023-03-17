#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
    int s;
    int f;
    char* name;
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
    job** list =(job**)(malloc(sizeof(job*)*8));
    int i=0;
    list[i++] = get_job(0,6,"job1");
    list[i++] = get_job(1,4,"job2");
    list[i++] = get_job(3,5,"job3");
    list[i++] = get_job(3,8,"job4");
    list[i++] = get_job(4,7,"job5");
    list[i++] = get_job(5,9,"job6");
    list[i++] = get_job(6,10,"job7");
    list[i++] = get_job(8,11,"job8");
    /*Sorting in ascending order wrt to finishing time*/
    merge_sort(list,0,i-1);

    job** arr = (job**)(malloc(sizeof(job*)*i));
    int p=0;
    arr[p] = list[p];
    int tmp=0;
    while(tmp!=i-1)
    {   
        job* x  = arr[p];
        for(int k=0;k<i;k++)
        {
            if(list[k]->s >= x->f)
            {   
                tmp = k;
                p=p+1;
                arr[p] = list[k];
                break;
            }
        }
    }
    for(int j=0;j<=p;j++)
    {
        printf("%s\t",arr[j]->name);
    }
}