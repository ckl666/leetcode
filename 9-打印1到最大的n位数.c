#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//考虑最大数问题
/*
void Print(int n)
{
    if(n <= 0)
    {
        printf("输入错误\n");
        return ;
    }
    char *num = (char *)malloc(sizeof(char)*(n+1));
    assert(num != NULL);
    memset(num,0,sizeof(char)*(n+1));
    int capacity = 0;
    int i = 0;
    while(capacity <= n)
    {
        i = 0;
        while(i <= capacity)
        {
            if(num[i] == '\0')
            {
                num[i] = '1';
                capacity++;
                break;
            }
            else if(num[i] == '9')
            {
                num[i] = '0';
                i++;
            }
            else
            {
                num[i] += 1;
                break;
            }
        }
        if(capacity > n)
        {
            break;
        }
        i = capacity-1;
        while(i >= 0)
        {
            printf("%c",num[i--]);
        }
        printf("\n");
    }
    free(num);
}

int main()
{
    Print(1);    
    Print(9);    
    return 0;
}
*/

void Print(int n,int i,char *num)
{
    if(n <= 0)
    {
        printf("输入错误\n");
        return ;
    }
    if(i >= n)
    {
        int j = 0;
        while(num[j] == '0')
        {
            j++;
        }
        for(; j < n; j++)
        {
            printf("%c",num[j]);
        }
        printf("\n");
    }
    else
    {
        int j = 0;
        for(j = 0; j <= 9; j++)
        {
            num[i] = j+'0';
            Print(n,i+1,num);
        }
    }
}

int main()
{
    int n = 2;
    char *num = (char*)malloc(sizeof(char)*(n+1));
    memset(num,'0',sizeof(char)*(n));
    Print(n,0,num);
}
