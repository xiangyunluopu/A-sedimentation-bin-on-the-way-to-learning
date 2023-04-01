#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
void Menu()
{
	printf("\n");
	printf("==========================\n");
	printf("***  ˳���---�Ĳ���   ***\n");
	printf("***  ����˳���----1   ***\n");
	printf("***  ����----------2   ***\n");
	printf("***  ɾ��----------3   ***\n");
	printf("***  ����λ��------4   ***\n");
	printf("***  ����Data------5   ***\n");
	printf("***  ���Seqlist---6   ***\n");
	printf("***  out-----------0   ***\n");
	printf("==========================\n");
}
void InitList(Seqlist* L)
{
	L->Length = 0;
}
void CreateList(Seqlist* L)
{
	int n = 0;
	int i = 0;
	int ret = 0;
	for (;;)
	{
		printf("������׼�������Ԫ�ظ�����");
		scanf("%d", &n);
		if (1 <= n && n <= MAXLEN)
		{
			for (i = 0; i < n; i += 1)
			{
				scanf("%d", &ret);
				L->Data[i] = ret;
				L->Length += 1;
				
			}
			break;
		}
		else
		{
			printf("��Χ��������");
		}
	}
}
void DispList(Seqlist* L)
{
	int i = 0;
		for (i = 0; i < L->Length; i += 1)
		{
			printf("[%d]:%-5d", i + 1, L->Data[i]);
		}
	
}
void InsElem(Seqlist* L, int n, int x)
{
	int i = 0;
	if (n == L->Length)
	{
		L->Data[L->Length] = x;
		L->Length += 1;
	}
	else
	{
		for (i = L->Length - 1; i >= n - 1; i -= 1)
		{
			L->Data[i + 1] = L->Data[i];
		}
		L->Data[n - 1] = x;
		L->Length += 1;
	}
}
void DelElem(Seqlist* L, int n, DataType* x)
{
	int i = 0;
	*x = L->Data[n - 1];
	for (i = n; i <= L->Length - 1; i += 1)
	{
		L->Data[i - 1] = L->Data[i];
	}
	L->Length -= 1;
}
void GetElem(Seqlist* L, int n, DataType* x)
{
	*x = L->Data[n - 1];
}
int Locate(Seqlist* L, int* n, DataType x)
{
	int i = 0;
	for (i = 0; i < L->Length; i += 1)
	{
		if (L->Data[i] == x)
		{
			*n = i + 1;
			return 1;
		}
	}
	return 0;
}