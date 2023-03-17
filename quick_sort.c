#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int start,int end)
{
    int pivot = a[start];
    int i=start+1;

    for(int j=start+1;j<=end;j++)
    {
        if(a[j]<pivot)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
        }
    }
    int tmp = a[i-1];
    a[i-1] = a[start];
    a[start] = tmp;
    return i-1;
}

void quick_sort(int a[], int start, int end)
{
    if(start<end)
    {
        int l = partition(a,start,end);
        quick_sort(a,start,l-1);
        quick_sort(a,l+1,end);
    }
}

void main()
{
    int a[] = {3,2,1,8,6,0};
    quick_sort(a,0,5);
    for(int i=0;i<=4;i++)
    {
        printf("%d\n",a[i]);
    }
}