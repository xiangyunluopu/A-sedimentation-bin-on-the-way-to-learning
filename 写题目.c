#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>

//int count_bit_one(int num) {
//	int count = 0;
//	while (num) {
//		if (1 == (num % 2)) {
//			count += 1;
//		}
//		num /= 2;
//	}
//	return count;
//}

//int count_bit_one(unsigned int num) {
//	int count = 0;
//	while (num) {
//		if (1 == (num % 2)) {
//			count += 1;
//		}
//		num /= 2;
//	}
//	return count;
//}
//0000
//int count_bit_one(int num) {
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i += 1) {
//		if (1 == ((num >> i) & 1)) {
//			count += 1;
//		}
//	}
//	return count;
//}

//int count_bit_one(int num) {
//	int count = 0;
//	while (num) {
//		num = num & (num - 1);
//		count += 1;
//	}
//	return count;
//}
//
//int main(void) {
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	count = count_bit_one(num);
//	printf("count = %d\n", count);
//	return 0;
//}

// ��ȡһ��������������λ��ż��λ�����ֱ��ӡ

//#include<stdio.h>
//
////00000000 00000000 00000000 00000000
//
//void print(int num) {
//	int i = 0;
//	//int ii = 0;
//	printf("������");
//	for (i = 31/*, ii = 1*/; i >= 0; i -= 2/*, ii += 1*/) {
//		//printf("%d\n", ii);
//		printf("%d", 1 & (num >> i));
//	}
//	printf("\n");
//	printf("ż����");
//	for (i = 32; i >= 1; i -= 2) {
//		printf("%d", (num >> i) & 1);
//	}
//}
//
//int main(void) {
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

// �����Ķ��������ж���bitλ��ͬ
// ���� ����1999��2298
// ������� 8

//#include<stdio.h>
//
//int fill_bit_count(int n, int m) {
//	// ^ ���������ͬΪ0������Ϊ1��
//	// �������ǿ����� n ^ m �������ж�������1�ĸ���
//	int num = n ^ m;
//	int count = 0;
//	while (num) {
//		num = (num - 1) & num;
//		count += 1;
//	}
//	return count;
//}
//
//int main(void) {
//	int n = 0;
//	int m = 0;
//	int count = 0;
//	scanf("%d%d", &n, &m);
//	count = fill_bit_count(n, m);
//	printf("%d", count);
//	return 0;
//}

//#include<stdio.h> 
//
//int main(void) {
//	//const int a = 3;
//	////a = 4;
//	//int* p = &a;
//	//*p = 4;
//	//printf("%d\n", a);
//	char a = 'a';
//	char b = 'b';
//	//char* const p = &a;
//	//p = &b;
//	//*p = 'c';
//	const char* const p = &a;
//	//p = &b;
//	//*p = 'c';
//	printf("%c\n", *p);
//	return 0;
//}

//#include<stdio.h>

// ����ʹ�õ���������������n .m ;

//int main(void) {
//	int n = 3;
//	int m = 5;
//	/*n = n + m;
//	m = n - m;
//	n = n - m;*/
//	/*n = n ^ m;
//	m = n ^ m;
//	n = n ^ m;*/
//	printf("n = %d, m = %d\n", n, m);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i += 1,p += 1) {
//		printf("%d ", *p);
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
// //1 �Լ���
//int main(void) {
//	//int num = 0;
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int count = 0;
//	int sum = 0;
//	printf("100��200 ֮�������Ϊ��");
//	for (i = 101; i <= 199; i += 2) {
//		for (j = 1; j <= i / 2; j += 1) {
//			if (!(i % j)) {
//				flag = ~flag;
//			}
//		}
//		if (flag) {
//			printf("%3d  ", i);
//			sum = sum + i;
//			count += 1;
//			flag = ~flag;
//		}
//	}
//	printf("\n�ܹ���%d������\nsum = %d\n", count, sum);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int i = 111;
//	int j = 3;
//	printf("%d", i % j);
//	return 0;
//}

//#include<stdio.h>
//
//int main(void) {
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i += 1) {
//		for (j = 2; j < i; i += 1) {
//			if (i % j == 0) {
//				break;
//			}
//		}
//		if (j == i)
//			printf("%d\t", 1);
//	}
//	return 0;
//}

//int main(void) {
//	int i = 4;
//	int j = 1;
//	printf("%d\n", i % 3);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
//int main(void) {
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 101; i <= 199; i += 2) {
//		for (j = 2; j <= sqrt(i); j += 1) {
//			if (!(i % j)) {
//				break;
//			}
//		}
//		if (j > sqrt(i)) {
//			printf("%-2d ", i);
//			count += 1;
//		}
//	}printf("\n");
//	printf("count = %d\n", count);
//	return 0;
//}

#include<stdio.h>

// �ܱ�4�����������ܱ�100����
// �ܱ�400����
//int main(void) {
//	int i = 0;
//	int count = 0;
//	for (i = 1000; i <= 2000; i += 1) {
//		if ((!(i % 4) && i % 100) || !(i % 400)) {
//			printf("%2d ", i); count += 1;
//		}
//	}printf("\n");
//	printf("count = %d\n", count);
//	return 0;
//}