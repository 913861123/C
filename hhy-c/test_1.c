#include <stdio.h>
int main() {
	char password[16] = { 0 };
	printf("请输入密码->");
	scanf("%s", password);//数组本来就是地址，所以不用取址符
	int ch = 0;
	char add;
	while (ch = getchar() != '\n') {
	}
	printf("确认密码Y/N ");
	scanf("%c", &add);
	if (add == 'Y') {
		printf("密码输入成功");
	}
	else if (add == 'N') {
		printf("密码输入取消");
	}
	else {
		printf("输入错误");
	}
	return 0;
}