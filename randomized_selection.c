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

int randomized_selection(int a[],int start, int end,int index)
{   
    index = index-1;
    if(end - start==0)
    {
        return a[start];
    }
    else
    {   
        int n = 1 + ( rand() % (end-start+1));
        int tmp = a[n];
        a[start] = a[n];
        a[n] = tmp;
        int l = partition(a,start,end);
        if(l<index)
        {
            int n = randomized_selection(a,l+1,end,index);
            return n;
        }
        else if(l>index)
        {
            int n = randomized_selection(a,start,l-1,index);
            return n;
        }
        else
        {
            return a[l];
        }
    }
}
void main()
{
    int a[] = {3,2,4,6,9};
    int number = randomized_selection(a,0,4,4);
    printf("%d",number);
}