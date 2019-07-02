#include <iostream>
#include <vector>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define MAX_INT 0x3f3f3f3f
#define MIN_INT -0x3f3f3f3f

//非递归算法
//分割数组
float MidNum(vector<int> &arr1,vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    if(n > m)
    {
        return MidNum(arr2,arr1);
    }

    int L1,L2,R1,R2,low = 0,high=2*n;
    while(low < high)
    {
        int c1 = (low + high)/2;
        int c2 = n+m-c1;
        L1 = (c1 == 0)?MIN_INT:arr1[(c1-1)/2];
        R1 = (c1 == 2*n)?MAX_INT:arr1[c1/2];
        L2 = (c2 == 0)?MIN_INT:arr2[(c2-1)/2];
        R2 = (c2 == 2*m)?MAX_INT:arr2[c2/2];

        if(L1 > R2)
        {
            high = c1-1;
        }
        else if(L2 > R1)
        {
            low = c1+1;
        }
        else
        {
            break;
        }
    }
    return (max(L1,L2) + min(R1,R2))/2.0;
}

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    cout << "输入两个数组的长度:";
    int size1,size2;
    cin >> size1 >> size2;
    int i = 0;
    for(; i < size1; i++)
    {
        int data;
        cin >> data;
        arr1.push_back(data);
    }
    for(i = 0; i < size2; i++)
    {
        int data;
        cin >> data;
        arr2.push_back(data);
    }
    float mid = MidNum(arr1,arr2);
    cout << mid << endl;
    return 0;
}
