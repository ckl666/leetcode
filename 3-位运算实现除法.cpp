#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace std;


int Div(int D,int d)
{
    assert(d != 0);
    bool flag = false;
    if(d*D > 0)
    {
        flag = true;
    }
    D = abs(D);
    d = abs(d);

    if(D < d)
    {
        return 0;
    }
    int num = 1;
    int sum = 0;
    int tmp = d;
    while( 1 )
    {
        while(D >= d)
        {
            d = d << 1;
            num *= 2;
        }
        d = d >> 1;
        num /= 2;
        if(D - d < d)
        {
            sum += num;
            break;
        }
        else
        {
            D = D-d;
            d = tmp;
            num = 1;
        }
    }
    if(!flag)
    {
        sum = -sum;
    }
    return sum;
}


int main()
{
    int D,d;
    cin >> D;
    cin >> d;
    cout << Div(D,d) << endl;
    return 0;
}
