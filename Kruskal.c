#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100

typedef struct
{
	int u;
	int v;
	int w;
}Edge;

int CreateEdge(Edge E[MAX])
{
	int anum = 0;
	int i = 0;
	printf("请输入边的个数>:");
	scanf("%d", &anum);
	getchar();
	printf("输入格式: 序号1 序号2 权值w\n");
	for (i = 0; i < anum; i += 1)
	{
		printf("v1 v2 w >: ");
		scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
	}
	return anum;
}

void sort(Edge E[MAX], int n)
{
	Edge temp;
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i += 1)
	{
		for (j = i + 1; j < n; j += 1)
		{
			if (E[i].w > E[j].w)
			{
				temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}
}

int seeks(int set[MAX], int vi)
{
	while (set[vi] > 0)
	{
		vi = set[vi];
	}
	return vi;
}

void Kruskal(Edge E[MAX], int n)
{
	int v1 = 0;
	int v2 = 0;
	int i = 0;
	int set[MAX] = { 0 };
	// n 是边的个数
	printf("最小生成树为>:\n");
	for (i = 0; i < n; i += 1)
	{
		v1 = seeks(set, E[i].u);
		v2 = seeks(set, E[i].v);
		if (v1 != v2)
		{
			printf("(%d, %d) %d\n", v1, v2, E[i].w);
			set[v1] = v2;
		}
	}
}

int main(void)
{
	int n = 0;
	Edge E[MAX];
	n = CreateEdge(E);
	sort(E, n);
	Kruskal(E, n);
	return 0;
}