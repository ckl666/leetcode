#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Swap(char *str,int lenStr)
{
	int i = 0;
	for(i = 0; i < lenStr/2; i++)
	{
		str[i] = str[i]^str[lenStr-i-1];
		str[lenStr-i-1] = str[i]^str[lenStr-i-1];
		str[i] = str[i]^str[lenStr-i-1];
	}
}

char *SubNum(char *p1,char *p2)
{
	assert(p1 != NULL && p2 != NULL);
	int lenStr1 = strlen(p1);
	int lenStr2 = strlen(p2);
	int flag = 0;
	char *str1 = NULL;
	char *str2 = NULL;
	if(lenStr1 > lenStr2)
	{
		str1 = p1;
		str2 = p2;
		flag = 0;
	}
	else if(lenStr1 < lenStr2)
	{
		int tmp = lenStr1;
		lenStr1 = lenStr2;
		lenStr2 = tmp;
		str1 = p2;
		str2 = p1;
		flag = 1;
	}
	else
	{
		if(strcmp(p1,p2) < 0)
		{
			str1 = p2;
			str2 = p1;
			flag = 1;
		}
		else if(strcmp(p1,p2))
		{
			str1 = p1;
			str2 = p2;
			flag = 0;
		}
		else
		{
			return "0";
		}
	}
	int i = lenStr1 - 1;
	int j = lenStr2 - 1;
	char ch = 0;
	char *str = (char *)calloc(lenStr1+lenStr2,sizeof(char));
	assert(str != NULL);
	int tag = 0;
	int k = 0;
	while(i >= 0 && j >= 0)
	{
		ch = str1[i];
		if(tag == 1)
		{
			ch -= 1;
		}
		ch -= str2[j];
		if(ch >= 0)
		{
			ch += '0';
			tag = 0;
		}
		else
		{
			ch = ch +10+'0';
			tag = 1;
		}
		str[k++] = ch;
		i--;
		j--;
	}
	while(i >= 0)
	{
		if(tag == 1)
		{
			ch = str1[i]-1;
			if(ch < '0')
			{
				ch = ch + 10;
			}
			else
			{
				tag = 0;
			}
			str[k++] = ch;
			i--;
		}
		else
		{
			str[k++] = str1[i--];
			tag = 0;
		}
	}
	while(str[k-1] == '0')
	{
		k--;
	}
	if(flag == 1)
	{
		str[k++] = '-';
	}
	if(k == 0)
	{
		str[k++] = '0';
	}
	str[k] = '\0';
	Swap(str,k);
	return str;
}



char *Addbriary(char *str1,char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	int lenStr1 = strlen(str1);
	int lenStr2 = strlen(str2);
	int i = lenStr1-1;
	int j = lenStr2-1;
	char *str = (char *)calloc(lenStr1+lenStr2,sizeof(char));
	assert(str != NULL);
	char ch = 0;
	char tag = 0;
	int k = 0;
	while(i >= 0 && j >= 0)
	{
		if(tag == 0)
		{
			ch = str1[i]-'0' + str2[j]-'0';
		}
		else
		{
			ch = str1[i]-'0' + str2[j]-'0' + 1;
		}
		if(ch >= 10)
		{
			tag = 1;
			ch -= 10;
		}
		else
		{
			tag = 0;
		}
		str[k++] = ch+'0';
		i--;
		j--;
	}
	while(i >= 0)
	{
		if(tag == 1)
		{
			if(str1[i]+1 > '9')
			{
				str[k++] = str1[i--]-9;
			}
			else
			{
				str[k++] = str[i--]+1;
				tag = 0;
			}
		}
		else
		{
			str[k++] = str[i--];
		}
	}
	while(j >= 0)
	{
		if(tag == 1)
		{
			if(str2[j]+1 > '9')
			{
				str[k++] = str2[j--]-9;  //+1-10
			}
			else
			{
				str[k++] = str[j--]+1;
				tag = 0;
			}
		}
		else
		{
			str[k++] = str2[j--];
		}
	}
	if(tag == 1)
	{
		str[k++] = '1';
	}
	str[k] = '\0';
	int lenStr = k;
	while(str[lenStr-1] == '0')
	{
		lenStr--;
	}
	while(lenStr == 0)
	{
		str[lenStr++] = '0';
	}
	str[lenStr] = '\0';
	Swap(str,lenStr);
	return str;
}
//大数乘法

char *MuNum(char *str1,char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	int lenStr2 = strlen(str2);
	char *num = (char *)malloc(sizeof(char)*(lenStr2+1));
	assert(num != NULL);
	memset(num,'0',lenStr2*sizeof(char));
	num[lenStr2] = '\0';
	int i = lenStr2-1;
	int tag = 0;
	char *str = Addbriary("0","0");
	char *pdel = NULL;
	pdel = str;
	while(strcmp(str2,num) != 0)
	{
		str = Addbriary(str1,str);
		free(pdel);
		pdel = str;
		for(i = lenStr2-1; i >= 0; i--)
		{
			num[i] += 1;
			if(num[i] > '9')
			{
				num[i] = '0';	
			}
			else
			{
				break;
			}
		}
	}
	return str;
}

int main()
{
	char *str1 = "11111111111111";
	char *str2 = "3";
	char *str = MuNum(str1,str2);
	printf("%s\n",str);
	return 0;
}

#if 0
int main()
{
	
}
#endif
