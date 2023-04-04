#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	
	//创建mine棋盘和show棋盘
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	// 随机数起点  时间戳
	srand((unsigned int)time(NULL));
	// 初始化mine棋盘
	initboard(mine, ROWS, COLS, '0');
	// 布置雷
	setmine(mine);
	// 打印雷的位置
	//dispboard(mine, ROW, COL);
	// 初始化show棋盘
	initboard(show, ROWS, COLS, '*');
	// dispboard
	dispboard(show, ROW, COL);
	//play
	play(mine, show);
}

void play(char mine[ROWS][COLS], char show[ROWS][ROWS])
{
	int n = ROW * COL - setcount;
	int x = 0;
	int y = 0;
	
	for (;n;)
	{
		printf("请输入:>");
		scanf("%d %d", &x, &y);
		if (1 <= x && x <= ROW && 1 <= y && y <= COL)
		{
			if ('1' == mine[x][y])
			{
				printf("你被炸死了\n");
				break;
			}
			else
			{
				plays(mine, show, x , y, &n);
				system("cls");
				dispboard(show, ROW, COL);
			}

		}
		else
		{
			printf("输入错误\n");
		}
	}
	if (0 == n);
	{
		printf("恭喜获胜！！！\n");
		dispboard(mine, ROW, COL);
	}
	
}

void plays(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* n)
{
	if ('*' == show[x][y])
	{
		if (0 == countboards(mine, x, y))
		{
			show[x][y] = ' ';
			*n -= 1;
			if (x - 1 >= 1 && y + 1 <= COL)
			{
				plays(mine, show, x - 1, y + 1, n);
			}
			if (x - 1 >= 1)
			{
				plays(mine, show, x - 1, y, n);
			}
			if (x - 1 >= 1 && y - 1 >= 1)
			{
				plays(mine, show, x - 1, y - 1, n);
			}
			if (y - 1 >= 1)
			{
				plays(mine, show, x, y - 1, n);
			}
			if (x + 1 <= ROW && y - 1 >= 1)
			{
				plays(mine, show, x + 1, y - 1, n);
			}
			if (x + 1 <= ROW)
			{
				plays(mine, show, x + 1, y, n);
			}
			if (x + 1 <= ROW && y + 1 <= COL)
			{
				plays(mine, show, x + 1, y + 1, n);
			}
			if (y + 1 <= COL)
			{
				plays(mine, show, x, y + 1, n);
			}
		}
		else
		{
			show[x][y] = '0' + countboards(mine, x, y);
			*n -= 1;
		}
		
	}


}

char countboards(char mine[ROWS][COLS], int x, int y)
{
	return
		(mine[x - 1][y + 1] - '0') + (mine[x - 1][y] - '0') +
		(mine[x - 1][y - 1] - '0') + (mine[x][y - 1] - '0') +
		(mine[x + 1][y - 1] - '0') + (mine[x + 1][y] - '0') +
		(mine[x + 1][y + 1] - '0') + (mine[x][y + 1] - '0');
}

void setmine(char mine[ROWS][COLS])
{
	int flag = setcount;
	int x = 0;
	int y = 0;
	for (;flag;)
	{
		x = rand() % ROW + 1; y = rand() % COL + 1;
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] != '1')
			{
				mine[x][y] = '1';
				flag -= 1;
			}
		}
	}
}




void dispboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i += 1)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i += 1)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j += 1)
		{
			printf("%c ", board[j][i]);
			
		}

		printf("\n");
	}
}

void initboard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i += 1)
	{
		for (j = 0; j < col; j += 1)
		{
			board[i][j] = set;
		}
	}
}