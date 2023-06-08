#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int arr[10] = { 0 };
	int* p = &arr[0];
	int i = 0;
	printf("intput numbers>:");
	for (i = 0; i < 10; i += 1)
	{
		scanf("%d", (p + i));
		if (*(p + i) % 2)
		{
			*(p + i) += 1;
		}
		else
		{
			*(p + i) -= 1;
		}
	}
	printf("  After change>:");
	for (i = 0; i < 10; i += 1)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}