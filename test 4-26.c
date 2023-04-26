#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>


typedef struct seq_stack {
	char data[100];
	int top;
}seq_stack;

void init_stack(seq_stack* S) {
	S->top = -1;
}

void push(seq_stack* S, char x) {
	if (S->top <= 99) {
		S->data[++S->top] = x;
	}
}

void pop(seq_stack* S,char* x) {
	if (S->top != -1) {
		*x = S->data[S->top--];
	}
}

int main() {
	seq_stack S;
	char x = 'c';
	char y = 'k';
	init_stack(&S);
	push(&S, x);
	push(&S, 'A');
	push(&S, y);
	pop(&S, &x);
	push(&S, 't');
	push(&S, x);
	pop(&S, &x);
	push(&S, 'S');
	for (; S.top != -1;) {
		pop(&S, &y);
		printf("%c", y);
	}
	printf("%c\n", x);
	return 0;
}