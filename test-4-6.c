#define _CRT_SECURE_NO_WARNINGS 1

#define datatype int 

typedef struct list_node
{
	datatype data;
	struct list_node* next;
}L;

#include<stdio.h>
#include<stdlib.h>

void cre_list(L* head)
{
	int i = 0;
	L* s;
	L* last = head;
	
	for (i = 0; i < 10; i += 1)
	{
		s = (L*)malloc(sizeof(L));
		s->data = i;
		// head-->[0][#]<--last
		// [1][]<--s
		s->next = last->next;
		last->next = s;
		last = s;
	}

}

void Lenth(L* head)
{
	int i = 0;
	L* p = head;
	for (i = 0; NULL != p->next; i += 1, p = p->next);
	printf("结点数为%d \n", i);
}

void ser_loca(L* head)
{
	int loca = 0;
	int i = 0;
	L* p = head;
	printf("请输入想要查询的位置\n");
	scanf("%d", &loca);
	//假设我想查询第一个位置
	//p->[0]  
	for (i = 0; i < loca; i += 1)
	{
		p = p->next;
	}
	printf("第%d个结点的值为%d\n", loca, p->data);
}

void ins_node(L* head)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	datatype s_ret = 0;
	L* p = head;
	L* l = head;
	L* s;
	for (flag = 0; NULL != l->next; flag += 1, l = l->next);
	printf("请输入想插入的位置");
	scanf("%d", &j);
	printf("\n请输入想插入的值");
	scanf("%d", &s_ret);
	if (j < 1 && j > flag + 1)
	{
		printf("范围超出\n");
	}
	else if (j == flag + 1)
	{
		for (i = 0; i < flag; i += 1, p = p->next);
		s = (L*)malloc(sizeof(L));
		s->data = s_ret;
		s->next = p->next;
		p->next = s;
	}
	else
	{
		for (i = 0; i < j - 1; i += 1)
		{
			p = p->next;
		}
		s = (L*)malloc(sizeof(L));
		s->data = s_ret;
		s->next = p->next;
		p->next = s;
	}
}

void dele_node(L* head)
{
	datatype x;
	int i = 0;
	int j = 0;
	L* s;
	L* ps = head;
	L* p = head;

	for (i = 0; NULL != p->next; i += 1, p = p->next);
	printf("请输入要删除的位置\n");
	scanf("%d", &j);
	if (1 <= j && j <= i)
	{
		for (i = 0; i < j - 1; ps = ps->next, i += 1);
		s = ps->next;
		x = s->data;
		ps->next = s->next;
		free(s);
		printf("已将第%d个结点的%d删除\n", j, x);
	}
	else
	{
		printf("位置不合法\n");
	}
}

int main()
{
	int ret = 0;
	L* head = (L*)malloc(sizeof(L));
	head->next = NULL;

	cre_list(head);//创建十个结点并赋值;

	do
	{
		printf("0.out\n1.计算结点个数\n2.按位置查询结点\n3.插入元素\n");
		printf("4.删除结点\n");
		scanf("%d", &ret);
		switch (ret)
		{
		case 0:
			break;
		case 1:
			Lenth(head);
			break;
		case 2:
			ser_loca(head);
			break;
		case 3:
			ins_node(head);
			break;
		case 4:
			dele_node(head);
			break;
		default:
			printf("输入错误\n");
		}
	}while(ret);
	return 0;
}
