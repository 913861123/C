#include <stdio.h>
void sum(int x){
	if (x > 9){//当i不是一位数时继续递归
		sum(x / 10);//把最后一位数字分离出去
	}
	printf("%d ", x%10);//直接打印出最后一位数字
}

int main(){
	int i = 0;
	scanf("%d", &i);
	sum(i);
	return 0;
}