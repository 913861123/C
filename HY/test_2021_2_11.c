#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest && src);

	if (dest < src)
	{//从前向后拷贝
		//以src的起始地址为分界线，如果dest的起始地址小于src起始的地址
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else//如果dest的起始地址等于或大于src的地址
	{//从后向前拷贝
		
		while (count--)
		{
			*((char*)dest+count) = *((char*)src+count);
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr+1,arr,16 );
	
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}