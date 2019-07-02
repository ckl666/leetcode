#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//动态规划
//时间复杂度O(maxVal*n)
int Count(int n,int maxVal,int num)
{
    int *tmp[2];
    tmp[0] = new int[(maxVal+1)*n];
    tmp[1] = new int[(maxVal+1)*n];
    int *des = tmp[0];
    int *src = tmp[1];
    int i = 0;
    for(i = 0; i < n*(maxVal+1); i++)
    {
        src[i] = 0;
    }
    for(i = 1; i <= maxVal; i++)
    {
        src[i] = 1;
    }
    //maxVAl*maxVal*n*n
    for(i = 1; i < n; i++)
    {
        int j = 0;
        for(j = 0; j <= maxVal; j++)
        {
            int k = 0;
            for(k = 0; k < j;k++)
            {
                des[j] += src[k];
            }
        }
        for(; j<=maxVal*n; j++)
        {
            int k = j-1;
            for(k = j-1; k > j-maxVal-1; k--)
            {
                des[j] += src[k];
            }
        }
        int *p = des;
        des = src;
        src = p;
    }
    int count = src[num];
    delete []tmp[0];
    delete []tmp[1];
    return count;
}



//n 表示骰子的个数 m表述出现的数字
/*递归 时间复杂度为指数级的maxVal^n
int count = 0;

void Probability(int i,int sum,int n,int num)
{
    if(i == n)
    {
        if(sum == num)
        {
            count++;
        }
    }
    else
    {
        int j = 0;
        for(j = 1; j <= 6; j++)
        {
            Probability(i+1,sum+j,n,num);
        }
    }
}

double Fun(int n,int num)
{
    Probability(0,0,n,num);
    return (double)count/pow((double)6,n);
}
*/
double Fun(int n,int num)
{
    int count = Count(n,6,num);
    return (double)count/pow((double)6,n);
}

int main()
{
    //double d = pow((double)6,3);
    int n = 5;
    int num = 20;
    double d = Fun(n,num);
    //printf("%f\n",)
    printf("%f\n",d);
    return 0;
}
