#include "address_list.h"

void menu()
{
	printf("************************************\n");
	printf("***** 1.新建联系人 2.打印联系人 ****\n");
	printf("***** 3.删除联系人 4.修改联系人 ****\n");
	printf("***** 5.查找联系人 6.排序联系人 ****\n");
	printf("********** 0.退出通讯录 ************\n");
}

enum Menu
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
	struct contact con;//创建了一个通讯录

	Initialize(&con);
	do
	{
		menu();
		printf("请输入:>");
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
			
			break;
		case EXIT:
			printf("成功退出通讯录\n");
			break;
		default:
			printf("选择错误，请从新选择\n");
			break;
		}
	} while (input);

}


int main()
{
	test();

	return 0;
}