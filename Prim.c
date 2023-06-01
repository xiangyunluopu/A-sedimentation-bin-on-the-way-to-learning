#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX 100
#define M 32767

int Create_cost(int cost[MAX][MAX])
{
	int vnum, anum;
	int i, j;
	int k;
	int v1, v2, w;
	printf("�����붨�����ͱ���>:");
	scanf("%d %d", &vnum, &anum);
	// vnum:�� �� anum:�� ��
	for (i = 0; i < vnum; i += 1)
	{
		for (j = 0; j < vnum; j += 1)
		{
			cost[i][j] = M;
		}
	}

	for (k = 0; k < anum; k += 1)
	{
		printf("�������%d��[��ʽ: v1(���) v2(�յ�) w(Ȩֵ)]>:", k + 1);
		scanf("%d %d %d", &v1, &v2, &w);
		cost[v1][v2] = w;
		cost[v2][v1] = w; // ����ͼ�Գ�
	}
	return vnum;
}

void Prim(int cost[MAX][MAX], int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lowcost[MAX] = { 0 };
	int closest[MAX] = { 0 };
	int min = M;
	printf("��С������Ϊ>:\n");
	lowcost[0] = -1;
	for (i = 1; i < n; i += 1)
	{
		lowcost[i] = cost[0][i];
	}

	for (i = 0; i < n - 1; i += 1)
	{
		min = M;
		k = i;
		for (j = 1; j < n; j += 1)
		{
			if (lowcost[j] != -1 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		lowcost[k] = -1;
		printf("(%d,%d)ȨֵΪ:%d\n", closest[k], k, min);
		for (j = 1; j < n; j += 1)
		{
			if (lowcost[j] != -1 && cost[k][j] < lowcost[j])
			{
				lowcost[j] = cost[k][j];
				closest[j] = k;
			}
		}
	}
}

int main(void)
{
	int n = 0;
	int cost[MAX][MAX] = { 0 };
	n = Create_cost(cost);
	Prim(cost, n);
	return 0;
}