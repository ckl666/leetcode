//给定一个无序的整数数组，找到其中最长上升子序列的长度。
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


//O(nlgn)
//归并法
//二分法查找
int Search(int *nums,int numsSize,int key)
{
	assert(nums != NULL && numsSize > 0);
	int low = 0;
	int high = numsSize-1;
	int mid = (low+high)/2;
	while(low < high)
	{
		if(nums[mid] > key)
		{
			high = mid-1;
		}
		else if(nums[mid] < key)
		{
			low = mid+1;
		}
		else
		{
			break;
		}
		mid = (low+high)/2;
	}
	return mid;
}

int lengthOfLIs(int *nums,int numsSize)
{
	assert(nums!= NULL && numsSize > 0);
	int max = 1;
	int i = 0;
	int *arr = (int *)calloc(numsSize,sizeof(int));
	arr[0] = nums[0];
	for(i = 1; i < numsSize; i++)
	{
		if(arr[max-1] < nums[i])
		{
			arr[max++] = nums[i];
		}
		else if(arr[max-1] > nums[i])
		{
			int pos = Search(arr,max,nums[i]);
			if(arr[pos] < nums[i])
			{
				pos++;
			}
			arr[pos] = nums[i];
		}
	}
	free(arr);
	arr = NULL;
	return max;
}

//O(n^2)
/*
int lengthOfLIS(int* nums, int numsSize) 
{
	assert(nums != NULL && numsSize > 0);
	int max = 0;
	int count = 1;
	int i = 0;
	int j = 0;
	for(i = 0; i < numsSize; i++)
	{
		int tmp = i;
		for(j = i+1; j < numsSize; j++)
		{
			if(nums[tmp] < nums[j])
			{
				tmp = j;
				count++;
			}
		}
		if(max < count)
		{
			max = count;
		}
		count = 1;
	}
	return max;
}
*/


int main()
{
	int nums[] = {1,2,3,4,5,2,1,3,5,6,7,8,9};
	int len = sizeof(nums)/sizeof(nums[0]);
	printf("%d\n",lengthOfLIs(nums,len));
	return 0;
}
