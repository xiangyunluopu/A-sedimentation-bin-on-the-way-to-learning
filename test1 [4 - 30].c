#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

#define data_type int

typedef struct S__node {
	data_type data;
	struct S__node* next;
}s_node;

typedef struct {
	/*struct S__node* front;
	struct S__node* rear;*/
	s_node* front;
	s_node* rear;
}s;

void menu(void) {
	printf("=================\n");
	printf("|  0.out        |\n");
	printf("|  1.init       |\n");
	printf("|  2.push       |\n");
	printf("|  3.pop        |\n");
	printf("|  4.get_front  |\n");
	printf("|  5.disp_all   |\n");
	printf("=================\n");
	printf("请输入菜单号>:");
}

s* init_0(void) {
	s* q = NULL;
	q = (s*)malloc(sizeof(s));
	s_node* p = (s_node*)malloc(sizeof(s_node));
	p->next = NULL;
	q->front = p;
	q->rear = q->front;
	return q;
}

s* init(s* q) { 
	s_node* p = NULL;/* = (s_node*)malloc(sizeof(s_node)); */
		// q [0-0] [0-1] [!=NULL] [!=NULL]
		//		   front    p       
		//				            rear
		for (;q->front != q->rear;) {
			p = q->front->next;
			q->front->next = p->next;
			if (NULL == p->next) {
				q->rear = q->front;
			}
			free(p);
		}
	return q;
}

void push(s* q, data_type* x) {
	s_node* p = (s_node*)malloc(sizeof(s_node));
	p->data = *x;
	q->rear->next = p;
	p->next = NULL;
	q->rear = p;
}

char get_front(s* q, data_type* x) {
	if (q->front == q->rear) {
		return 'n';
	}
	else {
		// [0.0] [0.1] [front]
		*x = q->front->next->data;
		return 'y';
	}
}

void disp_all(s* q) {
	int i = 0;
	s_node* p = NULL;
	if (q->front == q->rear) {
		printf("队空\n");
	}
	else {
		printf("从头到尾的队列元素:\n");
		for (i = 1, p = q->front->next; p != NULL;) {
			printf("第%d位为[%d]\n", i++, p->data);
			p = p->next;
		}
	}
}

char pop(s* q, data_type* x) {
	s_node* p = NULL;
	if (q->front == q->rear) {
		return 'n';
	}
	else { // [0.0]  [0.1]  [1.2]  [2.?]
		   //                 p
		p = q->front->next;
		q->front->next = p->next;
		*x = p->data;
		free(p);
		return 'y';
	}
}

int main(void) {
	int i = 0;
	int j = 0;
	int n = 0;
	char o = 0;
	int a = 0;
	int b = 0;
	data_type arr1[1000] = { 0 };
	data_type x = 0;
	s* q = init_0();
	do
	{
		menu();
		o = scanf("%d", &a);
		switch (a) {
		case 0:

			break;
		case 1:
			init(q);
			break;
		case 2:
			printf("你想入队几个值>:"); scanf("%d", &n);
			for (i = 0; i < n; i += 1) {
				printf("请输入第[%d]个>:", i + 1);
				scanf("%d", &arr1[i]);
			}
			for (i = 0; i < n; i += 1) {
				x = arr1[i]; 
				push(q, &x);
				printf("[%d]", q->rear->data);
			}
			printf("已入队\n");
			break;
		case 3:
			b = pop(q, &x);
			if ('y' == b) {
				printf("[%d]出队\n", x);
			}
			else {
				printf("队空\n");
			}
			break;
		case 4:
			b = get_front(q, &x);
			if ('y' == b) {
				printf("get_front->[%d]\n", x);
			}
			else {
				printf("队空\n");
			}
			break;
		case 5:
			disp_all(q);
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (a);
	return 0;
}