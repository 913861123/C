#include <stdio.h>

void my_strcpy(char* arr1, const char* arr2){

	while (*arr1 = *arr2){//实现strcpy
		++arr1;
		++arr2;
	}
}

int main(){
	char arr1[] = "xxxxxxxxxxx";
	char arr2[] = "shcoll";
	printf("传递前\n%s\n%s\n", arr1, arr2);
	my_strcpy(arr1,arr2);
	printf("传递后\n%s\n%s\n", arr1, arr2);
	return 0;
}