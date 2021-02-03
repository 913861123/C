#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <assert.h>
char* xuanzhuang(const char* s1,char* s2)
{
	assert(s1 != NULL && s2 != NULL);//断言
	char arrs[100] = {0};//辅助将原字符复制一份
	strcpy(arrs, s1);//拷贝字符串
	strcat(arrs, s1);//连接字符串

	return strstr(arrs, s2);//看看找不着得到
}

int main()
{
	char s1[100] = "AABCD";
	char s2[100] = "ABCDA";
	if (xuanzhuang(s1, s2) != NULL)
	{
		printf("该字符串是旋转后的字符\n");
	}
	else
	{
		printf("该字符串不是旋转后的字符");
	}
	return 0;
}