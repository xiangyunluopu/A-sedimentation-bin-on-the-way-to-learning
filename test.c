#define _CRT_SECURE_NO_WARNINGS 1

#include "LIFO.h"

int main() {
	char n = -1;
	int A = 0;
	int i = 0;
	int j = 0;
	SeqStack S;
	int flag = 0;
	InitStack(&S);
	do {
		mune();
		scanf("%d", &A);
		switch (A) {
		case 1:
			InitStack(&S);
			break;
		case 2:
			printf("请输入想要入栈的个数>:");
			scanf("%d", &i);
			flag = Push(&S, i);
			i = 0;
			if (1 == flag) {
				printf("栈满\n");
			}
			else if (2 == flag) {
				printf("想要入栈的个数超出栈空间\n");
			}
			else {
				printf("入栈 OK \n");
			}
			break;
		case 3:
			printf("请输入想要弹栈的个数>:");
			scanf("%d", &i);
			flag = Pop(&S, i);
			if (1 == flag) {
				printf("栈空\n");
			}
			else if (2 == flag) {
				printf("出栈个数太多\n");
			}
			else if (3 == flag) {
				printf("数字不合法\n");
			}
			else {
				printf("弹栈， ok\n");
			}
			break;
		case 4:
			flag = GetTop(&S);
			if (1 == flag) {
				printf("栈空");
			}
			else if (0 == flag) {
				printf("Top:%d\n", x);
			}
			break;
		case 0:
			n = ~n;
			break;
		default:
			printf("输入错误\n");
		}
	} while (n);



	return 0;
}