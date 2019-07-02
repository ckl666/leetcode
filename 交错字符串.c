#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//动态规划
//
/*
	char s1[] = "aabcc";
	char s2[] = "dbbca";
	char s3[] = "aadbbbccac";
*/

void Show(int *arr,int row,int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i <= row; i++)
    {
        for(j = 0; j <= col; j++)
        {
            printf("%d ",arr[i*(col+1)+j]);
        }
        printf("\n");
    }
}

bool isInterleave(char* s1, char* s2, char* s3) 
{
    assert(s1 != NULL && s2 != NULL && s3 != NULL);
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    int lens3 = strlen(s3);
    int *arr = (int *)malloc(sizeof(int)*(lens1+1)*(lens2+1));
    assert(arr != NULL);
    memset(arr,0,sizeof(int)*(lens1+1)*(lens2+1));
    int i = 0;      //s1的下标
    int k = 0;      //s3的下标
    int j = 0;      //s2的下标
    for(i = 0; i <= lens1; i++)
    {
        if(i == 0)   //第一行数据
        {
            for(j = 1; j <= lens2; j++)
            {
                if((j-1 <= 1 || arr[i*(lens2+1)+j-1] == 1) && s2[j-1] == s3[j-1])
                {
                    arr[i*(lens2+1)+j-1] = 1;
                }
            }
        }
        else
        {
            if(s1[i-1] == s3[i-1])
            {
                arr[i*(lens2+1)] = 1;
            }
            for(j = 1; j <= lens2; j++)
            {
                if((arr[i*(lens2+1)+j-1] == 1 && s2[j-1] == s3[i+j-1]) || (arr[(i-1)*(lens2+1)+j] == 1 && s1[i-1] == s3[i+j-1]))
                {
                    arr[i*(lens2+1)+j] = 1;
                }
            }
        }
    }
    Show(arr,lens1,lens2);
    if(arr[lens1*(lens2+1)+lens2] == 1)
    {
        return true;
    }
    return false;
}



//回溯算法
/*
bool isInterleave(char* s1, char* s2, char* s3) 
{
	assert(s1 != NULL && s2 != NULL && s3 != NULL);
	int lenS3 = strlen(s3);
	int *stack = (int *)malloc(sizeof(int)*lenS3);
	assert(stack != NULL);
	int top = 0;
	memset(stack,0,sizeof(int)*lenS3);
	int i = 0;
	int j = 0;
	int k = 0;
	while(s3[k] != '\0')
	{
		if(s1[i] == '\0' && s2[j] == '\0')
		{
			break;
		}
		if(s1[i] == s3[k] && s2[j] == s3[k])
		{
			stack[top++] = i;
			stack[top++] = j;
			stack[top++] = k;
			i++;
			k++;
		}
		else if(s1[i] == s3[k])
		{
			i++;
			k++;
		}
		else if(s2[j] == s3[k])
		{
			j++;
			k++;
		}
		else
		{
			if(top == 0)
			{
				break;
			}
			else
			{
				k = stack[--top];
				j = stack[--top];
				i = stack[--top];
				j++;
				k++;
			}
		}
	}
	free(stack);
	stack = NULL;
	if(s3[k]=='\0' && s1[i] == '\0' && s2[j] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

int main()
{
	char s1[] = "aabcc";
	char s2[] = "dbbca";
	char s3[] = "aadbbbaccc";
 	printf("%d\n",isInterleave(s1,s2,s3));
	return 0;
}
