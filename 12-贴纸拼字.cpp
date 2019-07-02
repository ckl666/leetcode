#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
/***********************************************************************************
我们给出了 N 种不同类型的贴纸。每个贴纸上都有一个小写的英文单词。

你希望从自己的贴纸集合中裁剪单个字母并重新排列它们，从而拼写出给定的目标字符串 target。

如果你愿意的话，你可以不止一次地使用每一张贴纸，而且每一张贴纸的数量都是无限的。

拼出目标 target 所需的最小贴纸数量是多少？如果任务不可能，则返回 -1

["with","great"]
***********************************************************************************/
#define min(x,y) ((x)>(y)?(y):(x))
#define INF 0x3f3f3f
const int MAX_LENGTH = 20;

int dp[MAX_LENGTH][MAX_LENGTH];

/**********************************************************************************
 * 动态规划
 * dp[i][j] 表示 i 到 j 的最小贴纸的数量
 *********************************************************************************/
class CMyclass
{
public:
    int fun(string des)
    {
        for(int i = 0; i < des.size(); i++)
        {
            dp[i][i] = 0;
        }

        for(int i = 1; i <= des.size(); i++)
        {
            for(int j = 0; j+i <= des.size(); j++)
            {
                string s(des.begin()+j,des.begin()+j+i);
                int k = 0;
                //若s可以整个被剪出，则最少贴纸为1
                for(; k < _str.size(); k++)
                {
                    if(strstr(_str[k].c_str(),s.c_str()))
                    {
                        dp[j][j+i] = 1;
                        break;
                    }
                }
                //若s不能被剪出，则找出中间第k个位置最少的贴纸
                if(k >= _str.size())
                {
                    if(s.size() == 1)
                    {
                        return -1;
                    }
                    int minNum = INF;
                    dp[j][j+i] = INF;
                    for(k = j; k < j+i; k++)
                    {
                        minNum = min(dp[j][k]+dp[k][j+i],minNum);
                    }
                    dp[j][j+i] = minNum;
                }
            }
        }
        return dp[0][des.size()];
    }

    void setStr()
    {
        cout << "输入字符串的个数:";
        int size;
        cin >> size;
        for(int i = 0; i < size; i++)
        {
            string str;
            cin >> str;
            _str.push_back(str);
        }
    }

private:
    vector<string> _str;
};


int main()
{
    //string str = "abcdefg";
    /*
    string tmp(str.begin()+3,str.begin()+5);
    cout << tmp << endl;
    */
    CMyclass my;
    string des = "abc";
    my.setStr();
    cout << my.fun(des) << endl;
    return 0;
}
