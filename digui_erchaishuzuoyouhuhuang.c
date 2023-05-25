#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

typedef struct t_node
{
	char data;
	struct t_node* left_child;
	struct t_node* right_child;
}tree;

void tree_branch(tree* t)
{
	char ch1 = 0;
	tree* s = NULL;
	printf("请输入%c的左孩子('0'代表空)>:", t->data);
	scanf("%c", &ch1);
	getchar();
	if ('0' == ch1)
	{
		t->left_child = NULL;
	}
	else
	{
		s = (tree*)malloc(sizeof(tree));
		s->data = ch1;
		t->left_child = s;
		//t->left_child = ch1;
	}
	printf("请输入%c的右孩子('0'代表空)>:", t->data);
	scanf("%c", &ch1);
	getchar();
	if ('0' == ch1)
	{
		t->right_child = NULL;
	}
	else
	{
		s = (tree*)malloc(sizeof(tree));
		s->data = ch1;
		t->right_child = s;
		//t->right_child = ch1;
	}
	if (t->left_child != NULL)
	{
		tree_branch(t->left_child);
	}
	if (t->right_child != NULL)
	{
		tree_branch(t->right_child);
	}
}

void create_tree(tree* t)
{
	char ch1 = 0;
	printf("请输入根结点>:");
	scanf("%c", &ch1);
	getchar();
	t->data = ch1;
	tree_branch(t);
}

void tree_list_print(tree* t)
{
	if (NULL == t)
	{
		return;
	}
	else
	{
		printf("%c", t->data);
		if (t->left_child != NULL)
		{
			printf("(");
			tree_list_print(t->left_child);
			if (t->right_child != NULL)
			{
				printf(",");
				tree_list_print(t->right_child);
				printf(")");
			}
			else
			{
				printf(")");
			}
		}
		else if (t->right_child != NULL)
		{
			printf("(,");
			tree_list_print(t->right_child);
			printf(")");
		}
	}
}

void print_tree(tree* t)
{
	printf("(");
	tree_list_print(t);
	printf(")\n");
}

void tree_swap_child(tree* t)
{
	tree* s = NULL;
	if (NULL == t->left_child && NULL == t->right_child)
	{
		return;
	}
	else
	{
		if (t->left_child != NULL)
		{
			tree_swap_child(t->left_child);
		}
		if (t->right_child != NULL)
		{
			tree_swap_child(t->right_child);
		}
		s = t->left_child;
		t->left_child = t->right_child;
		t->right_child = s;
	}
}

int main(void)
{
	tree* t;
	t = (tree*)malloc(sizeof(tree));
	create_tree(t);
	print_tree(t);
	tree_swap_child(t);
	print_tree(t);
	return 0;
}