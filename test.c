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
//		printf("�ӿգ����ܳ��ӣ�\n");
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
//		printf("�ӿգ����ܳ���Ԫ�أ�\n");
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
//		p = Q->front->next; // �������е�head���ĵ�ַ��ֵ��p
//		*x = p->data; // �����׵�data��ֵ��xָ����ָ��ĵ�ַ���ڴ�ռ���
//		Q->front->next = p->next; // �����е�head����е�frontָ��ָ����׺����һ�����
//		if (NULL == p->next) {
//			Q->rear = Q->front; // ��rearָ��Ҳָ��frontָ����ָ���head���
//		}
//		free(p); // �ͷ�p��ָ��Ľ��
//		return 1;
//	}
//}

//int GetFront(LinkQueue* Q, DataType* x) {
//	if (Q->front == Q->rear) {
//		printf("�ӿգ��޶���Ԫ�أ�\n");
//		return 0;
//	}
//	else {
//		*x = Q->front->next->data; // ȡ����Ԫ��
//		return 1;
//	}
//}

//typedef struct {
//	DataType data[MAXSIZE];
//	int top;
//}Queue;
//
//int InQueue(LinkQueue* Q, DataType x) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front) { // �ж϶��Ƿ���
//		printf("������������ӣ�\n");
//		return 0;
//	}
//	else {
//
//	}
//}