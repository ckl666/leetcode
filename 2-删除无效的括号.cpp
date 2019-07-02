#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void display(vector<char> &str)
{
    int i = 0;
    for(; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout <<endl;
}

//首先获取括号匹配的需要删除的最小值
int getMinDelete(vector<char> &str)
{
    int i = 0;
    int num = 0;
    stack<char> st;
    for(; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')')
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                num++;
            }
        }
    }
    return num;
}


void deleteChar(vector<char> &str,int i,int min,int x[],int num)
{
    if(i == str.size() && num <= min)
    {
        vector<char> s;
        int j = 0;
        for(; j < str.size(); j++)
        {
            if(x[j] == 1)
            {
                s.push_back(str[j]);
            }
        }
        if(getMinDelete(s) == 0)
        {
            display(s);
        }
    }
    else
    {
        x[i] = 1;
        deleteChar(str,i+1,min,x,num);
        if(num + 1 <= min && (str[i] == '(' || str[i] == ')'))
        {
            x[i] = 0;
            deleteChar(str,i+1,min,x,num+1);
        }
    }
}

int main()
{
    char str[] = "()())(a)";
    vector<char> s;
    int len = sizeof(str)/sizeof(str[0]);
    int i = 0;
    for(; i < len; i++)
    {
        s.push_back(str[i]);
    }
    int min = getMinDelete(s);
    int *x = new int[len];
    deleteChar(s,0,min,x,0);
    return 0; 
}
