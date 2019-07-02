#include <iostream>

using namespace std;

/*
 * 给定一个未排序的整数数组，找出其中未出现的最小的正数
 * {1,2,0}  ============》3
 * {2,3,-1} ============》1
 * dp[i] 表示 前i个元素未出现的最小正数
 * dp[0] = 1;
 * 
 * 构造小根堆
 * 时间复杂读O(n *log n)
 * 
 *
 */
#if 0
void creatMinHeap(int *arr,int start,int end)
{
    int tmp = arr[start];
    for(int i = 2*start+1; i <= end; i = 2*i+1)
    {
        if(i+1 <= end && arr[i] > arr[i+1])
        {
            i++;
        }
        if(tmp > arr[i])
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


int fun(int *arr,int len)
{
    int *brr = new int[len];
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > 0)
        {
            brr[j++] = arr[i];   
        }
    }
    if(j == 0)
    {
        delete []brr;
        return 1;
    }
    else if(j == 1)
    {
        delete []brr;
        return brr[0] == 1 ? 2:1;
    }
    //创建最小堆
    for(int i = (j-2)/2; i >= 0; i--)
    {
        creatMinHeap(brr,i,j-1);
    }
    
    int num = 1;
    for(int i = 0; i < j; i++)
    {
        if(brr[0] == num)
        {
            num++;
        }
        else if(brr[0] > num)
        {
            delete[]brr;
            return num;
        }
        brr[0] = brr[j-i-1];
        creatMinHeap(brr,0,j-i-2);
    }
    delete []brr;
    return j;
}
#endif 
void swap(int *arr,int i,int j)
{
    arr[i] = arr[i]^arr[j];
    arr[j] = arr[i]^arr[j];
    arr[i] = arr[i]^arr[j];
}


//循环不变式
/*如果数组的内容大于数组的长度或者小于0就将该内容放在相应的位置
 */
/*
int fun(int *arr,
        int len)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > 0 && arr[i] <= len)
        {
            if(arr[i] == i+1)
            {
                continue;
            }
            else
            {
                swap(arr,i,arr[i]-1);
                i--;
            }
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(arr[i] != i+1)
        {
            return i+1;
        }
    }
    return len+1;
}
*/
//hash法
int fun(int *arr,int len)
{
    bool *hash = new bool[len];
    for(int i = 0; i < len; i++)
    {
        hash[i] = false;
    }
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > 0 && arr[i] <= len)
        {
            hash[arr[i]-1] = true;
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(!hash[i])
        {
            return i+1;
        }
    }
    return len+1;
}


int main()
{
    int arr[] = {0,-1,2,3,1,4,34,21,423};
    int arr1[] = {0,-1,2,3,1,4,5,21,423};
    int arr2[] = {2,3,1,4,34,21,423};
    int arr3[] = {0,-1,1,2,3,5};
    int arr4[] = {0,-1,-2,-3,-1,-4,-34,-21,-423};
    int len = sizeof(arr)/sizeof(arr[0]);
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int len3 = sizeof(arr3)/sizeof(arr3[0]);
    int len4 = sizeof(arr4)/sizeof(arr4[0]);
    cout << fun(arr,len) << endl;
    cout << fun(arr1,len1) << endl;
    cout << fun(arr2,len2) << endl;
    cout << fun(arr3,len3) << endl;
    cout << fun(arr4,len4) << endl;
    return 0;
}
