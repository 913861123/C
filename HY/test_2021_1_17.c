#include <stdio.h>
int main() {
	char password[16] = { 0 };
	printf("请输入密码->");
	scanf("%s", password);//数组本来就是地址，所以不用取址符
	int ch = 0;//因为getchar可能会返回EOF,EOF=-1所以要用int
	while (ch = getchar() != '\n') {//清除缓冲区
	}
	printf("确认密码Y/N ");
	ch = getchar();//获取一个字符
	if (ch == 'Y') {
		printf("密码输入成功\n密码为：%s", password);
	}
	else if (ch == 'N') {
		printf("密码输入取消\n");
	}
	else {
		printf("输入错误");
	}
	return 0;
}
