#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	for (; n > 2; n--)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
////1 1 2 3 5 8 13
////        a b c
//
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	printf("%d\n", Fib(k));
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		main();
//	}
//
//	return 0;
//}
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//
//void mizer()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", rand() % 100);
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	mizer();
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int www(int i)
//{
//	char arr[] = { '6' };
//	if (i > 0)
//		printf("%d\n", www(i - 1));
//	else
//		return strlen(arr);
//}

//int main()
//{
//	int i = 0;
//	
//
//	for (i = 1; i <= 10; i++)
//	{
//		www(i);
//	}
//
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char ar[] = { '2','3'};
//	printf("%d", strlen(ar));
//	return 0;
//
//}

//#include<stdio.h>
//#include<string.h>
//
//
//int sunn3()
//{
//	char arr3[] = { '6' };
//	return strlen(arr3);
//}
//int sunn2()
//{
//	char arr2[] = { '6' };
//	return strlen(arr2) + sunn3();
//}
//int sunn1()
//{
//	char arr1[] = { '6' };
//	return strlen(arr1) + sunn2();
//}
//
//int sunn()
//{
//	char arr[] = { '6' };
//	return (strlen(arr) + sunn1()) % 100;
//}
//
//int main()
//{
//	int ret = 0;
//	ret = sunn();
//	printf("%d", ret);
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr1[i]);
//
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr1[][4] = { {1, 2, 3, },{5, 6},{7} };
//	int i = 0;
//	int j = 0;
//	for (j = 0; j < 4; j++)
//	{
//		for (i = 0; i < 3; i++)
//		{
//			printf("arr1[%d][%d] = %d ", i, j, arr1[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr[3][4] = { {1,2,3,4},{1,2,3,4},'1234'};
//	printf("%d", strlen(arr));
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p ", i, j, &arr[i][j]);
//
//		}
//		puts("\n");
//	}
//	return 0;
//}
//#include<stdio.h>

//int Fab(int k)
//{
//	
//	int c = 0;
//	int b = 1;
//	int a = 1;
//
//	if ( k > 3 )
//	{
//		return Fab(k - 1);
//	}
//	else if (3 == k)
//	{
//		return 2;
//	}
//	else
//	{
//		return 1;
//	}
//
//}
//1 1 2 3 5 8
//  a b c
//#include<stdio.h>
//int Fab(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (n > 2)
//	{
//		for (; n > 2; n--)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int k = 0;
//	for (;;)
//	{
//		scanf("%d", &k);
//		printf("%d\n", Fab(k));
//	}
//	return 0;
//}
