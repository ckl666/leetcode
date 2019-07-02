#include <iostream>
#include <vector>

using namespace std;
/************************************************************************************
给定一个整数数组 A，找出索引为 (i, j, k) 的三元组，使得：
0 < A.length <= 1000
A[i] <= 2048 100000000000

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0，其中 & 表示按位与（AND）操作符。
输出符合条件的个数
************************************************************************************/
class Myclass
{
public:
/*
 * 三个下标不同 6种
 * 其中两个相同 3种
 * 三个下标都相同 1种
 */
    //O(n^3)
    int fun()
    {
        int count = 0;
        for(int i = 0; i < _nums.size(); ++i)
        {
            for(int j = 0; j < _nums.size(); ++j)
            {
                for(int k = 0; k < _nums.size(); ++k)
                {
                    int tmp = _nums[i] & _nums[j];
                    tmp = tmp & _nums[k];
                    if(tmp == 0)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    void setNum()
    {
        cout << "输入size:";
        int size;
        cin >> size;
        for(int i = 0; i < size; i++)
        {
            int data;
            cin >> data;
            _nums.push_back(data);
        }
    }
private:
    vector<int> _nums;
};



int main()
{
    Myclass my;
    my.setNum();
    cout << my.fun() << endl;
    return 0;
}
