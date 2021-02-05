#include <stdio.h>

#include <assert.h>
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);

	while (*s1++&&*s2++)
	{
		if (*s1 > *s2)
			return 1;

		else if (*s1 < *s2)
			return -1;
	}
	

		return 0;
}


int main()
{
	char arr1[] = "abcde";
	char arr2[] = "abcda";
	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	
	return 0;
}