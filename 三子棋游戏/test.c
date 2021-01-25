#include "game.h"

void menu(){

	printf("*******************************\n");
	printf("**********   1.玩游戏  ********\n");
	printf("**********   0.退出    ********\n");
	printf("*******************************\n");

}

void game(){
	char ret = 0;
	char board[ROW][COL];//用二维数组来存数据

	InitBboard(board, ROW, COL);//生成棋盘初始化为空格

	DisplayBoard(board, ROW, COL);//打印棋盘

	while (1){

		GamerMore(board, ROW, COL);//玩家下棋

		ret = Judge(board, ROW, COL);//判断输赢
		if(ret != 'c'){
			break;
		}

		DisplayBoard(board, ROW, COL);

		ComputerMore(board, ROW, COL);//电脑随机下棋

		ret = Judge(board, ROW, COL);
		if (ret != 'c'){
			break;
		}

		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*'){
		printf("恭喜你获得胜利\n");
	}
	else if (ret == '#'){
		printf("电脑赢了\n");
	}
	else if (ret == 's'){
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main(){
	int inpute = 0;
	srand((unsigned int)time(NULL));//随机数起点
	do
	{
		menu();//游戏菜单
		printf("请选择->");
		scanf("%d", &inpute);
		printf("\n---三子棋---\n\n");
		switch (inpute){
		case 1:{  //玩游戏
				game();//三子棋游戏
				break;
			}
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请从新选择\n");
				break;
		}
	} while (inpute);
	return 0;
}