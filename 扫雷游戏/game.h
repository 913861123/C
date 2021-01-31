

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define THUNDER 10//雷的个数

//初始化棋盘
void InitBoard(char mine[ROWS][COLS],int rows,int cols,char ret);

//打印棋盘
void DisplayBoard(char mine[ROWS][COLS], int row, int col);
void DisplayBoard(char check[ROWS][COLS],int row,int col);

//布置雷
//mine是存放布置雷的信息
//lei布置雷的个数
void SetMine(char mine[ROWS][COLS],int row,int col,int lei);

//排雷
void FineMine(char mine[ROWS][COLS],
			  char check[ROWS][COLS],
			  int row, int col);
