#pragma once

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2
#define setcount 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void menu();
void game();
void initboard(char board[ROWS][COLS], int row, int col, char set);
void dispboard(char board[ROWS][COLS], int row, int col);
void setmine(char mine[ROWS][COLS]);
char countboards(char mine[ROWS][COLS], int x, int y);
void play(char mine[ROWS][COLS], char show[ROWS][ROWS]);
void plays(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* n);