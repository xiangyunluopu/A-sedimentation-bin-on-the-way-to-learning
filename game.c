#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("***********************\n");
	printf("*** 1.play   0. out ***\n");
	printf("***********************\n");
}

void initNAC(char NAC[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i += 1)
	{
		for (j = 0; j < 3; j += 1)
		{
			NAC[i][j] = ' ';
		}
	}
}

//    |   |   
// ---|---|---
//    |   |   
// ---|---|---
//    |   |   
//

void dispNAC(char NAC[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < COL; i += 1)
	{
		for (j = 0; j < ROW; j += 1)
		{
			printf(" %c ", NAC[i][j]);
			if (j < ROW - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < COL - 1)
		{
			for (j = 0; j < ROW; j += 1)
			{
				printf("---");
				if (j < ROW - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void playNAC(char NAC[ROW][COL])
{
	int x = 0, y = 0;
	for (;;)
	{
		scanf("%d %d", &x, &y);
		if (1 <= x && x <= COL && 1 <= y && y <= ROW)
		{
			NAC[y - 1][x - 1] = '*';
			break;
		}
		else
		{
			printf("位置不合法\n");
		}
	}
}

void computerNAC(char NAC[ROW][COL])
{
	int x = 0, y = 0;
	for (;;)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (NAC[y][x] == ' ')
		{
			NAC[y][x] = '#';
			break;
		}
	}

}

char ju_NAC(char NAC[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ALL; i += 1)
	{
		if (NAC[0][i] == NAC[1][i] && NAC[1][i] == NAC[2][i] && NAC[1][i] != ' ')
		{
			return NAC[1][i];
		}
		if (NAC[i][0] == NAC[i][1] && NAC[i][1] == NAC[i][2] && NAC[i][1] != ' ')
		{
			return NAC[i][1];
		}
		
	}
	if (NAC[0][0] == NAC[1][1] && NAC[1][1] == NAC[2][2] && NAC[1][1] != ' ')
	{
		return NAC[1][1];
	}
	if (NAC[0][2] == NAC[1][1] && NAC[1][1] == NAC[2][0] && NAC[1][1] != ' ')
	{
		return NAC[1][1];
	}
	
	for (i = 0; i < ALL; i += 1)
	{
		for (j = 0; j < ALL; j += 1)
		{
			if (NAC[i][j] == ' ')
			{
				return '1';
			}
		}
	}
	return '0';
}
//玩家赢 -- *
//电脑赢 -- #
//平局   -- 0
//继续   -- 1
void play()
{
	char ret = 0;
	char NAC[ROW][COL] = { 0 };
	//  初始化棋盘
	initNAC(NAC);
	dispNAC(NAC);
	for (;;)
	{
		
		playNAC(NAC);
		dispNAC(NAC);
		ret = ju_NAC(NAC);
		if (ret == '*')
		{
			printf("赢\n");
			break;
		}
		else if (ret == '#')
		{
			printf("输\n");
			break;
		}
		else if (ret == '0')
		{
			printf("平\n");
			break;
		}
		computerNAC(NAC);
		dispNAC(NAC);
		ret = ju_NAC(NAC);
		if (ret == '*')
		{
			printf("赢\n");
			break;
		}
		else if (ret == '#')
		{
			printf("输\n");
			break;
		}
		else if (ret == '0')
		{
			printf("平\n");
			break;
		}

	}
	
}