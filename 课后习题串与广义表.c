#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include<stdio.h>

typedef struct
{
	char vec[MAXSIZE];
	int len;
}Str;

void ConcatStr(Str* r1, Str* r2)
{
	int i = 0;
	if (r1->len + r2->len > MAXSIZE)
	{
		printf("两个串太长，溢出!\n");
	}
	else
	{
		for (i = 0; i < r2->len; i += 1)
		{
			r1->vec[i + r1->len] = r2->vec[i];
		}
		r1->vec[i + r1->len] = '\0';
		r1->len = r1->len + r2->len;
	}
}