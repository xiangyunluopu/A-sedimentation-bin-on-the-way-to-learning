#define _CRT_SECURE_NO_WARNINGS 1

#include "LIFO.h"

void mune() {
	printf("=======================\n");
	printf("|      1.��ʼ��ջ     |\n");
	printf("|      2.��ջ����     |\n");
	printf("|      3.��ջ����     |\n");
	printf("|      4.getջ��Ԫ��  |\n");
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
	// �ж�ջ�Ƿ�Ϊ��,�����룻
	int i = 0;
	if (1 == FullStack(S)) {
		return 1;
	}
	else if ((ret + S->top +1) > MAXLEN){
		return 2;
	}
	else {
		for (i = 1; i <= ret; i += 1) {
			printf("�������%d����ջ��ֵ>:", i);
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
	// ��ջ����ֻ��Ҫ�ж��Ƿ�Ϊ�ռ���
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
	// �ж�ջ�Ƿ�Ϊ��
	if (1 == EmptyStack(S)) {
		return 1;
	}
	// ��Ϊ�վͻ�ȡtopԪ��
	else if (0 == EmptyStack(S)) {
		x = S->data[S->top];
		return 0;
	}
}