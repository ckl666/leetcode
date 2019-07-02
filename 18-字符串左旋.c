#include <stdio.h>
#include <assert.h>
#include <string.h>

//abcdefg ==》cdefgab
void Reversr(char *str,int start,int end)
{
    assert(str != NULL);
    while(end > start)
    {
        str[start] = str[start]^str[end];
        str[end] = str[start]^str[end];
        str[start] = str[start]^str[end];
        end--;
        start++;
    }
}

void StrLeftChange(char *str,int n)     //n左旋位数
{
    int len = strlen(str);
    Reversr(str,0,len-1);
    Reversr(str,0,len-n-1);
    Reversr(str,len-n,len-1);
}


int main()
{
    char str[] = "abcdefg";
    int n = 2;
    StrLeftChange(str,n);
    printf("%s\n",str);
    return 0;
}
