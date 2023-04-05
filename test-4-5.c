#define _CRT_SECURE_NO_WARNINGS 1

//#define data_type int
//
//typedef struct link_node
//{
//	data_type data;
//	struct linknode* next;
//}link_list;
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int count = 0;
//	int i = 0;
//	link_list* head;
//	link_list* s;
//	
//
//	head = (link_list*)malloc(sizeof(link_list));
//	head->next = NULL;
//	//head --> [][]
//	link_list* last = head;
//	link_list* flag = head;
//	for (i = 0; i < 10; i += 1)
//	{
//		s = (link_list*)malloc(sizeof(link_list));
//		// head --> [0][-->3]
//		//      --> [1][NULL]
//		//      --> [2][-->1]
//		//    s --> [3][-->2]
//		s->next = head->next;
//		head->next = s;
//	}
//	
//	for (;flag->next != NULL;)
//	{
//		flag = flag->next;
//		count += 1;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}

#define data_type int

typedef struct linknode
{
	data_type data;
	struct linknode* next;
}L;

#include<stdio.h>
#include<stdlib.h>

void cre_L_H(L* head, int n)
{
	int i = 0;
	L* s = NULL;

	for (i = 1; i <= n; i += 1)
	{
		s = (L*)malloc(sizeof(L));
		printf("请为第%d个元素赋值", i);
		scanf("%d", &s->data);
		//head --> [#][-->2]
		//     --> [1][NULL]
		//   s --> [2][-->]
		s->next = head->next;
		head->next = s;
	}
}

void cre_L_T(L* head, int n)
{
	int i = 0;
	// 创建last指针==head;
	L* last = head;
	L* s = NULL;
	for (i = 1; i <= n; i += 1)
	{
		s = (L*)malloc(sizeof(L));
		printf("请为第%d个元素赋值", i);
		scanf("%d", &s->data);
		//          [0][-->1] <-- head
		//          [1][-->2] 
		//    s --> [2][#] <-- last 
		s->next = NULL;
		last->next = s;
		last = s;
	}
}

int length_L(L* head)
{
	L* p = head;
	int count = 0;
	for (;p->next != NULL;)
	{
		p = p->next;
		count += 1;
	}
	return count;
}

int Locate(L* head, data_type* x, int count)
{
	int j = 0;
	L* p = head;
	if (p->next != NULL)
	{
		for (j = 0; p != NULL && p->data != *x; j += 1, p = p->next);
		if (NULL == p)
		{
			return -1;
		}
		else
		{
			return j;
		}
	}
	else
	{
		return 0;
	}
}

int ser_list_loca(L* head, int node_loca, data_type* x)
{
	L* p = head;
	int i = 0;
	if (p->next == NULL)
	{
		return 0;
	}
	else if (node_loca > length_L(p))
	{
		return -1;
	}
	else
	{
		for (i = 1; i <= node_loca; i += 1)
		{
			p = p->next;
		}
		*x = p->data;
		return 1;
	}
}

int in_list(L* head, int input, data_type x)
{
	int j = 0;
	L* s = (L*)malloc(sizeof(L));
	L* p = head;
	s->data = x;
	if (input > length_L(p) + 1 && input < 1)
	{
		return 0;
	}
	else
	{
		//       [0][-->1]
		//       [1][-->2]
		//       [2][-->3]
		//       [3][#]
		for (j = 0; j <= input - 1; j += 1)
		{
			p = p->next;
		}
		s->next = p;
		p->next = s;
		return 1;
	}

}

int main()
{
	int node_loca = 0;
	int n = 0;
	int count = 0;
	int input = 0;
	data_type x;
	int ret = 0;
	L* head = (L*)malloc(sizeof(L));
	head->next = NULL;
	printf("请输入要建立的节点数量\n");
	scanf("%d", &n);
	cre_L_T(head, n);
	count = length_L(head);
	printf("总共有%d个节点\n", count);
	printf("请输入想要查找的值");
	scanf("%d", &x);
	ret = Locate(head, &x, count);
	if (0 == ret)
	{
		printf("表为空\n");
	}
	else if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，是第%d个节点\n", ret);
	}
	A:
	printf("请输入查找的位置");
	scanf("%d", &node_loca);
	if (node_loca < 1)
	{
		printf("位置不合法\n");
	}
	else
	{
		ret = ser_list_loca(head, node_loca, &x);
		if (0 == ret)
		{
			printf("表为空\n");
		}
		else if (-1 == ret)
		{
			printf("超出表的范围\n");
		}
		else
		{
			printf("第%d个节点的值为%d\n", node_loca, x);
		}
	}

	printf("请输入要插入的节点位置");
	scanf("%d", &input);
	printf("\n");
	printf("请输入插入的值");
	scanf("%d", &x);
	printf("\n");
	ret = in_list(head, input, x);
	if (0 == ret)
	{
		printf("插入失败\n");
	}
	else
	{
		printf("插入成功");
	}
	goto A;
	return 0;
}
