#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 15

#include <stdio.h>

void get_len(char str[MAXSIZE], int* sz)
{
	for (*sz = 0; str[*sz] != '\0'; *sz += 1);
}

void gets(char str[MAXSIZE], int* sz)
{
	scanf("%s", str);
	get_len(str, sz);
}

void in_1(int* flag_str)
{
	int i = 0;
	for (i = 0; i < MAXSIZE; i += 1)
	{
		*(flag_str + i) = 1;
	}
}

void count_one_def(char str[MAXSIZE], int flag_str[MAXSIZE], int sz)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int count_def = 0;
	char tmp = 0;
	for (i = 0; i < sz; i += 1)
	{
		if (1 == flag_str[i])
		{
			flag_str[i] = 0;
			count_def += 1;
			for (j = i + 1, count = 1, tmp = str[i]; j + 1 < sz; j += 1)
			{
				if (tmp == str[j])
				{
					count += 1;
					flag_str[j] = 0;
				}
			}
			printf("%c有%d个\n", tmp, count);
		}
	}
	printf("共有%d个不同的字符\n", count_def);
}

int main(void)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int count_def = 0;
	char tmp = 0;

	char str[MAXSIZE] = { 0 };
	int sz = 0;
	//int count = 0;
	int flag_str[MAXSIZE] = { 0 };
	in_1(flag_str);
	gets(str, &sz);
	//count_one_def(str, flag_str, sz);
	for (i = 0; i < sz; i += 1)
	{
		if (1 == flag_str[i])
		{
			flag_str[i] = 0;
			count_def += 1;
			for (j = i + 1, count = 1, tmp = str[i]; j < sz; j += 1)
			{
				if (tmp == str[j])
				{
					count += 1;
					flag_str[j] = 0;
				}
			}
			printf("%c有%d个\n", tmp, count);
		}
	}
	printf("共有%d个不同的字符\n", count_def);
	return 0;
}