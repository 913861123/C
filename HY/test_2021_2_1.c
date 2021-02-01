#include <stdio.h>

void yanghui(int n)
{
	int sanjiao[40][40] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		sanjiao[i][0] = 1;//每一行第一个数字都是1

		for (j = 1; j < i; j++)//从第二列开始填数字
		{
			sanjiao[i][j] = sanjiao[i - 1][j] + sanjiao[i - 1][j - 1];
		}

		for (j = 0; j < i; j++)
		{
			printf("%d ", sanjiao[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	printf("请输入杨辉三角的层数\n");
	scanf("%d", &n);
	yanghui(n);
	return 0;
}