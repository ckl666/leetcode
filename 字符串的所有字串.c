#include <stdio.h>


void SubString(int n)
{
	const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int maxnum = 1<<n;          //2^n
    int i = 0;
    int j = 0;
	for(i = 0;i < maxnum; i++)//处理0到2^n  -1之间的数字
	{
		for(j=0;j<n;j++)//j表示二进制右数第几位
		{
			if( (i&(1<<j)) != 0)//表示当前位不为0,则需要打印相应的字母
			{
				printf("%c ",str[j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	SubString(4);
	return 0;
}
