#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void biseach(int arr[], int sz)
{	 // left = 0; right = -1
	 // left < right
	 // mid = (0 + 0 )/ 2
	 // k = -1
	 //   [1]      [2][3][4] //[5] [6] [7] [8] [9]
	 //    0     ///  1  2  3     4   5   6   7   8
	int k = 0;
	int left = 0;
	int right = 0;
	int mid = 0;
	left = 0;
	right = sz - 1;

	printf("请输入要查找的值>:");
	scanf("%d", &k);
	while (left <= right)// right < left
	{
		mid = (left + right) / 2;
		if (k == arr[mid])
		{
			printf("找到了下标为:%d\n", mid);
			break;
		}
		else if (k < arr[mid])
		{
			right = mid - 1;
		}
		else     //if (k > arr[mid])
		{
			left = mid + 1;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
}

int main(void)
{
	int arr1[10] = { 0 };
	int i = 0;
	int j = 0;
	int tmp = 0;
	int sz = 0;
	srand((unsigned int)time(NULL));

	for (i = 0; i <= 9; i += 1)
	{
		arr1[i] = rand() % 21;
	}

	for (i = 0; i <= 9; i += 1)
	{
		printf("值：%d ; sub: %d\n", arr1[i], i);
		//printf("sub:[%d]\n", i);
	}
	//[][][][][][][]|[]
	//[][][][][][]|[]
	//[j][j + 1][][][]|[]
	//____
	// <
	for (i = 9; i >= 1; i -= 1)
	{
		for (j = 0; j <= i - 1; j += 1)
		{
			if (arr1[j] > arr1[j + 1])
			{
				tmp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i += 1)
	{
		printf("%d ", arr1[i]);
	}

	sz = sizeof(arr1) / sizeof(arr1[0]);
	printf("\nsz = %d", sz);
	biseach(arr1, sz);

	return 0;
}