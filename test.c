#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int main()
{
	int input = 0;
	do
	{
		
		meun();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			puts("输入错误，请重新输入！！");
		}

	} while (input);
	
	return 0;
}