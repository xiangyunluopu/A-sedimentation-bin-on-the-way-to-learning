#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100

typedef int DataType;
typedef struct stacknode {
	DataType data;
	struct stacknode* next;
}Stack;

void MenuStack() {
	printf("     这是一个栈，现在是菜单      \n");
	printf("=================================\n");
	printf("|       1. 初始化栈             |\n");
	printf("|       2. 入栈操作             |\n");
	printf("|       3. 弹栈操作             |\n");
	printf("|       4. get_top元素          |\n");
	printf("|       5. show_栈中元素        |\n");
	printf("|       6. 十、二进制转换       |\n");
	printf("|       0. out                  |\n");
	printf("=================================\n");
	printf("请输入（ 0 - 7 ）>:");
}

Stack* InitStack(Stack* S) {
	Stack* P = NULL;
	if (NULL != S) {
		for (; P != NULL;) {
			P = S->next;
			free(S);
			S = P;
		}
		return P;
	}
	else {
		return S;
	}
}

Stack* PushStack(Stack* S, int num) {
	char dis = 0;
	Stack* P = NULL;
	for (;num > 0; num -= 1) {
		P = (Stack*)malloc(sizeof(Stack));
		printf("剩余[%d]你想放什么值>:", num);dis = scanf("%d", &P->data);
		// 头
		P->next = S;
		S = P;
	}
	return P;
}

int EmptyStack(Stack* S) {
	if (NULL == S) {
		return 1;
	}
	else {
		return 0;
	}
}

Stack* PopStack(Stack* S, DataType* x, int* nu1) {
	Stack* P = NULL;
	if (EmptyStack(S)) {
		*nu1 = 1;
		return S;
	}
	else {
		P = S;
		S = P->next;
		*x = P->data;
		free(P);
		return S;
	}
}



int get_top(Stack* S, DataType* x) {
	if (EmptyStack(S)) {
		return 1;
	}
	else {
		*x = S->data;
		return 0;
	}
}

Push(Stack* S, DataType x) {
	Stack* P = (Stack*)malloc(sizeof(Stack));
	P->data = x;
	P->next = S;
	S = P;
	return S;
}

Stack* D_B(Stack* S, DataType* x) {
	for (; *x;) {
		S = Push(S, *x % 2);
		*x /= 2;
	}
	return S;
}

int main() {
	char dis = 0;
	int nu1 = 0;
	int cd1 = ~0;
	Stack* S = NULL;
	Stack* p = NULL;
	DataType x = 0;
	int num = 0;
	//int arr[MAXSIZE] = { 0 };
	for (; cd1;) {

		MenuStack();
		dis = scanf("%d", &cd1);
		switch (cd1) {
		case 0:
			cd1 = ~cd1;
			break;
		case 1:
			S = InitStack(S);
			break;
		case 2:
			up1:
			printf("你想放几个进去>:"); dis = scanf("%d", &num);
			if (num < 0 || num > 20) {
				printf("这个数目，不可以\n");
				goto up1;
			}
			else if (0 == num) {
				goto down1;
			}
			S = PushStack(S, num);
			down1:
			num = 0;
			break;
		case 3:
			S = PopStack(S, &x, &nu1);
			if (nu1) {
				printf("栈空，不能出栈\n");
			}
			else {
				printf("[%d]弹出栈\n", x);
				x = 0;
			}
			nu1 = 1;
			break;
		case 4:
			nu1 = get_top(S, &x);
			if (nu1) {
				printf("栈空\n");
			}
			else {
				printf("top[%d]\n", x);
				x = 0;
			}
			break;
		case 5:
			if (NULL == S) {
				printf("栈空\n");
			}
			else {
				p = S;
				printf("栈中元素为>:");
				for (; p != NULL; p = p->next) {
					printf("%3d", p->data);
				}
				printf("\n");
				p = NULL;
			}
			break;
		case 6:
			printf("请输入你想转换的值0d>:"); scanf("%d", &x);
			S = D_B(S, &x);
			if (NULL != S) {
				printf("转换之后的值0b>:");
				if (S->data >= 0) {
					for (; NULL != S;) {
						printf("%d", S->data);
						p = S->next;
						free(S);
						S = p;
					}
				}
				else {
					for (nu1 = 0; NULL != S;) {
						if (nu1) {
							printf("%d", S->data * -1);
							p = S->next;
							free(S);
							S = p;
						}
						else {
							printf("%d", S->data);
							p = S->next;
							free(S);
							S = p;
							nu1 = ~nu1;
						}
					}
				}
				printf("\n");
				nu1 = 0;
			}
			else {
				printf("转化失败\n");
			}
			break;
		case 7:

			break;
		default:
			printf("请重输\n");
			break;
		}
		
	}

	return 0;
}