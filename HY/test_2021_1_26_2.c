#include <stdio.h>

int main(){
	int a = 10;
	int b = 20;
	printf("交换前a=%d b=%d\n", a, b);
	a = a^b;//a和b异或得到一个密码
	b = a^b;//密码和b异或得到原来的a
	a = a^b;//密码和原来的a异或得到原来的b
	printf("交换后a=%d b=%d\n", a, b);

}