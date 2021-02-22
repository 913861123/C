#include <stdio.h>

int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		--n;
	}
	return c;
}

int main()
{
	int n = 0;
	printf("请输入要求的第n个斐波那契数\n");
	scanf("%d", &n);
	printf("第%d个斐波那契数为%d",n,Fibonacci(n));
	
	return 0;
}