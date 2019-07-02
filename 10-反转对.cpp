#include <iostream>
#include <vector>

using namespace std;

/**********************************************************
 * 给定一个数组nums 如果i < j 并且 nums[i] > 2*nums[j]
 * 就说(i, j)是一个反转对
 *********************************************************/
class CMyclass
{
public:
    CMyclass(int count = 0):_count(count){}
    
    void fun()
    {
        for(int i = 0; i < _nums.size()-1; i++)
        {
            for(int j = i+1; j < _nums.size(); j++)
            {
                if(_nums[i] > 2*_nums[j])
                {
                    _count++;
                }
            }
        }
    }

    void setNums()
    {
        cout << "输入数组的大小:";
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
private:
    vector<int> _nums;
    int _count;
};



int main()
{
    CMyclass my;
    my.setNums();
    my.fun();
    my.display();
    return 0;
}
