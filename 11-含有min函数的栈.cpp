#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int min(vector<int> &data,stack<int> &minIndex)
{
    if(minIndex.size() == 0)
    {
        throw "栈为空";
    }
    return data[minIndex.top()];
}

void push(vector<int> &data,stack<int> &minIndex,int val)
{
    cout<<val<<" ";
    data.push_back(val);
    if(data.size() == 1)
    {
        minIndex.push(data.size()-1);
    }
    else if(data[minIndex.top()] > val)
    {
        minIndex.push(data.size()-1);
    }
}

void pop(vector<int> &data,stack<int> &minIndex)
{
    if(minIndex.top() == data.size()-1)
    {
        minIndex.pop();
    }
    data.erase(data.begin()+(data.size()-1));
}

int main()
{
    vector<int> data;
    stack<int> minIndex;
    srand((int)(time(NULL)));
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        push(data,minIndex,rand()%101);
        cout<<min(data,minIndex)<<endl;
    }
    cout<<endl<<endl;
    while(!data.empty())
    {
        pop(data,minIndex);
        cout<<min(data,minIndex)<<endl;
    }
    exit(0);
}

