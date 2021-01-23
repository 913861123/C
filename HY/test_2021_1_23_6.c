#include <stdio.h>
int sums = 0;//用来装每个位上的和
int DigitSum(int n){
	
	sums += n % 10;//把最后一位分离出来相加
	if (n > 9){
		return DigitSum(n / 10);//去掉最后一位数
	}
	 if (n < 10){//当n为变成个位数时返回和
		 return sums;
	 }
}
int main(){
	int n = 0;
	scanf("%d", &n);
	int sum=DigitSum(n);
	printf("%d", sum);
	return 0;
}