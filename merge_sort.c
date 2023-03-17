#include<stdio.h>
#include<stdlib.h>

void merge(int p,int q,int r, int arr[])
{   
    int n1 = q-p+1;
    int n2 = r-q;

    int left[n1], right[n2];

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
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
  
}

void merge_sort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (r+l)/2;

        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        merge(l,m,r,arr);
    }
}

void main()
{
    int a[] = {2,98,6,1,3};
    merge_sort(a,0,4);
    for(int i=0;i<=4;i++)
    {
        printf("%d\t", a[i]);
    }
}