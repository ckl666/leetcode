#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define BIG 214748

//动态规划
//c[i][j] = min{c[i-1][j],1+c[i][j-T[i]]}

void Show(int *arr,int row,int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%-7d ",arr[i*col+j]);
        }
        printf("\n");
    }
}


int min(int a,int b)
{
    return a<b?a:b;
}

//t 数组存放硬币的面值，coins存放硬币的个数，n表示找的零钱数
int MinCoins(int *t,int len,int n)
{
    int *arr = (int *)malloc(sizeof(int) *(len)*(n+1));
    assert(arr != NULL);
    memset(arr,BIG,sizeof(int)*len*(n+1));
    int i = 0;
    /*
    for(i = 0; i <= n; i++)
    {
        arr[i] = i%t[0]==0?(i/t[0]>coins[0]?BIG:(i/t[0])):BIG;
    }
    */
    for(i = 0; i <= n; i++)
    {
        arr[i] = i%t[0]==0?i/t[0]:BIG;
    }
    int j = 0;
    for(i = 1; i < len; i++)
    {
        arr[i*(n+1)] = 0;
        for(j = 1; j <= n; j++)
        {
            if(j-t[i] >= 0)
            {
                arr[i*(n+1)+j] = min(arr[(i-1)*(n+1)+j],1+arr[i*(n+1)+(j-t[i])]);
            }
            else
            {
                arr[i*(n+1)+j] = arr[(i-1)*(n+1)+j];
            }
        }
    }
    Show(arr,len,n+1);
}

int main()
{
    int t[] = {1,2,5};
    //int coins[] = {3,3,3};
    int len = sizeof(t)/sizeof(t[0]);
    MinCoins(t,len,18);
    return 0;
}
