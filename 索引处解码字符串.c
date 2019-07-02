#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//leet2code3
//leetleetcodeleetleetcodeleetleetcode

char DecodeAtIndex(char* S, int K) 
{
    assert(S != NULL);
    int len = strlen(S);
    char *str = (char *)calloc(len,sizeof(char));
    assert(str != NULL);
    int i = 0;
    int j = 0;
    int lenStr = len;
    for(i; i < len; i++)
    {
        if(j >= K)
        {
            break;
        }
        if(isalpha(S[i]))
        {
            str[j++] = S[i];
        }
        if(isdigit(S[i]))
        {
            int count = S[i] - '0';
            char *tmp = (char *)realloc(str,sizeof(char)*lenStr+j*(count-1));
            assert(tmp);
            str = tmp;
            str[j] = '\0';
            lenStr = lenStr+(j-1)*count;
            int k = 0;
            char *s = (char *)malloc(sizeof(char)*lenStr);
            assert(s != NULL);
            strcpy(s,str);
            for(k = 0; k < count-1; k++)
            {
                strcat(str,s);
            }
            free(s);
            s = NULL;
            j = j*count;
        }
    }
    printf("%s\n",str);
    if(j > K)
    {
        return str[K-1];
    }
    else
    {
        return 0;
    }
}

int main()
{
   char str[] = "leet2code3";
   int k = 10;
   char ch = DecodeAtIndex(str,k);
   printf("%c\n",ch);
   return 0;
}
