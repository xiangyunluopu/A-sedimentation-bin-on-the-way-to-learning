#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>

typedef struct s_q {
	int data;
	struct s_q* next;
}sq;

void menu(void) {
	printf("*---------------*\n");
	printf("|    0.out      |\n");
	printf("|    1.disp     |\n");
	printf("|    2.push     |\n");
	printf("|    3.pop      |\n");
	printf("*---------------*\n");
	printf("������˵���>:");
}

void disp(sq* rear) {
	int i = 0;
	sq* head = NULL;
	sq* p = NULL;
	if (NULL == rear) {
		printf("�ӿ�\n");
	}
	else { // �Ӳ�Ϊ��ʱ
		head = rear->next;
		p = head;          // Ūһ��head��Ϊ�������ɶ���
		for (i = 1; head != p || 1 == i; i += 1, p = p->next) { 
			printf("��%dλԪ��Ϊ>:{ %d }\n", i, p->data);
		}
	}
}

sq* push(sq* rear, int x) {
	sq* head = NULL;
	sq* s = (sq*)malloc(sizeof(sq));
	s->next = NULL;
	s->data = x;
	if (NULL != rear) {
		head = rear->next;
		rear->next = s;
		s->next = head;
		rear = s;
	}
	else { // ��Ϊ��ʱ
		rear = s;
		s->next = rear;
	}
	return rear;
}

char pop(sq* rear, int* x) {
	sq* p = NULL;
	if (NULL == rear) { // ��Ϊ��
		return 'n';
	}
	else { // �Ӳ�Ϊ��
		p = rear->next;
		*x = p->data;
		rear->next = p->next;
		free(p);
		return 'y';
	}
}

int main(void) {
	int o = 0;
	sq* rear = NULL;
	int a = 0;
	char b = '0';
	int x = 0;
	do {
		menu();
		o = scanf("%d", &a);
		switch (a) {
		case 0:

			break;
		case 1:
			disp(rear);
			break;
		case 2:
			printf("�������������ֵ>:");
			o = scanf("%d", &x);
			rear = push(rear, x);
			break;
		case 3:
			b = pop(rear, &x);
			if ('y' == b) {
				printf("{ %d }����\n", x);
			}
			else { // b == 'n' ʱ
				printf("�ӿ�\n");
			}
			break;
		default:
			printf("��ú�����˵���\n");
			break;
		}
	} while (a);
	return 0;
}