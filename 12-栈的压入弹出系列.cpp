#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

bool Judge(int *pushArr,int *popArr,int lenArr)
{
    assert(pushArr != NULL && popArr != NULL);
    int *stack = (int *)malloc(sizeof(int) *lenArr);
    assert(stack != NULL);
    int top = 0;
    int x = 0;
    int y = 0;
    while(x < lenArr && y < lenArr)
    {
        if(pushArr[x] != popArr[y])
        {
            stack[top++] = pushArr[x++];
        }
        else
        {
            x++;
            y++;
            while(stack[top-1] == popArr[y])
            {
                y++;
                top--;
            }
        }
    }
    if(top != 0)
    {
        for(; top > 0; --top)
        {
            if(y < lenArr && stack[top-1] != popArr[y])
            {
                return false;
            }
            else if(y >= lenArr)
            {
                return false;
            }
            y++;
        }
    }
    return true;
}

int main()
{
    int pushArr[] = {1,2,3,4,5};
    int popArr1[] = {4,5,3,2,1};
    int popArr2[] = {4,3,2,1,5};
    int popArr3[] = {4,3,5,1,2};
    int len = sizeof(pushArr)/sizeof(pushArr[0]);
    if(Judge(pushArr,popArr1,len))
    {
        printf("符合\n");
    }
    else
    {
        printf("不符合\n");
    }
    if(Judge(pushArr,popArr2,len))
    {
        printf("符合\n");
    }
    else
    {
        printf("不符合\n");
    }
    if(Judge(pushArr,popArr3,len))
    {
        printf("符合\n");
    }
    else
    {
        printf("不符合\n");
    }
    exit(0);
}


