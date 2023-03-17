#include<stdio.h>
#include<stdlib.h>

int cross_over_sum(int arr[],int low,int mid,int high)
{
    int l_sum = -100;
    int sum=0;
    int left;
    for(int i=mid;i>=0;i--)
    {
        sum+=arr[i];
        if(sum>l_sum)
        {
            l_sum = sum;
            left = i;
        }
    }
    int r_sum = -100;
    sum=0;
    int right;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=arr[i];
        if(sum>r_sum)
        {
            r_sum =sum;
            right = i;
        }
    }
    return r_sum+l_sum;
}
int max_subarray(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        int lsum = max_subarray(arr,left,mid);
        int rsum = max_subarray(arr,mid+1,right);
        int cross_sum = cross_over_sum(arr,left,mid,right);
        if(lsum>rsum && lsum>cross_sum)
        return lsum;
        else if(lsum<rsum && rsum>cross_sum)
        return rsum;
        else return cross_sum;
    }
    if(left==right) return arr[0];
}
void main()
{
    int arr[] = {5,1,-2,3,-6,50};
    int s =  max_subarray(arr,0,5);
    printf("%d",s);
}