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
//	puts("��ӭ�����������Ĳ˵�!!\n");
//	puts("*****���Ұ�����1******\n");
//	puts("*****���밴����2******\n");
//	puts("*****ɾ��������3******\n");
//	puts("*****�˳��밴�¡���0**\n");
//	return 0;
//}
//#include<stdio.h>
//#include<windows.h>
//int welcome()
//{
//	puts("��ӭ��������������ʱ�˵�����\n\n����1����ӡ��ã���\n����0���˳����򣡣�\n");
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
//			puts("�����˳�����");
//			system("pause");
//			system("cls");
//			break;
//		}
//		if (1 == j)
//		{
//			puts("��ã���");
//			system("pause");
//			system("cls");
//		}
//		if (0 != j && 1 != j)
//		{
//			puts("����������������룡��");
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
//		printf("�ҵ��ˣ���\n�ǵ�%d��Ԫ��\n", mid + 1);
//	}
//	else
//	{
//		printf("�Ҳ�������\n");
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
//		puts("����������");
//		scanf("%s", input);
//		if (strcmp(input, "123456") == 0)
//		{
//			puts("������ȷ����̫ǿ�ˣ���\n");
//			break;
//		}
//		else
//		{
//			system("cls");
//			printf("������ˣ���\n��ʣ%d�λ��ᣡ��\n", 3 - i);
//		}
//
//	}
//	if (i <= 3)
//	{
//		puts("��¼�ɹ�����\n");
//		system("pause");
//		system("cls");
//	}
//	else
//	{
//		system("cls");
//		puts("����������������󣡣�\n");
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