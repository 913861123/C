#include "game.h"


//空棋盘上每个位置放的是空格
void InitBboard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col){

	int i = 0;
	for (i = 0; i < row; i++)
	{//第一行分割行
		printf("---|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++){//打印数据
			printf(" %c ", board[i][j]);
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++){//打印其他分割行
			printf("---");
			printf("|");
		}
		printf("\n");
	}
	printf("\n");
}



//玩家下棋
void GamerMore(char board[ROW][COL], int row, int col){

	int x = 0;
	int y = 0;

	printf("玩家下:\n");
	while (1){
		printf("请输入一个坐标,数字用空格隔开->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col){
			if (board[x - 1][y - 1] != ' '){
				printf("坐标已被占用,请重新输入");
			}
			else 
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else 
		{
			printf("坐标输入非法，请从新输入");
		}
	}
	
}

//电脑下棋
void ComputerMore(char board[ROW][COL], int row, int col){
	
	printf("电脑下：\n");

		while (1){
			int x = rand() % row;//生成随机坐标
			int y = rand() % col;
			if (board[x][y] == ' '){
				board[x][y] = '#';
				break;
			}
	}

}

//平局判断
static int JudgeDraw(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
				return 0;	
		}
	}
	return 1;
}

//判断输赢
char Judge(char board[ROW][COL], int row, int col){
	int i = 0;
	//判断3行
	for (i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
	}

	//判断3列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			{
				return board[0][i];
			}
	}

	//对角判断
	
		if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
		{
			return board[1][1];
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[1][1]!=' ')
		{
			return board[1][1];
		}

		//判断平局
		if (JudgeDraw(board, row, col) == 1){
			return 's';//游戏平局
		}
		
			return 'c';//游戏继续

}
