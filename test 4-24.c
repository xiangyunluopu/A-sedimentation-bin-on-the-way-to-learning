#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main() {
//	int a = 0;
//	int* p1 = &a;
//	printf("%p", p1);
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(long*));
//	printf("%d\n", sizeof(double*));
//	// 都为四个字节 但是加1，跳动步数不一样
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	int a = 0;
//	int* intp1 = &a;
//	char* chp1 = &a;
//	printf("%p\n", intp1);
//	printf("%p\n", intp1 + 1);
//	printf("%p\n", chp1);
//	printf("%p\n", chp1 + 1);
//	printf("%p\n", chp1 + 4);
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	int a[10] = { 0 };
//	int* intp1 = &a;
//	char* chp1 = &a;
//	int i = 0;
//	/*for (i = 0; i < 10; i += 1) {
//		*(intp1 + i) = 1;
//		
//	}*/
//	for (i = 0; i < 10; i += 1) {
//		*(chp1 + 4 * i) = 1;
//	}
//	for (i = 0; i < 10; i += 1) {
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int* test() {
//	int a = 20;
//	int* intp = &a;
//	return intp;
//}
//
//int main() {
//	int* tp1 = test();
//	return 0;
//}

//int main() {
//	int* p;
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int* tp1 = arr;
//	int i = 0;
//	for (i = 0; i < 11; i += 1) {
//		tp1 += 1;
//	}
//	return 0;
//}