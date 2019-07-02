#include <stdio.h>
#include <assert.h>


//1 3 5 4 2
void ResverNums(int *nums,int start,int end)
{
    int i = 0;
    int mid = (end-start)/2+start;
    for(i = start; i < mid; i++)
    {
        nums[i] = nums[i]^nums[end-i+start];
        nums[end-i+start] = nums[i]^nums[end-i+start];
        nums[i] = nums[i]^nums[end-i+start];
    }
}


//下一个序列

void nextPermutation(int* nums, int numsSize) 
{
    assert(nums != NULL);
    if(numsSize <= 0)
    {
        return ;
    }
    int i = 0;
    for(i = numsSize-2; i >= 0; i--)
    {
        if(nums[i+1] > nums[i])
        {
            break;
        }
    }
    if(i < 0)
    {
        ResverNums(nums,0,numsSize-1);        
        return ;
    }
    int j = 0;
    for(j = numsSize-1; j > i; j++)
    {
        if(nums[j] > nums[i])
        {
            nums[i] = nums[j]^nums[i];
            nums[j] = nums[j]^nums[i];
            nums[i] = nums[j]^nums[i];
            break;
        }
    }
    ResverNums(nums,i+1,numsSize-1);
}

void Show (int *nums,int numsSize)
{
    assert(nums != NULL);
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}


int main()
{
    int nums[] = {1,2,5,4,3};
    int len = sizeof(nums)/sizeof(nums[0]);
    nextPermutation(nums,len);
    Show(nums,len);
    return 0;
}
