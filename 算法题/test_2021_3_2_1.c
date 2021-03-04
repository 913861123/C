#include <stdio.h>
#include <assert.h>

char one_char(const char* ch, int leng)
{
	assert(ch != NULL && leng > 0);

	int i = 0;
	int j = 0;
	int conte = 0;

	for (i = 0; i < leng - 1; i++)
	{
		conte = 0;
		for (j =0; j < leng - 1; j++)
		{
			if (i != j)
			{
				if (ch[i] == ch[j])//当有相同的字符时直接跳出循环进行下一轮判断
				{
					++conte;
					break;
				}
			}
			
		}
		if (0 == conte)
		{
			return ch[i];
		}
	}

}

int main()
{
	char ch[] = "babaccdeff";
	char ret = one_char(ch, sizeof(ch) / sizeof(ch[0]));

	printf("%c", ret);
	return 0;
}