#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int c = 0;
	for (i = 101; i <= 200; i += 2)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}

		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
			c++;
		}
	}
	printf("\n\n%d\n", c);
	return 0;
}
//int main()
//{
//	int i = 0;
//	int c = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (0 == i % 4 && 0 != i % 100)
//		{
//			printf("%d ", i); c++;
//		}
//		if (0 == i % 400)
//		{
//			printf("%d ", i); c++;
//		}
//	}
//	printf("\n%d\n", c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	if (m < n)
//	{
//		int t = 0;
//		t = m;
//		m = n;
//		n = t;
//	}
//	for (; r = m % n;)
//	{
//		m = n;
//		n = r;
//	}
//	printf("\n这两个数的最大公因数为%d\n", n);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int c = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (0 == i % 3)
//		{
//			printf("%d ", i);
//			c++;
//		}
//	}
//	printf("\n%d\n", c);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int c = 0;
//	for (i = 3; i <= 100; i += 3)
//	{
//		printf("%d ", i); c++;
//	}
//	printf("\n%d\n", c);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int t = 0;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}