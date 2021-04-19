#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int flags = 0;

int my_aito(unsigned char* str)
{
	//判断空指针和空字符串
	if (str == NULL || *str == '\0')
		return 0;
	long sum = 0;
	int flag = 1;
	//跳过空白字符
	while (isspace(*str))
	{
		str++;
	}
	//处理正负号
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	if(*str == '-')
	{
		flag = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (isdigit(*str))//判断是不是数字字符
		{
			sum = sum*10+flag*(*str - '0');
			if (sum > INT_MAX || sum < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
		str++;
	}
	flags = 1;

	return (int)sum;

}