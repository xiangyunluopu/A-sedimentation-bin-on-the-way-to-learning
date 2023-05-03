#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

#define BOARD 3
#define ROW BOARD
#define COL BOARD  // 设置棋盘为 3*3 大小 

#define play_board '*' // 设置玩家下的棋子为 *
#define computer_board '#' // 设置电脑下的棋子为 #

void Menu(void) {
	printf("*------------*\n");
	printf("|  0.out     |\n");
	printf("|  1.play    |\n");
	printf("*------------*\n");
}

void init_board(char board[ROW][COL]) { // 将棋盘填充为空格 
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i += 1) {
		for (j = 0; j < COL; j += 1) {
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL]) { // 实现棋盘打印
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
		} // 上面这个部分 负责打印 [1.0],[1.1],[1.2] 这三行
		//============================================
		   // 下面这个部分 负责打印 [0.0],[0.1] 这两行
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

void computer_play_chess(char board[ROW][COL]) { // 电脑随机下子
	printf("电脑下\n");
	int x = 0;
	int y = 0;
	while (1) {
		/*x = rand() % COL;
		y = rand() % ROW;*/
		x = 0;
		y = 1;
		if (board[y][x] == ' ') { // 判断棋盘随机位置是否为空
			board[y][x] = computer_board;
			break;
		}
	}
}

void play_chess(char board[ROW][COL]) {
	int y = 0;
	int x = 0;
	up:
	printf("请输入x,y坐标>:");
	scanf("%d%d", &x, &y);
	if (board[y - 1][x - 1] != ' ' && 1 <= x && x <= COL && 1 <= y && y <= ROW) {
		printf("请重新输入\n");
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

void play(void) { // 游玩过程 
	//先打印棋盘，需要一个二维数组，还要先初始化（填充‘空格’） 
	char board[ROW][COL] = { 0 }; // 这是将来的棋盘内容
	init_board(board); // 初始化棋盘
	//print_board(board); // 打印棋盘来看看，写后注释带掉
	// 以上是棋盘的准备
	
	// 以下是下棋过程
	// 玩家下 *， 电脑下 #
	// 设win返回值为 * 代表玩家胜利
	// 设win返回值为 # 代表电脑胜利
	// 设win返回值为 ？代表继续
	// 设win返回值为 ！代表平局
	char win = 0;
	while (1) { // 给个死循环 在局势判断不为 '?' 时跳出循环
		// 电脑下   
		computer_play_chess(board);
		// 打印棋盘
		print_board(board);
		system("pause");// 暂停一下
		// 判断局势
		win = judge(board);
		if ('?' != win) {
			break;
		}
		// 玩家下
		play_chess(board);
		// 打印棋盘
		print_board(board);
		system("pause"); // 暂停一下
		// 判断局势
		win = judge(board);
		if ('?' != win) {
			break;
		}
	}
	if ('*' == win) {
		printf("你获胜\n");
	}
	else if ('#' == win) {
		printf("电脑获胜\n");
	}
	else if ('!' == win) {
		printf("平局\n");
	}
}

int main(void) {
	srand((unsigned int)time(NULL)); // 利用时间戳作为随机数生成函数的起点
	int menu = 0;                    // 为后面电脑随机下子，做准备
	do {
		Menu(); // 首先做个菜单
		scanf("%d", &menu);
		if (1 == menu) {
			play();
		}
	} while (menu);
	
	return 0;
}