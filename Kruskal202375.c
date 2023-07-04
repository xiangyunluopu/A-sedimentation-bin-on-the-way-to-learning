#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100

typedef struct
{
	int u;
	int v;
	int w;
}Edge;

Edge E[MAX];

int CreateEdge(void)
{
	int anum, i;
	printf("请输入边的个数:"), scanf("%d", &anum);
	printf("请输入各个边的顶点以及权值(v1 v2 w)\n");
	for (i = 0; i < anum; i += 1)
	{
		printf("v1 v2 w:"), scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
	}
	return anum;
}

void sort(int n)
{
	int i, j;
	Edge tmp;
	char f;

	for (i = n - 1; i > 0; i -= 1)
	{
		for (j = 0, f = 1; j < i; j += 1)
		{
			if (E[j].w > E[j + 1].w)
			{
				tmp = E[j];
				E[j] = E[j + 1];
				E[j + 1] = tmp;
				f = 0;
			}
		}
		if (f)
			break;
	}
}

int seeks(int set[], int v)
{
	int i;
	for (i = v; set[i] > 0; i = set[i]);
	return i;
}

void Kruskal(int n)
{
	int i, v1, v2;
	int set[MAX] = { 0 };
	for (i = 0; i < n; i += 1)
	{
		v1 = seeks(set, E[i].u);
		v2 = seeks(set, E[i].v);
		if (v1 != v2)
		{
			printf("(%d,%d) %d\n", E[i].u, E[i].v, E[i].w);
			set[v1] = v2;
		}
	}
}

int main(void)
{
	int n = CreateEdge();
	sort(n);
	printf("最小生成树为:\n");
	Kruskal(n);
	return 0;
}