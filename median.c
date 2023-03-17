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
        int m = l + (r-l)/2;

        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(l,m,r,arr);
    }
}
int median_sub(int arr[], int start, int end)
{
    merge_sort(arr,start,end);
    return arr[(start+end)/2];
}

int median_find(int arr[], int start, int end,int p)
{
    if((end-start)+1>5)
    {   
        int e = 4,k=0;
        int s=start;
        int sub = (end-start)/5;
        int median[sub+1];
        for(int i=0;i<sub;i++)
        {
            median[k++] = median_sub(arr,start,e);
            start = e+1;
            e = e+5;
        }
        if(5*k <= (end-start)+1)
        {
            median[k++] = median_sub(arr,e+1,end);
        }
        start = s;
        int m = (k==1)?median[k-1]:median_find(median,0,k-1,(k-1)/2);

        int pos;
        for(int j=0;j<=end;j++)
        {
            if(arr[j]==m)
            {
                pos = j;
                break;
            }
        }
        
        int tmp = arr[pos];
        arr[pos] = arr[start];
        arr[start] = tmp;
        int pivot = arr[start];
        int i=start+1;
         
        for(int j=start+1;j<=end;j++)
        {
            if(arr[j]<pivot)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
            }
        }
        tmp = arr[i-1];
        arr[i-1] = arr[start];
        arr[start] = tmp;

        if(i-1 == p)
        return pivot;

        if( i-1<p)
        return median_find(arr,i,end,p-i);
        
        if(i-1>p)
        return median_find(arr,start,i-2,p);
    }
    else
    {
        merge_sort(arr,start,end);
        return arr[p+start];
    }
}
void main()
{
    int arr[]={1,2,3,4,5,6,7};
    int m = median_find(arr,0,6,3);
    printf("%d",m);

}