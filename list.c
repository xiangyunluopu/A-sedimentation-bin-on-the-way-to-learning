#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// �˵�
// ��ʼ�������� --1
// ���� --2
// ɾ�� --3
// ��ֵ���� --4
// ��λ�ò��� --5
// ��ʾ���Ԫ�� --6

void menu()
{
	printf("===================\n");
	printf("*** ��ʼ��---1\n");
	printf("*** ����---2\n");
	printf("*** ɾ��---3\n");
	printf("*** ��ֵ����---4\n");
	printf("*** ��λ�ò���---5\n");
	printf("*** �����㳤��---6\n");
	printf("*** ��ʾ���Ԫ��---7\n");
	printf("*** out---0\n");
	printf("===================\n");
}

void init_list(L* head) // 1
{
	int i = 0;
	int j = 0;
	L* p = head;
	L* s;
	printf("����Ū����");
	scanf("%d", &j);

	for (i = 1; i <= j; i += 1)
	{
		s = (L*)malloc(sizeof(L));
		printf("��Ϊ��%d��Ԫ�ظ�ֵ", i);
		scanf("%d", &s->data);
		s->next = p->next;
		p->next = s;
		p = s;
	}

}

void ins_list(L* head) // 2
{
	L* s;
	L* p = head;
	int ret = 0;
	int i = 0;
	int j = 0;
	printf("��������������λ�� >:");
	scanf("%d", &j);
	printf("\n���������븳��ֵ>:");
	scanf("%d", &ret);

	for (i = 0; p->next != NULL && i < j - 1; i += 1, p = p->next);
	if (p != NULL)
	{
		s = (L*)malloc(sizeof(L));
		s->data = ret;
		s->next = p->next;
		p->next = s;
	}
	else
	{
		printf("����ʧ��");
	}
}

void dele_node(L* head) //3
{
	L* p = head;
	L* s;
	int i = 0, j = 0;
	data_type x = 0;
	// ɾ����λ��---�����жϱ��Ƿ�Ϊ�� 
	if (p->next == NULL)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		printf("�붨λ��Ҫɾ����λ��>:");
		scanf("%d", &j);
		for (i = 0; i < j - 1; i += 1, p = p->next);
		s = p->next;
		x = s->data;
		p->next = s->next;
		free(s);
		printf("����%dλ����%dɾ��\n", j, x);
	}
	// ��Ҫ��λ����Ҫɾ������ǰһλ
	// ��Ҫ����ָ��
	// ��Ҫһ��ѭ��������
	// ��Ҫһ��λ�ô���
	// һ����ӳ����data_type x;
}

void sea_data(L* head)  //4
{
	L* p = head;
	int i = 0;
	data_type x = 0;
	
	if (p->next == NULL)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		printf("��������Ҫ���ҵ�ֵ>:");
		scanf("%d", &x);
		for (i = 0; p != NULL && p->data != x; i += 1, p = p->next);
		if (p == NULL)
		{
			printf("�Ҳ���\n");
		}
		else
		{
			printf("��%dλ����ҵ���\n", i);
		}
	}
	//����ǰ�ֵsea
	//���жϱ��Ƿ�Ϊ��
	//��Ҫѭ��
	//��Ҫһ��int ��ӳλ��
	//��Ҫdata x ���洢����ֵ


}

void sea_node(L* head)  // 5
{
	L* p = head;
	// L* ps = head;
	int i = 0;
	int node = 0;
	int n = 0;
	data_type x = 0;

	if (p->next == NULL)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		printf("����������ҵ�λ��>:");
		scanf("%d", &node);
		for (n = 0; p->next != NULL; n += 1, p = p->next);
		p = head;
		if (1 <= node && node <= n)
		{
			for (i = 0; i < node; p = p->next ,i += 1);
			x = p->data;
			printf("��%d����ֵλ%d\n", node, x);
		}
		else
		{
			printf("λ�����벻�Ϸ�\n");
		}
		
	}

	// �жϱ��Ƿ�Ϊ��
	// �����ĳ���
	// ���泤�ȵ�int
	// �жϲ���λ���Ƿ�Ϸ�
	// ��Ҫһ��ָ��
	// ��Ҫһ��ѭ��������
	// data_type x
	// ���������λ�õ� int

}

void list_node_count(L* head) // 6
{
	int i = 0;
	L* p = head;
	for (i = 0; p->next != NULL; p = p->next, i += 1);
	printf("����ĳ���Ϊ%d\n", i);
}

disp_node_all(head) // 7
{
	int i = 0;
	data_type x = 0;
	L* p = head;
	if (p->next == NULL)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		for (i = 1, p = p->next; p != NULL; p = p->next, i += 1)
		{
			x = p->data;
			printf("[%d][%d]\n", i, x);
		}
		printf("\n");
	}
}
