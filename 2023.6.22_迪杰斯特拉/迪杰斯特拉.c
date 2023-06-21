#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100
#define M 65535

int Create_Collar_Matrix(int cost[][MAX])
{
	int vnum = 0/*边*/, anum = 0/*顶点*/;
	int v1 = 0, v2 = 0, w = 0;
	int i = 0, j = 0;

	printf("请输入顶点的个数和边的个数(格式:anum vnum)(用空格做间隔):>");
	scanf("%d %d", &anum, &vnum); getchar();

	for (i = 0; i < anum; i += 1)
		for (j = 0; j < anum; j += 1)
			cost[i][j] = M;

	for (i = 1; i <= vnum; i += 1)
	{
		printf("请输入%d条边的起点和终点与权值(格式:v1 v2 w)(用空格做间隔)>:", i);
		scanf("%d %d %d", &v1, &v2, &w); getchar();
		cost[v1][v2] = w;
	}

	return anum;
}

void Dijkstra(int cost[][MAX], int anum, int v)
{
	int s[MAX] = { 0 }, path[MAX] = { 0 }, dist[MAX] = { 0 };
	int i = 0, j = 0;

	for (i = 0; i < anum; i += 1)
	{
		if (i != v)
		{
			s[i] = 0;
			dist[i] = cost[v][i];
			if (dist[i] < M)
			{
				path[i] = v;
			}
			else
			{
				path[i] = -1;
			}
		}
		else
		{
			s[v] = 1;
			dist[v] = 0;
			path[v] = v;
		}
	}

	for (i = 0; i < anum; i += 1)
	{
		int mindis = M;
		int u = -1;
		for (j = 0; j < anum; j += 1)
		{
			if (0 == s[j] && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		}
		if (u != -1)
		{
			s[u] = 1;
			for (j = 0; j < anum; j += 1)
			{
				if (0 == s[j] && cost[u][j] + dist[u] < dist[j])
				{
					dist[j] = cost[u][j] + dist[u];
					path[j] = u;
				}
			}
		}

	}

	for (i = 0; i < anum; i += 1)
	{
		if (i != v)
		{
			if (dist[i] < M)
			{
				int per = i;
				printf("%d -> %d的最短路径的权值为%d,最短路径的倒序为>:", v, i, dist[i]);
				while (path[per] != per)
				{
					printf("%d ->", per);
					per = path[per];
				}
				printf("%d\n", v);
			}
			else
			{
				printf("%d ->%d没有路径\n", v, i);
			}
		}
	}

}

int main(void)
{
	int cost[MAX][MAX] = { 0 };
	int anum = 0, v = 0;
	anum = Create_Collar_Matrix(cost);
	printf("请输入求最小路径的起点:>");
	scanf("%d", &v); getchar();
	Dijkstra(cost, anum, v);
	return 0;
}