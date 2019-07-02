#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*************************************************************************************************************
一个已排序好的表 A，其包含 1 和其他一些素数.  当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。

那么第 k 个最小的分数是多少呢?  以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.

构建一个大根堆,里面存储double类型的两个素数的比值
*************************************************************************************************************/
class comp
{
public:
    //构造一个大根堆
    bool operator()(const pair<int,int> &left, const pair<int,int> &right)
    {
        return (double)left.first/left.second < (double)right.first/right.second;
    }
};

class CMyclass
{
public:
    vector<int> fun(int K)
    {
        /**************************************************************************************************
         这里利用了 根堆 求top K 的方法
         算法中，堆中的元素个数始终为K个，调整大根堆的时间复杂度为log2 K,
         所以总的时间复杂度为O(n^2 * log 2K) =====> O(n^2);
         *************************************************************************************************/
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> qu;
        for(int i = 0; i < _nums.size()-1; ++i)
        {
            for(int j = i+1; j < _nums.size(); ++j)
            {
                if(qu.size() < K)
                {
                    qu.push(pair<int,int>(_nums[i],_nums[j]));
                }
                else
                {
                    double tmpn = (double)_nums[i]/_nums[j];
                    double tmpq = (double)qu.top().first/qu.top().second;
                    if(tmpn < tmpq)
                    {
                        qu.pop();
                        qu.push(pair<int,int>(_nums[i],_nums[j]));
                    }
                }
            }
        }
        vector<int> res;
        res.push_back(qu.top().first);
        res.push_back(qu.top().second);
        return res;
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
    int K;
    cout << "输入K:";
    cin >> K;
    vector<int> res = my.fun(K);
    cout << res[0] << "  " << res[1] << endl; 
    return 0;
}
