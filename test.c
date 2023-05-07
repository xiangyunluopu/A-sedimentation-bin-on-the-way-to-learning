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
//#include<stdio.h>

//void reverse_string_(char* str, int lift, int right) {
//	char tmp = 0;
//	if (lift < right) {
//		tmp = *(str + lift);
//		*(str + lift) = *(str + right);
//		*(str + right) = tmp;
//		reverse_string_(str, lift + 1, right - 1);
//	}
//}
//
//void reverse_string(char* str, int lift, int right) {
//	reverse_string_(str, lift, right - 1);
//}
//
//int my_strlen(char* str) {
//	if ('\0' != *str) {
//		return 1 + my_strlen(str + 1);
//	}
//	else {
//		return 0;
//	}
//}
//
//int main(void) {
//	char str[] = "abcdef";
//	int sz = my_strlen(str);
//	// printf("%d\n", sz);
//	reverse_string(str, 0, sz); // 此函数的使用方法， 在第二个传参中放入一个0，在三个传参中放入sz;
//	printf("%s", str);
//	return 0;
//}

//#include<stdio.h>
//// abcvdef
//// fbcde\0
//// fecd00
//// fed000
//void reverse_string(char* str) {
//	/*int sz = 0;
//	int i = 0;
//	if ('\0' != *str) {
//		while ('\0' != *(str + sz)) {
//			sz += 1;
//		}
//		
//	}*/
//	//printf("%d", sz);
//	int sz = 0;
//	char tmp = 0;
//	while ('\0' != *(str + sz)) {
//		sz += 1;
//	}
//	tmp = *str;
//	*str = *(str + sz - 1);
//	*(str + sz - 1) = '\0';
//	if (*(str + 2) != '\0') {
//		reverse_string(str + 1);
//	}
//	*(str + sz - 1) = tmp;
//}
//
//int main(void) {
//	char str[] = "abcdef";
//	reverse_string(str);
//	printf("%s", str);
//	return 0;
//}

// 计算一个数的每一位之和

//#include<stdio.h>
//
//int sum_(int n) {
//	int count = 0;
//	/*if (n) {
//		return (n % 10) + sum_(n / 10);
//	}
//	else {
//		return 0;
//	}*/
//	while (n) {
//		count += (n % 10);
//		n /= 10;
//	}
//	return count;
//}
//
//int main(void) {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", sum_(n));
//	return 0;
//}

//#include<stdio.h>
//
//// 递归实现k的n次方
//int n_k(n, k) {
//	int num = 0;
//	if (n = 0) {
//		return 0;
//	}
//	else if (n < 0) {
//		n *= -1;
//		num = k;
//		while (n > 1) {
//			num *= k;
//			n -= 1;
//		}
//		return 1 / num;
//	}
//	else if (n > 0) {
//		num = k;
//		while (n > 1) {
//			num *= k;
//			n -= 1;
//		}
//		return num; 
//	}
//}
//int main(void) {
//	int k = 0;
//	int n = 0;
//	printf("k = "); scanf("%d", &k);
//	printf("n = "); scanf("%d", &n);
//	printf("%d", n_k(n, k));
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int k = 2;
//	int n = 2;
//	int num = k;
//	while (n > 1) {
//		num *= k;
//		n -= 1;
//	}
//	printf("%d", num);
//	return 0;
//}

//#include<stdio.h>
//
//double k_n(double k, double n) {
//	double num = k;
//	if (0 == k) {
//		num = 1;
//	}
//	else if (n < 0) {
//		n *= -1;
//		while (n > 1) {
//			num *= k;
//			n -= 1;
//		}
//		num /= 1;
//	}
//	else if (n > 0) {
//		while (n > 1) {
//			num *= k;
//			n -= 1;
//		}
//	}
//	return num;
//}
//
//int main(void) {
//	double k = 0;
//	double n = 0;
//	double num = 0;
//	scanf("%lf%lf", &k, &n);
//	num = k_n(k, n);
//	printf("%lf", num);
//	return 0;
//}

//#include<stdio.h>
//
//double K_N(double k, double n) {
//	if (n == 0) {
//		return 1;
//	}
//	else if (n > 0) {
//		return k * K_N(k, n - 1);
//	}
//	else if (n < 0) {
//		n *= -1;
//		return 1 / (k * K_N(k, n - 1));
//	}
//}
//
//int main(void) {
//	double k = 0;
//	double n = 0;
//	double num = 0;
//	scanf("%lf%lf", &k, &n);
//	num = K_N(k, n);
//	printf("%lf", num);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int main(void) {
//
//		return 0;
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int Fib(n) {
//	int i = 0;
//	int sum[2] = { 0 };
//	int tmp = 0;
//	if (n == 1 || n == 2) {
//		return 1;
//	}
//	for (i = 0; i < n; i += 1) {
//		if (i == 0) {
//			sum[0] = 1;
//		}
//		else if (i == 1) {
//			sum[1] = 1;
//		}
//		else {
//			tmp = sum[1];
//			sum[1] = sum[0] + sum[1];
//			sum[0] = tmp;
//			
//		}
//	}
//	return sum[1];
//}
//
//int main(void) {
//	int n = 0;
//	scanf("%d", &n);
//	n = Fib(n);
//	printf("%d\n", n);
//	return 0;
//}

//#include<stdio.h>
//
//int Fib(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 1;
//	}
//	else {
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//int main(void) {
//	int n = 0;
//	scanf("%d", &n);
//	n = Fib(n);
//	printf("%d\n", n);
//	return 0;
//}

