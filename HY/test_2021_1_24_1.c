#include <stdio.h>

void maopao(int arr[], int sz){
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++){//总共要冒泡数字总数减一次
		for (j = 0; j < sz - 1 - i;j++){//剩下的要排列的数就是冒泡次数减去冒泡完的数字
			if (arr[j]>arr[j + 1]){
				int jh = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = jh;
			}
		}
	}
}
int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("冒泡排序前 ");
	for (int i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n冒泡排序后 ");
	maopao(arr, sz);
	for (int j = 0; j < sz; j++){
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}