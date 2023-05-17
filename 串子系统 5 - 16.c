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
	printf("这是一个串\n");
	printf("==========================================\n");
	printf("	1.建立一个新串并显示该串长度\n");
	printf("	2.求子串\n");
	printf("	3.删除子串\n");
	printf("	4.插入子串\n");
	printf("	5.查找子串\n");
	printf("	6.比较两个串的大小\n");
	printf("	7.连接两个子串\n");
	printf("	8.子串替换\n");
	printf("	0.返回\n");
	printf("==========================================\n");
	printf("请输入菜单号>:");
}

//void str_creat(string* S)
//{
//	//char ch[MAXSIZE] = { 0 };
//	int i = 0;
//	printf("请输入一段字符串\n");
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
	for (len = 0; S->ch[len] != '\0'; len += 1); // 单个字符用单引号
	S->length = len;
}

void str_creat(string* S)
{
	gets(S->ch); // 
	str_len(S);
}

int str_sub(string* S, string* V, int i, int len)
{
	// 先判断位置与长度是否合法
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
	// 先判断位置以及长度是否和法 [1] [2] [3] [4] [5] [6]
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
	// 先判断合法性
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
		for (j = S->length - 1; j >= i - 1; j -= 1)// 太粗心了移动操作要从最后一个元素开始
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
	{	// S->length 这里有一个元素的啊！！！！！！
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
		// 先查找位置， 创建一个i 来记录位置
		i = str_index(S, V);
		// 删除字串，
		// 卧槽我忘记了不是什么时候都可以删的有条件 i！= 0
		if (i != 0)
		{
			str_delete(S, i, V->length);
			// 插入子串
			str_insert(S, T, i);
		}
	} while (i && i + V->length <= S->length - T->length + 1); // 这里后面的判断式子我不是很理解
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
			printf("建立一个新串\n");
			printf("请输入一串字符串>:");
			str_creat(S);
			printf("该串为>:");
			puts(S->ch);
			printf("该串的长度为:>%d\n", S->length);
			break;
		case 2:
			printf("输入想要查询sub的初始位置>:");
			scanf("%d", &i);
			printf("请输入想要查询sub的长度>:");
			scanf("%d", &len);
			if (str_sub(S, V, i, len))
			{
				printf("查询sub成功，原来的主串为>:");
				puts(S->ch);
				printf("sub为>:");
				puts(V->ch);
			}
			else
			{
				printf("查询失败\n");
			}
			break;
		case 3:
			printf("输入想要删除的子串的初始位置>:");
			scanf("%d", &i);
			printf("输入想要删除的字串的长度>:");
			scanf("%d", &len);
			printf("删除前的原串为>:");
			puts(S->ch);
			if (str_delete(S, i, len))
			{
				printf("删除后的串为>:");
				puts(S->ch);
			}
			else
			{
				printf("删除失败\n");
			}
			break;
		case 4:
			printf("请输入要在主串中插入的位置>:");
			scanf("%d", &i);
			printf("请输入一个子串>:");
			str_creat(V);
			printf("原来的主串为>:");
			puts(S->ch);
			if (str_insert(S, V, i))
			{
				printf("插入后的主串为>:");
				puts(S->ch);
			}
			else
			{
				printf("插入失败\n");
				printf("此时的主串为>:");
				puts(S->ch);
			}
			break;
		case 5:
			printf("请输入想查找的子串>:");
			str_creat(V);
			if (i = str_index(S, V))
			{
				printf("该字串在主串中第一次出现的位置为:[%d]\n", i);
				puts(S->ch);
				puts(V->ch);
			}
			else
			{
				printf("查找失败\n");
			}
			break;
		case 6:
			printf("请输入第一个串>:");
			str_creat(S);
			printf("请输入第二个串>:");
			str_creat(V);
			i = str_compare(S, V);
			if (i > 0)
			{
				printf("第一个串大于第二个\n");
			}
			else if (i < 0)
			{
				printf("第二个串大于第一个\n");
			}
			else
			{
				printf("两串大小相等\n");
			}
			break;
		case 7:
			printf("请输入第一个串>:");
			str_creat(S);
			printf("请输入第二个串>:");
			str_creat(V);
			if (str_cat(S, V))
			{
				printf("连接后的串为:");
				puts(S->ch);
			}
			else
			{
				printf("连接失败\n");
			}
			break;
		case 8:
			printf("请输入主串>:");
			str_creat(S);
			printf("请输入在主串查找的子串>:");
			str_creat(V);
			printf("请输入要替换的子串>:");
			str_creat(T);
			str_replace(S, V, T);
			printf("替换后的主串为:");
			puts(S->ch);
			break;
		case 0:

			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (num_mune);
	return 0;
}