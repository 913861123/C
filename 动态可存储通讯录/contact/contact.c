#include "contact.h"

//�ж�ͨѶ¼�Ƿ�Ҫ����
int dilatation(contact* pc)
{
	if (pc->people == pc->cont)
	{
		//ÿ������������ϵ�˿ռ�
		struct information* ptr = (struct information*)realloc(pc->data, (pc->cont + 2) * sizeof(struct information));
		if (ptr == NULL)
		{
			printf("ͨѶ¼����ʧ��\n");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->cont += 2;//��������������ϵ�˿ռ�
			printf("ͨѶ¼���ݳɹ�\n");
			return 0;
		}
	}
	return 1;
}

void ReadContact(contact* pc)
{
	//���ļ�
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn == NULL)
	{
		printf("ReadContact::%s\n", strerror(errno));//���ļ�ʧ��ʱ����
		return;
	}
	//����ϵ����Ϣ����ͨѶ¼
	information tmp = { 0 };
	while (fread(&tmp, sizeof(information), 1, pfIn))//fread���ص��Ƕ�ȡ�ļ���Ϣ�ĸ�������û�ж�ȡ��ʱ�򷵻�0
	{
		//�ж�ͨѶ¼�Ƿ�Ҫ����
		if(dilatation(pc)==0)
		{
			printf("ͨѶ¼��ʼ��ʧ��\n");
			return;
		}
		
		//������Ϣ
		pc->data[pc->people] = tmp;
		pc->people++;
	}
	//�ر��ļ�
	fclose(pfIn);
	pfIn = NULL;
}

//��̬���ʼ��ͨѶ¼
void Initialize(struct contact* pc)
{
	pc->people = 0;//ͨѶ¼�����õ�ʱ��û����Ч����Ϣ
	pc->cont = MAX;//һ��ʼͨѶ¼ֻ�ܷ�MAX���˵���Ϣ
	pc->data = (struct information*)malloc(MAX * sizeof(struct information));
	if (malloc == NULL)
	{
		printf("��ʼ��ͨѶ¼ʧ��\n");
		exit(1);//ʧ���˳���������
	}

	//���ļ���ȡ��ϵ����Ϣ�ŵ�ͨѶ¼
	ReadContact(pc);
}

//��̬������ϵ��
void AddContact(struct contact* pc)
{
		if(dilatation(pc);)//�ж�ͨѶ¼�Ƿ�Ҫ����
		{
			printf("�ռ䲻������������ʧ��");
			return;
		}
		printf("�����������ϵ�˵�����:>");
		scanf("%s", pc->data[pc->people].name);
		printf("�Ա�:>");
		scanf("%s", pc->data[pc->people].sex);
		printf("����:>");
		scanf("%d", &(pc->data[pc->people].age));
		printf("�绰:>");
		scanf("%s", pc->data[pc->people].phone);
		printf("סַ:>");
		scanf("%s", pc->data[pc->people].address);
		printf("�ɹ������ϵ��\n");
		pc->people++;

}

void ShowContact(const struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "�Ա�", "����", "�绰", "סַ");
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

//���Ǹ�������ϵ�˵ĺ���
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
	//ͨѶ¼��û��Ҫ�ҵ���ϵ��ʱ
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

		if (ret == -1)
		{
			printf("ɾ��ʧ�ܣ�ͨѶ¼û�и���ϵ��\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->people; j++)
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
	if (pc->people == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("������Ҫ�޸��˵�����");
		scanf("%s", name);
		int ret = LookupContact(pc, name);

		if (ret == -1)
		{
			printf("ͨѶ¼��û�и���ϵ��\n");
		}
		else
		{
			printf("������Ҫ�޸���ϵ�˵�����:>");
			scanf("%s", pc->data[ret].name);
			printf("�Ա�:>");
			scanf("%s", pc->data[ret].sex);
			printf("����:>");
			scanf("%d", &(pc->data[ret].age));
			printf("�绰:>");
			scanf("%s", pc->data[ret].phone);
			printf("סַ:>");
			scanf("%s", pc->data[ret].address);
			printf("�޸ĳɹ�\n");
		}
	}
}

void FindContact(const struct contact* pc)
{
	if (pc->people == 0)
	{
		printf("����ʧ�ܣ�ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX];
		printf("������Ҫ�����˵�����:>");
		scanf("%s", name);
		int ret = LookupContact(pc, name);

		if (ret == -1)
		{
			printf("ͨѶ¼��û�и���ϵ��\n");
		}
		else
		{
			printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "�Ա�", "����", "�绰", "סַ");

			printf("%-10s\t%-10s\t%-10d\t%-10s\t%-10s\n",
				pc->data[ret].name,
				pc->data[ret].sex,
				pc->data[ret].age,
				pc->data[ret].phone,
				pc->data[ret].address);

		}

	}
}

//����������
static int name_sort(const void* s1, const void* s2)
{
	return strcmp(((struct information*)s1)->name,((struct information*)s2)->name);
}

//����������
static int age_sort(const void* s1, const void* s2)
{
	return (((struct information*)s1)->age) - (((struct information*)s2)->age);
}

void RangkContact(struct contact* pc)
{
	int x = 1;
	while (x)//ֻ������ɹ��Ż�ֹͣѭ��
	{
		printf("��ѡ������ʽ\n1/0(����/����):>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			qsort(pc->data, pc->people, sizeof(pc->data[0]), name_sort);
			printf("������������ϵ�˳ɹ�\n");
			x = 0;
			break;
		case 0:
			qsort(pc->data, pc->people, sizeof(pc->data[0]), age_sort);
			printf("������������ϵ�˳ɹ�\n");

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
	//���ļ�
	FILE* pfOut = fopen("contact.dat", "wb");//�Զ����Ƶķ�ʽ��
	if (pfOut == NULL)
	{
		printf("Conserve::%s", strerror(errno));//���ļ�ʧ�ܱ����˳�
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i < pc->people; i++)
	{
		fwrite(pc->data + i, sizeof(information), 1,pfOut);//�Զ����Ƶķ�ʽд����Ϣ
	}
	//�ر��ļ�
	fclose(pfOut);
	pfOut = NULL;
	printf("��ϵ����Ϣ����ɹ�\n");
}
