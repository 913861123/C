#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define NAME_MAX 10
#define SEX_MAX 4
#define PHONE_MAX 12
#define ADDRESS_MAX 30
#define MAX 3//通讯录最大容量


//存放联系人信息的结构体
typedef struct information
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
}information;

//存放联系人的结构体
typedef struct contact
{
	struct information *data;
	int people;//记录联系人的个数
	int cont;//通讯录最大的容量
}contact;//重命名结构体

//初始化通讯录
void Initialize(struct contact* pc);

//新建联系人
void AddContact(struct contact* pc);

//打印联系人
void ShowContact(const struct contact* pc);

//删除联系人
void DeleteContact(struct contact* pc);

//修改联系人
void AmendContact(struct contact* pc);

//查找联系人
void FindContact(const struct contact* pc);

//排序联系人
void RangkContact(struct contact* pc);

//销毁通讯录
void DisposalContact(struct contact* pc);

//保存通讯录数据到文件
void Conserve(contact* pc);

