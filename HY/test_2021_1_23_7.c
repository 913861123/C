#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse_string(char* arr, int sz){
	int left = 0;
	int right = sz - 1;
	char div;//空字符用来交换字符数组的字符
	while (left<right){
		div = arr[left];
		arr[left] = arr[right];
		arr[right] = div;
			++left;
			--right;	
	}	
		printf("%s", arr);
}
int main(){
	char arr[] = "abcdef";
	int sz = strlen(arr);
	reverse_string(arr, sz);
	
	return 0;
}