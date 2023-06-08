#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	float price[] = { 3250.00,2680.00,2750.00,5480.00,5180.00 };
	float tmp = 0;
	int sz = sizeof(price) / sizeof(price[0]);
	for (i = 0; i < sz - 1; i += 1)
	{
		for (j = i + 1; j < sz; j += 1)
		{
			if (price[i] < price[j])
			{
				tmp = price[i];
				price[i] = price[j];
				price[j] = tmp;
			}
		}
	}
	for (i = 0; i < sz; i += 1)
	{
		printf("%.2f  ", price[i]);
	}
	return 0;
}