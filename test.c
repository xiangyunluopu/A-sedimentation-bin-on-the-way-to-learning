#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int data;
	struct listnode* next;
}LL;

int main() {
	int i = 0;
	int j = 0;
	LL* head = (LL*)malloc(sizeof(LL));
	LL* q = NULL;
	LL* p = NULL;
	head->next = NULL;
	/***********创建十个结构体************/
	for (i = 1, q = head; i <= 10; i += 1) {
		p = (LL*)malloc(sizeof(LL));
		if (NULL == p) {
			exit(1);
		}
		p->data = i;
		p->next = q->next;
		q->next = p;
		q = p;
	}
	/*===================================*/
	int data = 0;
	for (p = head->next, i = 0; i < 10; i += 1) {
		data = p->data;
		printf("%3d", data);
		p = p->next;
	}
	/***********将单链表倒过来************/
	p = head;
	for (i = 1; i <= 10; i += 1) {

		q = p->next;
		p = p->next;
	}
	// 此时的q->最后一个结点；
	p = head; 
	LL* s = head;
	for (j = 10; j > 0; j -= 1) {
		for (i = 0; i < j - 1; i += 1) {
			s = s->next;
		}
		p = s->next;
		p->next = s;
		s = head;
	}
	p = head->next;
	p->next = NULL;
	head->next = q;
	/*====================================*/
	printf("\n\n\n");
	data = 0;
	for (p = head->next, i = 0; i < 10; i += 1) {
		data = p->data;
		printf("%3d", data);
		p = p->next;
	}

	return 0;
}