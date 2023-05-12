#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>

#define DataType int
#define MAXSIZE	10

typedef struct Linknode {
	DataType data;
	struct Linknode* next;
}LinkListQ;

typedef struct LinknodeQueue {
	struct Linknode* front;
	struct Linknode* rear;
}LinkQueue;
//
//int DeQueue(LinkQueue* Q, DataType* x) {
//	LinkListQ* p = NULL;
//	if (Q->front == Q->rear) {
//		printf("队空，不能出队元素！\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next;
//		*x = p->data;
//		Q->front->next = p->next;
//		if (NULL == p->next)
//			Q->rear = Q->front;
//		free(p);
//		return 1;
//	}
//}

//int DeQueue(LinkQueue* Q, DataType* x) {
//	LinkListQ* p = NULL;
//	if (Q->front == Q->rear) {
//		printf("队空，不能出队元素\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next;
//		*x = p->data;
//		Q->front->next = p->next;
//		if (NULL == p->next) {
//			Q->rear = Q->front;
//		}
//		free(p);
//		return 1;
//	}
//}

//int DeQueue(LinkQueue* Q, DataType* x) {
//	LinkListQ* p = NULL;
//	if (Q->front == Q->rear) {
//		printf("队空，不能出队元素\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next; // 取队首地址
//		*x = p->data; // 取队首元素
//		Q->front->next = p->next; // 令头结点指向队首结点指向的结点
//		if (NULL == p->next) { // 判断是否只有一个元素
//			Q->rear = Q->front; // 让尾指针也指向队头指针指向的头结点
//		}
//		free(p); // 释放原队首结点
//		return 1;
//	}
//}

//int GetFront(LinkQueue* Q, DataType* x) {
//	if (Q->front == Q->rear) {
//		printf("队空，无队头元素！\n");
//		return 0;
//	}
//	else {
//		*x = Q->front->next->data; // 取队头元素
//		return 1;
//	}
//}

typedef struct ListSqe {
	DataType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

//int InQueue(SeqQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // 判断是否队满？
//		printf("队满，不能入队！\n");
//		return 0;
//	}
//	else {
//		Q->rear = (Q->rear + 1) % MAXSIZE;
//		Q->data[Q->rear] = x;
//		return 1;
//	}
//}

//int GetFront(SeqQueue* Q, DataType* x) {
//	if (Q->front == Q->rear) {
//		printf("队空，无队头元素！\n");
//		return 0;
//	}
//	else {
//		*x = Q->data[Q->rear];
//		return 1;
//	}
//}
//
//int InQueue(SeqQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // 判断是否队满？？
//		printf("队满，不能入队元素!\n");
//		return 0;
//	}
//	else {
//		Q->rear = (Q->rear + 1) % MAXSIZE;
//		Q->data[Q->rear] = x;
//	}
//
//}