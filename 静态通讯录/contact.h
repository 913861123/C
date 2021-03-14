#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NAME_MAX 10
#define SEX_MAX 4
#define PHONE_MAX 12
#define ADDRESS_MAX 30
#define MAX 100

//�����ϵ����Ϣ�Ľṹ��
struct information
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
};

//�����ϵ�˵Ľṹ��
 struct contact
{
	struct information data[MAX];//�����MAX���˵���Ϣ
	int people;//��¼��ϵ�˵ĸ���
};

 //��ʼ��ͨѶ¼
void Initialize(struct contact* pc);

//�½���ϵ��
void AddContact(struct contact* pc);

//��ӡ��ϵ��
void ShowContact(const struct contact* pc);

//ɾ����ϵ��
void DeleteContact(struct contact* pc);

//�޸���ϵ��
void AmendContact(struct contact* pc);

//������ϵ��
void FindContact(const struct contact* pc);

//������ϵ��
void RangkContact(struct contact* pc);
