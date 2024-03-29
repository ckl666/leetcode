#include <iostream>

using namespace std;

/***************************************************************************************************************************
f(x) 是 x! 末尾是0的数量。（回想一下 x! = 1 * 2 * 3 * ... * x，且0! = 1）

例如， f(3) = 0 ，因为3! = 6的末尾没有0；而 f(11) = 2 ，因为11!= 39916800末端有2个0。给定 K，找出多少个非负整数x ，有 f(x) = K 的性质。

示例 1:
输入:K = 0
输出:5
解释: 0!, 1!, 2!, 3!, and 4! 均符合 K = 0 的条件。

示例 2:
输入:K = 5
输出:0
解释:没有匹配到这样的 x!，符合K = 5 的条件。
*****************************************************************************************************************************/
class Solution
{
public:
    int fun(int n)
    {
        int count = 0;
        for(int i = 5; i <= n; i += 5)
        {
            int num = i;
            while(num != 0)
            {
                if(num % 5 == 0)
                {
                    count++;
                }
                num /= 5;
            }
        }
        return count;
    }
};


int main()
{
    Solution s;
    cout << "输入n的阶乘:";
    int n;
    cin >> n;
    cout << s.fun(n) << endl;
    return 0;
}
