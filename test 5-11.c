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
//		printf("�ӿգ����ܳ���Ԫ�أ�\n");
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
//		printf("�ӿգ����ܳ���Ԫ��\n");
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
//		printf("�ӿգ����ܳ���Ԫ��\n");
//		return 0;
//	}
//	else {
//		p = Q->front->next; // ȡ���׵�ַ
//		*x = p->data; // ȡ����Ԫ��
//		Q->front->next = p->next; // ��ͷ���ָ����׽��ָ��Ľ��
//		if (NULL == p->next) { // �ж��Ƿ�ֻ��һ��Ԫ��
//			Q->rear = Q->front; // ��βָ��Ҳָ���ͷָ��ָ���ͷ���
//		}
//		free(p); // �ͷ�ԭ���׽��
//		return 1;
//	}
//}

//int GetFront(LinkQueue* Q, DataType* x) {
//	if (Q->front == Q->rear) {
//		printf("�ӿգ��޶�ͷԪ�أ�\n");
//		return 0;
//	}
//	else {
//		*x = Q->front->next->data; // ȡ��ͷԪ��
//		return 1;
//	}
//}

typedef struct ListSqe {
	DataType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

//int InQueue(SeqQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // �ж��Ƿ������
//		printf("������������ӣ�\n");
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
//		printf("�ӿգ��޶�ͷԪ�أ�\n");
//		return 0;
//	}
//	else {
//		*x = Q->data[Q->rear];
//		return 1;
//	}
//}
//
//int InQueue(SeqQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // �ж��Ƿ��������
//		printf("�������������Ԫ��!\n");
//		return 0;
//	}
//	else {
//		Q->rear = (Q->rear + 1) % MAXSIZE;
//		Q->data[Q->rear] = x;
//	}
//
//}