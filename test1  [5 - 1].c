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
	printf("请输入菜单号>:");
}

void disp(sq* rear) {
	int i = 0;
	sq* head = NULL;
	sq* p = NULL;
	if (NULL == rear) {
		printf("队空\n");
	}
	else { // 队不为空时
		head = rear->next;
		p = head;          // 弄一个head是为了提升可读性
		for (i = 1; head != p || 1 == i; i += 1, p = p->next) { 
			printf("第%d位元素为>:{ %d }\n", i, p->data);
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
	else { // 队为空时
		rear = s;
		s->next = rear;
	}
	return rear;
}

char pop(sq* rear, int* x) {
	sq* p = NULL;
	if (NULL == rear) { // 队为空
		return 'n';
	}
	else { // 队不为空
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
			printf("请输入想输入的值>:");
			o = scanf("%d", &x);
			rear = push(rear, x);
			break;
		case 3:
			b = pop(rear, &x);
			if ('y' == b) {
				printf("{ %d }出队\n", x);
			}
			else { // b == 'n' 时
				printf("队空\n");
			}
			break;
		default:
			printf("请好好输入菜单号\n");
			break;
		}
	} while (a);
	return 0;
}