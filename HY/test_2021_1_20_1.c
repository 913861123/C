#include <stdio.h>
#include <string.h>//用strlen需要的头文件
#include <windows.h>//用Sleep所需要的头文件
#include <stdlib.h>//用system所需要的头文件
int main(){
	char log[] = "#############";
	char arr[] = "Hello world !";
	int cd = strlen(log)-1;//strlen计算字符串的长度
	int left = 0;
	int right = cd;
	while (left <= right){
		log[left] = arr[left];
		log[right] = arr[right];
		Sleep(1000);//延迟打印,单位是毫秒
		system("cls");//system是用来执行系统命令的,cls是清空屏幕的意思
		printf("%s\n", log);
			left++;
			right--;

	}
	
	return 0;
}