#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>

//int  fill_bit_one(unsigned int n) {
//	int count = 0;
//	while (n) {
//		if (1 == n % 2) {
//			count += 1;
//		}
//		n /= 2;
//	}
//	return count;
//}

//int fill_bit_one(int n) {
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i += 1) {
//		if (1 == ((n >> i) & 1)) {
//			count += 1;
//		}
//	}
//	return count;
//}

//int fill_bit_one(int n) {
//	int count = 0;
//	while (n) {
//		n = n & (n - 1);
//		count += 1;
//	}
//	return count;
//}
//
//int main(void) {
//	int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	count = fill_bit_one(n);
//	printf("count = %d\n", count);
//	return 0;
//}

#include<stdio.h>

//int bit(int n, int m) {
//	int ret = n ^ m;
//	int count = 0;
//	while (ret) {
//		ret = ret & (ret - 1);
//		count += 1;
//	}
//	return count;
//}

int bit_bit(int n) {
	if (n) {
		return 1 + bit_bit(n = n & (n - 1));
	}
	else {
		return 0;
	}
}

int bit(int n, int m) {
	return bit_bit(n ^ m);
}

int main(void) {
	int n = 1999;
	int m = 2299;
	int count = 0;
	count = bit(n, m);
	printf("count = %d\n", count);
	return 0;
}
