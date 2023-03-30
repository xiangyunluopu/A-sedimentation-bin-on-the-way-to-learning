#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include <stdio.h>

int main()
{
	int i = 0;
	menu();
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		gameNAC();
		break;
	case 0:
		break;
	default:
		puts("输入错误，请重新输入！！");
	}

	return 0;
}

