#include "address_list.h"


//初始化通讯录
void Initialize(struct contact* pc)
{
	pc->people = 0;
	memset(pc->data, 0, sizeof(pc->data));

}

void AddContact(struct contact* pc)
{
	if (pc->people == MAX)
	{
		printf("通讯录已满无法添加\n");
	}
	else
	{
		printf("输入要添加的姓名:>");
		scanf("%s", pc->data[pc->people].name);
		printf("性别:>");
		scanf("%s", pc->data[pc->people].sex);
		printf("年龄:>");
		scanf("%d", &(pc->data[pc->people].age));
		printf("电话:>");
		scanf("%s", pc->data[pc->people].phone);
		printf("住址:>");
		scanf("%s", pc->data[pc->people].address);
		pc->people++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("通讯录为空\n");
	}
	
	else
	{
		int j = 0;
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "住址");
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

//查找通讯录联系人
static int LookupContact(const struct contact* pc, char* name)
{//然此函数只能在本文件内使用
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		if (strcmp(pc->data->name, name) == 0)
		{
			return i;
		}
	}
	//没找到时
	return -1;
}

void DeleteContact(struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入要删除联系人的姓名:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("通讯录中没有此联系人\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->people - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			printf("删除成功\n");
			pc->people--;
		}
	}
}

void AmendContact(struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入要修改联系人的姓名:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("通讯录中没有此联系人\n");
		}
		else
		{
			printf("输入修改的后的名字:>\n");
			scanf("%s", pc->data[ret].name);
			printf("修改后的性别:>");
			scanf("%s", pc->data->sex);
			printf("修改后的年龄:>");
			scanf("%d", &(pc->data[ret].age));
			printf("修改后的电话:>");
			scanf("%s", pc->data[ret].phone);
			printf("修改后的住址:>");
			scanf("%s", pc->data[ret].address);
			printf("修改成功\n");
		}
	}
}

void FindContact(const struct contact* pc)
{
	if (0 == pc->people)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入要查找联系人的姓名:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		if (-1 == ret)
		{
			printf("通讯录中没有此联系人\n");
		}
		else
		{
			printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "住址");

			printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
				pc->data[ret].name,
				pc->data[ret].sex,
				pc->data[ret].age,
				pc->data[ret].phone,
				pc->data[ret].address);
		}
	}
}