//将m变为n
#include <stdio.h>

int Change(int m,int n)
{
    int count = 0;  //统计变化的次数
    int x = m^n;
    while(x != 0)
    {
        count++;
        x = x&(x-1);
    }
    return count;
}

int main()
{
    int m = 10;
    int n = 13;
    printf("%d \n",Change(m,n));
    return 0;
}
