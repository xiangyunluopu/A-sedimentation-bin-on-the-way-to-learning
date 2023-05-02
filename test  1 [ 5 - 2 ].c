#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main(void) {
//
//	{
//		int a = 4;
//	}
//	printf("%d", a);
//	return 0;
//}

#include <stdio.h>

int main(void) {
	int i = 0;
	int arr[10] = { 1 };
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i += 1) {
		printf(" %d", arr[i]);
	}
	printf("\n");
	return 0;
}