
#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* arr1, const char* arr2)
{
	char* ret = arr1;
	assert(arr1 && arr2);
	while ((*arr1++ = *arr2++))
	{

	}
	return ret;
}

int main()
{
	char arr1[100] = { 0 };
	char arr2[] = "hello word !";
	my_strcpy(arr1, arr2);
	printf("%s",arr1);

	return 0;
}