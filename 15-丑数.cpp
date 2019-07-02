#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void Show(vector<int> arr)
{
    int i = 0;
    while(i < arr.size())
    {
        cout<<arr[i]<<" ";
        if(i % 10 == 0)
        {
            cout<<endl;
        }
        i++;
    }
}

int Min(int a,int b,int c)
{
    a = a>b?b:a;
    return a>c?c:a;
}

int GetUglyNumber(int index)
{
    if(index  <= 0)
    {
        return 0;
    }
    vector<int> arr;
    int max = 1;
    arr.push_back(1);
    int t2 = 0,t3 = 0,t5 = 0;
    int m2,m3,m5;
    int i = 1;
    while(i < index)
    {
        while(arr[t2]*2 <= max)
        {
            t2++;
        }
        m2 = arr[t2]*2;
        while(arr[t3]*3 <= max)
        {
            t3++;
        }
        m3 = arr[t3]*3;
        while(arr[t5]*5 <= max)
        {
            t5++;
        }
        m5 = arr[t5]*5;
        max = Min(m2,m3,m5);
        arr.push_back(max);
        i++;
    }
    //Show(arr);
    return arr[index-1];
}

int main()
{
    int index = 100;
    cout<<GetUglyNumber(index)<<endl;
    return 0;
}
