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
	printf("�����Ϊ%d \n", i);
}

void ser_loca(L* head)
{
	int loca = 0;
	int i = 0;
	L* p = head;
	printf("��������Ҫ��ѯ��λ��\n");
	scanf("%d", &loca);
	//���������ѯ��һ��λ��
	//p->[0]  
	for (i = 0; i < loca; i += 1)
	{
		p = p->next;
	}
	printf("��%d������ֵΪ%d\n", loca, p->data);
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
	printf("������������λ��");
	scanf("%d", &j);
	printf("\n������������ֵ");
	scanf("%d", &s_ret);
	if (j < 1 && j > flag + 1)
	{
		printf("��Χ����\n");
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
	printf("������Ҫɾ����λ��\n");
	scanf("%d", &j);
	if (1 <= j && j <= i)
	{
		for (i = 0; i < j - 1; ps = ps->next, i += 1);
		s = ps->next;
		x = s->data;
		ps->next = s->next;
		free(s);
		printf("�ѽ���%d������%dɾ��\n", j, x);
	}
	else
	{
		printf("λ�ò��Ϸ�\n");
	}
}

int main()
{
	int ret = 0;
	L* head = (L*)malloc(sizeof(L));
	head->next = NULL;

	cre_list(head);//����ʮ����㲢��ֵ;

	do
	{
		printf("0.out\n1.���������\n2.��λ�ò�ѯ���\n3.����Ԫ��\n");
		printf("4.ɾ�����\n");
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
			printf("�������\n");
		}
	}while(ret);
	return 0;
}
