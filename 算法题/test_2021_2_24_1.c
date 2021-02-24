#include <stdio.h>
#include <assert.h>

int min_n(int* arr,int k)
{
	assert(arr != NULL);
	int tmp = arr;
	int i = 0;
	if (1 == k)
	{
		return arr[1];
	}
	
	for (i = 1; i < k; i++)
	{
		if (tmp > arr[i])
		{
			tmp = arr[i];
		}
	}
	return tmp;
}

int main()
{
	int arr[] = { 35,24,16,32,10,15,42,15,98,44,9,11 };
	int k = 0;
	scanf("%d", &k);
	printf("%d",min_n(arr,k));
	return 0;
}