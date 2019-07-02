#include <stdio.h>

#define N 0.0000001


//高效率求解高次幂
double Fun(double base,int n)
{
    if(n == 1)
    {
        return base;
    }
    else
    {
        double tmp = Fun(base,n/2);
        if(n % 2 == 0)
        {
            return tmp*tmp;
        }
        else
        {
            return tmp*tmp*base;
        }
    }
}

double Pow(double base,int n)
{
    double resoult = 1.0;
    int i = 0;
    if(n >= 1)
    {
        resoult = Fun(base,n);
    }
    else if(n < 0)
    {
        if(base > -N && base < N)
        {
            return -1;  //异常处理
        }
        resoult = 1.0/Fun(base,-n);
    }
    return resoult;
}

int main()
{
    printf("%f\n",Pow(2.0,3));
    printf("%f\n",Pow(-2.0,3));
    printf("%f\n",Pow(2.0,-3));
    printf("%f\n",Pow(0,3));
    printf("%f\n",Pow(0,-3));
    return 0;
}
