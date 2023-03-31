#pragma once

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void meun();
void initNAC(char NAC[ROW][COL]);
void game();
void my_printf(char NAC[ROW][COL]);
void play_NAC(char NAC[ROW][COL]);
void computer_play_NAC(char NAC[ROW][COL]);
char is_win(char NAC[ROW][COL]);
int dogfall(char NAC[ROW][COL]);
