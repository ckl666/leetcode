#include <iostream>
#include <vector>

using namespace std;

/**************************************************************************************************************************
给定一个由 0 和 1 组成的数组 A，将数组分成 3 个非空的部分，使得所有这些部分表示相同的二进制值。

如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：

A[0], A[1], ..., A[i] 组成第一部分；
A[i+1], A[i+2], ..., A[j-1] 作为第二部分；
A[j], A[j+1], ..., A[A.length - 1] 是第三部分。
这三个部分所表示的二进制值相等。
如果无法做到，就返回 [-1, -1]。

注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0] 表示十进制中的 6，而不会是 3。
此外，前导零也是被允许的，所以 [0,1,1] 和 [1,1] 表示相同的值。
 **************************************************************************************************************************/

class CMyclass
{
public:

    //计算指针下标的时间复杂度为O(n)
    vector<int> fun()
    {
        vector<int> index;
        vector<int> resoult;
        resoult.push_back(-1);
        resoult.push_back(-1);
        for(int i = _nums.size()-2; i >= 0; --i)
        {
            if(_nums[i] == _nums[_nums.size()-1])
            {
                index.push_back(i);
            }
        }
        int p1 = _nums.size()-1;
        int p2,p3;
        while(!index.empty())
        {
            p2 = index.front();
            index.erase(index.begin());
            for(int i = 0; i < index.size(); i++)
            {
                p3 = index[i];
                int t3 = p3,t1 = p1,t2 = p2;
                while(t1 > p2 && t2 > p3 && t3 >=0)
                {
                    if(_nums[t1] == _nums[t2] && _nums[t3] == _nums[t2])
                    {
                        --t1; --t2; --t3;
                    }
                    else
                    {
                        break;
                    }
                }
                while(t1 > p2)
                {
                    if(_nums[t1] == 0)
                    {
                        --t1;
                    }
                    else
                    {
                        break;
                    }
                }
                while(t2 > p3)
                {
                    if(_nums[t2] == 0)
                    {
                        --t2;
                    }
                    else
                    {
                        break;
                    }
                }
                while(t3 >= 0)
                {
                    if(_nums[t3] == 0)
                    {
                        --t3;
                    }
                    else
                    {
                        break;
                    }
                }
                if(t1 == p2 && t2 == p3 && t3 == -1)
                {
                    resoult[0] = p3;
                    resoult[1] = p2+1;
                    return resoult;
                }
            }
        }
        return resoult;
    }

    void setNums()
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
    CMyclass my;
    my.setNums();
    vector<int> res = my.fun();
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
