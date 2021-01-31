

#include "game.h"

void InitBoard(char mine[ROWS][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = ret;
		}
	}
}

void DisplayBoard(char mine[ROWS][COLS], int row, int col)
{
	printf("------扫雷游戏------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i <=col; i++)//打印行号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印列号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");

}

void SetMine(char mine[ROWS][COLS], int row, int col, int lei)
{
	
	while (lei)
	{
		//1-9的随机数
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';//坐标没有雷的话就布置一颗雷
			lei--;//每布置成功一颗雷就就减一
		}
	}
}

//计算mine数组周围8个坐标有几个雷
int GeMinelei(char mine[ROWS][COLS],int x ,int y)
{
	return mine[x-1][y-1] +
		mine[x][y-1] +
		mine[x+1][y-1] +
		mine[x-1][y] +
		mine[x+1][y] +
		mine[x-1][y+1]+
		mine[x][y+1] +
		mine[x+1][y+1] - 8 * '0';
}



void FineMine(char mine[ROWS][COLS], char check[ROWS][COLS], int row, int col)
{
	int win = 0;
	//9*9-10=71
	while (win<row*col - THUNDER)
	{
		int x = 0;
		int y = 0;
		printf("请输入要排查的x,y坐标>");
		scanf("%d%d", &x, &y);

		//判断坐标合法性
		if (x >= 1 && x <= row&&y >=1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//该坐标是不是雷不是雷，统计周围雷的个数
				int lei= GeMinelei(mine, x, y);
				check[x][y] = lei + '0';//存放的是数字字符
				DisplayBoard(check, row, col);
				win++;
			}
		}
		else
		{
			printf("违规坐标，请重新输入!\n");
		}
		if (win == row*col - THUNDER)
		{
			printf("恭喜你，排雷成功\n");
			DisplayBoard(mine, row, col);
		}
	}
}
