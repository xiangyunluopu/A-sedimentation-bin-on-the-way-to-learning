#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list_node {
	int a;
	int b;
	int c;
	struct list_node* next;
}LLL;


int main() {
	srand((unsigned int)time(NULL));   // 利用时间戳来作为随机数生成函数的起点
	LLL* head = (LLL*)malloc(sizeof(LLL));
	int i = 0;
	int j = 0;
	int L = 0;
	int num1 = 0;
	int num2 = 0;
	LLL* A = NULL;
	LLL* B = NULL;
	LLL* C = NULL;
	LLL* D = NULL;
	LLL* p = NULL;
	LLL* s = NULL;
	head->next = NULL;
	for (;;) {
		j = rand() % 21;
		if (2 < j && j <= 20) {
			break;
		}
	}
	A = head;
	for (i = j; i > 0; i -= 1) {
		B = (LLL*)malloc(sizeof(LLL));
		num1 = rand() % 11;
		num2 = rand() % 11;
		B->a = num1;
		B->b = num2;
		B->c = (num1 + num2);
		B->next = A->next;
		A->next = B;
		A = A->next;
	}
	A = NULL;
	B = NULL;
	// 随机结点个数与随机值都生成完毕
	// 打印
	A = head->next;
	for (L = 0; A != NULL; A = A->next) {
		printf("%3d", A->c);
		L += 1;
	}
	A = NULL;
//                                                    A        B         C        D
	// [1][->1] [2][->3] [3][->4] [4][->5] [5][->6] [6][->7] [7][->8] [8][NULL]  NULL
	for (i = 0; i < L - 1; i += 1) {
		A = head;
		B = head->next;
		C = B->next;
		D = C->next;
		for (j = 0 + i; j < L - 1; j += 1) {
			if (B->c > C->c) {
				A->next = C;
				C->next = B;
				B->next = D;
				B = A->next;
				C = B->next;
			}
			if (j < L - 2) {
				D = D->next;
			}
			C = C->next;
			B = B->next;
			A = A->next;
		}
	}
	A = NULL; B = NULL; C = NULL; D = NULL;
	printf("\n\n");
	A = head->next;
	for (L = 0; A != NULL; A = A->next) {
		printf("%3d", A->c);
		L += 1;
	}
	A = NULL;
	return 0;
}

//#include <stdio.h>
//
//int main() {
//
//	int arr[7] = { 2, 4, 8, 32, 0, 9, 7 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	for (j = 7; j > 0; j -= 1) {
//		for (i = 0; i < j - 1; i += 1) {
//			if (arr[i] > arr[i + 1])
//			{
//				n = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = n;
//			}
//		}
//	}
//
//
//	return 0;
//}
