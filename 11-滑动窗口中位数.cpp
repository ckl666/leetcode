#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

/*************************************************************
 * 给定滑动窗口的大小，每次向后移动一位，记录每次移动后的
 * 中位数，并输出中位数数组
 ************************************************************/
class Compair
{
public:
    bool operator()(const pair<int,int> &left,const pair<int,int> &right)
    {
        return left.second < right.second;
    }

};



class CMyclass
{
public:
    //k表示滑动窗口的大小
    vector<double> fun(int k)
    {
        pair<int,int> pa;
        vector<double> resoult;
        set<pair<int,int>,Compair> s;
        for(int i = 0; i < k; i++)
        {
            pa.first = i;
            pa.second = _nums[i];
            s.insert(pa);
        }
        
        set<pair<int,int> >::iterator it = s.begin();
        int index = k/2;
        double data;
        for(int j = 0; j < index; j++)
        {
            ++it;
        }
        if(k % 2 == 0)
        {
            data = ((double)it->second + (++it)->second) /2;
        }
        else
        {
            data = (double)it->second;
        }
        resoult.push_back(data);
        
        for(int i = k; i < _nums.size(); i++)
        {
            //删除一个元素
            pa.first = i-k;
            pa.second = _nums[i-k];
            s.erase(pa);
            
            //添加一个元素
            pa.first = i;
            pa.second = _nums[i];
            s.insert(pa);

            it = s.begin();
            for(int j = 0; j < index; j++)
            {
                ++it;
            }
            if(k % 2 == 0)
            {
                data = ((double)it->second + (++it)->second) /2;
            }
            else
            {
                data = (double)it->second;
            }
            resoult.push_back(data);
        }
        return resoult;
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
private:
    vector<int> _nums;
};



int main()
{
    CMyclass my;
    my.setNums();
    vector<double> vec = my.fun(3);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
