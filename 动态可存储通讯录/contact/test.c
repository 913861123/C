#include "contact.h"

void menu()
{
	printf("*****************************************\n");
	printf("******* 1.新建联系人 2.打印联系人 *******\n");
	printf("******* 3.删除联系人 4.修改联系人 *******\n");
	printf("******* 5.查找联系人 6.排序联系人 *******\n");
	printf("************* 0.退出通讯录 **************\n");
}
enum Menus
{
	EXIT,
	ADD,
	SHOW,
	DELETE,
	AMEND,
	FIND,
	RANGK
};

void test()
{
	int input = 0;
	struct contact con;

	Initialize(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case AMEND:
			AmendContact(&con);
			break;
		case FIND:
			FindContact(&con);
			break;
		case RANGK:
			RangkContact(&con);
			break;
		case EXIT:
			DisposalContact(&con);
			printf("通讯录已经退出\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;

		}
	} while (input);
}

int main()
{
	test();
	return 0;
}