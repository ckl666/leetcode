#include <iostream>
#include <stack>

using namespace std;

bool Pop(stack<int> &st1,stack<int> &st2,int &val)
{
    if(st2.empty())
    {
        if(st1.empty())
        {
            return false;
        }
        else
        {
            int tmp = 0;
            while(!st1.empty())
            {
                tmp = st1.top();
                st2.push(tmp);
                st1.pop();
            }
        }
    }
    val = st2.top();
    st2.pop();
    return true;
}

bool Push(stack<int> &st1,int val)
{
    st1.push(val);
    return true;
}

int main()
{
    stack<int> st1;
    stack<int> st2;
    int val = 0;
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        Push(st1,i);  
    }
    while(Pop(st1,st2,val))
    {
        cout<<"val = "<<val<<endl;
    }
    return 0;
}
