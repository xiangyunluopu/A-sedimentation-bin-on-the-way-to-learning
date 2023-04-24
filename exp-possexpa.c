#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct zh {
	char ch[10];
	int top;
};

int main() {
	int i = 0;
	int j = 0;
	struct zh zh;
	zh.top = -1;
	char exp[6];
	char possexp[10];
	char* xp = exp;
	scanf("%s", &exp);
	for (; *xp != '\0';) {
		switch (*xp) {
		case '(':
			zh.top += 1;
			zh.ch[zh.top] = *xp;
			xp += 1;
			break;
		case ')':
			for (; zh.ch[zh.top] != '(';) {
				possexp[i++] = zh.ch[zh.top];
				zh.top -= 1;
			}
			xp -= 1;
			break;
		case '*':
		case '/':
			for (; '*' == zh.ch[zh.top] || '/' == zh.ch[zh.top];) {
				possexp[i++] = zh.ch[zh.top];
				zh.top -= 1;
			}
			zh.top += 1;
			zh.ch[zh.top] = *xp;
			xp += 1;
			break;
		case '+':
		case '-':
			for (; '(' != zh.ch[zh.top] && -1 != zh.top;) {
				possexp[i++] = zh.ch[zh.top];
				zh.top -= 1;
			}
			zh.top += 1;
			zh.ch[zh.top] = *xp;
			xp += 1;
			break;
		case ' ':
			xp += 1;
			break;
		default:
			for (;'0' <= *xp && *xp <= '9';) {
				possexp[i++] = *xp;
				xp += 1;
			}
			possexp[i++] = ',';
			break;
		}
		for (; -1 != zh.top;) {
			zh.top -= 1;
			possexp[i++] = zh.ch[zh.top];
		}
	}
	possexp[i] = '\0';
	printf("%s", possexp);
	return 0;
}