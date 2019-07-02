#include <iostream>
#include <vector>
#include <deque>  //双端队列
using namespace std;

void Print(vector<int>&vec)
{
	vector<int>::iterator it  = vec.begin();
	for(;it != vec.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}


//双端队列中始终是由高到底的顺序，队列尾部放数据，队列头部取数据
//存储数据的索引值，用于判断最大值是否已经失效
vector<int> maxWatch(vector<int> &nums,int k)
{
	deque<int> dq;
	vector<int> arr;
	for(int i = 0; i < nums.size(); i++)
	{
		if(!dq.empty() && dq.front() == i-k) dq.pop_front();
		while(!dq.empty() && nums[dq.back()] < nums[i])
		{
			dq.pop_back();	
		}
		dq.push_back(i);
		if(i >= k-1) arr.push_back(nums[dq.front()]);
	}
	return arr;
}

int main()
{
	int arr[] = {-1,2,3,2,1,-1,-1,2,6,7};
	int len = sizeof(arr)/sizeof(arr[0]);
	vector<int> nums;
	for(int i = 0; i < len; i++)
	{
		nums.push_back(arr[i]);
	}
	int k = 3;
	vector<int> vec = maxWatch(nums,k);
	Print(vec);
}
