#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	for (;;)
//	{
//
//
//	}
//	return 0;
//}
//int welcome()
//{
//	puts("欢迎来到我制作的菜单!!\n");
//	puts("*****查找按——1******\n");
//	puts("*****插入按——2******\n");
//	puts("*****删除按——3******\n");
//	puts("*****退出请按下——0**\n");
//	return 0;
//}
//#include<stdio.h>
//#include<windows.h>
//int welcome()
//{
//	puts("欢迎来到我制作的临时菜单！！\n\n按下1，打印你好！！\n按下0，退出程序！！\n");
//	return 0;
//}
//int main()
//{
//	int j = 0;
//	for (;;)
//	{
//		welcome();
//		scanf("%d", &j);
//		system("cls");
//		if (0 == j)
//		{
//			puts("即将退出！！");
//			system("pause");
//			system("cls");
//			break;
//		}
//		if (1 == j)
//		{
//			puts("你好！！");
//			system("pause");
//			system("cls");
//		}
//		if (0 != j && 1 != j)
//		{
//			puts("输入错误，请重新输入！！");
//			system("pause");
//			system("cls");
//		}
//					
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (9 == i % 10)
//		{
//			count++;
//		}
//		if (9 == i / 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	printf("%d", 5 % 4);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char i = 0;
//	char j = 0;
//	double sum = 0.0;
//	for (i = 1; i <= 100; i++, ++i)
//	{
//		sum += 1.0 / i;
//	}
//	for (j = 2; j <= 100; j++, ++j)
//	{
//		sum -= 1.0 / j;
//	}
//	printf("sum = %lf", sum);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char i = 0;
//	double sum = 0.0;
//	int pendulum = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += pendulum * 1.0 / i;
//		pendulum = -pendulum;
//	}
//	printf("sum = %lf", sum);
//	return 0;
//}

//#include<stdio.h>
//
//
//int main()
//{
//	int arr[] = { -1, -2, 4, 6, 9, -99, 100, 89, 7, 10 };
//	int cpe = arr[0];
//	int i = 0;
//	for (i = 1; i < 10; i++)
//	{
//		if (cpe < arr[i])
//		{
//			cpe = arr[i];
//		}
//	}
//	printf("%d", cpe);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 9; i >= 1; i--)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-2d| ", j, i, i * j);
//		}
//		puts("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int lift = 0;
//	int right = sizeof(arr) - 1;
//	int mid = (lift + right) / 2;
//	int k = 0;
//	scanf("%d", &k);
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
//		{
//			break;
//		}
//	}
//	if (k == arr[mid])
//	{
//		printf("找到了！！\n是第%d个元素\n", mid + 1);
//	}
//	else
//	{
//		printf("找不到！！\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<Windows.h>
//int main()
//{
//	char input[20] = { 0 };
//	int i = 0;
//	
//	for (i = 1; i <= 3; i++)
//	{
//		puts("请输入密码");
//		scanf("%s", input);
//		if (strcmp(input, "123456") == 0)
//		{
//			puts("密码正确，你太强了！！\n");
//			break;
//		}
//		else
//		{
//			system("cls");
//			printf("你输错了！！\n还剩%d次机会！！\n", 3 - i);
//		}
//
//	}
//	if (i <= 3)
//	{
//		puts("登录成功！！\n");
//		system("pause");
//		system("cls");
//	}
//	else
//	{
//		system("cls");
//		puts("三次输入密码均错误！！\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 3; i++)
//	{
//		puts("haha!!");
//		continue;
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	char arr[20] = {0};
	scanf("%s", arr);
	while (getchar() != '\0');
	return 0;
}