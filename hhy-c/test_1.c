#include <stdio.h>
int main() {
	char password[16] = { 0 };
	printf("����������->");
	scanf("%s", password);//���鱾�����ǵ�ַ�����Բ���ȡַ��
	int ch = 0;
	char add;
	while (ch = getchar() != '\n') {
	}
	printf("ȷ������Y/N ");
	scanf("%c", &add);
	if (add == 'Y') {
		printf("��������ɹ�");
	}
	else if (add == 'N') {
		printf("��������ȡ��");
	}
	else {
		printf("�������");
	}
	return 0;
}