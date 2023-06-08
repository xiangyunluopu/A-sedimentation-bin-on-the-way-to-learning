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
	printf("\n       ���Ա�");
	printf("\n========================");
	printf("\n|    1.�������Ա�      |");
	//printf("\n|    2.���Ա�ֵ      |");
	printf("\n|    2.�������Ա�      |");
	printf("\n|    3.����Ԫ��        |");
	printf("\n|    4.ɾ��Ԫ��        |");
	printf("\n|    5.��ӡ���Ա�      |");
	printf("\n|    0.�˳�            |");
	printf("\n========================");
	printf("\n������˵���(0 ~ 6)>:");
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
		printf("\n���������Ա�ĳ���>:");
		scanf("%d", &Obj->Len);
		printf("\n������%d����ʼֵ", Obj->Len);
		for (i = 0; i < Obj->Len; i += 1)
		{
			printf("\nʣ��%d, ������>:", Obj->Len - i);
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
		printf("\n���Ա�δ�������޷�ɾ��Ԫ��");
	}
	else if (0 == Obj->Len)
	{
		printf("\n���Ա�Ϊ�գ��޷�ɾ��Ԫ��");
	}
	else
	{
		printf("\n��������ɾ����Ԫ��λ��(1 ~ %d)>:", Obj->Len);
		scanf("%d", &k); getchar();
		while (k < 1 || k > Obj->Len)
		{
			printf("�����ɾ��λ�ò��Ϸ�������������>:");
			scanf("%d", &k);
		}
		for (i = k; i < Obj->Len; i += 1)
		{
			Obj->data[i - 1] = Obj->data[i];
		}
		Obj->Len -= 1;
		printf("\nɾ���ɹ�");
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
		printf("\n���Ա�δ�������޷�����Ԫ��");
	}
	else if (Obj->Len < MAXSIZE)
	{
		printf("\n������������ֵ>:");
		scanf("%d", &x); getchar();
		printf("\n������������λ��(1 ~ %d)>:", Obj->Len + 1);
		scanf("%d", &k); getchar();
		while (k < 1 || k > Obj->Len + 1)
		{
			printf("\nλ�ò��Ϸ����������������λ��(1 ~ %d)>:", Obj->Len + 1);
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
		printf("\n���������޷�����");
	}
}

void DispList(List* Obj)
{
	int i = 0;
	if (-1 == Obj->Len)
	{
		printf("\n���Ա�δ�������޷���ӡ");
	}
	else if (0 == Obj->Len)
	{
		printf("\n���Ա�Ϊ�գ��޷���ӡ");
	}
	else
	{
		printf("\n���Ա��ӡ����\n");
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
				printf("\n���Ѿ�����");
			}
			break;
		case 2:
			if (Obj.Len < 0)
			{
				printf("\n���Ա�δ�������޷�����");
			}
			else
			{
				Obj.Len = -1;
				printf("\n���Ա�������");
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
			printf("���벻�Ϸ�\n");
			system("pause"); getchar();
			break;
		}
	}
	return 0;
}