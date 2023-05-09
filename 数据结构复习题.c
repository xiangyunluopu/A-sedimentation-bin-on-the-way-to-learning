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
////		printf("顺序表已满！\n");
////		return -1;
////	}
////	if (i < 1 || i > L->Length + 1) {
////		printf("插入位置出错！\n");
////		return 0;
////	}
////	if (i == L->Length + 1) {
////		L->data[L->Length] = x;
////		// 或者是 L->data[i - 1] = x;
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
//		printf("顺序表已满！\n");
//		return -1;
//	}
//	if (i < 1 || i > L->Length + 1) {
//		printf("插入位置出错！\n");
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
//		printf("顺序表为NULL!\n");
//		return 0;
//	}
//	if (i < 1 || i > L->Length) {
//		printf("不存在第i个元素\n");
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
//// 45题: 头插法建立链表函数
//
//#include<malloc.h>
//#include<stdio.h>
//
//void Create_List_Head(LinkList* head, int n) {
//	LinkList* s = NULL;
//	int i;
//	printf("请输入%d个整数: ", n);
//	for (i = 0; i < n; i += 1) {
//		s = (LinkList*)malloc(sizeof(LinkList));
//		scanf("%d", &s->data);
//		// [0][->1] <- head
//		// [1][NULL]
//		// [][]
//		s->next = head->next;
//		head->next = s;
//	} // ok
//	printf("建立链表成功!\n");
//}
//
//// 46题,尾插法建立链表函数
//
//void CreateList(LinkList* head, int n) {
//	LinkList* s = NULL;
//	LinkList* Last = NULL;
//	int i = 0;
//	Last = head;
//	printf("请输入%d个整数:", n);
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
//	printf("建立链表成功!\n");
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

// 求链表长度函数

int LengthList(LinkList* head) {
	LinkList* p = head->next;
	int j = 0;
	while (p != NULL) {
		p = p->next;
		j += 1;
	}
	return j;
}

// 查找x的元素的位置

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
		printf("在表的第%d位找到值为%d的结点！\n", j, x);
	}
	else {
		printf("未找到值为%d的结点!\n");
	}
}

// 按位置查找位置

void SearchList(LinkList* head, int i) {
	LinkList* p = NULL;
	int j = 0;
	p = head->next;
	if (i > LengthList(head)) {
		printf("位置错误，链表中没有该位置！\n");
	}
	while (j < i && NULL != p) {
		p = p->next;
		j += 1;
	}
	if (NULL != p) {
		printf("在第%d位上的元素值为%d!\n", i, p->data);
	}
}

// 链表的按位置插入操作

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
		printf("插入元素成功！\n");
	}
	else {
		printf("插入元素失败\n");
	}
}

// 又一个按位置插入函数

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
		printf("插入元素成功！\n");
	}
	else {
		printf("插入元素失败\n");
	}
}

// 按位置删除链表中元素函数 
 
void DelList(LinkList* head, int i) {
	int j = 0;
	DataType x; //好像1明白了
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
		printf("删除第%d位上的元素%d成功!\n", i, x);
	}
	else {
		printf("删除结点位置错误，删除失败！\n");
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
		printf("删除第%d位上的元素%d成功！\n", i, x);
	}
	else {
		printf("删除结点位置错误，删除失败！\n");
	}
}

typedef struct node {
	DataType data;
	struct node* next;
}LinkStack;

LinkStack* Push(LinkStack* S, DataType x)

{  /*进栈函数*/

	LinkStack* p;

	p = (LinkStack*)malloc(sizeof(LinkStack));/*生成新结点*/

	/*********代码填空***********/
	p->data = x;
	/*********代码填空***********/
	p->next = S;
	/*********代码填空***********/
	S = p;
	/*********代码填空***********/
	return S;
}

LinkStack* Pop(LinkStack* S, DataType* x)

{  /*出栈函数*/

	LinkStack* p = NULL/*********代码填空***********/;
	
	if (EmptyStack(S))    /*调用判空函数EmptyStack(S)，判断栈是否为空*/

	{

		printf("\t栈空，不能出栈!");

		return NULL/*********代码填空***********/;
		
	}

	else                     /*栈不为空*/

	{

		*x = S->data/*********代码填空***********/;
			
		p = S;                  /*p结点指向原栈顶S*/

		S = S->next;            /*原栈顶S指向其下一个结点*/

		free(p);              /*释放原栈顶空间*/

		return S;/*********代码填空***********/;

	}

}

LinkStack* Pop(LinkStack* S, DataType* x)

{  /*出栈函数*/

	LinkStack* p;

	if (EmptyStack(S))    /*调用判空函数EmptyStack(S)，判断栈是否为空*/

	{

		printf("\t栈空，不能出栈!");

		return NULL;         /*栈空不能出栈*/

	}

	else                     /*栈不为空*/

	{

		*x = S->data/*********代码填空***********/;

		p = S/*********代码填空***********/;

		S = p->next/*********代码填空***********/;

		free(p)/*********代码填空***********/;

		return S;             /*返回栈顶S*/

	}

}

int GetTop(LinkStack* S, DataType* x/*********代码填空***********/)

{  /*获取栈顶元素函数*/

	if (EmptyStack(S))      /*调用判空函数EmptyStack(S)，判断栈是否为空*/

	{

		printf("栈空!");

		return 0/*********代码填空***********/;

	}

	else                 /*栈不为空*/

	{

		*x = S->data/*********代码填空***********/;       /*栈顶元素赋给变量x*/

		return 1;/*********代码填空***********/;

	}

}

LinkStack *Pop(LinkStack *S,DataType *x)

{  /*出栈函数*/

   LinkStack *p;

   if(EmptyStack(S))    /*调用判空函数EmptyStack(S)，判断栈是否为空*/

   {

       printf("\t栈空，不能出栈!");

       return NULL;         /*栈空不能出栈*/

   }

   else                     /*栈不为空*/

   {

      *x=S->data;           /*/*********注释填空***********//*将栈顶的值赋给解引用的指针变量x中*/

      p=S;                  /*/*********注释填空***********//*使得p 指向栈顶元素*/

      S=S->next;            /*/*********注释填空***********//*使得S指向栈顶元素的下一个元素*/

      free(p);              /*/*********注释填空***********//*释放原先的栈顶元素*/

      return S;             /*返回栈顶S*/

   }

}

typedef struct node {
	DataType data[MAXSIZE];
	int top;
}SeqStack;

int Push(SeqStack* S, DataType x)

{   /*进栈操作函数*/

	if (MAXSIZE - 1 == S->top/*********代码填空***********/)

	{
		printf("栈满，不能进栈!");

		return 0;                /*栈满不能进栈*/

	}

	else                          /*栈不为满*/

	{   
		S->top += 1/*********代码填空***********/;

		S->data[S->top] = x;/*********代码填空***********/;

		return 1/*********代码填空***********/;

	}

}

int Pop(SeqStack* S, DataType* x)

{   /*出栈操作函数*/

	if (-1 == S->top/*********代码填空***********/)

	{
		printf("栈空，不能出栈!");

		return 0;              /*栈空不能出栈*/

	}

	else                        /*栈不为空*/

	{   *x = S->data[S->top]/*********代码填空***********/;

		S->top -= 1/*********代码填空***********/;

		return 1/*********代码填空***********/;

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

{   /*初始化链队列函数*/

	LinkQueue* Q;

	LinkListQ* p;

	Q = (LinkQueue*)malloc(sizeof(LinkQueue)); /*/*********注释填空***********//*生成一个LinkQueue结构体内存空间并将内存地址赋给Q*/

		p = (LinkListQ*)malloc(sizeof(LinkListQ)); /*/*********注释填空***********//*生成一个LinkListQ结构体内存空间并将内存地址赋给p*/

		Q->front = p;    /*/*********注释填空***********//*将p的值赋给Q指向的结构体中的front*/

		Q->rear = p;     /*/*********注释填空***********//*将p的值赋给Q指向的结构体中的rear*/

		return Q;

}