#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 20
#define MAXVALUE 20

void Fill_Random(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i += 1)
	{
		arr[i] = rand() % MAXVALUE + 1;
	}
}

void Disp_Arr_Ori(int arr[], int sz)
{
	int i = 0;
	printf("原始数组如下\n");
	for (i = 0; i < sz; i += 1)
	{
		printf("%d  ", arr[i]);
	}
}

void Bubble_Sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	char flag = 0;
	// [] [] [] [] [] [] []| []
	// ____
	for (i = sz - 1; i > 0; i -= 1)
	{
		flag = 1;
		for (j = 0; j < i; j += 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

void Insert_Sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 1; i < sz; i += 1)
	{
		tmp = arr[i];
		for (j = i; j > 0; j -= 1)
		{
			if (arr[j - 1] > tmp)
			{
				arr[j] = arr[j - 1];
			}
			else
			{
				arr[j] = tmp;
				break;
			}
		}
		if (j <= 0)
		{
			arr[j] = tmp;
		}
	}
}

void Sort_Sel(int arr[], int sz)
{
	int sel = 0;
	printf("\n现在有两种排序方式");
	printf("\n选择冒泡法请输入 0 ，选择插入排序法请输入 1 ");
	printf("\n请输入(1 ~ 2)>:");
	scanf("%d", &sel); getchar();
	while (sel != 0 && sel != 1)
	{
		printf("\n输入不合法，请重新输入(0 ~ 1)>:");
		scanf("%d", &sel); getchar();
	}
	if (sel)
	{
		Insert_Sort(arr, sz);
	}
	else
	{
		Bubble_Sort(arr, sz);
	}
}

void Disp_Arr_Alter(int arr[], int sz)
{
	int i = 0;
	printf("\n排序后的数组如下\n");
	for (i = 0; i < sz; i += 1)
	{
		printf("%d  ", arr[i]);
	}
}

int main(void)
{
	int arr[MAXSIZE] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	srand((unsigned int)time(NULL));

	Fill_Random(arr, sz);

	Disp_Arr_Ori(arr, sz);

	Sort_Sel(arr, sz);

	Disp_Arr_Alter(arr, sz);
	return 0;
}