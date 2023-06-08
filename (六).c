#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	int tmp = 0;
	int arr_score[] = { 95,80,85,72,65,79,42,81 };
	int sz = sizeof(arr_score) / sizeof(arr_score[0]);
	for (i = 0; i < sz - 1; i += 1)
	{
		for (j = i + 1; j < sz; j += 1)
		{
			if (arr_score[i] < arr_score[j])
			{
				tmp = arr_score[i];
				arr_score[i] = arr_score[j];
				arr_score[j] = tmp;
			}
		}
	}
	printf("成绩由高到低排序如下\n");
	for (i = 0; i < sz; i += 1)
	{
		printf("%-3d", arr_score[i]);
		sum += arr_score[i];
	}
	printf("\n平均分为>:%3d", sum / sz);

	return 0;
}
