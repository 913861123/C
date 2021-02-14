#include <stdio.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	while (count)
	{
		*((char*)dest) = *((char*)src);
		++(char*)dest;
		++(char*)src;
		--count;
	}
}

int main()
{
	char arr[100] = "hello ";
	char arr2[] = "word !";
	my_memcpy(arr+6, arr2, 6);
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c", arr[i]);
	}
	
	return 0;
}