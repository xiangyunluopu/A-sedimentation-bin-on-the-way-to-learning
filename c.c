#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 1;
	int n = 0;
	int ret = 1;
	int ret2 = 0;
	for (n = 1; n <=4 ; n++)
	{
			ret = i * ret;
	
		ret2 = ret + ret2;
	}
	printf("%d", ret2);
	return 0;
}
//int main()
//{
//	int n = 1;
//	int i = 1;
//	int j = 0;
//	int c = 1;
//	int s = 1;
//	int sum = 0;
//	while (n <= 10)
//	{
//		i = 1; c = 1;
//		while (i <= n)
//		{
//			j = i * c;
//			c = j;
//			i++;
//		}
//		sum = c * s;
//		s = sum;
//		n++;
//	}
//	printf("%d",sum);
//	return 0;
//}
//int main()
//{
//	int long long i = 1;
//	int long long n = 1;
//	int long long a = 1;
//	int long long b = 0;
//	int long long c = 1;
//	int long long d = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		for (i = 1,a = 1;i <= n;i++)
//		{
//			b = a * i;
//			a = b;
//		}
//		d = a * c;
//		c = d;
//		
//
//	}
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int n = 0;
//	int a = 1;
//	int b = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		b = i * a;
//		a = b;
//
//	}
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int ch;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	char i[20] = { "hello,world!" };
//	puts(i);
//	
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	while (i != EOF)
//	{
//		 i = getchar();
//		 putchar(i);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	while (i <= 9)
//	{
//		i++;
//		if (6 == i)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}


//int main()
//{
//	int i = 0; int n = 0; int m =9 ;
//	switch (i)
//	{
//		case 0:
//		{
//			switch (n)
//			{
//				case 0:
//				{
//					m++; n++;
//					break;
//				}
//				default:
//				{
//					break;
//				}
//			}
//			break;
//		}
//		default:
//		{
//			break;
//		}
//	}
//	printf("%d %d\n", n, m);
//	return 0;
//}
//int main()
//{
//	int i;
//	int n;
//	printf("�齱��?\nyes�밴1\nno�밴0\n");
//	scanf("%d",&i);
//	if (1 == i)
//	{
//		printf("��������ѡ��1����0��");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 0:
//		{
//			printf("һ�Ƚ�\n");
//			return n;
//			break;
//
//		}
//		case 1:
//		{
//			printf("лл�ݹ�\n");
//			return n;
//			break;
//
//
//		}
//		default:
//		{
//			printf("�������\n");
//			return n;
//			break;
//		}
//
//		}
//	}
//	else if (0 == i)
//	{
//		printf("�ð�\n");
//	}
//	if (i != 1 && i != 0)
//	{
//		printf("�������\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	int a, b;
//	int c;
//	
//	while (9)
//	{
//		printf("����Ҫ������0����no,1����yes��\n");
//		scanf("%d", &i);
//		switch (i)
//		{
//		case 0:
//			printf("�ðɣ�\n");
//			break;
//		case 1:
//		{
//
//
//			printf("������һ������,0����+��1����-��2����*��3����/,��������һ������\n");
//			scanf("%d %d %d", &a, &c, &b);
//			
//			
//			
//			if (0 == c)
//				printf("a + b = %d\n", a + b);
//			else if (1 == c)
//				printf("a - b = %d\n", a - b);
//			else if (2 == c)
//				printf("a * b = %d\n", a * b);
//			else if (3 == c)
//				printf("a / b = %d\n", a / b);
//			else
//				printf("������󣡣�\n");
//
//
//
//			break;
//		}
//		default:
//			printf("�������\n");
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	switch (a)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("�����գ�");
//			break;
//		case 6:
//		case 7:
//			printf("��Ϣ�գ���");
//			break;
//		default:
//			printf("������Χ��������1~7��");
//	}
//	return 0;
//}