#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 * 在数字中间加入加减运算符，使得运算结果等于指定的值
 */
void display(int *num,char *sign,int len,int sum)
{
    for(int i = 0; i < len; i++)
    {
        if(sign[i] != ' ')
        {
            cout << " " << sign[i] << " ";
        }
        cout << num[i];
    }
    cout << " = " << sum << endl;
}

/*
 * ************************************************************************
 * sign 存放运算符
 * num 存放数字
 * i 表示递归到数组中的第几个数字
 * len 数组的长度
 * sum 前i个数字运算后的结果值
 * desSum 运算的最后结果值
 * pre 前一个数字的值
 * ************************************************************************
*/
void fun(char *sign,int *num,int i,int len,int sum,int desSum,int pre)
{
    if(i >= len)
    {
        if(sum == desSum)
        {
            display(num,sign,len,desSum);
        }
    }
    else
    {
        //当前取加号值时
        sign[i] = '+';
        fun(sign,num,i+1,len,sum+num[i],desSum,num[i]);

        //当前取减号值时
        sign[i] = '-';
        fun(sign,num,i+1,len,sum-num[i],desSum,-num[i]);

        //当前数字与前一个数字组成一个整体时
        sign[i] = ' ';
        sum = sum-pre;

        //前一个数字为正数时
        if(pre >= 0)
        {
            pre = pre*10+num[i];
            fun(sign,num,i+1,len,sum+pre,desSum,pre);
        }
        //前一个数字是负数时
        else
        {
            pre = pre*10-num[i];
            fun(sign,num,i+1,len,sum+pre,desSum,pre);
        }
    }
}



int main()
{
    int num[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(num)/sizeof(num[0]);
    char *sign = new char[len];
    
    fun(sign,num,0,len,0,100,0);
    
    return 0;
}
