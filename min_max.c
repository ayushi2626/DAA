#include<stdio.h>
#include<stdlib.h>

int max(int arr[], int start, int end)
{
    if(start<end)
    {
        int mid = (end+start)/2;
        int i = max(arr,start,mid);
        int j =max(arr,mid+1,end);
        if(i>j) return i;
        else return j;
    }
    if(start==end) return arr[start];
}
int min(int arr[], int start, int end)
{
    if(start<end)
    {
        int mid = (end+start)/2;
        int i = min(arr,start,mid);
        int j =min(arr,mid+1,end);
        if(i<j) return i;
        else return j;
    }
    else return arr[start];
}
void main()
{
    int arr[] = {1,85,96,20,3,4,69,77,100,502};
    int n = min(arr,0,9);
    printf("%d",n);
}