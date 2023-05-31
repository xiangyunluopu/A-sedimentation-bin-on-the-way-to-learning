#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100

typedef struct
{
	int n, e; // n:������ ��e:������
	char vexs[MAX]; // ��������
	int edges[MAX][MAX]; // �ߵ��ڽӾ���
}MGraph;

void CreateMGraph(MGraph* G)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int s = 0;
	char ch1 = 0;
	char ch2 = 0;
	printf("�����붥����>:");
	scanf("%d", &G->n); getchar();
	printf("������ߵĸ���>:");
	scanf("%d", &G->e); getchar();
	for (i = 0; i < G->n; i += 1)
	{
		printf("�������%d������", i + 1);
		scanf("%c", &G->vexs[i]);
		getchar();
	}
	for (i = 0; i < G->n; i += 1)
	{
		for (j = 0; j < G->n; j += 1)
		{
			G->edges[i][j] = 0;
		}
	}
	for (n = 0; n < G->e; n += 1)
	{
		printf("�������%d����>:", n + 1);
		scanf("%c %c", &ch1, &ch2);
		getchar();
		for (s = 0; s < G->n; s += 1)
		{
			if (G->vexs[s] == ch1)
			{
				i = s;
			}
			if (G->vexs[s] == ch2)
			{
				j = s;
			}
		}
		G->edges[i][j] = 1;
		G->edges[j][i] = 1;
	}
}

void DispMGraph(MGraph G)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < G.n; i += 1)
	{
		for (j = 0; j < G.n; j += 1)
		{
			printf("%5d", G.edges[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	DispMGraph(G);
	return 0;
}