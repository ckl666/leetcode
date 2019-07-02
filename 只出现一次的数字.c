#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//有两个数字出现了一次,其余数字都出现了两次


int* singleNumber(int* nums, int numsSize) 
{
    assert(nums != NULL && numsSize > 0);
    int tmp = nums[0];
    int i = 0;
    for(i = 1; i < numsSize; i++)
    {
        tmp = tmp^nums[i];
    }
    for(i = 0; i < 32; i++)
    {
        if(tmp & (1<<i) == 1)
        {
            tmp = tmp&(1<<i);
            break;
        }
    }
    int *arr = (int *)calloc(2,sizeof(int));
    assert(arr != NULL);
    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] & tmp) == 0)    //注意运算符的优先级
        {
            arr[0] = arr[0]^nums[i];
        }
        else
        {
            arr[1] = arr[1]^nums[i];
        }
    }
    return arr;
}


int main()
{
    int nums[] = {1,1,2,3,3,2,4,5};
    int len = sizeof(nums)/sizeof(nums[0]);
    int *arr = singleNumber(nums,len);
    printf("%d %d\n",arr[0],arr[1]);
    free(arr);
    arr = NULL;
    return 0;
}
