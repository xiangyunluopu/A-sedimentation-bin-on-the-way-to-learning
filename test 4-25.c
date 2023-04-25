#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main() {
//	int* pt1;
//	return 0;
//}

//int* test() {
//	int a = 0;
//	return &a;
//}
//
//int main() {
//	int* pt1 = test();
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int* pt1 = &arr[0];
//	int* pt2 = arr;
//	int* pt3 = &arr[9];
//	printf("%p\n", &arr[0]);
//	printf("%p\n", arr);
//	printf("%p\n", &arr[9]);
//	return 0;
//}

//int main() {
//	int arr[10] = { 10 };
//	int i = 0;
//	int* pt1 = arr;
//	for (i = 0; i < 10; i += 1) {
//		*(pt1 + i) = i + 1;
//	}
//	for (i = 0; i < 10; i += 1) {
//		printf("%d ", *(pt1 + i));
//	}
//	printf("\n");
//	for (i = 0; i < 5; i += 1) {
//		printf("%d ", *(pt1 + 2 * i + 1));
//	}
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int* pt1 = arr;
//	int* pt2 = &arr[9];
//	printf("%d\n", pt2 - pt1);
//	printf("%d\n", pt1 - pt2);
//	return 0;
//}

#define N_VALUES 5

//int main() {
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[0]; vp < &values[N_VALUES];) {
//		*vp++ = 0;
//	}
//	for (vp = &values[0]; vp < &values[N_VALUES];) {
//		printf("%d", *vp++);
//	}
//	return 0;
//}

//int main() {
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[N_VALUES]; vp >= &values[0];) {
//		*vp-- = 0;
//	}
//	for (vp = &values[N_VALUES]; vp >= &values[0];) {
//		printf("%d", *vp--);
//	}
//	return 0;
//} c 语言标准， 数组的指针可以和后面一个元素的地址比较，但是不可以和前面一个元素的地址比较

//int main() {
//	int arr[10] = { 0 };
//	int* pt1 = arr;
//	int i = 0;
//	for (i = 0; i < 10; i += 1) {
//		printf("%p ============= %p\n", pt1 + i, &arr[i]);
//	}
//	return 0;
//}

//喜欢的字体却不能用

//int main() {
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i += 1) {
//		*(p + i) = i + 1;
//	}
//	for (i = 0; i < 10; i += 1) {
//		printf("%d ", *p++);
//	}
//	return 0;
//}

//void my_strlen(char* str, int* count) {
//	for (; *str++ != '\0'; *count += 1);
//}

//void my_strlen(char* str, int* count) {
//	if (*str++ != '\0') {
//		*count += 1;
//		my_strlen(str, count);
//	}
//}

//int my_strlen(char* str) {
//	if ('\0' != *str++) {
//		return 1 + my_strlen(str);
//	}
//	else {
//		return 0;
//	}
//}

//int my_strlen(char* str) {
//	char* pc1 = str;
//	char* pc2 = str;
//	for (; '\0' != *str++;) {
//		pc2 += 1;
//	}
//	return pc2 - pc1;
//}
//
//int main() {
//	char str[20] = "123456789";
//	int count = 0;
//	//my_strlen(str, &count);
//	count = my_strlen(str);
//	printf("%d\n", count);
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int* pt1 = arr;
//	int* pt2 = &arr;
//	int* pt3 = &arr[9];
//	printf("%p\n", pt1 + 10);
//	printf("%p\n", pt2 + 1);
//	printf("%p\n", pt3 + 1);
//	return 0;
//}
