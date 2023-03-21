#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr1[] = "*********************";
	char arr2[] = "welcome to 物联网2201";
	int lift = 0;
	int right = strlen(arr1) - 1;
	for (;lift <= right;right--, lift++)
	{
		system("cls");
		arr1[lift] = arr2[lift];
		arr1[right] = arr2[right];
		printf("%s", arr1);
		Sleep(500);

	}
	return 0;
}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char ch[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int lift = 0;
//	int right = sizeof(ch)/sizeof(ch[0]) - 1;
//	
//	int k = 0;
//	int mid = (lift + right) / 2;
//	scanf("%d", &k);
//	for (; lift <= right;)
//	{
//		mid = (lift + right) / 2;
//		
//		if (ch[mid] < k)
//		{
//			lift = mid + 1;
//			
//		}
//		else if (k < ch[mid])
//		{
//			right = mid - 1;
//			
//		}
//		else
//		{
//			printf("找到了下标为:%d", mid);
//			break;
//		}
//	}
//	if (lift > right)
//	{
//		printf("找不到！！");
//	}
//	return 0;
//}




//#include <stdio.h>
//#include <Windows.h>
//int main()
//{
//	
//	for (;;) 
//	{
//		printf("\a");
//	
//	}
//	
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//int main()
//{
//	char arr1[] = { "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   " };
//	char arr2[] = { "                                                                        " };
//	char arr3[] = { "                                                                        " };
//	int lift1 = 0;
//	int right = strlen(arr1) - 1;
//	int lift2 = -1;
//	for (; lift2 < right; lift1++, lift2 = lift2 + 1)
//	{
//		arr2[lift1] = arr1[lift1];
//		arr2[lift1 + 1] = arr1[lift1 + 1];
//		arr2[lift1 + 2] = arr1[lift1 + 2];
//		arr2[lift2] = arr3[lift2];
//		printf("%s", arr2);
//		
//		Sleep(500);
//		system("cls");
//
//	}
//	return 0;
//}





//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//int delay(unsigned int time)
//{
//	unsigned int i = 0;
//	unsigned char j = 0;
//	for (i = 0; i < time; i++)
//	{
//		Sleep(1);
//	}
//	return 0;
//}
//int main()
//{
//	for (;;)
//	{
//		printf("!!");
//		Sleep(1000);
//		system("cls");
//		Sleep(1000);
//		
//
//	}
//	return 0;
//}