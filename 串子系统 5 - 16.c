#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <string.h>
//#include <malloc.h>

#define MAXSIZE 100

typedef struct {
	char ch[MAXSIZE];
	int length;
}string;

void gets(char ch[MAXSIZE])
{
	scanf("%s", ch);
}

void mune(void)
{
	printf("����һ����\n");
	printf("==========================================\n");
	printf("	1.����һ���´�����ʾ�ô�����\n");
	printf("	2.���Ӵ�\n");
	printf("	3.ɾ���Ӵ�\n");
	printf("	4.�����Ӵ�\n");
	printf("	5.�����Ӵ�\n");
	printf("	6.�Ƚ��������Ĵ�С\n");
	printf("	7.���������Ӵ�\n");
	printf("	8.�Ӵ��滻\n");
	printf("	0.����\n");
	printf("==========================================\n");
	printf("������˵���>:");
}

//void str_creat(string* S)
//{
//	//char ch[MAXSIZE] = { 0 };
//	int i = 0;
//	printf("������һ���ַ���\n");
//	if (S->length != 0)
//	{
//		S->length = 0;
//	}
//	scanf("%s", &S->str);
//	for (i = 0; S->str[i] != "\0"; i += 1);
//	S->length = i;
//}

void str_len(string* S)
{
	int len = 0;
	for (len = 0; S->ch[len] != '\0'; len += 1); // �����ַ��õ�����
	S->length = len;
}

void str_creat(string* S)
{
	gets(S->ch); // 
	str_len(S);
}

int str_sub(string* S, string* V, int i, int len)
{
	// ���ж�λ���볤���Ƿ�Ϸ�
	int j = 0;
	if (i >= 1 && i - 1 + len <= S->length)
	{
		for (j = 0; j < len; j += 1, i += 1)
		{
			V->ch[j] = S->ch[i - 1];
		}
		V->ch[len] = '\0';
		return 1;
	}
	else
	{
		return 0;
	}
}

int str_delete(string* S, int i, int len)
{//                                0   1   2   3   4   5
	// ���ж�λ���Լ������Ƿ�ͷ� [1] [2] [3] [4] [5] [6]
	int j = 0;
	if (i >= 1 && i <= S->length && i - 1 + len <= S->length)
	{
		for (j = i - 1; j < S->length; j += 1)
			S->ch[j] = S->ch[j + len];
		S->ch[j + len] = '0';
		S->length -= len;
		return 1;
	}
	else
	{
		return 0;
	}
}

int str_insert(string* S, string* V, int i)
{
	int j = 0;
	// ���жϺϷ���
	if (i < 1 || i > S->length + 1)
	{
		return 0;
	}
	else if ( MAXSIZE == S->length)
	{
		return 0;
	}
	else if (S->length + V->length <= MAXSIZE)
	{
		for (j = S->length - 1; j >= i - 1; j -= 1)// ̫�������ƶ�����Ҫ�����һ��Ԫ�ؿ�ʼ
		{
			S->ch[j + V->length] = S->ch[j];
		}
		for (j = 0; j < V->length; j += 1, i += 1)
			S->ch[i - 1] = V->ch[j];
		S->length += V->length;
		S->ch[S->length] = '\0';
		return 1;
	}
	else
	{
		return 0;
	}
}

int str_index(string* S, string* V)
{
	int i = 0;
	int j = 0;
	while (i < S->length && j < V->length)
	{
		if (S->ch[i] == V->ch[j])
		{
			i += 1;
			j += 1;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j >= V->length)
		{
			break;
		}
	}
	if (j >= V->length)
	{
		return i - j + 1;
	}
	else
	{
		return 0;
	}
}

int str_compare(string* S, string* V)
{
	int s = 0;
	int v = 0;
	for (;s < S->length && v < V->length; s += 1, v += 1)
	{
		if (S->ch[s] != V->ch[v])
		{
			return S->ch[s] - V->ch[v];
		}
	}
	return S->ch[s] - V->ch[v];
}

int str_cat(string* S, string* V)
{
	int i = 0;
	int j = 0;
	if (S->length + V->length <= MAXSIZE)
	{	// S->length ������һ��Ԫ�صİ�������������
		for (i = S->length, j = 0; j < V->length; i += 1, j += 1)
		{
			S->ch[i] = V->ch[j];
		}
		S->length += V->length;
		S->ch[S->length] = '\0';
		return 1;
	}
	else if (S->length < MAXSIZE)
	{
		for (i = S->length, j = 0; i < MAXSIZE; i += 1, j += 1)
		{
			S->ch[i] = V->ch[j];
		}
		S->length = MAXSIZE;
		S->ch[MAXSIZE] = '\0';
		return 0;
	}
	else
	{
		return 0;
	}
}

void str_replace(string* S, string* V, string* T)
{
	int i = 0;
	do
	{
		// �Ȳ���λ�ã� ����һ��i ����¼λ��
		i = str_index(S, V);
		// ɾ���ִ���
		// �Բ��������˲���ʲôʱ�򶼿���ɾ�������� i��= 0
		if (i != 0)
		{
			str_delete(S, i, V->length);
			// �����Ӵ�
			str_insert(S, T, i);
		}
	} while (i && i + V->length <= S->length - T->length + 1); // ���������ж�ʽ���Ҳ��Ǻ����
}	// i + V->length <= S->length

int main(void)
{
	int num_mune = 0;
	int i = 0;
	int len = 0;
	/*string* S = NULL;
	string* T = NULL;
	string* V = NULL;*/
	string s1;
	string s2;
	string s3;
	string* S = &s1;
	string* T = &s2;
	string* V = &s3;
	do
	{
		/*S = (string*)malloc(sizeof(string));
		T = (string*)malloc(sizeof(string));
		V = (string*)malloc(sizeof(string));*/
		mune();
		scanf("%d", &num_mune);
		switch (num_mune)
		{
		case 1:
			printf("����һ���´�\n");
			printf("������һ���ַ���>:");
			str_creat(S);
			printf("�ô�Ϊ>:");
			puts(S->ch);
			printf("�ô��ĳ���Ϊ:>%d\n", S->length);
			break;
		case 2:
			printf("������Ҫ��ѯsub�ĳ�ʼλ��>:");
			scanf("%d", &i);
			printf("��������Ҫ��ѯsub�ĳ���>:");
			scanf("%d", &len);
			if (str_sub(S, V, i, len))
			{
				printf("��ѯsub�ɹ���ԭ��������Ϊ>:");
				puts(S->ch);
				printf("subΪ>:");
				puts(V->ch);
			}
			else
			{
				printf("��ѯʧ��\n");
			}
			break;
		case 3:
			printf("������Ҫɾ�����Ӵ��ĳ�ʼλ��>:");
			scanf("%d", &i);
			printf("������Ҫɾ�����ִ��ĳ���>:");
			scanf("%d", &len);
			printf("ɾ��ǰ��ԭ��Ϊ>:");
			puts(S->ch);
			if (str_delete(S, i, len))
			{
				printf("ɾ����Ĵ�Ϊ>:");
				puts(S->ch);
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			break;
		case 4:
			printf("������Ҫ�������в����λ��>:");
			scanf("%d", &i);
			printf("������һ���Ӵ�>:");
			str_creat(V);
			printf("ԭ��������Ϊ>:");
			puts(S->ch);
			if (str_insert(S, V, i))
			{
				printf("����������Ϊ>:");
				puts(S->ch);
			}
			else
			{
				printf("����ʧ��\n");
				printf("��ʱ������Ϊ>:");
				puts(S->ch);
			}
			break;
		case 5:
			printf("����������ҵ��Ӵ�>:");
			str_creat(V);
			if (i = str_index(S, V))
			{
				printf("���ִ��������е�һ�γ��ֵ�λ��Ϊ:[%d]\n", i);
				puts(S->ch);
				puts(V->ch);
			}
			else
			{
				printf("����ʧ��\n");
			}
			break;
		case 6:
			printf("�������һ����>:");
			str_creat(S);
			printf("������ڶ�����>:");
			str_creat(V);
			i = str_compare(S, V);
			if (i > 0)
			{
				printf("��һ�������ڵڶ���\n");
			}
			else if (i < 0)
			{
				printf("�ڶ��������ڵ�һ��\n");
			}
			else
			{
				printf("������С���\n");
			}
			break;
		case 7:
			printf("�������һ����>:");
			str_creat(S);
			printf("������ڶ�����>:");
			str_creat(V);
			if (str_cat(S, V))
			{
				printf("���Ӻ�Ĵ�Ϊ:");
				puts(S->ch);
			}
			else
			{
				printf("����ʧ��\n");
			}
			break;
		case 8:
			printf("����������>:");
			str_creat(S);
			printf("���������������ҵ��Ӵ�>:");
			str_creat(V);
			printf("������Ҫ�滻���Ӵ�>:");
			str_creat(T);
			str_replace(S, V, T);
			printf("�滻�������Ϊ:");
			puts(S->ch);
			break;
		case 0:

			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (num_mune);
	return 0;
}