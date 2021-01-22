#include <stdio.h>

int Fac(int n){
	if (n <= 1)
		return 1;
	else
		return n*Fac(n - 1);//n*(n-1)求n的阶层
	
}

int main(){
	int x = 0;
	scanf("%d", &x);
	int sum=Fac(x);
	printf("%d\n", sum);
	return 0;
}