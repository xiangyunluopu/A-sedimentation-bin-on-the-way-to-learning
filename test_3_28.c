#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>

//int main()
//{
//	int k = 0;
//	int arr[] = { 1,4,6,8,34,5,9,654,76,87,444 };
//	int i = 0;
//	int n = 0;
//	int j = sizeof(arr) / sizeof(arr[0]);
//	for(i = 0; i < j; i++)
//		for (n = i; n < j - 1; n++)
//		{
//			if (arr[n] > arr[n + 1])
//			{
//				k = arr[n + 1];
//				arr[n + 1] = arr[n];
//				arr[n] = k;
//			}
//		}
//	for (i = 0; i < j; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int QSQ(int arr[], int n)
//{
//	int lift = 0;
//	int right = n - 1;
//	int mid = 0;
//	int k = 0;
//	scanf("%d", &k);
//	for (right = 98, lift = 0; lift <= right;)
//	{
//		
//		mid = (lift + right) / 2;
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			lift = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	
//	
//		return -1;
//	
//
//}
//int bbc()
//{
//	
//	int ret = 0;
//	ret = rand();
//	return ret;
//}
//int main()
//{
//	int ret = 0;
//	int arr[99] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int m = 0;
//	srand((unsigned int)time(NULL));
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = bbc() % 1000;
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = i; j < n - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				m = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = m;
//			}
//		}
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	if (-1 == QSQ(arr, n))
//	{
//		printf("找不到！！");
//	}
//	else
//	{
//		printf("找到了，是第%d个元素，下标为：%d", QSQ(arr, n) + 1, QSQ(arr, n));
//	}
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	int lift = 0;
//	int right = (sizeof(arr1) / sizeof(arr1[0])) - 1;
//	int mid = 0;
//	scanf("%d", &k);
//	
//	for (; lift <= right;)
//	{
//		mid = (lift + right) / 2;
//		if (arr1[mid] < k)
//		{
//			lift = mid + 1;
//		}
//		else if (arr1[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("%d", mid);
//			break;
//		}
//	}
//	if (lift > right)
//	printf("找不到！！");
//
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void load(int arr[], int sub)
//{
//	int i = 0;
//	for (i = 0; i <= sub; i += 1)
//	{
//		arr[i] = rand() % 1000;
//	}
//}
//
//void sort(int arr[], int sub)
//{
//	int i = 0;
//	int j = 0;
//	int s = 0;
//	for (i = sub; i >= 0; i -= 1)
//		for (j = i; j < sub; j += 1)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				s = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = s;
//			}
//		}
//}
//
//int sear(int k, int arr[], int sub)
//{
//	int lift = 0;
//	int right = sub;
//	int mid = 0;
//	for (; lift <= right;)
//	{
//		mid = (lift + right) / 2;
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			lift = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[99999] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int sub = sz - 1;
//	int i = 0;
//	int k = 0;
//
//	srand((unsigned)time(NULL));
//	load(arr, sub);
//	sort(arr, sub);
//	puts("请输入");
//	scanf("%d", &k);
//	i = sear(k, arr, sub);
//	if (-1 == i)
//	{
//		puts("找不到！！\n");
//	}
//	else
//		printf("找到了！！\nsub = %d", i);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void trans(int arr[], int j)
{
	int n = 0;
	n = arr[j];
	arr[j] = arr[j - 1];
	arr[j - 1] = n;
}
//void sort(int sz, int arr[])
//{
//	int i = 0;
//	int j = 0;
//	int s = 0;
//	int sub = sz - 1;
//	for (i = sub; i >= 0; i -= 1)
//		for (j = i; j < sub; j += 1)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				s = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = s;
//			}
//		}
//}
//void sort(int sz, int arr[])
//{
//	int sub = sz - 1;
//	int count = 1;
//	int cp = 1;
//	int j = 0;
//	if (0 == sz % 2)
//	{
//	up:
//		count = cp;
//		for (j = 1; j <= sub; j += 2)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				trans(arr, j);
//				count += 1;
//			}
//		}
//		for (j = 2; j < sub; j += 2)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				trans(arr, j);
//				count += 1;
//			}
//		}
//		if (count != cp)
//		{
//			goto up;
//		}
//	}
//	else
//	{
//	upw:
//		count = cp;
//		for (j = 1; j < sub; j += 2)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				trans(arr, j);
//				count += 1;
//			}
//		}
//		for (j = 2; j <= sub; j += 2)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				trans(arr, j);
//				count += 1;
//			}
//		}
//		if (count != cp)
//		{
//			goto upw;
//		}
//
//	}
//}

void stu(int arr[], int sz)
{
	int sub = sz - 1;
	int i = 0;
	for (i = 0; i <= sub; i += 1)
	{
		arr[i] = rand();
	}
}

void my_printf(int arr[], int sz)
{
	int i = 0;
	int sub = sz - 1;
	for (i = 0; i <= sub; i += 1)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int i = 0;
	int arr[99999 + 1] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned)time(NULL));
	stu(arr, sz);
	my_printf(arr, sz);
	sort(sz, arr);
	my_printf(arr, sz);
	return 0;
}