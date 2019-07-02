#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define SIZE 4

/*********************************************************************************
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24

[4,1,8,7]

(8-4)*(7-1) = 24
*********************************************************************************/

class Myclass
{
public:

    Myclass()
    {
        _sign.push_back('+');
        _sign.push_back('-');
        _sign.push_back('*');
        _sign.push_back('/');
    }
/***************************************************************************************
 * 回溯算法：
 *      选取数组中的任意两个值进行运算，将运算后的结果加入到数组中，并将选取的两个值删除
 *      递归进入下一个状态，此时数组中由三个值，每进行一次递归，数组中减少一个元素，直到
 *      数组中的元素个数为1时，判断该值是否为24若是，则返回true 否则返回false.
 *
 *      本次递归出来后恢复递归前的状态，进行下一个运算符的计算，
 *
 *      括号只是改变运算的顺序，由于回溯算法包含了所有的情况，所以不需要考虑括号的情况
 *
 **************************************************************************************/
    bool fun(vector<double> _nums)
    {
        if(_nums.size() == 1) 
        {
            if(_nums[0] == 24)
                return true;
            else
                return false;
        }
        for(int i = 0; i < _nums.size(); i++)
        {
            for(int j = i+1; j < _nums.size(); j++)
            {
                for(int k = 0; k < _sign.size(); k++)
                {
                    double data = 0;
                    if(_sign[k] == '+' || _sign[k] == '*')
                    {
                        switch(_sign[k])
                        {
                            case '+':
                                data = _nums[i] + _nums[j];
                                break;
                            case '*':
                                data = _nums[i] * _nums[j];
                                break;
                            default:
                                break;
                        }
                        double tmpi = _nums[i];
                        double tmpj = _nums[j];
                        _nums.erase(_nums.begin()+i);
                        _nums.erase(_nums.begin()+j-1);
                        _nums.push_back(data);
                        if(fun(_nums))
                        {
                            return true;
                        }
                        _nums.pop_back();
                        _nums.insert(_nums.begin()+i,tmpi);
                        _nums.insert(_nums.begin()+j,tmpj);
                    }
                    else
                    {
                        double tmpi = _nums[i];
                        double tmpj = _nums[j];
                        double data1;
                        double data2;
                        switch(_sign[k])
                        {
                            case '-':
                                {
                                    data1 = _nums[i] - _nums[j];
                                    data2 = _nums[j] - _nums[i]; 
                                    break;
                                }
                            case '/':
                                {
                                    data1 = tmpi / tmpj;
                                    data2 = tmpj / tmpi;
                                    break;
                                }
                        }
                        _nums.erase(_nums.begin()+i);
                        _nums.erase(_nums.begin()+j-1);
                        _nums.push_back(data1);
                        if(fun(_nums))
                        {
                            return true;
                        }
                        _nums.pop_back();
                        _nums.push_back(data2);
                        if(fun(_nums))
                        {
                            return true;
                        }
                        _nums.pop_back();
                        _nums.insert(_nums.begin()+i,tmpi);
                        _nums.insert(_nums.begin()+j,tmpj);

                    }
                }
            }
        }
        return false;
    }

private:
    vector<char> _sign;
};

void setNums(vector<double> &_nums)
{
    for(int i = 0; i < SIZE; i++)
    {
        double data;
        cin >> data;
        _nums.push_back(data);
    }
}

int main()
{
    Myclass my;
    vector<double> _nums;
    setNums(_nums);

    cout << my.fun(_nums) << endl;
    return 0;
}
