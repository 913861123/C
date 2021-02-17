#include <stdio.h>

int conte = 0;//统计移动次数
void print(char s1, char s2)
{
	printf("%c--->%c\n", s1, s2);
	conte++;
}

void Move(int n, char a, char b, char c)
{
	if (1 == n)
	{
		print(a, c);
	}
	else
	{
		Move(n - 1, a, c, b);//把A柱上n-1个盘子通过 C柱 移到了B柱上
		print(a, c);//将最底下的盘子从A柱移到B柱上
		Move(n - 1, b,a ,c );//把B柱上n-1个盘子通过 A柱 移到了C柱上


	}
	

}

int main()
{
	int n = 0;
	printf("请输入汉诺塔层数\n");
	scanf("%d", &n);
	Move(n, 'A', 'B', 'C');
	printf("至少要移动%d次", conte);
	return 0;
}