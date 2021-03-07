#include <stdio.h>
#include <string.h>
#include <assert.h>

void reversal(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		++left;
		--right;
	}
}

int main()
{
	char ch[] = "hello bei jing.";
	int len = strlen(ch);
	reversal(ch,ch+len-1);//逆序字符串

	char* s1 = ch;
	char* s2 = ch;
	
	while (*s1)
	{
		s2 = s1;
		while (*s2 != ' '&& *s2 != '\0')//当s2没指向空格时
		{
			++s2;
		}
		reversal(s1, s2 - 1);//逆序每一个单词
		if (*s2 == ' ')
		{
			s1 = s2 + 1;
		}
		else//等于、0时
		{
			s1 = s2;
		}

	}
	
	printf("%s\n", ch);

	return 0;

}