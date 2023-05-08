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

 // 先教你写一个做加法的自定义函数

#include<stdio.h>
// 这里前面需要加上返回的值的类型，返回int
int add(int x, int y) { // 这里的参数叫形参，这些名字知道也是有意义的

	return x + y;

}// 我们需要将加好的数返回去
    // 这里main错了
int main(void) { // 现在是 0 + 0 = 0
	// 先定义两个int 变量
	int a = 0;
	int b = 0; // 给初始化值是一个好习惯
	int sum = 0;
	scanf("%d%d", &a, &b); // 这里要加上取地址符 &
	sum = add(a, b);  // 把a b 传递进去，这个操作叫传参
	         // 这里的，（）里面的参数叫实参
	printf("%d + %d = %d\n", a, b, sum);//用打印函数就得引用stdio.h
	return 0;
} //卧槽写错了

// 我们现在写一个输入相加