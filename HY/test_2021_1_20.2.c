#include <stdio.h>
#include <stdlib.h>//使用strcmp()函数时所需要的头文件
int main(){
	int i ;
	char password[16] = {0};
	char password2[16] = {0};
	printf("请设置你的密码>\n");
	scanf("%s", password2);
	printf("密码设置成功\n请输入密码登录账号>\n");

	for (i = 0; i < 3;i++){//当密码输入错误三次时退出
		scanf("%s", password);
		if (strcmp(password, password2) == 0){//strcmp用来字符串之间的比较
			printf("登录成功\n");
			break;
		}
		else{
			printf("密码错误\n");
		}
		
	}
	if (i == 3){
		printf("密码输入次数过多,程序退出\n");
	}
	return 0;
}