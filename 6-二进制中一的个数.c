#include <stdio.h>

int Num(int n)
{
    int count = 0;
    while(n != 0)
    {
        count++;
        n = n&(n-1);
    }
    return count;
}

int main()
{
    printf("%d \n",Num(-1));
    return 0;
}
