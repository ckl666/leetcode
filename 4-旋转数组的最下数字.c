#include <stdio.h>

//旋转数组的最小值
int Min(int *arr,int len)
{
    int left = 0;
    int right = len-1;
    int mid = (left+right)/2;
    if(arr[left] < arr[right])
    {
        return arr[left];
    }
    else if(arr[left] > arr[right])
    {
        if(arr[mid] > arr[right])
        {
            left = mid+1;
        }
        else if(arr[mid] < arr[right])
        {
            
        }
    }
}

int main()
{
    return 0;
}
