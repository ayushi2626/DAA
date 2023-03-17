#include<stdio.h>
#include<stdlib.h>

int* merge(int *right,int *left, int n1, int n2)
{   
   
    int *arr = (int*) malloc(sizeof(int)*(n1+n2));

    int i=0,k=0,j=0;

    while(i<=n1 && j<=n2)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<=n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<=n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return &arr[0];
}

int* merge_sort(int *a, int start, int end)
{   
    if(end==start)
    {
        int *b = (int*) malloc(sizeof(int));
        *b = a[start];
        return b;
    }
    int mid = (end+start)/2;

    int *left_sorted = merge_sort(a, start, mid);
    int *right_sorted = merge_sort(a,mid+1,end);
    int n_left = mid-start;
    int n_right = end-mid-1;

    int *merged_arr = merge(left_sorted, right_sorted,n_left, n_right);
    
    return merged_arr;
}
void main()
{
    int a[]={2,5,8,1};
    int *sorted = merge_sort(a,0,3);
    for(int i =0;i<4;i++)
    {
        printf("%d\n",*(sorted+i));
    }

}