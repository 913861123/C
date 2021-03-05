#include <stdio.h>
#include <string.h>
#include <assert.h>

char repeat(const char* arr, int len)
{
	assert(arr != NULL && len > 0);
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len - i; j++)
		{
			if (arr[i] == arr[j])
			{
				return arr[i];
			}
		}
	}

	return ' ';
}
int main()
{
	char ch[] = "qywyer23tdd";
	int len = strlen(ch);
	char ret = repeat(ch, len - 1);
	printf("%c", ret);

	return 0;
}