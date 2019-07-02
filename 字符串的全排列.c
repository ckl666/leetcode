#include <stdio.h>
#include <string.h>
#include <assert.h>

//递归，字符串的全排列
void Swap(char *s1,char *s2)
{
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int IsSwap(char *begin,char *end)
{
    assert(begin != NULL && end != NULL);
    char *p = begin;
    for(p; p < end; p++)
    {
        if(*p == *end)
        {
            return 0;
        }
    }
    return 1;
}

void Permutation(char *str,char *begin)
{
    if(*begin == '\0')
    {
        printf("%s\n",str);
    }
    else
    {
        char *pchr = begin;
        for(pchr = begin; *pchr != '\0'; pchr++)
        {
            if(IsSwap(begin,pchr) == 1)     //去除重复
            {
                Swap(begin,pchr);
                Permutation(str,begin+1);
                Swap(begin,pchr);
            }
        }
    }
}

/*
void Permutation1(char *str,char *begin)
{

}
*/
//非递归

void Permutation1(char *str)
{
    assert(str != NULL);
    int len = strlen(str);
    int i = 0;
    int j = 0;
    int k = 0;

}

int main()
{
    char str[] = "abcd";
    Permutation(str,str);
    return 0;
}
