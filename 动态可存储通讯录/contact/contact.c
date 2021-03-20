#include "contact.h"

//判断通讯录是否要增容
int dilatation(contact* pc)
{
	if (pc->people == pc->cont)
	{
		//每次扩容两个联系人空间
		struct information* ptr = (struct information*)realloc(pc->data, (pc->cont + 2) * sizeof(struct information));
		if (ptr == NULL)
		{
			printf("通讯录扩容失败\n");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->cont += 2;//扩容增加两个联系人空间
			printf("通讯录扩容成功\n");
			return 0;
		}
	}
	return 1;
}

void ReadContact(contact* pc)
{
	//打开文件
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn == NULL)
	{
		printf("ReadContact::%s\n", strerror(errno));//打开文件失败时报错
		return;
	}
	//把联系人信息导入通讯录
	information tmp = { 0 };
	while (fread(&tmp, sizeof(information), 1, pfIn))//fread返回的是读取文件信息的个数，当没有读取到时候返回0
	{
		//判断通讯录是否要增容
		if(dilatation(pc)==0)
		{
			printf("通讯录初始化失败\n");
			return;
		}
		
		//导入信息
		pc->data[pc->people] = tmp;
		pc->people++;
	}
	//关闭文件
	fclose(pfIn);
	pfIn = NULL;
}

//动态版初始化通讯录
void Initialize(struct contact* pc)
{
	pc->people = 0;//通讯录创建好的时候没有有效的信息
	pc->cont = MAX;//一开始通讯录只能放MAX个人的信息
	pc->data = (struct information*)malloc(MAX * sizeof(struct information));
	if (malloc == NULL)
	{
		printf("初始化通讯录失败\n");
		exit(1);//失败退出整个代码
	}

	//从文件读取联系人信息放到通讯录
	ReadContact(pc);
}

//动态新增联系人
void AddContact(struct contact* pc)
{
		if(dilatation(pc);)//判断通讯录是否要增容
		{
			printf("空间不够，增加容量失败");
			return;
		}
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

void ShowContact(const struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "姓名", "性别", "年龄", "电话", "住址");
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
		printf("请输入要删除联系人的姓名:>");
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
			printf("请输入要修改联系人的姓名:>");
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
		printf("请输入要查找人的姓名:>");
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
static int name_sort(const void* s1, const void* s2)
{
	return strcmp(((struct information*)s1)->name,((struct information*)s2)->name);
}

//按年龄排序
static int age_sort(const void* s1, const void* s2)
{
	return (((struct information*)s1)->age) - (((struct information*)s2)->age);
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

		}
	}
}

void DisposalContact(struct contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->people = 0;
	pc->cont = 0;
}

void Conserve(contact* pc)
{
	//打开文件
	FILE* pfOut = fopen("contact.dat", "wb");//以二进制的方式打开
	if (pfOut == NULL)
	{
		printf("Conserve::%s", strerror(errno));//打开文件失败报错退出
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		fwrite(pc->data + i, sizeof(information), 1,pfOut);//以二进制的方式写入信息
	}
	//关闭文件
	fclose(pfOut);
	pfOut = NULL;
	printf("联系人信息保存成功\n");
}
