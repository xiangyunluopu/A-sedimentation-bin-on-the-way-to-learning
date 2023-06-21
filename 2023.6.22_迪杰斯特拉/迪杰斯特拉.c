#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100
#define M 65535

int Create_Collar_Matrix(int cost[][MAX])
{
	int vnum = 0/*��*/, anum = 0/*����*/;
	int v1 = 0, v2 = 0, w = 0;
	int i = 0, j = 0;

	printf("�����붥��ĸ����ͱߵĸ���(��ʽ:anum vnum)(�ÿո������):>");
	scanf("%d %d", &anum, &vnum); getchar();

	for (i = 0; i < anum; i += 1)
		for (j = 0; j < anum; j += 1)
			cost[i][j] = M;

	for (i = 1; i <= vnum; i += 1)
	{
		printf("������%d���ߵ������յ���Ȩֵ(��ʽ:v1 v2 w)(�ÿո������)>:", i);
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
				printf("%d -> %d�����·����ȨֵΪ%d,���·���ĵ���Ϊ>:", v, i, dist[i]);
				while (path[per] != per)
				{
					printf("%d ->", per);
					per = path[per];
				}
				printf("%d\n", v);
			}
			else
			{
				printf("%d ->%dû��·��\n", v, i);
			}
		}
	}

}

int main(void)
{
	int cost[MAX][MAX] = { 0 };
	int anum = 0, v = 0;
	anum = Create_Collar_Matrix(cost);
	printf("����������С·�������:>");
	scanf("%d", &v); getchar();
	Dijkstra(cost, anum, v);
	return 0;
}