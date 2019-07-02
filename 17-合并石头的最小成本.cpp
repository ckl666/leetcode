#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
/***********************************************************************************************************
有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。

每次移动（move）需要将连续的 2 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。

找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。
***********************************************************************************************************/
#define MAX_LENGTH 20
#define min(x,y) ((x) > (y) ? (y) : (x))
#define INF 0x3f3f3f

int dp[MAX_LENGTH][MAX_LENGTH];


class CMyclass
{
public:
/**********************************************************************************************************
 * dp[i][j] 表示 (i <= j)i-j堆进行合并的最小成本
 *
 * dp[i][j] = min(dp[i][k]+dp[k+1][j],dp[i][j])(i <= k <= j)
 *********************************************************************************************************/
    int fun()
    {  
        //初始化
        for(int i = 0; i < _nums.size(); i++)
        {
            for(int j = 0; j < _nums.size(); j++)
            {
                dp[i][j] = INF;
            }
            dp[i][i] = _nums[i];
        }
        
        for(int i = 1; i < _nums.size(); ++i)
        {
            for(int j = 0; j+i < _nums.size(); ++j)
            {
                for(int k = j; k <= j+i; k++)
                {
                    int a = dp[j][k];
                    int b = dp[k+1][j+i];
                    if(j != k)
                    {
                        a *= 2;
                    }
                    if(k+1 < j+i)
                    {
                        b *= 2;
                    }
                    dp[j][j+i] = min(a+b,dp[j][j+i]);
                }
            }
        }

        return dp[0][_nums.size()-1];
        
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
    cout << my.fun() << endl;
    return 0;
}
