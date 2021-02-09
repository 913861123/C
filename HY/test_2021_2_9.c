#include <stdio.h>

struct stu//结构体的声明
{
	char name2[20];
	char sex[10];
	int age;
}s1,s2;//在这创建变量的话s1和s2是全局的

struct book
{
	char name3[30];
	int price;
};

void print1(struct book c)
{
	printf("%s %d\n", c.name3, c.price);

}

void print2(struct book* s)
{
	printf("%s %d\n", s->name3, s->price);
}

struct school
{
	char name1[10];
	char classroom[20];
	struct stu;//结构体嵌套调用
	struct book;
};

int main()
{
	struct stu s1 = { "张三","男",18 };//结构体变量的创建
	struct stu s2 = { "李四","女",19 };

	printf("%s %s %d\n", s1.name2, s1.sex, s1.age);
	printf("%s %s %d\n", s2.name2, s2.sex, s2.age);

	struct book c = { "C语言程序设计",30 };
	struct book web = { "前端",28 };
	print1(c);//传值，创建一个print函数用来打印结构体
	print2(&web);//传地址打印，结构体传参传地址会更好

	struct school one = { "某大学","20届",
		{"小明","男",18 },//结构体的嵌套调用
		{"C语言程序设计", 100}
};
	printf("%s %s %s %s %d %s %d",//嵌套调用后打印
		one.name1, one.classroom,
		one.name2, one.sex, one.age,
		one.name3, one.price);
	return 0;
}