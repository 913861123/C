#include <stdio.h>
#include <assert.h>

char one_char(const char* ch, int leng)
{
	assert(ch != NULL && leng > 0);
	if (1 ==  leng)
	{
		return ch[0];
	}
	int i = 0;
	int j = 0;
	int cont = 0;
	for (i = 0; i < leng-1; i++)
	{
		cont = 0;
		for (j = i + 1; j < leng - i-1; j++)
		{
			if (ch[i] == ch[j])
			{
				cont++;
				
			}
		}
		if (0==cont)
		{
			return ch[i];
		}

	}
}

int main()
{
	char ch[] = "abaccdeff";
	char ret = one_char(ch, sizeof(ch) / sizeof(ch[0]));

	printf("%c", ret);
	
	return 0;
}