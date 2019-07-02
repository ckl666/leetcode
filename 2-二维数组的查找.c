#include <stdio.h>
#include <assert.h>

#define MAX 100
#define N 4

int Find(int *arr,int col,int row,int num)
{
    int found = 0;
    int x = 0;
    int y = col-1;
    while(x < row && y >= 0)
    {
        if(arr[x*col+y] < num)
        {
            x++;    
        }
        else if(arr[x*col+y] > num)
        {
            y--;
        }
        else
        {
            found = 1;
            break;
        }
    }
    return found;
}

int main()
{
    int arr[] = {
        1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };
    int row = 4;
    int col = 4;
    int num = 5;
    if(Find(arr,col,row,num))
    {
        printf("num is here\n");
    }
    else
    {
        printf("num is not here\n");
    }
    return 0;
}
