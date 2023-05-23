#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//#include <malloc.h>

//#define DataType int
#define MAXSIZE 100
//#define DataType int

typedef struct
{
	int weight;
	int parent;
	int left_child;
	int right_child;
}HF_node;

typedef HF_node HF[MAXSIZE];

int n;

//typedef struct
//{
//	DataType data[MAXSIZE / 2];
//	int top;
//}L;

//typedef HF_node HF[MAXSIZE];

void inps_HFM(HF T)
{
	printf("请输入共有多少个权值(n <= %d)>:", MAXSIZE / 2);
	scanf("%d", &n);
	//HF t;
	//t = (HF*)malloc(sizeof(HF));
	int i = 0;
	for (i = 0; i < n; i += 1)
	{
		printf("请输入第%d的权值", i + 1);
		scanf("%d", &T[i].weight);
	}
	for (i = 0; i < 2 * n - 1; i += 1)
	{
		T[i].parent = -1;
		T[i].left_child = -1;
		T[i].right_child = -1;
	}
	//return &t;
}

void sel_hfm(HF T, int i, int* p1, int* p2)
{
	int j = 0;
	int min1 = 999999;
	int min2 = 999999;
	for (j = 0; j < i; j += 1)
	{
		if (-1 == T[j].parent)
		{
			if (T[j].weight < min1)
			{
				min1 = T[j].weight;
				*p1 = j;
			}
		}
	}
	for (j = 0; j < i; j += 1)
	{
		if (-1 == T[j].parent)
		{
			if (T[j].weight < min2 && j != *p1)
			{
				min2 = T[j].weight;
				*p2 = j;
			}
		}
	}
}

void make_hfm_t(HF T)
{
	int p1 = 0;
	int p2 = 0;
	int i = 0;
	for (i = n; i < 2 * n - 1; i += 1)
	{
		sel_hfm(T, i, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		//printf("%d", n);
		T[i].left_child = T[p1].weight;
		T[i].right_child = T[p2].weight;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void print_hfm_t(HF T)
{
	int i = 0;
	printf("哈夫曼树的各边显示:\n");
	for (i = n; i < 2 * n - 1; i += 1)
	{
		printf("(%d,%d) (%d,%d)\n", T[i].weight, T[i].left_child, T[i].weight, T[i].right_child);
	}
}

void Areat(HF T, int i)
{
	if (-1 != T[T[i].parent].parent)
	{
		Areat(T, T[i].parent);
	}
	if (T[i].weight == T[T[i].parent].right_child)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}

void coder_hfm_t(HF T)
{
	int i = 0;
	int j = 0;
	int a = 0;
	//L* Q = (L*)malloc(sizeof(L));
	printf("哈夫曼编码\n");
	for (i = 0; i < n; i += 1)
	{
		a = i;
		//printf("%d", T[i].parent);
		//Q->top = -1;
		printf("%d的编码:", T[i].weight);
		Areat(T, i);
		
		/*for (j = Q->top; j >= 0; j -= 1)
		{
			printf("%d", Q->data[j]);
		}*/
		printf("\n");
		i = a;
	}
}

int main(void)
{
	HF T;
	inps_HFM(T);
	make_hfm_t(T);
	print_hfm_t(T);
	coder_hfm_t(T);
	return 0;
}