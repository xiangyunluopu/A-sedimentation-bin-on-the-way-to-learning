#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int i = 0;
	int c = 0;
	scanf("%d %d", &a, &b);
	c = a + b;
	for (i = 0; i < c; i += 1)
	{
		printf("hello,world\n");
	}
	return 0;
}