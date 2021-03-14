#include "contact.h"

void Initialize(struct contact* pc)
{
	pc->people = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(struct contact* pc)
{
	if (pc->people == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入添加联系人的姓名:>");
		scanf("%s", pc->data[pc->people].name);
		printf("性别:>");
		scanf("%s", pc->data[pc->people].sex);
		printf("年龄:>");
		scanf("%d", &(pc->data[pc->people].age));
		printf("电话:>");
		scanf("%s", pc->data[pc->people].phone);
		printf("住址:>");
		scanf("%s", pc->data[pc->people].address);
		printf("成功添加联系人\n");
		pc->people++;
	}
}

void ShowContact(const struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n","姓名","性别","年龄","电话","住址");
		for (i = 0; i < pc->people; i++)
		{
			printf("%-10s\t%-10s\t%-10d\t%-10s\t%-10s\n",
				pc->data[i].name,
				pc->data[i].sex,
				pc->data[i].age,
				pc->data[i].phone,
				pc->data[i].address);
		}
	}
}

//这是个查找联系人的函数
static LookupContact(const struct contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	//通讯录里没有要找的联系人时
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
		printf("请输入要删除联系人的姓名");
		scanf("%s", name);
		int ret = LookupContact(pc, name);

		if (ret == -1)
		{
			printf("删除失败，通讯录没有该联系人\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->people; j++)
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
	if (pc->people == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入要修改人的姓名");
		scanf("%s", name);
		int ret = LookupContact(pc, name);
		
		if (ret == -1)
		{
			printf("通讯录中没有该联系人\n");
		}
		else
		{
			printf("请输入要修改联系人的姓名");
			scanf("%s", pc->data[ret].name);
			printf("性别:>");
			scanf("%s", pc->data[ret].sex);
			printf("年龄:>");
			scanf("%d", &(pc->data[ret].age));
			printf("电话:>");
			scanf("%s", pc->data[ret].phone);
			printf("住址:>");
			scanf("%s", pc->data[ret].address);
			printf("修改成功\n");
		}
	}
}

void FindContact(const struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("查找失败，通讯录为空\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("请输入要查找人的姓名");
		scanf("%s", name);
		int ret = LookupContact(pc, name);

		if (ret == -1)
		{
			printf("通讯录中没有该联系人\n");
		}
		else
		{
			printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "姓名", "性别", "年龄", "电话", "住址");
			
				printf("%-10s\t%-10s\t%-10d\t%-10s\t%-10s\n",
					pc->data[ret].name,
					pc->data[ret].sex,
					pc->data[ret].age,
					pc->data[ret].phone,
					pc->data[ret].address);
			
		}
		
	}
}

//按名字排序
static int name_sort(const void* s1,const void* s2)
{
	return strcmp(((struct contact*)s1)->data->name, ((struct contact*)s2)->data->name);
}

//按年龄排序
static int age_sort(const void* s1,const void* s2)
{
	return (((struct contact*)s1)->data->age)-(((struct contact*)s2)->data->age);
}

void RangkContact(struct contact* pc)
{
	int x = 1;
	while (x)//只有排序成功才会停止循环
	{
		printf("请选择排序方式\n1/0(名字/年龄):>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			qsort(pc->data, pc->people, sizeof(pc->data[0]), name_sort);
			printf("按名字排序联系人成功\n");
			x = 0;
			break;
		case 0:
			qsort(pc->data, pc->people, sizeof(pc->data[0]), age_sort);
			printf("按年龄排序联系人成功\n");
			x = 0;
			break;
		default:
			printf("输入错误");
			break;
		}
		
	}

}
