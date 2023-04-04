#define _CRT_SECURE_NO_WARNINGS 1

//typedef struct linknode
//{
//	int data;
//	struct linknode* next;
//}LinkList;
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	LinkList* head = NULL;
//	LinkList* heads;
//	head = (LinkList*)malloc(sizeof(LinkList));
//	printf("%p \n", head);
//	//heads = &()malloc(sizeof(LinkList));
//	printf("%p \n", heads);
//	return 0;
//}	

typedef struct linknode
{
	int data;
	struct linknode* next;
}LinkList;

#include<stdio.h>
#include<stdlib.h>

int main()
{
	LinkList* head;
	LinkList* heads;
	head = (LinkList*)malloc(sizeof(LinkList));
	heads = (LinkList*)malloc(sizeof(LinkList));
	head->data = 7;
	heads->data = 8;
	printf("%p\n", head);
	printf("%d\n", head->data);
	free(head);
	printf("%p\n", head);
	printf("%d\n", head->data);
	printf("\n");
	printf("%p\n", heads);
	printf("%d\n", heads->data);
	heads = NULL;
	printf("%p\n", heads);
	printf("%d\n", heads->data);
	return 0;

	//还是得用free；
}