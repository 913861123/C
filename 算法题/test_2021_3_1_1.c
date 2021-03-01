#include <stdio.h>
#include <assert.h>

int add_max(int* arr, int leng)
{
	assert(arr != NULL && leng > 0);
	int i = 0;
	int j = 0;
	int sum = arr[0];
	int tmp;

	for (i = 0; i < leng - 1; i++)//有多少个数就遍历多少次
	{
		tmp = arr[i];
		if (sum < tmp)//这里是用来判断下一个数是否比上一个大，用于只有一个正数的情况
		{
			sum = tmp;
		}
		for (j = i + 1; j < leng; j++)//i+1个数相加比较
		{
			tmp += arr[j];
			if (sum < tmp)//如果算出来的结果大于sum就交换
			{
				sum = tmp;
			}
		}
	}

	return sum;
}


int main()
{
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };

	int ret = add_max(arr, sizeof(arr) / sizeof(arr[0]));

	printf("%d", ret);
	
	return 0;
}