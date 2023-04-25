#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void trans(char* exp, char* possexp) {
	struct z {
		char data[10];
		int top;
	}op;
	op.top = -1;
	for (; ',' != *exp;) {
		switch (*exp) {
		case '(':
			op.top += 1;
			op.data[op.top] = *exp;
			exp += 1;
			break;
		case ')':
			for (; '(' != op.data[op.top];) {
				*possexp = op.data[op.top];
				possexp += 1;
				op.top--;
			}
			op.top -= 1;
			exp += 1;
			break;
		case '*':
		case '/':
			for (; '*' == op.data[op.top] || '/' == op.data[op.top];) {
				*possexp = op.data[op.top];
				possexp += 1;
				op.top -= 1;
			}
			op.top += 1;
			op.data[op.top] = *exp;
			exp += 1;
			break;
		case '+':
		case '-':
			for (; -1 != op.top && '(' != op.data[op.top];) {
				*possexp = op.data[op.top];
				possexp += 1;
				op.top -= 1;
			}
			op.top += 1;
			op.data[op.top] = *exp;
			exp += 1;
			break;
		case ' ':
			break;
		default:
			for (; '0' <= *exp && *exp <= '9';) {
				*possexp = *exp;
				possexp += 1;
				exp += 1;
			}
			*possexp = ',';
			possexp += 1;
			break;
		}
	}
	if (-1 != op.top) {
		*possexp = op.data[op.top];
		op.top -= 1;
		possexp += 1;
	}
	*possexp = '\0';
}

float compvalue(char* possexp) {
	struct M {
		float data[10];
		int top;
	}V;
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;
	float d = 0.0;
	V.top = -1;
	for (;'\0' != *possexp;) {
		switch (*possexp) {
		case '+':
			b = V.data[V.top--];
			a = V.data[V.top--];
			c = a + b;
			V.data[++V.top] = c;
			possexp += 1;
			break;
		case '-':
			b = V.data[V.top--];
			a = V.data[V.top--];
			c = a - b;
			V.data[++V.top] = c;
			possexp += 1;
			break;
		case '*':
			b = V.data[V.top--];
			a = V.data[V.top--];
			c = a * b;
			V.data[++V.top] = c;
			possexp += 1;
			break;
		case '/':
			b = V.data[V.top--];
			a = V.data[V.top--];
			c = a / b;
			V.data[++V.top] = c;
			possexp += 1;
			break;
		default:
			for (d = 0; ',' != *possexp;) {
				d = d * 10 + (*possexp - '0');
				possexp += 1;
			}
			possexp += 1;
			V.top += 1;
			V.data[V.top] = d;
			d = 0;
		}
	}
	for (; V.top != 0;) {
		a = V.data[V.top--];
		b = V.data[V.top--];
		c = a + b;
		V.data[++V.top] = c;
	}
	d = V.data[V.top];
	return d;
}

int main() {
	float count = 0.0;
	char possexp[50] = { 0 };
	char exp[50] = { 0 };
	scanf("%s", exp);
	//printf("%s\n", exp);
	trans(exp, possexp);
	printf("%s\n", possexp);
	count = compvalue(possexp);
	printf("%f", count);
	return 0;
}