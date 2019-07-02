#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//常数空间复杂度
int *productExceptSelf(int *nums,int numsSize)
{
    assert(nums != NULL && numsSize > 0);
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    assert(nums != NULL);
    int i = numsSize-1;
    arr[i] = 1;
    for(i = numsSize-2; i >= 0; i--)
    {
        arr[i] = arr[i+1]*nums[i+1];
    }
    int tmp = nums[0];
    for(i = 1; i < numsSize; i++)
    {
        arr[i] = arr[i]*tmp;
        tmp = tmp*nums[i];
    }
    return arr;
}


//空间复杂度O(n)
/*
int* productExceptSelf(int* nums, int numsSize) 
{
    assert(nums != NULL && numsSize > 0);      
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    int *brr = (int *)malloc(sizeof(int)*numsSize);
    assert(arr != NULL && brr != NULL);
    int i = 0;
    int j = 0;
    arr[0] = 1;
    for(i = 1; i < numsSize; i++)
    {
        arr[i] = arr[i-1]*nums[i-1];
    }
    brr[j++] = 1;
    for(i = numsSize-2; i >= 0; i--)
    {
        brr[j] = brr[j-1]*nums[i+1];
        j++;
    }
    for(i = 0; i < numsSize; i++)
    {
        arr[i] = arr[i]*brr[numsSize-i-1];
    }
    free(brr);
    brr = NULL;
    return arr;
}
*/
//1,2,3,4
//1,1,2,6

void Show(int *arr,int len)
{
    assert(arr != NULL);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *nums = productExceptSelf(arr,len);
    Show(nums,len);
    free(nums);
    nums = NULL;
    return 0;
}
