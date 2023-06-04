#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

#define MAX 100
#define VertexType char

int visited[MAX] = { 0 };

typedef struct node
{
	int adjvex;
	struct node* next;
}EdgeNode;

typedef struct vexnode
{
	VertexType data;
	EdgeNode* firstedge;
}VHeadNode;

typedef struct
{
	VHeadNode adjlist[MAX];
	int vnum, anum;
}Adjlist;

void MenuGraph(void)
{
	printf("\n            图子系统");
	printf("\n===================================");
	printf("\n|      1——更新邻接表            |");
	printf("\n|      2——深度优先遍历          |");
	printf("\n|      3——广度优先遍历          |");
	printf("\n|      0——返回                  |");
	printf("\n===================================");
	printf("\n请输入菜单号( 0 ~ 3 )>:");
}

void CreateAGraph(Adjlist* G, char flag)
{
	int i = 0, j = 0, k = 0;
	EdgeNode* p = NULL;
	if ('0' == flag)
	{
		printf("\n无向图");
	}
	else
	{
		printf("\n有向图");
	}
	printf("\n请输入顶点个数>:");
	scanf("%d", &i); getchar();
	while (i <= 0 || i > MAX)
	{
		printf("\n请重新输入顶点个数>:");
		scanf("%d", &i); getchar();
	}
	G->vnum = i;
	printf("\n请输入边的个数>:");
	scanf("%d", &i); getchar();
	if ('0' == flag)
	{
		while (i <= 0 || i > ((G->vnum - 1) * G->vnum) / 2)
		{
			printf("\n请重新输入边的个数>:");
			scanf("%d", &i); getchar();
		}
	}
	else
	{
		while (i <= 0 || i > (G->vnum - 1) * G->vnum)
		{
			printf("\n请重新输入边的个数>:");
			scanf("%d", &i); getchar();
		}
	}
	G->anum = i;
	printf("\n以下输入各个顶点的值( 从 [1] 开始 )");
	for (i = 0; i < G->vnum; i += 1)
	{
		printf("\n请键入第%d个顶点的值>:", i + 1);
		scanf("%c", &G->adjlist[i].data); getchar();
	}
	printf("\n以下输入边的信息( 从 [0] 开始 , 格式:v1 v2 )");
	for (k = 0; k < G->anum; k += 1)
	{
		printf("\n键入第%d条边>:", k);
		scanf("%d %d", &i, &j); getchar();
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;
		if ('0' == flag)
		{
			p = (EdgeNode*)malloc(sizeof(EdgeNode));
			p->adjvex = i;
			p->next = G->adjlist[j].firstedge;
			G->adjlist[j].firstedge = p;
		}
	}
}

void DispAGraph(Adjlist G)
{
	int i = 0;
	EdgeNode* p = NULL;
	for (i = 0; i < G.vnum; i += 1)
	{
		printf("\n%d [%c]", i, G.adjlist[i].data);
		p = G.adjlist[i].firstedge;
		while (NULL != p)
		{
			printf(" --> %d [%c]", p->adjvex, G.adjlist[p->adjvex].data);
			p = p->next;
		}
	}
}

void DFS(Adjlist* G, int vi)
{
	printf("( %d , %c )", vi, G->adjlist[vi].data);
	visited[vi] = 1;
	EdgeNode* p = G->adjlist[vi].firstedge;
	while (NULL != p)
	{
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex); 
		// 我没有判断是否遍历，大失误；
		p = p->next;
	}
}

void BFS(Adjlist* G, int vi)
{
	int qu[MAX] = { 0 }, rear = 0, front = 0;
	EdgeNode* p = NULL;
	printf("\n");
	rear = (rear + 1) % MAX;
	qu[rear] = vi;
	visited[vi] = 1;
	while (rear != front)
	{
		front = (front + 1) % MAX;
		vi = qu[front];
		printf("( %d , %c )", vi, G->adjlist[vi].data);
		p = G->adjlist[vi].firstedge;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				rear = (rear + 1) % MAX;
				qu[rear] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}

int main(void)
{
	Adjlist G = { 0 };
	char ch1 = 0;
	char ch2 = 0;
	char flag = 0;
	int num1 = 0;

	ch1 = 'y';
	while ('y' == ch1 || 'Y' == ch2)
	{
		MenuGraph();
		scanf("%c", &ch2);
		getchar();
		switch (ch2)
		{
		case '1':
			gtup1:
			printf("\n如想建立无向图请输入( 0 )");
			printf("\n如想建立有向图请输入( 1 )");
			printf("\n请键入>:");
			scanf("%c", &flag);
			getchar();
			if ('0' != flag && '1' != flag)
			{
				goto gtup1;
			}
			CreateAGraph(&G, flag);
			DispAGraph(G);
			break;
		case '2':
			printf("\n以下为深度优先遍历");
			printf("\n请输入DFS的起点>:");
			scanf("%d", &num1); getchar();
			if (num1 < 0 || num1 >= G.vnum)
			{
				printf("\n起点错误");
			}
			else
			{
				DFS(&G, num1);
				for (num1 = 0; num1 < G.vnum; num1 += 1)
				{
					visited[num1] = 0;
				}
			}
			break;
		case '3':
			printf("\n以下为广度优先遍历");
			printf("\n请输入BFS的起点>:");
			scanf("%d", &num1); getchar();
			if (num1 < 0 || num1 >= G.vnum)
			{
				printf("\n起点错误");
			}
			else
			{
				BFS(&G, num1);
				for (num1 = 0; num1 < G.vnum; num1 += 1)
				{
					visited[num1] = 0;
				}
			}
			break;
		case '0':
			ch1 = 'n';
			break;
		default:
			printf("输入错误\n");
			break;
		}
		if ('0' != ch2)
		{
			printf("\n按回车键继续，按任意键返回主菜单\n");
			ch2 = getchar();
			if ('\xA' != ch2)
			{
				getchar();
				ch1 = 'n';
			}
		}
	}

	return 0;
}