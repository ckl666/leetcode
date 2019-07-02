#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//

void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int* maxSlidingWindow(int* nums, int numsSize, int k)
{
    assert(nums != NULL && k > 0 && k < numsSize);
    int *arr = (int *)malloc(sizeof(int)*(numsSize-k+1));
    assert(arr != NULL);
    int i = 0;
    int j = 0;
    int next = 0;
    int index = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(i-k >= index)
        {
            index = next;
            next = -1;
        }
        if(nums[i] > nums[index])
        {
            next = -1;
            index = i;
        }
        else if(next == -1 || nums[index]-nums[i] <= nums[index]-nums[next])
        {
            next = i;
        }
        if(i-k+1 >= 0)
        {
            arr[j++] = nums[index];
        }
    }
    return arr;
}



int main()
{
    int nums[] = {-1,3,2,1,-1,-1,2,7};
    int len = sizeof(nums)/sizeof(nums[0]);
    int *arr = maxSlidingWindow(nums,len,3);
    Show(arr,len-2);
    return 0;
}
