#include <iostream>
#include <vector>

using namespace std;

const int MAX_LENGTH = 20;

/*
 * 给定一个二维平面，平面上由若干个点，求最多有几个点在同一条直线上
 */

struct Node
{
    bool operator == (const Node &s)const
    {
        return (s._x == _x && s._y == _y);
    }
    Node(int x = 0,int y = 0):_x(x),_y(y){}
    int _x;
    int _y;
};

//动态规划
class CMyclass
{
public:
    CMyclass(int m = 0):_max(m){}
    //判断点val是否在指向上
    bool isBeeline(int i,int j,const Node &val)const
    {
        if(val == _arr[i] || val == _arr[j])
        {
            return true;
        }
        if(_arr[i]._y - _arr[j]._y == 0)
        {
            return val._y == _arr[i]._y;
        }
        else if(val._y - _arr[i]._y == 0)
        {
            return false;
        }
        else
        {
            return (double)(_arr[i]._x - _arr[j]._x) / (_arr[i]._y - _arr[j]._y)
                == (double)(val._x - _arr[i]._x) / (val._y - _arr[i]._y);
        }
    }
    void fun()
    {
        for(int i = 0; i < _arr.size(); i++)
        {
            for(int j = i+1; j < _arr.size(); j++)
            {
                int m = 0;
                for(int k = 0; k < _arr.size(); k++)
                {
                    if(isBeeline(i,j,_arr[k]))
                    {
                        m++;
                    }
                }
                if(_max < m)
                {
                    _max = m;
                }
            }
        }
        
    }
    void setArr()
    {
        cout << "输入节点个数:";
        int size;
        cin >> size;
        cout << "输入节点的坐标:" <<  endl;
        for(int i = 0; i < size; i++)
        {
            int x,y;
            cin >> x >> y;
            _arr.push_back(Node(x,y));
        }
    }

    void display()
    {
        cout << _max << endl;
    }
private:
    vector<Node> _arr;
    int _max;
};




int main()
{
    CMyclass my;
    my.setArr();
    my.fun();
    my.display();
    return 0;
}
