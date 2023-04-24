#define _CRT_SECURE_NO_WARNINGS 1

#define size 100

#include <stdio.h>

void trans(char exp[size], char possexp[size]) {
	int j = 0;
	struct zhang {
		char f[size];
		int top;
	};
	struct zhang op;
	op.top = -1;
	for ( j = -1; *exp != '\n';) {
		switch (*exp) {
		case '+':
		case '-':
			if (op.f[op.top] != '(' && op.top != -1) {
				for (; op.f[op.top] != '(' && op.top != -1;) {
					j += 1;
					possexp[j] = op.f[op.top];
					op.top -= 1;
				}
			}
			op.top += 1;
			op.f[op.top] = *exp;
			exp++;
			break;
		case '*':
		case '/':
			if (op.f[op.top] == '*' || op.f[op.top] == '/') {
				for (; op.top != -1 && (op.f[op.top] == '*' || op.f[op.top] == '/');) {
					j += 1;
					possexp[j] = op.f[op.top];
					op.top -= 1;
				}
			}
			
			op.top += 1;
			op.f[op.top] = *exp;
			exp += 1;
			break;
		case '(':
			op.top += 1;
			op.f[op.top] = *exp;
			exp += 1;
			break;
		case ')':
			for (; op.f[op.top] != '(';) {
				j += 1;
				possexp[j] = op.f[op.top];
				op.top -= 1;
			}
			exp += 1;
		case ' ':
			exp += 1;
			break;
		default:
			for (; '0' <= *exp && *exp <= '9';) {
				j += 1;
				possexp[j] = *exp;
				exp += 1;
			}
			j += 1;
			possexp[j] = '#';
			break;
		}
		
	}
	j += 1;
	possexp[j] = '\0';
	printf("%s", possexp);
	
}

int main() {
	char exp[size] = { 0 };
	char possexp[size] = { 0 };
	scanf("%s", exp);

	trans(exp, possexp);

	return 0;
}

//#include <stdio.h>
//
//int i = 0;
//
//int main() {
//
//	printf("[%d]hello,world!\n", i);
//
//	
//		main();
//	
//
//	return 0;
//}