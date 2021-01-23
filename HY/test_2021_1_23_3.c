#include <stdio.h>
int ace(int n, int k){
	if (k !=0 ){
		k--;
		return n*ace(n,k);
	}
	else {
		return 1;
	}
}
int main(){
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);//n的k次方
	int sum=ace(n, k);
	printf("%d\n", sum);
	return 0;
}