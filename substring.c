#include<stdio.h>
#include<stdlib.h>

void match(char p[],char m[],int s1,int s2)
{
    for(int i=0;i<s1-s2;i++)
    {   
        int check=1;
        for(int j=0;j<s2;j++)
        {
            if(p[i+j]==m[j] || m[j]=='*')
            {
                check=1;
            }
            else
            {
                check=0;
                break;
            }
        }
        if(check==1) printf("%d ",i);
    }
}
void main()
{
    char s1[] = "ababbab";
    char s2[] = "ab*";
    int m[7];
    match(s1,s2,7,3);
}