#include <stdio.h>
#include <string.h>
#include <assert.h>

void left_move(char* arr, int x)
{
	assert(arr);
	int len = strlen(arr);
	x = x % len;//长度为6的话，当移动8次相当于移动2次，减少循环次数
	int i = 0;
	int j = 0;
	for (j = 0; j < x; j++)
	{
		char tmp = *arr;//把第一个字符放放到一个临时空间
		for (i = 0; i < len - 1; i++)//把剩下的字符往前移
		{
			*(arr + i) = *(arr + i + 1);
		}
		*(arr + len - 1) = tmp;//再把第一个字符放到最后
	}
}

int main()
{
	char arr[] = "ABCDEF";
	int x = 0;
	printf("输入要旋转的字符个数");
	scanf("%d", &x);
	left_move(arr, x);
	printf("%s", arr);

	return 0;
}