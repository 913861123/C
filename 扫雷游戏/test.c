#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("********  1.玩游戏  *******\n");
	printf("********  0.退出    *******\n");
	printf("***************************\n");

}

void game()
{
	//创建对应的二维数组
	char mine[ROWS][COLS];//存放布置好雷的信息
	char check[ROWS][COLS];//存放排出雷的信息

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(check, ROWS, COLS, '*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);测试查看布置好的雷的
	DisplayBoard(check, ROW, COL);

	SetMine(mine,ROW,COL,THUNDER);//布置雷
	//DisplayBoard(mine, ROW, COL);便于查看自己布置的雷

	FineMine(mine, check, ROW, COL);//排查雷
}

int main()
{
	int inpute = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();//游戏菜单
		printf("请选择(1/0)>");
		scanf("%d", &inpute);
		switch (inpute)
		{
		case 1://玩游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}

	} while (inpute);
	return 0;
}