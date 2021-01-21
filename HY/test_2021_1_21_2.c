#include <stdio.h>
#include <math.h>
int shusu(int i){
	for (int j = 2; j <= sqrt(i); j++){////如果i是素数那么2到根号i中一定有个数字能整除i
		if (i%j== 0){
			return 0;
		}
	}
	return 1;//是素数返回1
}
int main(){
	int i = 0;
	for (int i = 100; i <= 200; i++){
		shusu(i);
		if (shusu(i) == 1){
			printf("%d\n", i);
		}
	}
	return 0;
}