#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void display(vector<int> &arr)
{
    int i = 0;
    for(; i < arr.size(); i++)
    {
        if(arr[i] == 1)
        {
            cout << '(';
        }
        else
        {
            cout << ')';
        }
    }
    cout << endl;
}

bool Judge(vector<int> &arr)
{
    int i = 0;
    vector<char> str;
    stack<char> st;
    for(; i < arr.size(); i++)
    {
        if(arr[i] == 1)
        {
            str.push_back('(');
        }
        else
        {
            str.push_back(')');
        }
    }
    for(i = 0; i < arr.size(); i++)
    {
        if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else if(!st.empty() && str[i] == ')')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    if(st.empty())
    {
        return true;
    }
    return false;
}

void fun(int i,int size,vector<int> &arr)
{
    if(i >= size)
    {
        if(Judge(arr))
        {
            display(arr);
        }
    }
    else
    {
        arr[i] = 1;
        fun(i+1,size,arr);
        arr[i] = 0;
        fun(i+1,size,arr);
    }
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr;
    int i = 0;
    for(; i < 2*size; i++)
    {
        arr.push_back(0);
    }
    fun(0,2*size,arr);
    return 0;
}
