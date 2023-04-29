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
	printf("|  0.退出           |\n");
	printf("|  1.初始化/格式化  |\n");
	printf("|  2.入队           |\n");
	printf("|  3.出队           |\n");
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
	else {// j = (s->front + 1) 时，会漏掉front元素；
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
			printf("请输入你想入队的值>:"); scanf("%d", &x); getchar();
			b = push(&s, &x);
			if ('n' == b) {
				printf("队满,无法入队！\n");
			}
			else if ('y' == b) {
				printf("入队成功\n");
			}
			break;
		case 3:
			b = out(&s, &x);
			if ('n' == b) {
				printf("队空,无法出队\n");
			}
			else if ('y' == b) {
				printf("[%d]出队\n", x);
			}
			break;
		case 4:
			b = get_front(&s, &x);
			if ('y' == b) {
				printf("front--[%d]\n", x);
			}
			else if ('n' == b) {
				printf("队空\n");
			}
			break;
		case 5:
			b = disp(&s);
			if ('n' == b) {
				printf("队空\n");
			}
			break;
		default:
			printf("****///a=-=)1jc\n");
			break;

		}

	} while (a);
	return 0;
}