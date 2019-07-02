#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int* countSmaller(int* nums, int numsSize) 
{
	assert(nums != NULL && numsSize > 0);
	int i = numsSize-1;
	int *arr = (int *)calloc(numsSize,sizeof(int));
	arr[i] = 0;
	assert(nums != NULL);
    i--;
    int j = numsSize-1;
    while(i >= 0)
	{
        while(j < numsSize)
        {
            if(nums[i] > nums[j])
            {
                arr[i--] = arr[j--]+1;
                break;
            }
            else
            {
                j++;
            }
        }
        if(j == numsSize)
        {
            arr[i--] = 0;
        }
        j = i+1;
	}
    return arr;
}

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
	int nums[] = {5,2,6,1};
	int len = sizeof(nums)/sizeof(nums[0]);
    int *arr = countSmaller(nums,len);
    Show(arr,len);
	return 0;
}
