#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
void menu()
{
	printf("**************************\n");
	printf("*****paly.1  out.0 *******\n");
	printf("**************************\n");
}

void initNAC(char (*NAC)[COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i += 1)
	{
		for (j = 0; j < COL; j += 1)
		{
			NAC[i][j] = ' ';
		}
	}
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |    
void my_printf(char (*NAC)[COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i += 1)
	{
		for (j = 0; j < COL; j += 1)
		{
			printf(" %c ", NAC[i][j]);
			if (j < COL - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j += 1)
			{
				printf("¡ª-");
				if (j < COL - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
}
void gameNAC()
{
	char NAC[ROW][COL] = { 0 };
	initNAC(NAC);
	my_printf(NAC);

}
