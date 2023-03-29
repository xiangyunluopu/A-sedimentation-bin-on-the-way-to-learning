#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	printf("%d", 15 % 3);
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<Windows.h>
//
//void stu(int arr[], int sub)
//{
//	int i = 0;
//	for (i = 0; i <= sub; i += 1)
//	{
//		arr[i] = rand() % 10;
//
//	}
//}
//void my_printf(int arr[], int sub)
//{
//	int i = 0;
//	for (i = 0; i <= sub; i += 1)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void bub_sort(int arr[], int sub)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <= sub; i += 1)
//	{
//		int flog = 0;
//		for (j = sub ; j > 0 + i; j -= 1)
//		{
//			if (arr[j - 1] < arr[j])
//			{
//				int tmp = arr[j - 1];
//				arr[j - 1] = arr[j];
//				arr[j] = tmp;
//				flog = 1;
//			}
//		}
//		if (flog == 0)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int sub = sz - 1;
//	srand((unsigned)time(NULL));
//	stu(arr, sub);
//	my_printf(arr, sub);
//	system("pause");
//	bub_sort(arr, sub);
//	my_printf(arr, sub);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 , 2 };
//	printf("%p\n", arr + 1);
//	//printf("%p\n", &arr[0] + 1);
//	//printf("%d\n", *arr + 1);
//	printf("%p\n", &arr + 1);
//	printf("%p\n", &arr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define N 5
//
//void stu(int (*arr)[N])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < N; i += 1)
//	{
//		for (j = 0; j < N; j += 1)
//		{
//			arr[i][j] = rand() % 10;
//		}
//	}
//
//}
//
//void my_printf(int(*arr)[N])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < N; i += 1)
//	{
//		for (j = 0; j < N; j += 1)
//		{
//			printf("%d  ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void fun(int (*arr)[N])
//{
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	scanf("%d", &m);
//	for (i = 0; i < N; i += 1)
//	{
//		for (j = N - 1 - m; j >= 0; j -= 1)
//		{
//			arr[i][j + m] = arr[i][j];
//		}
//		for (j = 0; j < m; j += 1)
//		{
//			arr[i][j] = 0;
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[N][N] = { 0 };
//	srand((unsigned)time(NULL));
//	stu(arr);
//	my_printf(arr);
//	fun(arr);
//	printf("\n\n\n");
//	my_printf(arr);
//	return 0;
//}
//#include<stdio.h>
//
//void sort(int* a, int* b, int* c)
//{
//	int tmp;
//	if (*a > *b)
//	{
//		tmp = *b;
//		*b = *a;
//		*a = tmp;
//	}
//	if (*a > *c)
//	{
//		tmp = *c;
//		*c = *a;
//		*a = tmp;
//	}
//	if (*b > *c)
//	{
//		tmp = *c;
//		*c = *b;
//		*b = tmp;
//	}
//
//}
//int main()
//{
//	int a = 13;
//	int b = 77;
//	int c = 0;
//	sort(&a, &b, &c);
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//#define N 10
//typedef struct ss
//{
//	char num[10];
//	int ach;
//}stu;
//
//fun(stu a[], stu* p)
//{
//	int i = 0;
//	strcpy(p->num, a[0].num);
//	p->ach = a[0].ach;
//	for (i = 1; i < N; i += 1)
//	{
//		if (p->ach > a[i].ach)
//		{
//			strcpy(p->num, a[i].num);
//			p->ach = a[i].ach;
//		}
//	}
//
//}
//
//int main()
//{
//	stu m;
//	stu a[N] = { {"A01", 81}, {"A02", 89}, {"A03", 66}, {"A04", 87}, {"A05", 77}, {"A06", 90},
//				{"A07", 79}, {"A08", 61}, {"A09", 80}, {"A10", 71} };
//	int i = 0;
//	puts("原始成绩！！");
//	for (i = 0; i < 10; i += 1)
//	{
//		printf("学号%s,成绩%d  ", a[i].num, a[i].ach);
//	}
//	fun(a, &m);
//	printf("\n最低成绩%d，学号为%s", m.ach, m.num);
//	return 0;
//}














