#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char input[20] = "";
	system("shutdown -s -t 60");
	while (1)
	{

		printf("你的电脑将在1分钟内关机，请输入666取消关机\n");
		scanf("%s", input);
		if (strcmp(input, "666") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}