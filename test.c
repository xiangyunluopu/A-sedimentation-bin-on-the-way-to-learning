#define _CRT_SECURE_NO_WARNINGS 1

#include "LIFO.h"

int main() {
	char n = -1;
	int A = 0;
	int i = 0;
	int j = 0;
	SeqStack S;
	int flag = 0;
	InitStack(&S);
	do {
		mune();
		scanf("%d", &A);
		switch (A) {
		case 1:
			InitStack(&S);
			break;
		case 2:
			printf("��������Ҫ��ջ�ĸ���>:");
			scanf("%d", &i);
			flag = Push(&S, i);
			i = 0;
			if (1 == flag) {
				printf("ջ��\n");
			}
			else if (2 == flag) {
				printf("��Ҫ��ջ�ĸ�������ջ�ռ�\n");
			}
			else {
				printf("��ջ OK \n");
			}
			break;
		case 3:
			printf("��������Ҫ��ջ�ĸ���>:");
			scanf("%d", &i);
			flag = Pop(&S, i);
			if (1 == flag) {
				printf("ջ��\n");
			}
			else if (2 == flag) {
				printf("��ջ����̫��\n");
			}
			else if (3 == flag) {
				printf("���ֲ��Ϸ�\n");
			}
			else {
				printf("��ջ�� ok\n");
			}
			break;
		case 4:
			flag = GetTop(&S);
			if (1 == flag) {
				printf("ջ��");
			}
			else if (0 == flag) {
				printf("Top:%d\n", x);
			}
			break;
		case 0:
			n = ~n;
			break;
		default:
			printf("�������\n");
		}
	} while (n);



	return 0;
}