#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100
#define M 65535

int GTCM(int cost[][MAX])
{
	//int cost[MAX][MAX] = { 0 };
	int vnum = 0, anum = 0;
	int i = 0, j = 0;
	int k = 0, h = 0;
	printf("请输入边的个数与顶点的个数:");
	scanf("%d %d", &anum, &vnum);
	for (i = 0; i < vnum; i += 1)
		for (j = 0; j < vnum; j += 1)
			cost[i][j] = M;
	printf("请输入各个边的边与权值(v1 v2 w)\n");
	for (i = 0; i < anum; i += 1)
	{
		printf("v1 v2 w:"), scanf("%d %d %d", &j, &k, &h);
		cost[j][k] = h, cost[k][j] = h;
	}
	return vnum;
}

void Prim(int cost[][MAX], int n)
{
	int lowcost[MAX] = { 0 }, closet[MAX] = { 0 };
	int i = 0, j = 0, k = 0;
	for (i = 1; i < n; i += 1)
	{
		lowcost[i] = cost[0][i];
		closet[i] = 0;
	}
	closet[0] = -1;
	for (i = 1; i < n; i += 1)
	{
		int min = M;
		k = i;
		for (j = 1; j < n; j += 1)
		{
			if (lowcost[j] < min && closet[j] != -1)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf("%d -> %d , W = %d\n", closet[k], k, lowcost[k]);
		closet[k] = -1;
		if (i != n - 1)
		{
			for (j = 1; j < n; j += 1)
			{
				if (closet[j] != -1 && cost[k][j] < lowcost[j])
				{
					lowcost[j] = cost[k][j];
					closet[j] = k;
				}
			}
		}
	}

}

int main(void)
{
	int cost[MAX][MAX] = { 0 };
	int n = 0;
	n = GTCM(cost);
	printf("最小生成树为:\n");
	Prim(cost, n);
	return 0;
}