#include <stdio.h>
#include <string.h>
#include <assert.h>

void reversal(char* left, char* right)//逆序字符串
{
	assert(left && right);
	while (left < right)
	{
		char cmp = *left;
		*left = *right;
		*right = cmp;
		right--;
		left++;
	}
}

void left_move(char* arr, int x)
{
	assert(arr);
	int len = strlen(arr);
	reversal(arr, arr + x - 1);//先逆序要旋转的字符
	reversal(arr + x, arr + len - 1);//再逆序要旋转后面的字符
	reversal(arr, arr + len - 1);//最后再把整个字符串逆序一遍
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