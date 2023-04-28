#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 8
#define DATATYPE int

typedef struct queue {
	DATATYPE data[MAX];
	int front, rear;
}sq;

void menu(void) {
	printf("*================*\n");
	printf("|   0.out        |\n");
	printf("|   1.initQueue  |\n");
	printf("|   2.入队       |\n");
	printf("|   3.出队       |\n");
	printf("|   4.取front元素|\n");
	printf("|   5.disp 元素  |\n");
	printf("*================*\n");
}

void initQueue(sq* q) {
	q->front = 0;
	q->rear = 0;
}

int fsq(sq* q) {
	if (q->front == (q->rear + 1) % MAX) {
		return 1;
	}
	else {
		return 0;
	}
}

int push_queue(sq* q, DATATYPE x) {
	if (fsq(q)) {
		return 1;
	}
	else {
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = x;
		return 0;
	}
}

int esq(sq* q) {
	if (q->front == q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int outsq(sq* q, DATATYPE* x) {
	if (esq(q)) {
		return 1;
	}
	else {
		q->front = (q->front + 1) % MAX;
		*x = q->front;
		return 0;
	}
}

int getfront(sq* q, DATATYPE* x) {
	if (esq(q)) {
		return 1;
	}
	else {
		*x = q->data[(q->front + 1) % MAX];
		return 0;
	}
}

int main(void) {
	sq q;
	DATATYPE x = 0;
	int b = 0;
	int a = 0;
	int n = 0;
	int i = 0;
	b = ~b;
	do {
		menu();
		scanf("%d", &a); getchar();
		switch (a) {
		case 0:
			printf("退出\n");
			b = ~b;
			break;
		case 1:
			initQueue(&q);
			printf("初始化/格式化\n");
			break;
		case 2:
			printf("想要输入几个>:"); scanf("%d", &n); getchar();
			for (i = 1; i <= n; i += 1) {
				printf("请输入[%d]值>:", i); scanf("%d", &x); getchar();
				if (push_queue(&q, x)) {
					printf("队满，不给入对\n");
					break;
				}
				else {
					printf("[%d]%d已入队\n", i, x);
				}
			}
			break;
		case 3:
			if (outsq(&q, &x)) {
				printf("队空!\n");
			}
			else {
				printf("->%d<-,出队\n", x);
			}
			break;
		case 4:
			if (getfront(&q, &x)) {
				printf("队空!\n");
			}
			else {
				printf("->%d<-,front\n", x);
			}
			break;
		case 5:

			break;
		default:
			printf("选项之外\n");
			break;
		}
	} while (b);

	return 0;
}