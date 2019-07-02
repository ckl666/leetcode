#include <iostream>
#include <vector>

using namespace std;
/*******************************************************************************************************************
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

dp[i][j][k] = dp[i][n][count] + dp[n+1][j][k-count];

1,2,4,2,5,7,2,4,9,0
*******************************************************************************************************************/
#define MAX 20
#define min(x,y) ((x) > (y) ? (y) : (x))


class CMyclass
{
public:

    int fun(int K)
    {
        vector<vector<vector<int> > > vec;
        vec.resize(_nums.size()+1);
        for( int i = 0; i < _nums.size()+1; i++)
        {
            vec[i].resize(_nums.size()+1);
            for(int j = 0; j < _nums.size()+1; j++)
            {
                vec[i][j].resize(K);
            }
        }

        for(int i = 1; i < _nums.size()+1; ++i)
        {
            for(int j = 0; j+i < _nums.size(); ++j)
            {
                int m = _nums[j+i] - _nums[j];
                if(m <= 0)
                {
                    vec[i][j][0] = 0;
                }
                else
                {
                    vec[i][j][1] = m;
                }
                for(int k = j; k < j+i; k++)
                {
                    for(int n = 0; n < K; n++)
                    {
                           
                    }
                }
            }
        }
    }

#if 0
    int fun(int K)
    {
        /****************************************************************************************************
         * 动态规划
         * dp[i][j] 表示从i到j的最大利润
         * count[i][j] 表示从i到j 取最大利润时的最少的交易次数
         ***************************************************************************************************/
        int dp[MAX][MAX];       
        int count[MAX][MAX];
        for(int i = 0; i <= _nums.size(); ++i)
        {
            for(int j = 0; j <= _nums.size(); ++j)
            {
                dp[i][j] = 0;
                count[i][j] = 0;
            }
        }

        for(int i = 1; i < _nums.size(); ++i)
        {
            for(int j = 0; j+i < _nums.size(); ++j)
            {
                int m = _nums[j+i] - _nums[j];
                //先将dp[j][j+i] 初始化为m,因为下面的比较中要用到dp[j][j+i]
                //所以要保证这个值是个有效值
                dp[j][j+i] = m;
                count[j][j+i] = 1;
                if(m <= 0)
                {
                    m = 0;
                    count[j][j+i] = 0;
                }
                for(int k = j; k < j+i; ++k)
                {
                    if(m < dp[j][k] + dp[k+1][j+i] && count[j][k] + count[k+1][j+i] <= K)
                    {
                        m = dp[j][k] + dp[k+1][j+i];
                        count[j][j+i] = count[j][k] + count[k+1][j+i];
                    }
                    else if(m == dp[j][k] + dp[k+1][j+i])
                    {
                        count[j][j+i] = min(count[j][j+i], count[j][k] + count[k+1][j+i]);
                    }
                }
                dp[j][j+i] = m;
            }
        }
        return dp[0][_nums.size()-1];
    }
#endif
    
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
    int k;
    cout << "输入K:";
    cin >> k;
    cout << my.fun(k) << endl;
    return 0;
}
