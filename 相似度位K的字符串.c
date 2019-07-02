#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
 * 字符串中的字符交换k次之后与字符串B相等
*/

int kSimilarity(char* A, char* B) 
{
    assert(A != NULL && B != NULL);
    int lenA = strlen(A);
    int lenB = strlen(B);
    if(lenA != lenB)
    {
        return -1;
    }
    int k = 0;
    int i = 0;
    for(i = 0; i < lenA; i++)
    {
        if(A[i] != B[i])
        {
            int j = 0;
            for(j = i+1; j < lenA; j++)
            {
                if(A[j] == B[i])
                {
                    A[j] = A[i] ^ A[j];
                    A[i] = A[i] ^ A[j];
                    A[j] = A[i] ^ A[j];
                    k++;
                    break;
                }
            }
            if(j >= lenA)
            {
                return -1;
            }
        }
    }
    return k;
}

int main()
{
    char A[] = "abcdabcd";
    char B[] = "bcadcbda";
    printf("%d \n",kSimilarity(A,B));
    return 0;
}
