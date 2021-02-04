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


//回调函数
void calculator(int(*p)(int, int))//函数指针
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("输入两个整数进行计算\n");
	scanf("%d %d", &x, &y);
	ret = p(x, y);//调用函数进行计算
	printf("%d\n", ret);
}
int main()
{
	
	int input = 0;

	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("成功退出计算器\n");
			break;
		case 1:
			calculator(Add);//传的时函数地址
			break;
		case 2:
			calculator(Sub);
			break;
		case 3:
			calculator(Mul);
			break;
		case 4:
			calculator(Div);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}