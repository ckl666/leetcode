#include <string>
#include <cctype>
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 128;

bool isNumber(const char* str)
{
    assert(str != NULL);
	int i = 0;
	int len = strlen(str);
	//消去字符串两边的空格
	while(str[i] == ' ')
	{
		i++;
	}
	while(str[len-1] == ' ')
	{
		len--;
	}

	//第一个字符必须为数字
	if(!isdigit(str[i++]))
	{
		return false;
	}

	for(; i < len; i++)
	{
		if(isdigit(str[i]))
		{
			;
		}
		else
		{
			if(str[i] == 'e' && isdigit(str[i+1]) )
			{
				;
			}
			else if(str[i] == '.' && isdigit(str[i+1]))
			{
				;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string str[] = {"  123  ", "1 a", "  123e213", "0.1 ", "23e21.3", "dwq", "123w"};
	int len = sizeof(str)/sizeof(str[0]);
	for(int i = 0; i < len; i++)
	{
		if(isNumber(str[i].c_str()))
		{
			cout << "is Number" <<endl;
		}
		else
		{
			cout << "is not Number" <<endl;
		}
	}
	return 0;
}
