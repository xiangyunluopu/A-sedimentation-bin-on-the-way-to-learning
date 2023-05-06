#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//typedef struct {
//	int data[10];
//	int top;
//}Sta;
//
//void ana(Sta* x, int n) {
//	if (n) {
//		x->top += 1;
//		x->data[x->top] = n % 10;
//		ana(x, n / 10);
//	}
//}
//
//void print(Sta* x, int n) {
//	int i = 0;
//	ana(x, n);
//	for (i = x->top; i > -1; i -= 1) {
//		printf("%d", x->data[i]);
//	}
//	printf("\n");
//}
//
//int main(void) {
//	Sta x;
//	x.top = -1;
//	int n = 1234;
//	print(&x, n);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	printf("%d\n", 1234 % 10);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int n = 0;
//	int i = 0;
//	int num = 0;
//	scanf("%d", &n);
//	for (i = 1, num = 1; i <= n; i += 1) {
//		num = i * num;
//	}
//	printf("%d\n", num);
//	return 0;
//}

//#include<stdio.h>
//
//int n_n_n(int n) {
//	if (n > 1)
//		return n * n_n_n(n - 1);
//	else if (n == 1)
//		return 1;
//}
//
//int main(void) {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", n_n_n(n));
//	return 0;
//}

//#include<stdio.h>
//
//int my_strlen(char* str) {
//	int count = 0;
//	while (*str != '\0') {
//		str += 1;
//		count += 1;
//	}
//	return count;
//}
//
//void reverse_string(char* str) {
//	int sz = my_strlen(str);
//	//printf("%d", sz);
//	int lift = 0;
//	int right = sz - 1;
//	char tmp = 0;
//	while (lift < right) {
//		tmp = *(str + lift);
//		*(str + lift) = *(str + right);
//		*(str + right) = tmp;
//		/*tmp = str[lift];
//		str[lift] = str[right];
//		str[right] = tmp;*/
//		lift += 1;
//		right -= 1;
//	}
//	printf("%s\n", str);
//}
//
//int main(void) {
//	char str[] = "abcdefg";
//	reverse_string(str);
//	
//	return 0;
//}
#include<stdio.h>

int main(void) {

	return 0;
}