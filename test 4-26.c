#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <malloc.h>
//
//
//typedef struct seq_stack {
//	char data[100];
//	int top;
//}seq_stack;
//
//void init_stack(seq_stack* S) {
//	S->top = -1;
//}
//
//void push(seq_stack* S, char x) {
//	if (S->top <= 99) {
//		S->data[++S->top] = x;
//	}
//}
//
//void pop(seq_stack* S,char* x) {
//	if (S->top != -1) {
//		*x = S->data[S->top--];
//	}
//}
//
//int main() {
//	seq_stack S;
//	char x = 'c';
//	char y = 'k';
//	init_stack(&S);
//	push(&S, x);
//	push(&S, 'A');
//	push(&S, y);
//	pop(&S, &x);
//	push(&S, 't');
//	push(&S, x);
//	pop(&S, &x);
//	push(&S, 'S');
//	for (; S.top != -1;) {
//		pop(&S, &y);
//		printf("%c", y);
//	}
//	printf("%c\n", x);
//	return 0;
//}

// ʵ��ʮ���ƣ�ת��Ϊ�˽��ƣ�

//#include <stdio.h>
//
//typedef struct zh {
//	int data[100];
//	int top;
//}zh;
//
//void ob(zh* op, int x) {
//	if (0 != x) {
//		op->data[++op->top] = x % 8;
//		ob(op, x / 8);
//	}
//}
//
//int main() {
//	zh op;
//	op.top = -1;
//	int x = 0;
//	printf("������һ��ʮ������>:");
//	scanf("%d", &x);
//	ob(&op, x);
//	printf("ת�����ֵΪ>:");
//	for (; op.top != -1;) {
//		printf("%d", op.data[op.top--]);
//	}
//	return 0;
//}

// ���ʽ�ӵ�Բ�����Ƿ���ȷ
#include <stdio.h>

int flag = 0;

int main() {
	int i = 0;
	char exp[20] = { '\0' };
	printf("�������Բ���ŵļ���ʽ(��.��β)>:");
	scanf("%s", exp);
	for (i = 0; '.' != *(exp + i); i += 1) {
		if ('(' == *(exp + i)) {
			flag += 1;
		}
		else if (')' == *(exp + i)) {
			flag -= 1;
		}
	}
	if (!flag) {
		printf("this ok.\n");
	}
	else {
		printf("emmmm\n");
	}
	return 0;
}




















