#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Copy(int *arr,int *brr,int left,int right)
{
    int i = 0;
    for(i = left; i <= right; i++)
    {
        arr[i] = brr[i];
    }
}

void Merge(int *arr,int *brr,int left,int mid,int right,int &count)
{
    int i = mid;
    int j = right;
    int k = right;
    while(i >= left && j >= mid+1)
    {
        if(arr[i] <= arr[j])
        {
            brr[k--] = arr[j--];
        }
        else
        {
            count += (j-mid);
            brr[k--] = arr[i--];
        }
    }
    while(i >= left && j < mid+1)
    {
        brr[k--] = arr[i--];
    }
    while(i < left && j >= mid+1)
    {
        brr[k--] = arr[j--];
    }
}

//基于归并排序的求逆序对数
void MergeSort(int *arr,int *brr,int left,int right,int &count)
{
    if(left < right)
    {
       int mid = (right-left)/2+left;
        MergeSort(arr,brr,left,mid,count);
        MergeSort(arr,brr,mid+1,right,count);
        Merge(arr,brr,left,mid,right,count);
        Copy(arr,brr,left,right);
    }
}

void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {12,3,23,12,34,432,312,31,132};
    //int arr[] = {12,3,23,12,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    //int *brr = (int *)malloc(sizeof(int)*len);
    int *brr = new int[len];
    int count = 0;
    MergeSort(arr,brr,0,len-1,count);
    cout<<count<<endl;
    Show(arr,len);
    return 0;
}
