#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
//
char *RreorganizeString(char* S) 
{
    assert(S != NULL);
    int len = strlen(S);
    int *hash = (int *)malloc(sizeof(int)*127);
    memset(hash,0,sizeof(int)*127);
    int hashmap[26] = {0};
    char *str = S;
    while(*str != '\0')
    {
        hash[*str]++;
    }
    int i = 0;
    int j = 0;
    for(i = 97; i <= 122; i++)
    {
        if(hash[i] > (len/2)+1)
        {
            return "";
        }
        hashmap[j] = i;
        int tmp = j;
        while((tmp-1)/2 >= 0)
        {   
            if(hash[hashmap[tmp]] > hash[hashmap[(tmp-1)/2]])
            {
                hashmap[tmp] = hashmap[tmp]^hash[(tmp-1)/2];
                hashmap[(tmp-1)/2] = hashmap[tmp]^hash[(tmp-1)/2];
                hashmap[tmp] = hashmap[tmp]^hash[(tmp-1)/2];
                tmp = (tmp-1)/2;
            }
            else
            {
                break;
            }
        }
        j++;
    }
    
}


int main()
{
    return 0;
}
