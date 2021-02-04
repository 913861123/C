#include <stdio.h>
#include <assert.h>


char* my_strcat(char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	char* p = arr1;
	while (*p)//当p指向\0时停止循环
	{
		p++;
	}
	while (*p++ = *arr2++)//从\0开始把arr2里的字符拷贝到arr1里
	{					//当考到arr2里的\0循环结束

	}
	return arr1;
}

int main()
{
	char arr1[100] = "hello word ";
	char arr2[] = "i love c";
	printf("%s",my_strcat(arr1, arr2));
	return 0;
}