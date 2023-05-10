#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define MAXSIZE 100
#define DataType int

typedef struct Linklistnode{
	DataType data;
	LinkListQ* next;
}LinkListQ;

typedef struct Queue {
	LinkListQ* front;
	LinkListQ* rear;
}LinkQueue;

//void EmptyQueue(LinkQueue* Q) {
//	if (Q->front == Q->rear) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}

//int DeQueue(LinkQueue* Q, DataType* x) {
//	LinkListQ* p = NULL;
//	
//	if (Q->front == Q->rear) {
//		printf("队空，不能出队！\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next;
//		*x = p->data; // x = Q->front->next->data;
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
//		printf("队空，不能出队元素！\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next;
//		*x = p->data;
//		Q->front->next = p->next;
//		if (NULL == p->next)
//			Q->rear == Q->front;
//		free(p);
//		return 1;
//	}
//}

//int DeQueue(LinkQueue* Q, DataType* x) {
//	LinkListQ* p = NULL;
//	if (Q->front == Q->rear) {
//		return 0;
//	}
//	else {
//		p = Q->front->next; // 将队列中的head结点的地址赋值给p
//		*x = p->data; // 将队首的data赋值给x指针所指向的地址的内存空间中
//		Q->front->next = p->next; // 将队列的head结点中的front指针指向队首后面的一个结点
//		if (NULL == p->next) {
//			Q->rear = Q->front; // 将rear指针也指向front指着所指向的head结点
//		}
//		free(p); // 释放p所指向的结点
//		return 1;
//	}
//}

//int GetFront(LinkQueue* Q, DataType* x) {
//	if (Q->front == Q->rear) {
//		printf("队空，无队首元素！\n");
//		return 0;
//	}
//	else {
//		*x = Q->front->next->data; // 取队首元素
//		return 1;
//	}
//}

//typedef struct {
//	DataType data[MAXSIZE];
//	int top;
//}Queue;
//
//int InQueue(LinkQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // 判断队是否满
//		printf("队满，不能入队！\n");
//		return 0;
//	}
//	else {
//
//	}
//}