#pragma once

#define ALL 3
#define ROW ALL
#define COL ALL

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void play();
void initNAC(char NAC[ROW][COL]);
void dispNAC(char NAC[ROW][COL]);
void playNAC(char NAC[ROW][COL]);
void computerNAC(char NAC[ROW][COL]);