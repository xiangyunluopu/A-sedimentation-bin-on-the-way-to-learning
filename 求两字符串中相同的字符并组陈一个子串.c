#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE	15 

#include <stdio.h>

void in_1(int* flag_str1)
{
	int i = 0;
	for (i = 0; i < MAXSIZE; i += 1)
	{
		*(flag_str1 + i) = 1;
	}
}

void get_str(char str[MAXSIZE])
{
	int i = 0;
	char ch = 0;
	for (i = 0; i < MAXSIZE; i += 1)
	{
		ch = getchar();
		if (ch == EOF || ch == '\n')
		{
			break;
		}
		str[i] = ch;
	}
	if (i < MAXSIZE)
	{
		str[i] = '\0';
	}
	else
	{
		str[i - 1] = '\0';
	}
	//while ((i = fgetc(stdin)) != EOF && i != '\n');
}

int main(void)
{
	int i = 0;
	int j = 0;
	char tmp = 0;
	int sz = 0;
	char str1[MAXSIZE] = { 0 };
	int flag_str1[MAXSIZE] = { 0 };
	char str2[MAXSIZE] = { 0 };
	char T[MAXSIZE] = { 0 };
	in_1(flag_str1);
	printf("请输入第一个串>:");
	get_str(str1);
	printf("请输入第二个串>:");
	get_str(str2);
	printf("str1 = { %s }\n", str1);
	printf("str2 = { %s }\n", str2);
	for (i = 0; i < MAXSIZE - 1; i += 1)
	{
		if (1 == flag_str1[i])
		{
			tmp = str1[i];
			flag_str1[i] = 0;
			for (j = i + 1; j < MAXSIZE - 1; j += 1)
			{
				if (tmp == str1[j])
				{
					flag_str1[j] = 0;
				}
			}
			for (j = 0; j < MAXSIZE - 1; j += 1)
			{
				if (tmp == str2[j])
				{
					T[sz++] = tmp;
					break;
				}
			}
		}
	}
	puts(T);
	return 0;
}