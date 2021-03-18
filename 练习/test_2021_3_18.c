


#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100];
	int len;
	int n = 0;
	int i = 0;//字母下标
	int j = 0;
	int cont = 0;
	scanf("%s", arr);
	len = strlen(arr);

			for(j=1;j<5;j++)
			{
				if (j%2!=0)
				{
					while ((arr[i] != 'a' && arr[i] != 'e' && arr[i] != 'i' && arr[i] != 'o' && arr[i] != 'u') && cont <= len)
					{
						cont++;
						++i;
					}
					if ((cont <= len) && (cont != 0))
					{
						n++;
					}
				}
				else
				{
					while ((arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') && cont <= len)
					{
						cont++;
						++i;
					}
					if ((cont <= len) && (cont != 0))
					{
						n++;
					}
				}
			}

	if (n == 4)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
		
	return 0;
}