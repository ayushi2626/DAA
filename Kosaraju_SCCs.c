#include<stdio.h>
#include<stdlib.h>


int graph[7][7] = {
    {0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0},
    {0,0,0,1,0,0,1},
    {0,0,0,0,0,0,0}
};
int graph_2[7][7] = {
    {0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0}
};

int visited[7] = {0,0,0,0,0,0,0};
int visited_2[7] = {0,0,0,0,0,0,0};
int count=0;
int t=0;


void DFS(int i,int* arr)
{
    int j;
    visited[i] = 1;
    for(j=0;j<7;j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {
            DFS(j,arr);
        }
    }
    arr[count++] = i;
}
void DFS_rev(int i)
{
    int j;
    visited_2[i] = 1;
    for(j=0;j<7;j++)
    {
        if(graph_2[i][j]==1 && !visited_2[j])
        {   
            DFS_rev(j);
        }
    }
}

void main()
{    
    int *arr = (int*)malloc(7*sizeof(int));
    for(int i=0;i<=6;i++)
    {      
        if(visited[i]==0)
        {
            DFS(i,arr);
        }
    }
    
    for(int i=6;i>=0;i--)
    {
        if(visited_2[arr[i]]==0)
        {   
            DFS_rev(arr[i]);
            t+=1;
        }
    }
    printf("%d",t);
    free(arr);

}
