#include <stdio.h>

void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int Partition(int *arr,int start,int end)
{
    int tmp = arr[start];
    while(start < end)
    {
        while(start < end && arr[end] >= tmp)
        {
            end--;
        }
        if(start >= end)
        {
            break;
        }
        if(arr[end] < tmp)
        {
            arr[start] = arr[end];
        }
        while(start < end && arr[start] <= tmp)
        {
            start++;
        }
        if(start >= end)
        {
            break;
        }
        if(arr[start] > tmp)
        {
            arr[end] = arr[start];
        }
    }
    arr[start] = tmp;
    return start;
}

void Adjust(int *arr,int start,int end)
{
    int tmp = arr[start];
    int i = 0;
    for(i = start*2+1; i <= end; i = i*2+1)
    {
        if(i+1 <= end && arr[i] < arr[i+1])
        {
            i++;
        }
        if(arr[i] > tmp)
        {
            arr[start] = arr[i];
            start = i;
        }
        else
        {
            break;
        }
    }
    arr[start] = tmp;
}

void Swap(int *arr,int i,int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void MinK(int *arr,int start,int end,int k)
{
    int i = 0;
    for(i = (k-2)/2; i >= 0; i--)
    {
        Adjust(arr,i,k-1);
    }
    i = k;
    for(i; i <= end; i++)
    {
        if(arr[i] < arr[0])
        {
            Swap(arr,0,i);
            Adjust(arr,0,k-1);
        }
    }
}

int main()
{
    int arr[] = {32,1,2,34,5,56,234,312,31,4,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    MinK(arr,0,len-1,k);
    Show(arr,k);
}


/*
 * 时间复杂度O(n)
void MinK(int *arr,int start,int end,int k)
{
    int par = Partition(arr,start,end);
    if(par > k)
    {
        MinK(arr,start,par-1,k);
    }
    if(par < k-1)
    {
        MinK(arr,par+1,end,k);
    }
}

int main()
{
    int arr[] = {32,1,2,34,5,56,234,312,31,4,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    MinK(arr,0,len-1,k);
    Show(arr,k);
}
*/
/*
//快排
void QuickSort(int *arr,int start,int end)
{
    int par = Partition(arr,start,end);
    if(par-1 > start)
    {
        QuickSort(arr,start,par-1);
    }
    if(par+1 < end)
    {
        QuickSort(arr,par+1,end);
    }
}

int main()
{
    int arr[] = {32,1,2,34,5,56,234,312,31,4,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len-1);
    Show(arr,len);
    return 0;
}
*/
