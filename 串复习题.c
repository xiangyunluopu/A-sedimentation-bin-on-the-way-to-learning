#define _CRT_SECURE_NO_WARNINGS 1

//#define char* String* 
//
//int main(void)
//{
//	
//	return 0;
//}
//
//void CreatStr(String* S)
//{
//
//}

#define MAXSIZE 15

#include <stdio.h>

typedef struct
{
	char* str[MAXSIZE];
	int len;
}String;

int StrLength(String* S)
{
	int count = 0;
	for (count = 0; S->str[count] != '\0'; count += 1);
	return count;
}
//
//void CreatStr(String* S)
//{
//	int i = 0;
//	char ch = 0;
//	for (i = 0; i < MAXSIZE; i += 1)
//	{
//		ch = getchar();
//		if (ch == EOF || ch == '\n')
//		{
//			break;
//		}
//		S->str[i] = ch;
//	}
//	if (i < MAXSIZE)
//	{
//		S->str[i] = '\0';
//	}
//	else
//	{
//		S->str[i - 1] = '\0';
//	}
//	S->len = StrLength(S);
//}

//void gets(S->str)
//{
//
//}

//void gets(char str[MAXSIZE])
//{
//	int i = 0;
//	char ch = 0;
//	for (i = 0; i < MAXSIZE; i += 1)
//	{
//		ch = getchar();
//		if (EOF == ch || '\0' == ch)
//		{
//			break;
//		}
//		str[i] = ch;
//	}
//	if (i < MAXSIZE)
//	{
//		str[i] = '\0';
//	}
//	else
//	{
//		str[i - 1] = '\0';
//	}
//	while ((ch = getchar()) != EOF && ch != '\r');
//}
//
//void CreatStr(String* S)
//{
//	gets(S->str);
//	S->len = StrLength(S);
//}
//
//int StrLength(String* S)
//{
//	int i = 0;
//	while (S->str[i] != '\0')
//	{
//		i += 1;
//	}
//	return i;
//}

//int SubString(String* S, String* Sub, int pos, int len)
//{
//	int j = 0;
//	if (pos < 1 || pos + len > S->len)
//	{
//
//
//	}
//}

//int StrLength(String* S)
//{
//	int i = 0;
//	while (S->str[i] != '\0')
//	{
//		i += 1;
//	}
//	return i;
//}

//int SubString(String* S, String* Sub, int pos, int len)
//{
//	int j = 0;
//	if (pos < 1 || pos > S->len || len < 1 || pos - 1 + len > S->len)
//	{
//		Sub->len = 0;
//		printf("参数错误！\n");
//		return 0;
//	}
//	else
//	{
//		for (j = 0; j < len; j += 1)
//		{
//			Sub->str[j] = S->str[pos - 1 + j];
//		}
//		Sub->str[j] = '\0';
//		Sub->len = len; // Sub->len = j;
//		return 1;
//	}
//
//}

//int SubString(String* S, String* Sub, int pos, int len)
//{
//	int j = 0;
//	if (pos < 1 || pos > S->len || len < 1 || pos - 1 + len > S->len)
//	{
//		Sub->len = 0;
//		printf("参数错误！\0");
//		return 0;
//	}
//	else
//	{
//		for (j = 0; j < len; j += 1)
//		{
//			Sub->str[j] = S->str[pos - 1 + j];
//		}
//		Sub->str[j] = '\0';
//		Sub->len = j; // Sub->len = len;
//		return 1;
//	}
//}

//int StrDelete(String* S, int i, int j)
//{
//	int k = 0;
//	if (i < 1 || j < 1 || i - 1 + j > S->len)
//	{
//		printf("所要删除的字串越界！\n");
//		return 0;
//	}
//	else
//	{
//		for (k = i - 1 + j; k < S->len; k += 1, i += 1)
//		{
//			S->str[i - 1] = S->str[k];
//		}
//		S->len = S->len - j;
//		S->str[S->len] = '\0';
//		return 1;
//	}
//}

//int StrInsert(String* S, String* S1, int i)
//{
//	int k = 0;
//	if (i > S->len + 1 || i < 1)
//	{
//		printf("插入位置错误！\n");
//	}
//	else if (S->len + S1->len > MAXSIZE)
//	{
//		printf("两串长度超过储存长度！\n");
//		return 0;
//	}
//	else
//	{
//		for (k = S->len - 1; k >= i - 1; k -= 1)
//		{
//			S->str[S1->len + k] = S->str[k];
//		}
//		for (k = 0; k < S1->len; k += 1)
//		{
//			S->str[i - 1 + k] = S1->str[k];
//		}
//		S->len += S1->len;
//		S->str[S->len] = '\0';
//		return 1;
//	}
//}

//int StrInsert(String* S, String* S1, int i)
//{
//	int k = 0;
//	if (i > S->len + 1 || i < 1)
//	{
//		printf("插入位置错误！\n");
//		return 0;
//	}
//	else if (S->len + S1->len > MAXSIZE)
//	{
//		printf("两串长度超过储存长度！\n");
//		return 0;
//	}
//	else
//	{
//		for (k = S->len - 1; k >= i - 1; k -= 1)
//		{
//			S->str[S1->len + k] = S->str[k];
//		}
//		for (k = 0; k < S1->len; k += 1)
//		{
//			S->str[i - 1 + k] = S1->str[k];
//		}
//		S->len = S->len + S1->len;
//		return 1;
//	}
//}

//int StrIndex(String* S, String* T)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while (i < S->len && j < T->len)
//	{
//		if (S->str[i] == T->str[j])
//		{
//			i += 1;
//			j += 1;
//		}
//		else
//		{
//			i = i - j + 1;
//			j = 0;
//		}
//	}
//	if (j >= T->len)
//	{
//		j = i - j + 1;
//	}
//	else
//	{
//		k = -1;
//	}
//	return k;
//}

//int StrCompare(String* S1, String* S2)
//{
//	int i = 0;
//	int flag = 0;
//	while (S1->str[i] != '\0' && S2->str[i] != '\0')
//	{
//		if (S1->str[i] != S2->str[i])
//		{
//			flag = 1;
//			break;
//		}
//		else
//		{
//			i += 1;
//		}
//	}
//	if (1 == flag && S1->len == S2->len) // 若每个位置字符相同且长度相等
//	{
//		return 0;
//	}
//	else
//	{
//		return S1->str[i] - S2->str[i];
//	}
//}

//int StrCat(String* S, String* T)
//{
//	int i = 0;
//	int flag = 0;
//	if (S->len + T->len <= MAXSIZE)
//	{
//		for (i = S->len; i - S->len < T->len; i += 1)
//		{
//			S->str[i] = T->str[i - S->len];
//		}
//		S->str[i] = '\0';
//		S->len += T->len;
//		flag = 1;
//	}
//	else if (S->len < MAXSIZE)
//	{
//		for (i = S->len; i < MAXSIZE; i += 1)
//		{
//			S->str[i] = T->str[i - S->len];
//		}
//		S->len = MAXSIZE;
//		flag = 0;
//	}
//	else
//	{
//		flag = 0;
//	}
//	return 0;
//}

void StrReplace(String* S, String* T, String* V)
{
	int i = 0;
	int n = S->len;
	int m = T->len;
	int q = V->len;
	int p = 1;
	do
	{
		i = StrIndex(S, T);
		if (i != -1) // S串中有T子串
		{
			StrDelete(S, i, m);
			StrInsert(S, V, i);
			p = i + q;
			S->len = S->len + q - m;
			n = S->len;
		}
	} while (p <= n - m + 1 && i != -1);
}