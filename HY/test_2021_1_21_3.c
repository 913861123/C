#include <stdio.h>
int nian(int i){
	if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)){
		return 0;
	}
	else
		return 1;
}
int main(){
	int i = 0;
	scanf("%d", &i);
	nian(i);
	if (nian(i) == 0){
		printf("%d是闰年\n",i);
	}
	else{
		printf("%d不是闰年\n",i);
	}
	return 0;
}