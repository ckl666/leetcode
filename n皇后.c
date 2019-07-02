#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//回溯算法
//n*n的棋盘 n个皇后彼此不能再同一行或同一列。或对角线
//输出一个位置
//每个king 占据一行，只要按顺序输出列

void Show(int *arr,int n)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ",arr[i*n+j]);
        }
        printf("\n");
    }
}


bool NKing(int n)
{
    int *arr = (int *)malloc(sizeof(int)*n*n);
    int *stack = (int *)malloc(sizeof(int)*2*n);
    int *hash = (int *)malloc(sizeof(int)*n);
    assert(hash != NULL && arr != NULL && stack != NULL);
    memset(arr,0,sizeof(int)*n*n);
    memset(hash,0,sizeof(int)*n);
    int top = 0;

    stack[top++] = 0;
    stack[top++] = 0;
    arr[0] = 1;
    int j = 0;
    int i = 1;
    hash[0] = 1;
    while(i < n)
    {
        for(; j < n; j++)
        {
            if(i == 0)
            {
                break;
            }
            if(j == 0)
            {
                if(hash[j] == 0 && arr[(i-1)*n+j] != 1 && arr[(i-1)*n+j+1] != 1)
                {
                    break;
                }
            }
            else if(j == n-1)
            {
                if(hash[j] == 0 && arr[(i-1)*n+j] != 1 && arr[(i-1)*n+j-1] != 1)
                {
                    break;
                }
            }
            else
            {
                if(hash[j] == 0 && arr[(i-1)*n+j] != 1 && arr[(i-1)*n+j-1] != 1 && arr[(i-1)*n+j+1] != 1)
                {
                    break;
                }
            }
        }
        if(j == n && top > 0)
        {
            j = stack[--top]+1;
            i = stack[--top];
            arr[i*n+j-1] = 0;
            hash[j-1] = 0;
        }
        else if(j != n)
        {
            arr[i*n+j] = 1;
            stack[top++] = i;
            stack[top++] = j;
            hash[j] = 1;
            i++;
            j= 0;
        }
        else
        {
            free(stack);
            free(hash);
            Show(arr,n);
            free(arr);
            return false;
        }
    }
    free(stack);
    free(hash);
    Show(arr,n);
    free(arr);
    return true;
}

int main()
{
    NKing(8); 
    return 0;
}

