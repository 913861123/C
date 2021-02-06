#include <stdio.h>
#include <string.h>

int matrix(int arr[3][5],int x,int row,int col)
{
	int r = 0;
	int c = col - 1;//数组行列下标
	
	while (r <= x - 1 && c >= 0)
	{
		if (arr[r][c] < x)//当数字矩阵右上角的数小于要找的那个数时
			r++;
		else if (arr[r][c] > x)//当数字矩阵右上角的数大于要找的那个数时
			c--;
		else
			return 1;
	}
	return 0;//当矩阵找完还没找到
}

int main()
{
	int x = 0;
	int arr[][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	printf("输入要找的那个数\n");
	scanf("%d", &x);
	int ret = matrix(arr,x,3,5);
	if (1 == ret)
		printf("找到了\n");
	else
		printf("找不到\n");

	return 0;
}