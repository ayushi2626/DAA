

#include<stdio.h>
#include<stdlib.h>
int inv=0;
void merge(int arr[],int s,int mid, int e)
{
    int left[mid-s+1],right[e-mid];
    for(int a=0;a<mid-s;a++)
    {
        left[a] = arr[s+a];
    }
    
     for(int a=0;a<e-mid+1;a++)
    {
        right[a] = arr[mid+1+a];

    }
    int i=0,j=0,k=s;

     while((i<mid-s+1) && (j<e-mid))
    {
        if(left[i]<right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            inv++;
            j++;
        }
        k++;
    }
    while(i<mid-s)
    {
        arr[k] = left[i];
        k++;
        i++;
        inv++;
    }
    while(j<e-mid)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
     
}
void merge_sort(int arr[],int s, int e)
{   
    if(s<e){
        int mid = (e+s)/2;
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
} 

void main()
{   
    int a[]={3,2,1,4,0};
    merge_sort(a,0,6);
    for(int i=0;i<5;i++)
    {
        printf("%d->",a[i]);
    }
}
