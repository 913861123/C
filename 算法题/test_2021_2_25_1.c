#include <stdio.h>

int half(int* arr, int sz)
{
	int conte = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz/2; i++)
	{
		conte = 1;
		for (j = i+1; j <sz-i; j++)
		{
			if (arr[i] == arr[j])
			{
				conte++;
			}
			
		}
		if (conte > sz / 2)
		{
			return arr[i];
		}
		
	}
		return 0;
}

int main()
{
	int arr[] = { 1,2,5,3,4,5,5,5,5};
	int ret = half(arr, sizeof(arr) / sizeof(arr[0]));
	if (ret != 0)
	{
		printf("%d", ret);
	}
	return 0;
}