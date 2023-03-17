#include<stdio.h>

int unimodal(int arr[],int l, int h)
{
    int mid = (l+h)/2;
    if(arr[mid]<arr[mid+1])
    {
        if(arr[mid+1]>arr[mid+2])
        {
            return arr[mid+1];
        }
        else
        {
            return unimodal(arr,mid+1,h);
        }
    }
    else
    {
        return unimodal(arr,l,mid);
    }
}

int main()
{
    int a[] = {1,2,3,4,3,2};
    int largest = unimodal(a,0,5);
    printf("%d",largest);
}