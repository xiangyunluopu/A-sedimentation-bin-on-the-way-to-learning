#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void meun()
{
	printf("*****************\n");
	printf("**play.1  out.0**\n");
	printf("*****************\n");
}
void initNAC(char NAC[ROW][COL])
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
void my_printf(char NAC[ROW][COL])
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
				printf("---");
				if (j < COL - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}
void play_NAC(char NAC[ROW][COL])
{
	int x = 0;
	int y = 0;
	printf("������(�ÿո�ָ���x��y)����:");
	for (;;)
	{
		
		scanf("%d%d", &x, &y);
		if ((x > 0 && x <= ROW) && (y > 0 && y <= COL))
		{
			if (' ' == NAC[x - 1][y - 1])
			{
				NAC[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ע��");
			}

		}
		else
		{
			printf("���벻�Ϸ�");
		}
	}

}
void computer_play_NAC(char NAC[ROW][COL])
{
	int x = 0;
	int y = 0;
	for (;;)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (x < ROW && y < COL)
		{
			if (NAC[x][y] == ' ')
			{
				NAC[x][y] = '#';
				break;
			}
		}
	}
}
//���Ӯ����*
//����Ӯ����#
// ƽ�֡���1
// ��������0
int dogfall(char NAC[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i += 1)
	{
		for (j = 0; j < COL; j += 1)
		{
			if (NAC[i][j] == ' ')
			{
				return '0';
			}
		}
	}
	return '1';
}
//���Ӯ����*
//����Ӯ����#
// ƽ�֡���1
// ��������0
char is_win(char NAC[ROW][COL])
{
	int i = 0;
	for (i = 0; i < ROW; i += 1)
	{
		if ((NAC[i][0] == NAC[i][1]) && (NAC[i][1] == NAC[i][2]) && (NAC[i][1] != ' '))
		{
			return NAC[i][1];
		}
	}
	for (i = 0; i < COL; i += 1)
	{
		if ((NAC[0][i] == NAC[1][i]) && (NAC[1][i] == NAC[2][i]) && (NAC[1][i] != ' '))
		{
			return NAC[i][1];
		}
	}
	if ((NAC[0][0] == NAC[1][1]) && (NAC[1][1] == NAC[2][2]) && (NAC[1][1]) != ' ')
	{
		return NAC[1][1];
	}
	if ((NAC[0][2] == NAC[1][1]) && (NAC[1][1] == NAC[2][0]) && (NAC[1][1] != ' '))
	{
		return NAC[1][1];
	}
	if (dogfall(NAC) == '1')
	{
		return '1';
	}
		return '0';
}
void game()
{
	char ret = 0;
	char NAC[ROW][COL] = { 0 };
	srand((unsigned)time(NULL));
	initNAC(NAC);
	my_printf(NAC);
	for (;;)
	{
		//�����
		play_NAC(NAC);
		//����
		system("cls");
		// ��ӡ
		my_printf(NAC);
		//�жϾ���
		ret = is_win(NAC);
		if (ret != '0')
		{
			break;
		}
		//������
		computer_play_NAC(NAC);
		//����
		system("cls");
		//��ӡ
		my_printf(NAC);
		//�жϾ���
		ret = is_win(NAC);
		if (ret != '0')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("win\n\n");
	}
	else if (ret == '#')
	{
		printf("fail\n\n");
	}
	else
		printf("dogfall\n\n");

}