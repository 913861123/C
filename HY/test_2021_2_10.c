#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct book
{
	char name[20];
	int price;
};
int cmp_int(const void* s1, const void* s2)
{//比较整形
	return *(int*)s1 - *(int*)s2;
}


int cmp_char(const void* s1, const void* s2)
{//比较字符型
	return strcmp((char*)s1, (char*)s2);
}


int cmp_float(const void* s1, const void* s2)
{//比较浮点型
	return *(float*)s1 - *(float*)s2;
}


int cmp_struct_name(const void* s1, const void* s2)
{//比较结构体,按名字排序
	return  strcmp(((struct book*)s1)->name, ((struct book*)s2)->name);
}


int cmp_struct_price(const void* s1, const void* s2)
{//比较结构体，按价格排序
	return ((struct book*)s1)->price - ((struct book*)s2)->price;
}




//打印整形数组
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//打印字符数组
void print2(char* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}


//打印浮点型数组
void print3(float* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.1f ", arr[i]);
	}
	printf("\n");
}


//打印结构体数组
void print4(struct book* s1, int sz)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%s ", s1->name);
		s1++;
	}
	printf("\n");
}


int main()
{
	int arr[] = { 9,2,1,3,4,10,5,6,8,7 };
	char arr2[] = { 'b','c','d','e','a','f','\0' };
	float arr3[] = { 2.2,1.1,4.4,3.3,9.9,8.8,5.5,6.6,7.7 };
	struct book bk[] = { {"c plus",35},{"java",30},{"html+css",25} };
	printf("排序前\n");
	print(arr, sizeof(arr) / sizeof(arr[0]));
	print2(arr2, sizeof(arr2) / sizeof(arr2[0]));
	print3(arr3, sizeof(arr3) / sizeof(arr3[0]));
	print4(bk, sizeof(bk) / sizeof(bk[0]));



	printf("排序后\n");
	qsort(arr,
		sizeof(arr) / sizeof(arr[0]),
		sizeof(arr[0]),
		cmp_int);
	print(arr, sizeof(arr) / sizeof(arr[0]));


	qsort(arr2,
		sizeof(arr2) / sizeof(arr2[0]),
		sizeof(arr2[0]),
		cmp_char);
	print2(arr2, sizeof(arr2) / sizeof(arr2[0]));


	qsort(arr3,
		sizeof(arr3) / sizeof(arr3[0]),
		sizeof(arr3[0]),
		cmp_float);
	print3(arr3, sizeof(arr3) / sizeof(arr3[0]));


	//按名字排序
	qsort(bk,
		sizeof(bk) / sizeof(bk[0]),
		sizeof(bk[0]),
		cmp_struct_name);
	print4(bk, sizeof(bk) / sizeof(bk[0]));


	//按价格排序
	qsort(bk,
		sizeof(bk) / sizeof(bk[0]),
		sizeof(bk[0]),
		cmp_struct_price);
	print4(bk, sizeof(bk) / sizeof(bk[0]));
	return 0;
}
