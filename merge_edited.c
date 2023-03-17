#include<stdio.h>
#include<stdlib.h>

int* merge(int *left,int *right, int n1, int n2)
{   
   // CHANGED: no need to copy a and b to left and right, just use directly
    int *arr = (int*) malloc(sizeof(int)*(n1+n2));
    int i=0,k=0,j=0;

    while(i<n1 && j<n2)
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
    while(i<n1) // CHANGED: not <=; it should be < n1
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2) // CHANGED: not <=; it should be < n2
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return arr; // CHANGED: return arr
    //free(arr);  ummm you're writing a statement after the return statement? u drunk?
}

int* merge_sort(int *a, int start, int end)
{   
    if(end==start) // CHANGED: Here is the main problem
    { // You need to return the subarray of a from index start to index end
        int* b = (int*)malloc(sizeof(int));
        b[0]=a[start];
        return b;
    }
    int mid = (end+start)/2;
    int n_left = mid - start + 1; // CHANGED: add -start: mid - start + 1
    int n_right = end - mid; // CHANGED: end-mid because end - (mid+1) + 1 = end-mid
    int *left_sorted = merge_sort(a, start, mid); // CHANGED: a,start, mid not 0
    int *right_sorted = merge_sort(a,mid+1,end);
    int *merged_arr = merge(left_sorted, right_sorted,n_left, n_right);
    free(left_sorted);
    free(right_sorted);
    return merged_arr;
}
int main()
{
    int a[]={4,3,5,8,1};
    int *sorted = merge_sort(a,0,4);
    for(int i =0;i<5;i++)
    {
        printf("%d\n",sorted[i]);
    }
    return 0;
}