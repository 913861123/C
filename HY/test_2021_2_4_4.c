#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* s1, const char* s2)
{
	assert(s1 && s2);
	const char* sp = s1;
	
	while (*sp)//当sp没有指向\0时
	{
		const char* p1 = sp;
		const char* p2 = s2;
		while ((*p1)&&(*p2)&&(*p1==*p2))//当p1和p2没有指向\0时
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return (char*)sp;
		}
		sp++;
	}
	return NULL;
}


int main()
{
	char arr1[] = "peaceS";
	char arr2[] = "ace";
	
	printf("%s",my_strstr(arr1, arr2));

	return 0;
}