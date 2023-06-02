#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define M 34267
#define	MAX 100

//#define add };

int Createcost(int cost[MAX][MAX])
{
	int vnum = 0;
	int anum = 0;
	int i = 0;
	int j = 0;
	int v1 = 0;
	int v2 = 0;
	int w = 0;
	printf("\n请输入顶点数和边数>:");
	scanf("%d %d", &vnum, &anum);

	for (i = 0; i < vnum; i += 1)
	{
		for (j = 0; j < vnum; j += 1)
		{
			cost[i][j] = M;
		}
	}
	printf("起点 终点 权值\n");
	printf(" v1   v2   w\n");
	for (i = 0; i < anum; i += 1)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		cost[v1][v2] = w;
	}

	return vnum;
}

void Dijkstra(int cost[MAX][MAX], int n, int v)
{
	int s[MAX] = { 0 };
	int path[MAX] = { 0 };
	int dust[MAX] = { 0 };
	int i = 0, j = 0, k = 0;
	int u = 0, pre = 0, mindis = 0;

	for (i = 0; i < n; i += 1)
	{
		dust[i] = cost[v][i];
		if (cost[v][i] < M)
		{
			path[i] = v;
		}
		else
		{
			path[i] = -1;
		}
	}
	path[v] = v;
	s[v] = 1;

	for (i = 0; i < n - 1; i += 1)
	{
		mindis = M;
		k = -1;
		for (j = 0; j < n; j += 1)
		{
			if (0 == s[j] && dust[j] < mindis)
			{
				mindis = dust[j];
				k = j;
			}
		}
		if (-1 != k)
		{
			s[k] = 1;
			for (j = 0; j < n; j += 1)
			{
				if (s[j] != 1 && dust[j] > dust[k] + cost[k][j])
				{
					dust[j] = dust[k] + cost[k][j];
					path[j] = k;
				}
			}
		}
	}
	printf("Dijkstra\n");
	for (i = 0; i < n; i += 1)
	{
		if (i != v)
		{
			printf("(%d-->%d)[%d] == (", v, i, dust[i]);
			pre = i;
			while (path[pre] != pre)
			{
				printf(" %d <-- ", pre);
				pre = path[pre];
			}
			printf(" %d )\n", path[pre]);
		}
	}
}

int main(void)
{
	int n = 0;
	int cost[MAX][MAX] = { 0 };
	n = Createcost(cost);
	Dijkstra(cost, n, 0);
	return 0;
}