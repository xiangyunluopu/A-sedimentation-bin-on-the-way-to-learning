#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int main()
{
	int t = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		scanf("%d", &t);
		switch (t)
		{
		case 0:
			break;
		case 1:
			play();
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (t);

	return 0;
}