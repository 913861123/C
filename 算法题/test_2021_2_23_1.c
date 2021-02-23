#include <stdio.h>
#include <string.h>

unsigned int conte_one(unsigned int x)
{
	unsigned int conte = 0;
	unsigned int p = 1;
	
	while (x!=0)
	{
		if (1 == (p & x))//当数字二进制最后一位为1时计数器加加
		{
			conte++;
		}
		x = x >> 1;//再向左移一位继续判断
	}
	return conte;
}

int main()
{
	unsigned int x = 0;
	scanf("%u", &x);
	printf("%u二进制中的1的个数为%u",x, conte_one(x));
	
	return 0;
}