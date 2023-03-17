#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>

int operate(int a, int b, char o)
{
    if(o=='+') return a+b;
    if(o=='-') return b-a;
    if(o=='*') return a*b;
    if(o=='/') return b/a;
}
void main()
{
    int top=-1;
    int size = 11;
    int arr[size];
    int top1=-1;
    int size1 = 11;
    int arr1[size1];
    char s[12];
    printf("Enter: ");
    gets(s);
    for(int i=0;i<=size;i++)
    {
        if(isalnum(s[i]))
        {   
            char z='0';
            if(isalnum(s[i+1]))
            {   
                int num=0;
                int j=i;
                while(isalnum(s[j]) && s[j]!='\0')
                {
                    int x = s[j] - z;
                    num=10*num+x;
                    j++;
                }
                arr[++top] = num;
                i=j-1;
            }
            else
            {
                arr[++top] = s[i] - z;
            }
        }
    }
    for(int i=0;i<=11 && top!=0;i++)
    {   
        if(!isalnum(s[i]) && s[i]!=' ')
        {
            int a = arr[top--];
            int b = arr[top--];
            int res = operate(a,b,s[i]);
            arr[++top] = res;
        }
    }
    printf("%d",arr[top]);
}