#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>

//int main(void) {
//	//printf("hello,world!");
//	//puts("hello,world!");
//	return 0;
//}

//int main(void) {
//
//	retur
//}

//int main(void) {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", n);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(long double));
//	return 0;
//}

 // �Ƚ���дһ�����ӷ����Զ��庯��

#include<stdio.h>
// ����ǰ����Ҫ���Ϸ��ص�ֵ�����ͣ�����int
int add(int x, int y) { // ����Ĳ������βΣ���Щ����֪��Ҳ���������

	return x + y;

}// ������Ҫ���Ӻõ�������ȥ
    // ����main����
int main(void) { // ������ 0 + 0 = 0
	// �ȶ�������int ����
	int a = 0;
	int b = 0; // ����ʼ��ֵ��һ����ϰ��
	int sum = 0;
	scanf("%d%d", &a, &b); // ����Ҫ����ȡ��ַ�� &
	sum = add(a, b);  // ��a b ���ݽ�ȥ����������д���
	         // ����ģ���������Ĳ�����ʵ��
	printf("%d + %d = %d\n", a, b, sum);//�ô�ӡ�����͵�����stdio.h
	return 0;
} //�Բ�д����

// ��������дһ���������