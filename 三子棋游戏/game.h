#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBboard(char board[ROW][COL], int row, int col);//初始化空棋盘


void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘


void GamerMore(char board[ROW][COL], int row, int col);//玩家下棋


void ComputerMore(char board[ROW][COL],int row,int col);//电脑下棋


char Judge(char board[ROW][COL],int row,int col);//判断输赢
