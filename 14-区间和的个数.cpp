#include<iostream>
#include <vector>

using namespace std;

/*******************************************************************************
 * 给定一个区间[lower,higher] S(i,j) 表示从i到j 的元素的和，求数组nums中有多少
 * 个这样的S 其中 i <= j 
 * [-2,5,-1] [-2,2] === 》3 (0,0) (0,2) (2,2)
 * 
 * 在时间复杂度O(n^2)上进行优化
 *
 * 分治法 求连续子数组的最大和
 *      : 
 ******************************************************************************/

int _count = 0;

class Myclass
{
    public:
        Myclass(int lower = 0,int higher = 0)
            :_lower(lower),_higher(higher)
        {}
        int fun()
        {
            for(int i = 0; i < _nums.size(); i++)
            {
                int sum = 0;
                for(int j = i; j < _nums.size(); j++)
                {
                    sum += _nums[j];
                    if(sum >= _lower && sum <= _higher)
                    {
                        _count++;
                    }
                }
            }
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

        void display()
        {
            cout << _count << endl;
        }
        
        int getSize()
        {
            return _nums.size();
        }

    private:
        vector<int> _nums;
        //int _count;
        int _lower;
        int _higher;
};

int main()
{
    Myclass my(-2.2);
    my.setNums();
    //my.fun(-2,2);
    my.Merge(0,my.getSize()-1);
    my.display();
    return 0;
}
