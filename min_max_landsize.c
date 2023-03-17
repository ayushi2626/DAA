#include<stdio.h>
#include<stdlib.h>

int space[6][6] = {
    {0,1,0,0,0,0},
    {1,1,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,1,1,0},
    {0,1,0,1,1,0},
    {0,0,0,0,0,0}
};
int visited[6][6] = {
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
};
int size =0;
int count=0;

void explore(int i, int j)
{   
    if(i>=0 && i<=5 && j>=0 && j<=5)
    {   
        if(space[i+1][j]==1 && visited[i+1][j]==0)
        {   
            visited[i+1][j]=1;
            size++;
            explore(i+1,j);
        }
        if(space[i-1][j]==1 && visited[i-1][j]==0)
        {   
            visited[i-1][j]=1;
            size++;
            explore(i-1,j);
        }
        if(space[i][j+1]==1 && visited[i][j+1]==0)
        {   
            visited[i][j+1] = 1;
            size++;
            explore(i,j+1);
        }
        if(space[i][j-1]==1 && visited[i][j-1]==0)
        {   
            visited[i][j-1]=1;
            size++;
            explore(i,j-1);
        }
    }      
}

void search()
{
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=5;j++)
        {   
            if(visited[i][j]==0 && space[i][j]==1)
            {
                explore(i,j);
                if(count<size)
                count=size;
                size=0;
            }
        }
    }
}

void main()
{
    search();
    printf("%d",count);
}
