#include <stdio.h>
#include <string.h>

char one_char(const char* arr, int leng)
{
	int i = 0;
	int j = 0;
	int conte = 0;
	for (i = 0; i < leng - 1; i++)
	{
		for (j = i + 1; j < leng - i; j++)
		{
			if (arr[i] != arr[j])
			{
				conte++;
			}
		}
		if (conte > leng - i)
		{
			return arr[i];
		}
	}
}

int main()
{
	char arr[] = "abccerrlcowswb";
	char ret = one_char(arr, strlen(arr));

	printf("%c", ret);
	return 0;
}