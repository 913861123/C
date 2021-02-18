#include <stdio.h>

int Move(int n)
{
	if (n <= 3)
	{
		return n;
	}

		return Move(n - 1) + Move(n - 2);
}

int main()
{
	int n = 0;
	printf("请输入台阶的数量\n");
	scanf("%d", &n);
	printf("共有%d种走法\n",Move(n));
	return 0;
}