#include <iostream>
#include <cassert>

using namespace std;

int leftIndex(int *arr,int low,int high,int num)
{
    assert(arr != NULL);
    int mid = (high-low)/2+low;
    while(low < high)
    {
        if(arr[mid] >= num)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        mid = (high-low)/2+low;
    }
    return mid;
}

int rightIndex(int *arr,int low,int high,int num)
{
    assert(arr != NULL);
    int mid = (high-low)/2+low;
    while(low < high)
    {
        if(arr[mid] <= num)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        mid = (high-low)/2+low;
    }
    return mid;
}

int SameCount(int *arr,int len,int num)
{
    int left = leftIndex(arr,0,len-1,num);
    int right = rightIndex(arr,0,len-1,num);
    int count = 0;
    if(arr[left] != num && arr[left+1] == num)
    {
        left++;
    }
    else if(arr[left] != num && arr[left+1] != num)
    {
        return 0;
    }
    if(arr[right] == num)
    {
        count = right - left + 1;
    }
    else
    {
        count = right - left;
    }
    return count;
}

int main()
{
    int arr[] = {1,2,3,3,3,3,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int num = 2;
    int count = SameCount(arr,len,num);
    cout<<count<<endl;
    return 0;
}
