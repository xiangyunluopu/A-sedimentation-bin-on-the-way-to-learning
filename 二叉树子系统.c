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
	printf("	1.����һ���µĶ�����\n");
	printf("	2.������ʾ����ʾ\n");
	printf("	3.�������\n");
	printf("	4.�������\n");
	printf("	5.�������\n");
	printf("	6.��α���\n");
	printf("	7.��Ҷ�ӽ����Ŀ\n");
	printf("	8.��������������\n");
	printf("	9.�������\n");
	printf("	0.out\n");
	printf("====================================\n");
	printf("������˵���>:");
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
		printf("������%c��������>:", t->data);
		t->left_child = CreateBTree();
		printf("������%c�����Һ���>:", t->data);
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
			printf("˵����������󰴻س�������0����ʾ��̽��Ϊ�գ�\n");
			printf("�밴������������������Ľ��:\n");
			printf("����������>:");
			T = CreateBTree();
			printf("�������ѽ���\n");
			break;
		case '2':
			printf("������ʾ:");
			ShowBTree(T);
			printf("\n");
			break;
		case '3':
			printf("�������>:");
			PreOrder(T);
			printf("\n");
			break;
		case '4':
			printf("�������>:");
			InOrder(T);
			printf("\n");
			break;
		case '5':
			printf("�������>:");
			PostOrder(T);
			printf("\n");
			break;
		case '6':
			printf("��α���>:");
			LevelOrder(T);
			printf("\n");
			break;
		case '7':
			/*count = 0;
			count = Leafnum(T);*/
			printf("Ҷ��>:%d", Leafnum(T));
			printf("\n");
			break;
		case '8':
			/*count = 0;
			count = Nodenum(T);*/
			printf("�������>:%d\n", Nodenum(T));
			break;
		case '9':
			printf("�ö������������%d\n", TreeDepth(T));
			break;
		case '0':

			break;
		default:
			printf("�������\n");
			break;
		}
	} while (ch1 != '0');
	return 0;
}