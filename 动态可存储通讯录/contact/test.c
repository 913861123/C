#include "contact.h"

void menu()
{
	printf("*****************************************\n");
	printf("******* 1.�½���ϵ�� 2.��ӡ��ϵ�� *******\n");
	printf("******* 3.ɾ����ϵ�� 4.�޸���ϵ�� *******\n");
	printf("******* 5.������ϵ�� 6.������ϵ�� *******\n");
	printf("************* 0.�˳�ͨѶ¼ **************\n");
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

	Initialize(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("ͨѶ¼�Ѿ��˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;

		}
	} while (input);
}

int main()
{
	test();
	return 0;
}