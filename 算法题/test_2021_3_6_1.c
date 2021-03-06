#include <stdio.h>
#include <string.h>
#include <assert.h>

void reversal(char* left,char* right)
{
	assert(left && right);
	while (left < right)
	{
		
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char ch[] = "hello bei jin.";

	reversal(ch, ch+strlen(ch)-1);

	char* s1 = ch;
	char* s2 = ch;
	printf("%s", ch);

	while (*s2 != ' ')
	{
		++s2;
	}
	reversal(s1, s2);
	s2 = s2 + 1;

	return 0;
}