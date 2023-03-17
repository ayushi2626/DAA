#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int knapsack(int v[],int w[],int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    else
    {
        if(w[n]<W)
        {   
            return max(v[n] + knapsack(v,w,n-1,W-w[n]),knapsack(v,w,n-1,W));
        }
        else return knapsack(v,w,n-1,W);
    }
}
int knapsack_opt(int* w,int* v,int **arr,int n,int W)
{   
    int curr=0;
    for(int i=1;i<n && curr<n;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(w[curr]>j)
            {
                arr[i][j] = arr[i-1][j];
            }
            else
            {
                if(v[curr]+arr[i-1][j-w[curr]]>arr[i-1][j])
                {
                    arr[i][j] = v[curr]+arr[i-1][j-w[curr]];
                }
                else{
                    arr[i][j] = arr[i-1][j];
                }
            }
        }
        curr++;
    }
}
void main()
{
    int v[5] = {2,2,4,5,3};
    int w[5] = {3,1,3,4,2};
    int i=6;
    int W=8;
    
    int **arr = (int **)malloc(i * sizeof(int *));
    for (int r = 0; r < 7; r++) {
        arr[r] = (int *)malloc(W * sizeof(int));
    }
    for(int a=0;a<W;a++)
    {
        arr[0][a]=0;
    }
    knapsack_opt(w,v,arr,i,W);
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<W;b++)
        {
            printf("%d ",arr[a][b]);
        }
        printf("\n");
    }
}



