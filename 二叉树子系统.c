#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

#define MAX 100
#define DataType char

typedef struct tree_node
{
	DataType data;
	struct tree_node* left_child;
	struct tree_node* right_child;
}BT;

void MenuTree(void)
{
	printf("====================================\n");
	printf("	1.建立一个新的二叉数\n");
	printf("	2.广义表表示法表示\n");
	printf("	3.先序遍历\n");
	printf("	4.中序遍历\n");
	printf("	5.后序遍历\n");
	printf("	6.层次遍历\n");
	printf("	7.求叶子结点数目\n");
	printf("	8.求二叉树结点总数\n");
	printf("	9.求树深度\n");
	printf("	0.out\n");
	printf("====================================\n");
	printf("请输入菜单号>:");
}



BT* CreateBTree(void)
{
	BT* t = NULL;
	DataType ch = 0;
	scanf("%c", &ch);
	getchar();
	if (ch != '0')
	{
		t = (BT*)malloc(sizeof(BT));
		t->data = ch;
		printf("请输入%c结点的左孩子>:", t->data);
		t->left_child = CreateBTree();
		printf("请输入%c结点的右孩子>:", t->data);
		t->right_child = CreateBTree();
		return t;
	}
	else
	{
		return t;
	}
}

void ShowBTree(BT* t)
{
	if (t != NULL)
	{
		printf("%c", t->data);
		if (t->left_child != NULL)
		{
			printf("(");
			ShowBTree(t->left_child);
			if (t->right_child != NULL)
			{
				printf(",");
				ShowBTree(t->right_child);
			}
			printf(")");
		}
		else if (t->right_child != NULL)
		{
			printf("(,");
			ShowBTree(t->right_child);
			printf(")");
		}
	}
}

void PreOrder(BT* T)
{
	if (T != NULL)
	{
		printf("%c", T->data);
		PreOrder(T->left_child);
		PreOrder(T->right_child);
	}
}

void InOrder(BT* T)
{
	if (T != NULL)
	{
		InOrder(T->left_child);
		printf("%c", T->data);
		InOrder(T->right_child);
	}
}

void PostOrder(BT* T)
{
	if (T != NULL)
	{
		PostOrder(T->left_child);
		PostOrder(T->right_child);
		printf("%c", T->data);
	}
}

void LevelOrder(BT* T)
{
	BT* p = T;
	int f = 1;
	int r = 2;
	BT* q[MAX] = { NULL };
	if (T != NULL)
	{
		
		do
		{
			q[f] = p;
			if (p->left_child != NULL)
			{
				q[r] = p->left_child;
				r = (r + 1) % MAX;
			}
			if (p->right_child != NULL)
			{
				q[r] = p->right_child;
				r = (r + 1) % MAX;
			}
			printf("%c", q[f]->data);
			f = (f + 1) % MAX;
			p = q[f];
		} while (f != r);
	}
}

int Leafnum(BT* T)
{
	//int count = 0;
	if (T != NULL)
	{
		if (T->left_child == NULL && T->right_child == NULL)
		{
			return 1;
		}
		else
		{
			/*count += TreeDepth(T->left_child);
			count += TreeDepth(T->right_child);*/
			return Leafnum(T->left_child) + Leafnum(T->right_child);
		}
	}
	else
	{
		return 0;
	}
	
}

int Nodenum(BT* T)
{
	if (T != NULL)
	{
		return Nodenum(T->left_child) + Nodenum(T->right_child) + 1;
	}
	else
	{
		return 0;
	}
}

int TreeDepth(BT* T)
{
	int left = 0;
	int right = 0;
	if (T != NULL)
	{
		left = TreeDepth(T->left_child);
		right = TreeDepth(T->right_child);
		if (left > right)
		{
			return 1 + left;
		}
		else
		{
			return 1 + right;
		}
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	BT* T = NULL;
	char ch1 = 0;
	//int count = 0;
	do
	{
		MenuTree();
		scanf("%c", &ch1);
		getchar();
		switch (ch1)
		{
		case '1':
			printf("说名：输入结点后按回车键（‘0’表示后继结点为空）\n");
			printf("请按先序序列输入二叉树的结点:\n");
			printf("请输入根结点>:");
			T = CreateBTree();
			printf("二叉树已建立\n");
			break;
		case '2':
			printf("广义表表示:");
			ShowBTree(T);
			printf("\n");
			break;
		case '3':
			printf("先序遍历>:");
			PreOrder(T);
			printf("\n");
			break;
		case '4':
			printf("中序遍历>:");
			InOrder(T);
			printf("\n");
			break;
		case '5':
			printf("后序遍历>:");
			PostOrder(T);
			printf("\n");
			break;
		case '6':
			printf("层次遍历>:");
			LevelOrder(T);
			printf("\n");
			break;
		case '7':
			/*count = 0;
			count = Leafnum(T);*/
			printf("叶子>:%d", Leafnum(T));
			printf("\n");
			break;
		case '8':
			/*count = 0;
			count = Nodenum(T);*/
			printf("结点总数>:%d\n", Nodenum(T));
			break;
		case '9':
			printf("该二叉树的深度是%d\n", TreeDepth(T));
			break;
		case '0':

			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (ch1 != '0');
	return 0;
}