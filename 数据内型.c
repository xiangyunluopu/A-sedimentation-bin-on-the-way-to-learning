#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main(void)
//{
//	//char 1 ���ֽ�
//	// int 4 ����
//	// float ����С��
//	char ch1 = 0;
//	int a = 0;
//	float f1 = 0.0;
//	int sz = 0;
//	
//	printf("%d\n", sizeof(char)); 
//	printf("%d\n", sizeof(a));
//	sz = sizeof(f1);
//	printf("%d\n", sz);
//	return 0;
//}

//int main(void)
//{
//	char ch = 'w';
//	printf("%c\n", ch);
//	printf("%c\n", 'p');
//	return 0;
//}
//
//�ֲ�����
//ȫ�ֱ���

//void W_W(void)
//{
//	printf("%d", a);
//}
//
//int b = 7;
//
//void W_W(void)
//{
//	printf("%d", b);
//}
//
//int main(void)
//{
//	{
//		int a = 0;
//		printf("%d\n", a);
//	}
//	printf("%d\n", b);
//	W_W();
//	return 0;
//}

//int main(void)
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	scanf("%d %d", &num1, &num2);// & ȡ��ַ����
//	sum = num1 + num2;
//	printf("sum = %d\n", sum);
//	return 0;
//}

//void W_W(void)
//{
//	const int a = 0;                     //
//	int* p = &a;                         // [88888] [0]
//	*p += 1; // a = a + 1;               // [88888] [1]
//	printf("a = %d\n", a);
//}
//
//int main(void)
//{
//	
//	W_W();
//	W_W();
//	W_W();
//}

//int main()
//{
//    char arr1[] = "bit";
//    char arr2[] = { 'b', 'i', 't' };
//    char arr3[] = { 'b', 'i', 't', '\0' };
//    int sz = 0;
//    printf("%s\n", arr1);
//    printf("%s\n", arr2);
//    printf("%s\n", arr3);
//    sz = sizeof(arr1) / sizeof(arr1[0]);
//    printf("%d\n", sz);
//    sz = sizeof(arr2) / sizeof(arr2[0]);
//    printf("%d\n", sz);
//    sz = sizeof(arr3) / sizeof(arr3[0]);
//    printf("%d\n", sz);
//    return 0;
//}

//int main()
//{                       
//    printf("c:\code\test.c\n"); // \ ת���ַ�'\'
//    return 0;
//}
//int main()
//{
//    //����1������Ļ�ϴ�ӡһ��������'����ô����
//    //����2������Ļ�ϴ�ӡһ���ַ������ַ�����������һ��˫���š�����ô����
//    printf("%c\n", '\'');
//    printf("%s\n", "\"");
//    return 0;
//}

//int main()
//{
//    printf("%d\n", strlen("abcdef")); // 6
//    // \62��������һ��ת���ַ�
//    printf("%d\n", strlen("c:\test\628\test.c"));
//    return 0;
//}

//int main()
//{
//    int coding = 0;
//    printf("���ȥ�ô����𣿣�ѡ��1 or 0��:>");
//    scanf("%d", &coding);
//    if (coding == 1)
//    {
//        printf("��֣�����к�offer\n");
//    }
//    else
//    {
//        printf("�������ؼ�������\n");
//    }
//    return 0;
//}

//int main()
//{
//    printf("�������\n");
//    int line = 0;
//    while (line <= 20000)  // 0 Ϊ�� ��0 Ϊ��
//    {
//        line++;
//        printf("��Ҫ����Ŭ���ô��� + %d\n", line);
//    }
//    if (line > 20000)
//        printf("��offer\n");
//    return 0;
//}

//int add(int x, int y) // �Ͳ�
//{
//	int sum = 0;
//	sum = x + y;
//	return sum;
//}
//
//int main(void)
//{
//	int a = 0;
//	int b = 0;
//	int sum = 0;
//	scanf("%d %d", &a, &b);
//	sum = add(a, b); // ʵ��
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int main(void)
//{
//	int i = 0;
//	int sz = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
//	sz = sizeof(arr) / sizeof(arr[0]);
//	while (i < sz)
//	{
//		printf("%d\n", arr[i]);
//		i += 1;
//	}
//	return 0;
//}

//static int b = 0;

//void O_O(void)
//{
//	static int a = 0;
//	printf("%d\n", a);
//	a += 1;
//}
//
//int main(void)
//{
//	int i = 0;
//	/*
//	printf("%d\n", ++i);
//	printf("%d\n", i);*/
//	/*while (i++ < 10)
//	{
//		O_O();
//	}*/
//
//	return 0;
//}

#include "test1.h"

int main(void)
{
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf("%d%d", &a, &b);
	sum = add(a, b);
	printf("sum = %d\n", sum);
	return 0;
}