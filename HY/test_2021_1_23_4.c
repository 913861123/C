#include <stdio.h>
int Fib(int n){
	if (n <= 2){//斐波那契前两个数是1
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);//前连个数之和等于第三个数
	}
}
int main(){
	int n = 0;
	scanf("%d", &n);
	int x=Fib(n);
	printf("第%d个斐波拉契数是%d\n", n, x);
	return 0;
}