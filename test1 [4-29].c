#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

#define datatype int

typedef struct s__node { // 
	datatype data;
	struct s__node* next;
}s_node;

typedef struct head__0 {
	struct s__node* front;
	struct s__node* rear;
}head_0;

void menu(void) {
	printf("*---------------------*\n");
	printf("|    0.�˳�           |\n");
	//printf("|    1.��ʼ��         |\n");
	printf("|    2.���           |\n");
	printf("|    3.����           |\n");
	printf("|    4.get_front      |\n");
	printf("|    5.disp_all       |\n");
	printf("*---------------------*\n");
}

head_0* init(head_0* q) {
	s_node* s = (s_node*)malloc(sizeof(s)); // ����hread ���
	s->next = NULL;
	q->front = s;
	q->rear = s;
	return q;
}

head_0* push(head_0* q, datatype* x) {
	s_node* s = (s_node*)malloc(sizeof(s_node));
	s->data = *x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
	return q;
}

char get_front(head_0* q, datatype* x) {
	if (q->front == q->rear) {
		return 'n';
	}
	else {
		*x = q->front->next->data;
		return 'y';
	}
}

int main(void) {
	int a = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	datatype arr[10] = { 0 };
	char b = '0';
	datatype x;
	head_0* q; // �������� 0 ���
	q = init(&q); // ��ʼ��
	do {
		menu();
		printf("������˵��ţ�0~5��>:");
		scanf("%d", &a);
		switch (a) {
		case 0:
			
			break;
		case 2:
			printf("������ٸ�>:"); scanf("%d", &n);
			printf("������:\n");
			for (i = 0; i < n; i += 1) {
				printf("��ʣ��[%d]===>:\n", i + 1);
				scanf("&d", &arr[i]);
			}
			for (i = 0; i < n; i += 1) {
				q = push(&q, &arr[i]);
			}
			break;
		case 3:

			break;
		case 4:
			b = get_front(&q, &x);
			if ('y' == b) {
				printf("get_front->[%d]\n", x);
			}
			else if ('n') {
				printf("�ӿ�\n");
			}
			break;
		case 5:

			break;
		default:
			printf("ajkhfbsdfjhb)(*&^\n");
			break;
		}
	} while(a);
	return 0;
}