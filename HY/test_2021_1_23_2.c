#include <stdio.h>

int Fac(int n){
	if (n <= 1){
		return 1;
	}
	else {
		return n*Fac(n - 1);//当n大于1的时候继续递归
	}
}

int main(){
	int n = 0;
	printf("输入一个整数求它的阶层\n");
	scanf("%d", &n);
	Fac(n);
	int sum = Fac(n);
	printf("%d\n", sum);
	return 0;
}