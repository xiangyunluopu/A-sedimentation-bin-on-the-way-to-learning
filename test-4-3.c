#define _CRT_SECURE_NO_WARNINGS 1

//

//#include<stdio.h>
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a = %d, b = %d\n", a, b);
//	/*a = a + b;
//	b = a - b;
//	a = a - b;*/
//	/*a = a * b;
//	b = a / b;
//	a = a / b;*/
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a = %d, b = %d\n", a, b);
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int i = 0;
//	int count = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i += 1)
//	{
//		int j = 0;
//		count = 0;
//		for (j = 0; j < sz; j += 1)
//		{
//			if (arr[i] == arr[j])
//			{
//				count += 1;
//			}
//
//		}
//		if (1 == count)
//		{
//			printf("��������%d", arr[i]);
//		}
//	}
//
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int i = 0;
//	int ret = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i += 1)
//	{
//		ret ^= arr[i];
//
//
//	}
//	printf("��������%d\n", ret);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<Windows.h>
//#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("Shutdown /s /t 60");
//	a:
//	printf("��ĵ���һ�����ڽ���ע������\n");
//	printf("����������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("Shutdown /a");
//	}
//	else
//	{
//		goto a;
//	}
//
//
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<Windows.h>
//
//int main()
//{
//	char input[20] = { 0 };
//	system("Shutdown /s /t 60");
//	printf("��ĵ��Խ���60s�ڱ�ע����\n");
//	
//	for (;;)
//	{
//		printf("����������ȡ��ע��\n");
//		scanf("%s", input);
//		
//		if (strcmp(input, "������") == 0);
//		{
//			system("Shutdown /a");
//			break;
//		}
//			
//		
//	}
//
//	return 0;
//}