#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define max 8
#define datatype int

typedef struct q
{
	datatype data[max];
	int front, re;
}sq;

void menu(void) {
	printf("*===================*\n");
	printf("|  0.�˳�           |\n");
	printf("|  1.��ʼ��/��ʽ��  |\n");
	printf("|  2.���           |\n");
	printf("|  3.����           |\n");
	printf("|  4.get,front      |\n");
	printf("|  5.dis,all        |\n");
	printf("*===================*\n");
}

void init(sq* s) {
	s->front = s->re = 0;
}

char push(sq* s, datatype* x) {
	if (s->front == (s->re + 1) % max) {
		return 'n';
	}
	else {
		s->re = ((s->re + 1) % max);
		s->data[s->re] = *x;
		return 'y';
	}

}

char disp(sq* s) {
	int i = 0;
	int j = 0;
	if (s->front == s->re) {
		return 'n';
	}
	else {// j = (s->front + 1) ʱ����©��frontԪ�أ�
		for (j = (s->front) % max, i = 1; j != s->re; i += 1, j = (j + 1) % max) {
			printf(" %d--[%d],", i, s->data[j + 1]);
		}
		printf("\n");
		return 'y';
	}
}

char out(sq* s, datatype* x) {
	if (s->front == s->re) {
		return 'n';
	}
	else {
		s->front = (s->front + 1) % max;
		*x = s->data[s->front];
		return 'y';
	}
}

char get_front(sq* s, datatype* x) {
	if (s->front == s->re) {
		return 'n';
	}
	else {
		*x = s->data[(s->front + 1) % max];
		return 'y';
	}
}

int main(void)
{
	datatype x = 0;
	int a = 1;
	char b = '0';
	sq s;
	do {
		menu();
		scanf("%d", &a); getchar();
		switch (a) {
		case 0:

			break;
		case 1:
			init(&s);
			break;
		case 2:
			printf("������������ӵ�ֵ>:"); scanf("%d", &x); getchar();
			b = push(&s, &x);
			if ('n' == b) {
				printf("����,�޷���ӣ�\n");
			}
			else if ('y' == b) {
				printf("��ӳɹ�\n");
			}
			break;
		case 3:
			b = out(&s, &x);
			if ('n' == b) {
				printf("�ӿ�,�޷�����\n");
			}
			else if ('y' == b) {
				printf("[%d]����\n", x);
			}
			break;
		case 4:
			b = get_front(&s, &x);
			if ('y' == b) {
				printf("front--[%d]\n", x);
			}
			else if ('n' == b) {
				printf("�ӿ�\n");
			}
			break;
		case 5:
			b = disp(&s);
			if ('n' == b) {
				printf("�ӿ�\n");
			}
			break;
		default:
			printf("****///a=-=)1jc\n");
			break;

		}

	} while (a);
	return 0;
}