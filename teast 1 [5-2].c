#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h> 
//
//int main(void) {
//	int arr[10] = { 13, 89, 3, 787, 3, 2, 34, 45, 56, 67 };
//	int i = 0;
//	int j = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int tmp = 0;
//	int flag = 1;
//	for (;sz > 1; sz -= 1) {
//		for (i = 0; i < sz - 1; i += 1) {
//			if (arr[i] > arr[i + 1]) {
//				tmp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag) {
//			break;
//		}
//	}
//	sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i += 1) {
//		printf(" [%d]", arr[i]);
//		if (sz - 1 == i) {
//			printf("\n");
//		}
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//
//void init(int* arr, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i += 1) {
//		*(arr + i) = 0;
//	}
//}
//
//void print(int* arr, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i += 1) {
//		printf(" %d", *(arr + i));
//	}
//	printf("\n");
//}
//
//void push(int* arr, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i += 1) {
//		*(arr + i) = i;
//	}
//}
//
//void reverse(int arr[], int sz) {
//	int lift = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; lift < right;) {
//		tmp = arr[lift];
//		arr[lift] = arr[right];
//		arr[right] = tmp;
//		i += 1;
//		lift += 1;
//		right -= 1;
//	}
//}
//
//int main(void) {
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr, sz);
//	print(arr,sz);
//	push(arr, sz);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int arr[5] = { 0 };
//	int i = 0;
//	short* p = (short*)arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i += 1) {
//		arr[i] = i;
//	}
//	for (i = 0; i < sz; i += 1) {
//		printf(" %d ", arr[i]);
//	}
//	for (i = 0; i < 6; i += 1) {
//		*p = 0;
//		p += 1;
//	}
//	for (i = 0; i < sz; i += 1) {
//		printf(" %d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>

//int q;
//
//int main(void) {
//	printf("%d\n", q);
//	return 0;
//}

//#include <stdio.h>
//
//int main(void) {
//	int i = -1;
//	unsigned int j = -1;
//	printf("%u",j);
//	return 0;
//}

