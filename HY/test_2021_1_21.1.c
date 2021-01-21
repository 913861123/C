#include <stdio.h>
#include <time.h>//time()函数所需要的头文件 
#include <stdlib.h>//srand和rand所需要的头文件 
void game(){
	printf("******************************\n");
	printf("**********  1.play  **********\n");
	printf("**********  2.byby  **********\n");
	printf("******************************\n");

}
int main(){
	int i=0;
	int number=0;
	int x = 0;//使用rand之前,得使用srand设置一个随机起点 
	srand((unsigned int)time(NULL));//NULL空指针，time用来生成时间戳，因为srand需要的是一个unsigned的整形所以，把time返回的time_t类型强制转换为（unsigned int）
	number = rand() % 100+1;//把随机生成数变成1到100之间,rand是用来生成随机数的
	game();
	
	do{
		printf("是否玩游戏（1/0）\n");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			printf("请猜数字\n");
			while (1){
				scanf("%d", &x);
				if (number == x){
					printf("恭喜你猜对了\n");
					break;
				}
				else if (number > x){
					printf("猜小了再猜\n");
				}
				else if (number < x){
					printf("猜大了再猜\n");
				}
			}
			break;
		case 0:
			printf("成功退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} 
	while (i);//当用户输入0时才能退出游戏，实现游戏可以重复玩 

	return 0;
}