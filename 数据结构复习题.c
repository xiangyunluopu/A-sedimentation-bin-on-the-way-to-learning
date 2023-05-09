//#define _CRT_SECURE_NO_WARNINGS 1

#define DataType int 
#define MAXSIZE 100

typedef struct {
	DataType data[MAXSIZE];
	int Length;
}SeqList;

typedef struct node{
	DataType data;
	struct node* next;
}LinkList;
//
////int InsElem(Link* L, int i, DataType x) {
////	int j;
////	if (MAXSIZE == L->Length) {
////		printf("˳���������\n");
////		return -1;
////	}
////	if (i < 1 || i > L->Length + 1) {
////		printf("����λ�ó���\n");
////		return 0;
////	}
////	if (i == L->Length + 1) {
////		L->data[L->Length] = x;
////		// ������ L->data[i - 1] = x;
////		L->Length += 1;
////		return 1;
////	}
////	for (j = L->Length - 1; j >= i - 1; j -= 1) {
////		L->data[j + 1] = L->data[j];
////	}
////	L->data[i - 1] = x;
////	L->Length += 1;
////	return 1;
////}
//
//int InsElem(SeqList* L, int i, DataType x) {
//	int j;
//	if (L->Length >= MAXSIZE) {
//		printf("˳���������\n");
//		return -1;
//	}
//	if (i < 1 || i > L->Length + 1) {
//		printf("����λ�ó���\n");
//		return 0;
//	}
//	if (L->Length + 1 == i) {
//		L->data[i - 1] = x;
//		L->Length += 1;
//		return 1;
//	}
//	for (j = L->Length - 1; j >= i - 1; j -= 1) {
//		L->data[j + 1] = L->data[j];
//	}
//	L->data[i - 1] = x; // or L->data[L->Length] = x;
//	L->Length += 1;
//	return 1;
//}
//
//int DelElem(SeqList* L, int i, DataType* x) {
//	int j = 0;
//	if (0 == L->Length) {
//		printf("˳���ΪNULL!\n");
//		return 0;
//	}
//	if (i < 1 || i > L->Length) {
//		printf("�����ڵ�i��Ԫ��\n");
//		return -1;
//	}
//	*x = L->data[i - 1];
//	for (j = i; j < L->Length; j += 1) {
//		L->data[j - 1] = L->data[j];
//	}
//	L->Length -= 1;
//	return 1;
//}
//
//// 45��: ͷ�巨����������
//
//#include<malloc.h>
//#include<stdio.h>
//
//void Create_List_Head(LinkList* head, int n) {
//	LinkList* s = NULL;
//	int i;
//	printf("������%d������: ", n);
//	for (i = 0; i < n; i += 1) {
//		s = (LinkList*)malloc(sizeof(LinkList));
//		scanf("%d", &s->data);
//		// [0][->1] <- head
//		// [1][NULL]
//		// [][]
//		s->next = head->next;
//		head->next = s;
//	} // ok
//	printf("��������ɹ�!\n");
//}
//
//// 46��,β�巨����������
//
//void CreateList(LinkList* head, int n) {
//	LinkList* s = NULL;
//	LinkList* Last = NULL;
//	int i = 0;
//	Last = head;
//	printf("������%d������:", n);
//	for (i = 0; i < n; i += 1) {
//		s = (LinkList*)malloc(sizeof(LinkList));
//		scanf("%d", &s->data);
//		// [0][NULL] <- head = Last
//		// [1][]
//		// [][]
//		s->next = Last->next;
//		Last->next = s;
//		Last = s;
//	}
//	printf("��������ɹ�!\n");
//}
//
//int LengthList(LinkList* head) {
//	LinkList* p = head;
//	int j = 0;	       // [head][->1]
//	while (p!= NULL) { // [1][->2]
//		p = p->next;   // [2][NULL]
//	}
//}

#include<stdio.h>
#include<malloc.h>
//
//typedef struct node {
//	int i;
//	struct node* next;
//}LinkList;

//int main(void) {
//	int i = 0;
//	LinkList* head = (LinkList*)malloc(sizeof(LinkList));
//	LinkList* p = NULL;
//	//LinkList* s = head;
//	//int i = 0;
//
//	head->next = NULL;
//
//	for (i = 0; i < 3; i += 1) {
//		p = (LinkList*)malloc(sizeof(LinkList));
//		// [head][NULL]
//		//
//		// [1][NULL] <- p
//		// [][]
//		// [][]
//		p->next = head->next;
//		head->next = p;
//	}
//
//	p = head->next;
//	i = 0;
//
//	while (p != NULL) {
//		p = p->next;
//		i += 1;
//	}
//
//	printf("%d\n", i);
//
//	return 0;
//}

// �������Ⱥ���

int LengthList(LinkList* head) {
	LinkList* p = head->next;
	int j = 0;
	while (p != NULL) {
		p = p->next;
		j += 1;
	}
	return j;
}

// ����x��Ԫ�ص�λ��

// [head][->1]
// [1][->2]
// [2][NULL]

void Locate(LinkList* head, DataType x) {
	int j = 1;
	LinkList* p = head->next;
	while (NULL != p && x != p->data) {
		p = p->next;
		j += 1;
	}
	if (NULL != p) {
		printf("�ڱ�ĵ�%dλ�ҵ�ֵΪ%d�Ľ�㣡\n", j, x);
	}
	else {
		printf("δ�ҵ�ֵΪ%d�Ľ��!\n");
	}
}

// ��λ�ò���λ��

void SearchList(LinkList* head, int i) {
	LinkList* p = NULL;
	int j = 0;
	p = head->next;
	if (i > LengthList(head)) {
		printf("λ�ô���������û�и�λ�ã�\n");
	}
	while (j < i && NULL != p) {
		p = p->next;
		j += 1;
	}
	if (NULL != p) {
		printf("�ڵ�%dλ�ϵ�Ԫ��ֵΪ%d!\n", i, p->data);
	}
}

// ����İ�λ�ò������

void InsList(LinkList* head, int n, DataType x) {
	int j = 0;
	LinkList* p = NULL;
	LinkList* s = NULL;
	p = head;
	while (j < n - 1 && NULL != p->next) {
		p = p->next;
		j += 1;
	}
	if (NULL != p) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = x;
		s->next = p->next;
		p->next = s;
		printf("����Ԫ�سɹ���\n");
	}
	else {
		printf("����Ԫ��ʧ��\n");
	}
}

// ��һ����λ�ò��뺯��

void InsList_2(LinkList* head, int i, DataType x) {
	int j = 0;
	LinkList* p = NULL;
	LinkList* s = NULL;
	p = head;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j += 1;
	}
	if (p != NULL) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = x;
		s->next = p->next;
		p->next = s;
		printf("����Ԫ�سɹ���\n");
	}
	else {
		printf("����Ԫ��ʧ��\n");
	}
}

// ��λ��ɾ��������Ԫ�غ��� 
 
void DelList(LinkList* head, int i) {
	int j = 0;
	DataType x; //����1������
	LinkList* p = head;
	//LinkList* s = NULL;
	LinkList* q = NULL;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j += 1;
	}
	if (p->next != NULL && j == i - 1) {
		//s = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
		printf("ɾ����%dλ�ϵ�Ԫ��%d�ɹ�!\n", i, x);
	}
	else {
		printf("ɾ�����λ�ô���ɾ��ʧ�ܣ�\n");
	}
}

void delist(LinkList* head, int i) {
	int j = 0;
	DataType x;
	LinkList* p = head;
	LinkList* s = NULL;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j += 1;
	}
	if (p->next != NULL && j == i - 1) {
		s = p->next;
		p->next = s->next;
		x = s->data;
		free(s);
		printf("ɾ����%dλ�ϵ�Ԫ��%d�ɹ���\n", i, x);
	}
	else {
		printf("ɾ�����λ�ô���ɾ��ʧ�ܣ�\n");
	}
}

typedef struct node {
	DataType data;
	struct node* next;
}LinkStack;

LinkStack* Push(LinkStack* S, DataType x)

{  /*��ջ����*/

	LinkStack* p;

	p = (LinkStack*)malloc(sizeof(LinkStack));/*�����½��*/

	/*********�������***********/
	p->data = x;
	/*********�������***********/
	p->next = S;
	/*********�������***********/
	S = p;
	/*********�������***********/
	return S;
}

LinkStack* Pop(LinkStack* S, DataType* x)

{  /*��ջ����*/

	LinkStack* p = NULL/*********�������***********/;
	
	if (EmptyStack(S))    /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/

	{

		printf("\tջ�գ����ܳ�ջ!");

		return NULL/*********�������***********/;
		
	}

	else                     /*ջ��Ϊ��*/

	{

		*x = S->data/*********�������***********/;
			
		p = S;                  /*p���ָ��ԭջ��S*/

		S = S->next;            /*ԭջ��Sָ������һ�����*/

		free(p);              /*�ͷ�ԭջ���ռ�*/

		return S;/*********�������***********/;

	}

}

LinkStack* Pop(LinkStack* S, DataType* x)

{  /*��ջ����*/

	LinkStack* p;

	if (EmptyStack(S))    /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/

	{

		printf("\tջ�գ����ܳ�ջ!");

		return NULL;         /*ջ�ղ��ܳ�ջ*/

	}

	else                     /*ջ��Ϊ��*/

	{

		*x = S->data/*********�������***********/;

		p = S/*********�������***********/;

		S = p->next/*********�������***********/;

		free(p)/*********�������***********/;

		return S;             /*����ջ��S*/

	}

}

int GetTop(LinkStack* S, DataType* x/*********�������***********/)

{  /*��ȡջ��Ԫ�غ���*/

	if (EmptyStack(S))      /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/

	{

		printf("ջ��!");

		return 0/*********�������***********/;

	}

	else                 /*ջ��Ϊ��*/

	{

		*x = S->data/*********�������***********/;       /*ջ��Ԫ�ظ�������x*/

		return 1;/*********�������***********/;

	}

}

LinkStack *Pop(LinkStack *S,DataType *x)

{  /*��ջ����*/

   LinkStack *p;

   if(EmptyStack(S))    /*�����пպ���EmptyStack(S)���ж�ջ�Ƿ�Ϊ��*/

   {

       printf("\tջ�գ����ܳ�ջ!");

       return NULL;         /*ջ�ղ��ܳ�ջ*/

   }

   else                     /*ջ��Ϊ��*/

   {

      *x=S->data;           /*/*********ע�����***********//*��ջ����ֵ���������õ�ָ�����x��*/

      p=S;                  /*/*********ע�����***********//*ʹ��p ָ��ջ��Ԫ��*/

      S=S->next;            /*/*********ע�����***********//*ʹ��Sָ��ջ��Ԫ�ص���һ��Ԫ��*/

      free(p);              /*/*********ע�����***********//*�ͷ�ԭ�ȵ�ջ��Ԫ��*/

      return S;             /*����ջ��S*/

   }

}

typedef struct node {
	DataType data[MAXSIZE];
	int top;
}SeqStack;

int Push(SeqStack* S, DataType x)

{   /*��ջ��������*/

	if (MAXSIZE - 1 == S->top/*********�������***********/)

	{
		printf("ջ�������ܽ�ջ!");

		return 0;                /*ջ�����ܽ�ջ*/

	}

	else                          /*ջ��Ϊ��*/

	{   
		S->top += 1/*********�������***********/;

		S->data[S->top] = x;/*********�������***********/;

		return 1/*********�������***********/;

	}

}

int Pop(SeqStack* S, DataType* x)

{   /*��ջ��������*/

	if (-1 == S->top/*********�������***********/)

	{
		printf("ջ�գ����ܳ�ջ!");

		return 0;              /*ջ�ղ��ܳ�ջ*/

	}

	else                        /*ջ��Ϊ��*/

	{   *x = S->data[S->top]/*********�������***********/;

		S->top -= 1/*********�������***********/;

		return 1/*********�������***********/;

	}

}

typedef struct node {
	//DataType data;
	struct node_* front;
	struct node_* rear;
}LinkQueue;

typedef struct node_ {
	DataType data;
	struct node_* next;
}LinkListQ;

LinkQueue* InitQueue()

{   /*��ʼ�������к���*/

	LinkQueue* Q;

	LinkListQ* p;

	Q = (LinkQueue*)malloc(sizeof(LinkQueue)); /*/*********ע�����***********//*����һ��LinkQueue�ṹ���ڴ�ռ䲢���ڴ��ַ����Q*/

		p = (LinkListQ*)malloc(sizeof(LinkListQ)); /*/*********ע�����***********//*����һ��LinkListQ�ṹ���ڴ�ռ䲢���ڴ��ַ����p*/

		Q->front = p;    /*/*********ע�����***********//*��p��ֵ����Qָ��Ľṹ���е�front*/

		Q->rear = p;     /*/*********ע�����***********//*��p��ֵ����Qָ��Ľṹ���е�rear*/

		return Q;

}