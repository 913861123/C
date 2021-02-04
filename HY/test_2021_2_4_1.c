#include <stdio.h>
#include <assert.h>

int my_strlen(const char* str)
{
	assert(str != NULL);
	int conte = 0;
	while (*str)//当str指向\0的时候停止循环
	{
		str++;
		conte++;
	}
	return conte;//返回字符串长度
}

int main()
{
	int len = 0;
	char arr[] = "abcdef";
	//int len = my_strlen(arr);
	//printf("%d\n", len);
	int(*pd)(char*) = &my_strlen;
	//len = (*pd)(arr);
	len = pd("123456789");//调用函数指针时可以不解引用
	printf("%d\n", len);
	return 0;
}