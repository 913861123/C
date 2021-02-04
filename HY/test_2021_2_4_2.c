#include <stdio.h>

void menu()
{
	printf("*******************************\n");
	printf("*******  1.Add  2.Sub  ********\n");
	printf("*******  3.Mul  4.Div  ********\n");
	printf("*******     0.exit    *********\n");
	printf("*******************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;

}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int input = 0;

	int(*calculator[])(int, int) = { 0, Add, Sub, Mul, Div };//函数指针数组（转移表）
	
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		if (0 == input)
		{
			printf("成功退出计算器\n");
			break;
		}
		else if (input >= 1 && input<= 4)
		{
			printf("输入两个整数进行计算\n");
			scanf("%d %d", &x, &y);
			ret = calculator[input](x, y);//调用函数指针数组里的函数进行计算
			printf("%d\n", ret);
		}
		else
		{
			printf("输入错错误请重新输入\n");
		}
		

	} while (input);

	return 0;
}