#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
	char arr1[] = "welcom to 物联网2201 ！！！！！！！！";
	char arr2[] = "*************************************";
	char lift = 0;
	int right = strlen(arr1) - 1;
	while (lift <= right)
	{
		arr2[lift] = arr1[lift];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		lift++; right--;
		if (lift <= right)
		system("cls");
		
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
}

//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	char turn[] = "123456";
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s",&password);
//		if (strcmp(password, turn) == 0)
//		{
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//
//	}
//	if (3 == i)
//	{
//		printf("三次密码均输入错误\n");
//	}
//	if (i < 3)
//	{
//		printf("恭喜你密码正确！！！！！！！\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	char lift = 0;
//	char right = sizeof(arr) / sizeof(arr[0]) - 1;
//	char mid = 0;
//	
//	while (lift <= right)
//	{
//	    mid = (lift + right) / 2;
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			lift = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为：%d\n", mid);
//			break;
//
//		}
//
//	}
//	if (lift > right)
//	{
//		printf("找不到");
//	}
//	return 0;
//}
//int main()
//{
//	char i = 0;
//	do
//	{
//		printf("%d\n", i);
//		
//		if (4 == i)
//		{
//			continue;
//		}
//		i++;
//
//	} while (i < 10);
//	
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret[10] = { 0 };
//	while (i <= 10)
//	{
//		ret[n] = i;
//		i++;
//		n++;
//	}
//	i = 0;
//	n = -1;
//	do
//	{
//		i++;
//		n++;
//		printf("%d ", ret[n]);
//
//	} while (i < 10);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	/*for (;;)
//	{
//		;
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret[10] = { 0 };
//	while (i <= 10)
//	{
//		ret[n] = i;
//		i++;
//		n++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", ret[i]);
//
//	}
//	return 0;
//}
//int main()
//{
//	char i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//		{
//			continue;
//		}
//		printf("%d ", i);
//
//	}
//	return 0;
//}

//int main()
//{
//	char i = 0;
//	char n = ' ';
//	for (i = 1; i <= 9; i++,n++)
//	{
//		printf("%c\n", n);
//
//	}
//	return 0;
//}
//int main()
//{
//
//	char i[20] = { 0 };
//	scanf("%s", &i);
//	char ch[20];
//	while (getchar() != '\n')
//	{
//		;
//	}
//	printf("%s\n", i);
//	scanf("%s", &ch);
//	printf("%s\n", ch);
//	
//
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int ret2 = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = i * ret;
//		ret2 = ret + ret2;
//	}
//	printf("%d\n", ret2);
//	
//	
//	
//	printf("%d", ret);
//	return 0;
//}