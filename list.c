#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// 菜单
// 初始化单链表 --1
// 插入 --2
// 删除 --3
// 按值查找 --4
// 按位置查找 --5
// 显示结点元素 --6

void menu()
{
	printf("===================\n");
	printf("*** 初始化---1\n");
	printf("*** 插入---2\n");
	printf("*** 删除---3\n");
	printf("*** 按值查找---4\n");
	printf("*** 按位置查找---5\n");
	printf("*** 计算结点长度---6\n");
	printf("*** 显示结点元素---7\n");
	printf("*** out---0\n");
	printf("===================\n");
}

void init_list(L* head) // 1
{
	int i = 0;
	int j = 0;
	L* p = head;
	L* s;
	printf("你想弄几个");
	scanf("%d", &j);

	for (i = 1; i <= j; i += 1)
	{
		s = (L*)malloc(sizeof(L));
		printf("请为第%d个元素赋值", i);
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
	printf("请输入你想插入的位置 >:");
	scanf("%d", &j);
	printf("\n请输入你想赋的值>:");
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
		printf("插入失败");
	}
}

void dele_node(L* head) //3
{
	L* p = head;
	L* s;
	int i = 0, j = 0;
	data_type x = 0;
	// 删除的位置---》先判断表是否为空 
	if (p->next == NULL)
	{
		printf("表为空\n");
	}
	else
	{
		printf("请定位想要删除的位置>:");
		scanf("%d", &j);
		for (i = 0; i < j - 1; i += 1, p = p->next);
		s = p->next;
		x = s->data;
		p->next = s->next;
		free(s);
		printf("将第%d位结点的%d删除\n", j, x);
	}
	// 需要定位到需要删除结点的前一位
	// 需要两个指针
	// 需要一个循环计数器
	// 需要一个位置储存
	// 一个反映结点的data_type x;
}

void sea_data(L* head)  //4
{
	L* p = head;
	int i = 0;
	data_type x = 0;
	
	if (p->next == NULL)
	{
		printf("表为空\n");
	}
	else
	{
		printf("请输入想要查找的值>:");
		scanf("%d", &x);
		for (i = 0; p != NULL && p->data != x; i += 1, p = p->next);
		if (p == NULL)
		{
			printf("找不到\n");
		}
		else
		{
			printf("在%d位结点找到了\n", i);
		}
	}
	//这个是按值sea
	//先判断表是否为空
	//需要循环
	//需要一个int 反映位置
	//需要data x 来存储查找值


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
		printf("表为空\n");
	}
	else
	{
		printf("请输入想查找的位置>:");
		scanf("%d", &node);
		for (n = 0; p->next != NULL; n += 1, p = p->next);
		p = head;
		if (1 <= node && node <= n)
		{
			for (i = 0; i < node; p = p->next ,i += 1);
			x = p->data;
			printf("第%d结点的值位%d\n", node, x);
		}
		else
		{
			printf("位置输入不合法\n");
		}
		
	}

	// 判断表是否为空
	// 计算表的长度
	// 保存长度的int
	// 判断查找位置是否合法
	// 需要一个指针
	// 需要一个循环计数器
	// data_type x
	// 储存想查找位置的 int

}

void list_node_count(L* head) // 6
{
	int i = 0;
	L* p = head;
	for (i = 0; p->next != NULL; p = p->next, i += 1);
	printf("链表的长度为%d\n", i);
}

disp_node_all(head) // 7
{
	int i = 0;
	data_type x = 0;
	L* p = head;
	if (p->next == NULL)
	{
		printf("表为空\n");
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
