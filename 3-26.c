#define _CRT_SECURE_NO_WARNINGS 1
//#include<string.h>
//
//int main()
//{
//	char arr1[] = "123456789";
//	strcpy(arr1, "****");
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char arr[] = "hello world";
//	printf("%s\n", arr);
//	memset(arr + 6, '*', 5);
//	printf("%s\n", arr);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	scanf("%d%d", &a, &b);
//	ret = is_big(a, b);
//	printf("%d", ret);
//
//	return 0;
//}
//
//
//int is_big(int a, int b)
//{
//	if (a > b)
//	{
//		return a;
//	}
//	else
//		return b;
//
//}

//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	printf("a ->:");
//	scanf("%d", &a);
//	printf("b ->:");
//	scanf("%d", &b);
//	ret = is_big(a, b);
//	if (ret == 0)
//	{
//		printf("max = %d", a);
//	}
//	else if (ret == 1)
//	{
//		printf("max = %d", b);
//	}
//	else
//	{
//		printf("max = a = b = %d", a);
//	}
//	return 0;
//}
//
//int is_big(int a, int b)
//{
//	if (a > b)
//	{
//		return 0;
//	}
//	else if (b > a)
//	{
//		return 1;
//	}
//	else
//	{
//		return 2;
//	}
//}
//#include<stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("a ->:"); scanf("%d", &a);
//	printf("b ->:"); scanf("%d", &b);
//	Exge_valb(&a, &b);
//	printf("a = %d   b = %d", a, b);
//	return 0;
//}
//
//void Exge_valb(int* px, int* py)
//{
//	int ret = 0;
//	
//		ret = *px;
//		*px = *py;
//		*py = ret;
//}


//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		j = is_prime(i);
//		if (0 == j)
//		{
//			printf("%d ", i);
//			n++;
//		}
//	}
//	printf("\n%d\n", n);
//	return 0;
//}
//
//int is_prime(int i)
//{
//	int j = 0;
//	if (0 == i % 2)
//	{
//		return 1;
//	}
//	for (j = 2; j <= sqrt(i); j++)
//	{
//		if (0 == i % j)
//		{
//			return 1;
//		}
//	}
//	return 0;
//
//}

//int main()
//{
//	int j = 0;
//	scanf("%d", &j);
//	printf("%d", j % 2);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int i;
//	int count = 0;
//	int ret = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		ret = is_leap_year(i);
//		if (0 == ret)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}
//
//int is_leap_year(int i)
//{
//	if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//	{
//		return 0;
//	}
//	else
//		return 1;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = 0;
//	int k = 0;
//	int a = 0;
//	sz = sizeof(arr1) / sizeof(arr1[0]) - 1;
//	
//	scanf("%d", &k);
//	a = binary_search(sz, arr1, k);
//	if (-1 == a)
//	{
//		printf("找不到！！");
//	}
//	else
//	{
//		printf("找到了，下标为%d", a);
//	}
//	return 0;
//}
//
//int binary_search(int sz, int arr1[], int k)
//{
//	int lift = 0;
//	int right = sz;
//	int mid = 0;
//	for (; lift <= right;)
//	{
//		mid = ( lift + right ) / 2;
//		if (arr1[mid] < k)
//		{
//			lift += 1;
//		}
//		else if (arr1[mid] > k)
//		{
//			right -= 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//#include<stdio.h>
//
//int main()
//{
//	printf("%d\n", printf("%d\n", printf("%d\n", 43)));
//	return 0;
//}

//#include<stdio.h>
//
//void ddb()
//{
//	printf("pp果\n");
//
//}
//
//
//void ppi()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		ddb();
//	}
//}
//int main()
//{
//	ppi();
//	return 0;
//}

//#include <stdio.h>

//void ADD(int* num)
//{
//	(*num)++;
//}
//
//int main()
//{
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < 3; i++)
//	{
//		ADD(&num);
//	}
//	printf("%d", num);
//
//
//}
//
//void mmm()
//{
//	printf("pp果\n");
//}
//
//void www()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		mmm();
//	}
//	
//
//}
//
//int main()
//{
//	www();
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	printf("pp果");
//	main();
//	return 0;
//}
//
//#include<stdio.h>
//
//void print(int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);
//	}
//	printf("%d ", num % 10);
//
//}
////(1234)
////(123) 4
////(12) 3 4
////(1) 2 3 4
////如何才能打印 4 3 2 1
//int main()
//{
//	int num = 1234;
//	print(num);
//	return 0;
//}

//#include<stdio.h>
//
//int my_strlen1(char* p)
//{
//	int ret = 0;
//	for (; *p != '\0'; )
//	{
//		ret += 1;
//		p += 1;
//	}
//	return ret;
//}
//
//int my_strlen2(char* p)
//{
//	if (*p != '\0')
//	{
//		return 1 + my_strlen2(p + 1);
//	}
//	else
//	{
//		return 0;
//	}
//
//
//}
//
//
//int main()
//{
//	char arr[] = "0123456789";
//	int ret = 0;
//	ret = my_strlen2(arr);
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<Windows.h>
//int Fac1(int n)
//{
//	int ret = 1;
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int Fac2(int n)
//{
//	if (n > 1)
//	{
//		return n * Fac2(n - 1);
//	}
//	else
//	{
//		return 1;
//	}
//
//}
//
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n);
//	printf("n! = %d", ret);
//
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "欢迎来到物联网2201";
//	char arr2[] = "******************";
//	int lift = 0;
//	int right = strlen(arr1) - 1;
//	for (; lift <= right; lift++, right--)
//	{
//		arr2[lift] = arr1[lift];
//		arr2[right] = arr1[right];
//		system("cls");
//		printf("%s", arr2);
//		Sleep(500);
//
//	}
//	printf("\n\n\n\n\n\n\n\n\n");
//
//}

//#include<stdio.h>
//
//int my_strlen(char* p)
//{
//	if (*p != '\0')
//	{
//		return 1 + my_strlen(p + 1);
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//
//
//int main()
//{
//	char arr[] = "0123456789";
//	printf("%d", my_strlen(arr));
//	return 0;
////}
//#include<stdio.h>
////n = n-1 + n-2
//int MMp(int n)
//{
//	if (n > 2)
//	{
//		return MMp(n - 1) + MMp(n - 2);
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	for (;;)
//	{
//		scanf("%d", &n);
//		printf("%d", MMp(n));
//	}
//	return 0;
//}
































