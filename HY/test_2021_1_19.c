#include <stdio.h>
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//二分查找只能用于一组有序数字查找
	int cd = sizeof(arr) / sizeof(arr[0]);//sizeof计算的是数组的大小，单位是字节。
	int left = 0;//左下标
	int right = cd - 1;//右下标
	int x=0;
	printf("请输入要查找的那个数\n");
	scanf("%d",&x);
	while (left <= right){
		int mid = left+(right-left)/ 2;//每次二分查找都要从新确定范围，所以要把变量定义到循环里面
		if (arr[mid] > x){//当找的那个数比中间那个数小时
			right = mid - 1;
		}
		else if (arr[mid] < x){//当找那个数比中间那个数大时
			left = mid + 1;
		}
		else {
			printf("找到了,这个数的下标是%d\n", mid);
			break;
		}
		
	}
	if (left>right){
		printf("找不到这个数字");
	}
	return 0;
} 