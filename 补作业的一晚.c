#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//void bit(int num) {
//	int i = 0;
//	printf("ÆæÊý>:");
//	for (i = 31; i >= 0; i -= 2) {
//		printf("%d ", 1 & (num >> i));
//	} printf("\n");
//	printf("Å¼Êý>:");
//	for (i = 32; i >= 1; i -= 2) {
//		printf("%d ", 1 & (num >> i));
//	} printf("\n");
//}


int main(void) {
	int num = 0;
	scanf("%d", &num);
	bit(num);
	return 0;
}