#include <stdio.h>
#include <assert.h>

void Swap(int *arr,int left,int right)
{
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
}


bool IsOdd(int *arr,int index)
{
    return arr[index] % 2 != 0;
}

void Change(int *arr,int len)
{
    assert(arr != NULL);
    int left = 0;
    int right = len-1;
    while(left < right)
    {
        while(left < right && IsOdd(arr,left))
        {
            left++;
        }
        while(right > left && !IsOdd(arr,right))
        {
            right--;
        }
        if(left < right)
        {
            Swap(arr,left,right);
        }
    }
}

void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,5,6,3,4,2,};
    int len = sizeof(arr)/sizeof(arr[0]);
    Show(arr,len);
    Change(arr,len);
    Show(arr,len);
    return 0;
}
