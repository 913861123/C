#include <stdio.h>

void number(int* arr, int sz){

	int left = 0;
	int right = sz - 1;
	while (left < right){
		if (arr[left] % 2 == 0 && arr[right] % 2 != 0){
			int m = arr[left];
			arr[left] = arr[right];
			arr[right] = m;
		}
		left++;
		right--;

	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	printf("交换前\n");
	for (i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	number(arr, sz);
	printf("交换后\n");
	for (i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}