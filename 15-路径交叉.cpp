#include <iostream>

using namespace std;

/*********************************************************************************
给定一个含有 n 个正数的数组 x。从点 (0,0) 开始，
先向北移动 x[0] 米，然后向西移动 x[1] 米，向南移动 x[2] 米，
向东移动 x[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。

编写一个 O(1) 空间复杂度的一趟扫描算法，判断你所经过的路径是否相交。
*********************************************************************************/

class CMyclass
{
    public:

        bool fun()
        {
            int x = 0;
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
}


int main()
{
    return 0;
}
