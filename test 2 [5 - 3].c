#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

#define BOARD 3
#define ROW BOARD
#define COL BOARD  // ��������Ϊ 3*3 ��С 

#define play_board '*' // ��������µ�����Ϊ *
#define computer_board '#' // ���õ����µ�����Ϊ #

void Menu(void) {
	printf("*------------*\n");
	printf("|  0.out     |\n");
	printf("|  1.play    |\n");
	printf("*------------*\n");
}

void init_board(char board[ROW][COL]) { // ���������Ϊ�ո� 
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i += 1) {
		for (j = 0; j < COL; j += 1) {
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL]) { // ʵ�����̴�ӡ
	int i = 0;							 //    |   |    // 1.0
	int j = 0;							 // ---|---|--- // 0.0
	for (i = 0; i < ROW; i += 1) {		 //    |   |    // 1.1
		for (j = 0; j < COL; j += 1) {	 // ---|---|--- // 0.1
			printf(" %c ", board[i][j]); //    |   |    // 1.2
			if (j < COL - 1) {
				printf("|");
			}
			if (COL - 1 == j) {
				printf("\n");
			}
		} // ����������� �����ӡ [1.0],[1.1],[1.2] ������
		//============================================
		   // ����������� �����ӡ [0.0],[0.1] ������
		if (i < ROW - 1) {
			for (j = 0; j < COL; j += 1) {
				printf("---");
				if (j < COL - 1) {
					printf("|");
				}
				if (COL - 1 == j) {
					printf("\n");
				}
			}
		}
	}
}

void computer_play_chess(char board[ROW][COL]) { // �����������
	printf("������\n");
	int x = 0;
	int y = 0;
	while (1) {
		/*x = rand() % COL;
		y = rand() % ROW;*/
		x = 0;
		y = 1;
		if (board[y][x] == ' ') { // �ж��������λ���Ƿ�Ϊ��
			board[y][x] = computer_board;
			break;
		}
	}
}

void play_chess(char board[ROW][COL]) {
	int y = 0;
	int x = 0;
	up:
	printf("������x,y����>:");
	scanf("%d%d", &x, &y);
	if (board[y - 1][x - 1] != ' ' && 1 <= x && x <= COL && 1 <= y && y <= ROW) {
		printf("����������\n");
		goto up;
	}
	board[y - 1][x - 1] = play_board;
}

char judge(char board[ROW][COL]) {
	int y = 0;
	int x = 0;
	for (y = 0; y < ROW; y += 1) {
		if (board[y][0] != ' ' && board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
			return board[y][0];
		}
	}
	for (x = 0; x < COL; x += 1) {
		if (board[0][x] != ' ' && board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
			return board[0][x];
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return board[1][1];
	}
	if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
		return board[1][1];
	}
	for (y = 0; y < ROW; y += 1) {
		for (x = 0; x < COL; x += 1) {
			if (' ' == board[y][x]) {
				return '?';
			}
		}
	}
	return '!';
}

void play(void) { // ������� 
	//�ȴ�ӡ���̣���Ҫһ����ά���飬��Ҫ�ȳ�ʼ������䡮�ո񡯣� 
	char board[ROW][COL] = { 0 }; // ���ǽ�������������
	init_board(board); // ��ʼ������
	//print_board(board); // ��ӡ������������д��ע�ʹ���
	// ���������̵�׼��
	
	// �������������
	// ����� *�� ������ #
	// ��win����ֵΪ * �������ʤ��
	// ��win����ֵΪ # �������ʤ��
	// ��win����ֵΪ ���������
	// ��win����ֵΪ ������ƽ��
	char win = 0;
	while (1) { // ������ѭ�� �ھ����жϲ�Ϊ '?' ʱ����ѭ��
		// ������   
		computer_play_chess(board);
		// ��ӡ����
		print_board(board);
		system("pause");// ��ͣһ��
		// �жϾ���
		win = judge(board);
		if ('?' != win) {
			break;
		}
		// �����
		play_chess(board);
		// ��ӡ����
		print_board(board);
		system("pause"); // ��ͣһ��
		// �жϾ���
		win = judge(board);
		if ('?' != win) {
			break;
		}
	}
	if ('*' == win) {
		printf("���ʤ\n");
	}
	else if ('#' == win) {
		printf("���Ի�ʤ\n");
	}
	else if ('!' == win) {
		printf("ƽ��\n");
	}
}

int main(void) {
	srand((unsigned int)time(NULL)); // ����ʱ�����Ϊ��������ɺ��������
	int menu = 0;                    // Ϊ�������������ӣ���׼��
	do {
		Menu(); // ���������˵�
		scanf("%d", &menu);
		if (1 == menu) {
			play();
		}
	} while (menu);
	
	return 0;
}