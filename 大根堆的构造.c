#include <stdio.h>
#include <assert.h>


void CreatHeap(int *arr,int len)
{
    assert(arr != NULL);
    int i = 0;
    for(i = 1; i < len; i++)
    {
        int sub = i;
        int parent = (sub-1)/2;
        while(parent >= 0)
        {
            if(arr[sub] > arr[parent])
            {
                int tmp = arr[sub];
                arr[sub] = arr[parent];
                arr[parent] = tmp;
                sub = parent;
                parent = (sub-1)/2;
            }
            else
            {
                break;
            }
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
    int arr[] = {2,1,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    CreatHeap(arr,len);
    Show(arr,len);
    return 0;
}
