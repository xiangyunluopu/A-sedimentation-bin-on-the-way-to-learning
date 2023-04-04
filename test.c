#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*******************\n");
	printf("** 1.play  0.out **\n");
	printf("*******************\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		if (1 == input)
		{
			game();
		}
		if (1 != input && 0 != input)
		{
			printf(" ‰»Î¥ÌŒÛ\n");
		}

	} while (input);
	return 0;
}