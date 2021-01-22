#include <stdio.h>
int chazhao(int number[], int k, int cd){
	int left = 0;
	int right = cd - 1;
	while (left<=right){
		int mid = left + (right - left) / 2;//每次查找都要重新初始化中间坐标
		if (number[mid] > k){
			right = mid - 1;
		}
		if (number[mid] < k){
			left = mid + 1;
		}
		if (number[mid] == k){
			return mid;
		}
	}
	
	if (left>right)
		return 0;
	
}
int main(){
	int number[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 0;
	int cd = sizeof(number) / sizeof(number[0]);
	printf("输入你要找的那个数\n");
	scanf("%d", &k);
	chazhao(number, k, cd);
	int ace = chazhao(number, k, cd);//数组在传参的时候，传的是数组首个元素的地址
	if (ace ==-1 ){
		printf("没找到\n");
	}
	else {
		printf("找到了下标是%d\n", ace);
	}
	return 0;
}