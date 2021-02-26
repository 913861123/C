#include <stdio.h>
#include <assert.h>

int half(int* arr, int len)//只能用于数组里有个数超过数组长度一半的数组
{
	assert(arr != NULL && len > 0);
	int conte = 0;
	int tmp = 0;
	int i = 0;

	for (i = 0; i < len; i++)
	{

		if (0 == conte)//当为0时更新数字
		{
			tmp = arr[i];
			conte = 1;
		}
		else if (tmp == arr[i])//相等加一
		{
			conte++;
		}
		else//不相等减一
		{
			conte--;
		}
	}

	return tmp;
}

int* halfs(int* arr, int len)//只有当数组里有超过长度一半的数才会返回数字
{
	assert(arr != NULL && len > 0);
	int i = 0;
	int j = 0;
	for (i = 0; i < len / 2; i++)
	{
		int conte = 1;//计算数字出现的个数
		int tmp = arr[i];
		for (j = i + 1; j <= len; j++)
		{

			if (tmp == arr[j])
			{
				conte++;
			}
			if (tmp > len / 2)//当数字个数超过数字的一时直接返回那个数字的地址
			{
				return &tmp;
			}
		}
	}

	return NULL;
}

void test1()
{
	int arr[] = { 1,2,5,3,4,5,5,5,5 };
	int* ret = half(arr, sizeof(arr) / sizeof(arr[0]));
	if (ret != NULL)
	{
		printf("%d\n", (int)ret);
	}
}

void test2()
{
	int arr[] = {3,2,1,3,3,2,2,3,3,1};
	int ret = half(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", ret);

}
int main()
{
	test1();
	test2();

	return 0;
}