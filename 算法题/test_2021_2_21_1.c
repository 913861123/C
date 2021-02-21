#include <stdio.h>
#include <assert.h>
void replace(char* arr)
{
	assert(arr != NULL);
	int conte = 0;//统计空格个数
	int lens = 0;//扩容后的数组长度
	int p1 = 0;//原数组最后一个元素的下标
	int p2 = 0;//数组扩充后的最后一个元素下标
	int len = 0;
	int i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == ' ')
			++conte;

		++len;//原来的字符串长度
		++i;
	}

	lens = len + conte * 2;
	p1 = len;
	p2 = lens;

	while (p1 >= 0 && p1 < p2)
	{
		if (arr[p1]==' ')//从后往前替换
		{
			arr[p2--] = '0';
			arr[p2--] = '2';
			arr[p2--] = '%';
		}
		else
		{
			arr[p2--] = arr[p1];
		}
		p1--;
	}
}

void test()
{
	char arr[100] = "hello word !";
	replace(arr);
	printf("%s\n", arr);
}
int main()
{
	test();
	return 0;
}