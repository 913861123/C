#include "address_list.h"


//��ʼ��ͨѶ¼
void Initialize(struct contact* pc)
{
	pc->people = 0;
	memset(pc->data, 0, sizeof(pc->data));

}

void AddContact(struct contact* pc)
{
	if (pc->people == MAX)
	{
		printf("ͨѶ¼�����޷����\n");
	}
	else
	{
		printf("����Ҫ��ӵ�����:>");
		scanf("%s", pc->data[pc->people].name);
		printf("�Ա�:>");
		scanf("%s", pc->data[pc->people].sex);
		printf("����:>");
		scanf("%d", &(pc->data[pc->people].age));
		printf("�绰:>");
		scanf("%s", pc->data[pc->people].phone);
		printf("סַ:>");
		scanf("%s", pc->data[pc->people].address);
		pc->people++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	
	else
	{
		int j = 0;
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰", "סַ");
		for (j = 0; j < pc->people; j++)
		{
			printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
				pc->data[j].name,
				pc->data[j].sex,
				pc->data[j].age,
				pc->data[j].phone,
				pc->data[j].address);
		}
	}
}

//����ͨѶ¼��ϵ��
static int LookupContact(const struct contact* pc, char* name)
{//Ȼ�˺���ֻ���ڱ��ļ���ʹ��
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		if (strcmp(pc->data->name, name) == 0)
		{
			return i;
		}
	}
	//û�ҵ�ʱ
	return -1;
}

void DeleteContact(struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("������Ҫɾ����ϵ�˵�����:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("ͨѶ¼��û�д���ϵ��\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->people - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			printf("ɾ���ɹ�\n");
			pc->people--;
		}
	}
}

void AmendContact(struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("������Ҫ�޸���ϵ�˵�����:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("ͨѶ¼��û�д���ϵ��\n");
		}
		else
		{
			printf("�����޸ĵĺ������:>\n");
			scanf("%s", pc->data[ret].name);
			printf("�޸ĺ���Ա�:>");
			scanf("%s", pc->data->sex);
			printf("�޸ĺ������:>");
			scanf("%d", &(pc->data[ret].age));
			printf("�޸ĺ�ĵ绰:>");
			scanf("%s", pc->data[ret].phone);
			printf("�޸ĺ��סַ:>");
			scanf("%s", pc->data[ret].address);
			printf("�޸ĳɹ�\n");
		}
	}
}

void FindContact(const struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("������Ҫ������ϵ�˵�����:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("ͨѶ¼��û�д���ϵ��\n");
		}
		else
		{
			printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰", "סַ");

			printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
				pc->data[ret].name,
				pc->data[ret].sex,
				pc->data[ret].age,
				pc->data[ret].phone,
				pc->data[ret].address);
		}
	}
}