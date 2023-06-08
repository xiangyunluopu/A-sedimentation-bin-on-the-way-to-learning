#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>

#define MAXSIZE 100
#define DataType int

typedef struct
{
	DataType data[MAXSIZE];
	int Len;
}List;

void Menu(void)
{
	printf("\n       线性表");
	printf("\n========================");
	printf("\n|    1.创建线性表      |");
	//printf("\n|    2.线性表赋值      |");
	printf("\n|    2.销毁线性表      |");
	printf("\n|    3.插入元素        |");
	printf("\n|    4.删除元素        |");
	printf("\n|    5.打印线性表      |");
	printf("\n|    0.退出            |");
	printf("\n========================");
	printf("\n请输入菜单号(0 ~ 6)>:");
}

int CreateList(List* Obj)
{
	//int len = 0;
	//char ch = 0;
	int i = 0;
	if (0 < Obj->Len)
	{
		return 1;
	}
	else
	{
		printf("\n请输入线性表的长度>:");
		scanf("%d", &Obj->Len);
		printf("\n请输入%d个初始值", Obj->Len);
		for (i = 0; i < Obj->Len; i += 1)
		{
			printf("\n剩余%d, 请输入>:", Obj->Len - i);
			scanf("%d", &Obj->data[i]); getchar();
		}
		//Clear();
		return 0;
	}
}

void DeleteList(List* Obj)
{
	int i = 0;
	int k = 0;
	if (-1 == Obj->Len)
	{
		printf("\n线性表未创建，无法删除元素");
	}
	else if (0 == Obj->Len)
	{
		printf("\n线性表为空，无法删除元素");
	}
	else
	{
		printf("\n请输入想删除的元素位置(1 ~ %d)>:", Obj->Len);
		scanf("%d", &k); getchar();
		while (k < 1 || k > Obj->Len)
		{
			printf("输入的删除位置不合法，请重新输入>:");
			scanf("%d", &k);
		}
		for (i = k; i < Obj->Len; i += 1)
		{
			Obj->data[i - 1] = Obj->data[i];
		}
		Obj->Len -= 1;
		printf("\n删除成功");
	}
}

void InputList(List* Obj)
{
	DataType x = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	if (-1 == Obj->Len)
	{
		printf("\n线性表未创建，无法插入元素");
	}
	else if (Obj->Len < MAXSIZE)
	{
		printf("\n请输入想插入的值>:");
		scanf("%d", &x); getchar();
		printf("\n请输入想插入的位置(1 ~ %d)>:", Obj->Len + 1);
		scanf("%d", &k); getchar();
		while (k < 1 || k > Obj->Len + 1)
		{
			printf("\n位置不合法，请重新输入插入位置(1 ~ %d)>:", Obj->Len + 1);
			scanf("%d", &k); getchar();
		}
		// [1] [2] [3] [4]
		// [0] [1] [2] [3] 
		if (Obj->Len == 0)
		{
			Obj->Len = 1;
			Obj->data[0] = x;
		}
		else
		{
			if (k != Obj->Len + 1)
			{
				for (i = Obj->Len - 1; i >= k - 1; i -= 1)
				{
					Obj->data[i + 1] = Obj->data[i];
				}
				Obj->data[k - 1] = x;
				Obj->Len += 1;
			}
			else
			{
				Obj->data[Obj->Len++] = x;
			}
		}
	}
	else
	{
		printf("\n表已满，无法插入");
	}
}

void DispList(List* Obj)
{
	int i = 0;
	if (-1 == Obj->Len)
	{
		printf("\n线性表未创建，无法打印");
	}
	else if (0 == Obj->Len)
	{
		printf("\n线性表为空，无法打印");
	}
	else
	{
		printf("\n线性表打印如下\n");
		for (i = 0; i < Obj->Len; i += 1)
		{
			printf("[%d]", Obj->data[i]);
		}
	}
}

int main(void)
{
	char ch1 = 'y';
	int num2 = 0;
	List Obj = { 0 };
	Obj.Len = -1;
	//printf("%d", Obj.Len);
	while ('y' == ch1)
	{
		Menu();
		scanf("%d", &num2); getchar();
		switch (num2)
		{
		case 0:
			ch1 = 'n';
			break;
		case 1:
			if (CreateList(&Obj))
			{
				printf("\n表已经创建");
			}
			break;
		case 2:
			if (Obj.Len < 0)
			{
				printf("\n线性表未创建，无法销毁");
			}
			else
			{
				Obj.Len = -1;
				printf("\n线性表已销毁");
			}
			break;
		case 3:
			InputList(&Obj);
			break;
		case 4:
			DeleteList(&Obj);
			break;
		case 5:
			DispList(&Obj);
			break;
		default:
			printf("输入不合法\n");
			system("pause"); getchar();
			break;
		}
	}
	return 0;
}