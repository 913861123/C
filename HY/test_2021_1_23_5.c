#include <stdio.h>
int Fib(int n){
	int a = 1;//斐波那契前两个数是1
	int b = 1;
	int c = 0;
	if (n <= 2){
		return 1;
	}
	while (n > 2){
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	
	return c;
}
int main(){
	int n = 0;
	scanf("%d", &n);
	int x=Fib(n);
	printf("第%d个斐波拉契数是%d\n", n, x);
	return 0;
}