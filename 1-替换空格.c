#include <stdio.h>
#include <string.h>
#include <assert.h>

void Change(char *str1,char *str2,char ch)
{
    assert(str1 != NULL && str2 != NULL);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = 0;
    int count = 0;
    while(str1[i] != '\0')
    {
        if(str1[i] == ch)
        {
            count++;
        }
        i++;
    }
    i = len1;
    j = i+count*(len2-1);
    while(i >= 0)
    {
        if(str1[i] != ch)
        {
            str1[j--] = str1[i];
        }
        else
        {
            int k = len2-1;
            for(;k >= 0; k--)
            {
                str1[j--] = str2[k];
            }
        }
        i--;
    }
}

int main()
{
    char str1[20] = " hel lo wor ld ";
    char ch = ' ';
    char str2[] = "%20";
    Change(str1,str2,ch);
    printf("%s\n",str1);
    return 0;
}
