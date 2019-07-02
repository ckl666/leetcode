#include <stdio.h>

int RectangleCover(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else
    {
        return RectangleCover(n-1)+RectangleCover(n-2);
    }
}

int main()
{
    printf("%d \n",RectangleCover(4));
    return 0;
}
