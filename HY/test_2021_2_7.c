#include <stdio.h>
#include <string.h>

void print_int(int* arr, int sz)//打印整形数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void print_char(char* arr, int sz)//打印字符型数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ",arr[i]);
	}
}
int cmp_int(const void* s1,const void* s2)
{
	return (*(int*)s1-*(int*)s2);//比较整形大小
}

int cmp_char(const void* s1, const void* s2)
{
	return (*(char*)s1 - *(char*)s2);//比较字符大小
}

void _swp(char* jh1, char* jh2,int width)//交换元素位置
{
	int i = 0;
	for (i = 0; i < width; i++)//循环一个元素的大小次，交换的就是一个元素
	{
		char tmp = *jh1;
		*jh1 = *jh2;
		*jh2 = tmp;
		jh1++;
		jh2++;
	}
}


void maopao_qsort(void *base,//待排序数据的起始位置
				 size_t num,//数组元素的个数
				 size_t width,//每个元素的大小
				 int(*cmp)(const void* s1, const void* s2))//自定义交换函数
{

	size_t i = 0;
	for (i = 0; i < num - 1; i++)//冒泡的趟数
	{
		size_t j = 0;
		for (j = 0; j <num-1 ; j++)
		{
			//相邻两个元素大小比较
			if (cmp((char*)base+(width*j), (char*)base + width*(j+1))>0)
			{//因为base是void类型，不能++和解引用所以强转为char
				//满足条件的话就交换两个元素的位置
				_swp((char*)base + (width * j) , (char*)base + width * (j + 1),width);
			}
		}
	}
}

void test1()
{
	int arr[] = { 2,1,9,3,4,10,5,6,7,8 };
	maopao_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
	print_int(arr, sizeof(arr) / sizeof(arr[0]));
}

void test2()
{
	char arr1[] = "badce";
	maopao_qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp_char);
	print_char(arr1, sizeof(arr1) / sizeof(arr1[0]));
}

int main()
{
	test1();//整形冒泡
	printf("\n");
	test2();//字符冒泡

	return 0;
}