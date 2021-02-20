#include <stdio.h>

int matrix(int arr[4][4],int x,int row,int col)
{
	int n = 0;
	int ret = col - 1;
	while (n <= row && ret >= 0)
	{
		if (arr[n][ret]<x)//当右上角的数小于要找的那个数时
		{
			n++;
		}
		else if(arr[n][ret]>x)//大于时
		{
			ret--;
		}
		else
		{
			return 1;
		}
	}
	return 0;//当数组找完时
}

int main()
{
	int arr[4][4] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	int x = 0;
	int jz = 0;
	printf("请输入要找的那个数\n");
	scanf("%d", &x);
	jz = matrix(arr,x,4,4);
	if (1 == jz)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}