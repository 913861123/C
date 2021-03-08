#include <stdio.h>

int test()
{
	union s1
	{
		char a;
		int i;
	}u;
	u.i = 1;
	
	return u.a;
}

int main()
{
	int ret = test();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}