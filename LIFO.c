#define _CRT_SECURE_NO_WARNINGS 1

#include "LIFO.h"

void mune() {
	printf("=======================\n");
	printf("|      1.初始化栈     |\n");
	printf("|      2.入栈操作     |\n");
	printf("|      3.出栈操作     |\n");
	printf("|      4.get栈顶元素  |\n");
	printf("|      0.out          |\n");
	printf("=======================\n");
}
void InitStack(SeqStack* S) {
	S->top = -1;
}

int FullStack(SeqStack* S) {
	if ((MAXLEN - 1) == S->top) {
		return 1;
	}
	else {
		return 0;
	}
}

int Push(SeqStack* S, int ret) {
	// 判断栈是否为满,随后插入；
	int i = 0;
	if (1 == FullStack(S)) {
		return 1;
	}
	else if ((ret + S->top +1) > MAXLEN){
		return 2;
	}
	else {
		for (i = 1; i <= ret; i += 1) {
			printf("请输入第%d个入栈的值>:", i);
			scanf("%d", &x);
			S->top += 1;
			S->data[S->top] = x;
		}
		return 0;
	}
}

int EmptyStack(SeqStack* S) {

	if (-1 == S->top) {
		return 1;
	}
	else if (-1 != S->top) {
		return 0;
	}

}

int Pop(SeqStack* S, int num) {
	// 出栈，我只需要判断是否为空即可
	if (num < 0) {
		return 3;
	}
	if (1 == EmptyStack(S)) {
		return 1;
	}
	else if((S->top - num) < -1){
		return 2;
	}
	else {
		for (;num; num -= 1) {
			S->top -= 1;
		}
		return 0;
	}
}

int GetTop(SeqStack* S) {
	// 判断栈是否为空
	if (1 == EmptyStack(S)) {
		return 1;
	}
	// 不为空就获取top元素
	else if (0 == EmptyStack(S)) {
		x = S->data[S->top];
		return 0;
	}
}