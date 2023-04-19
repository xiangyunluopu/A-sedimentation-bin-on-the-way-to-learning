#pragma once

#include <stdio.h>

#define MAXLEN 10



typedef int DataType;
DataType x;
typedef struct {
	DataType data[MAXLEN];
	int top;
}SeqStack;

void mune();
void InitStack(SeqStack* S);
int Push(SeqStack* S, int ret);
int FullStack(SeqStack* S);
int Pop(SeqStack* S, int num);
int EmptyStack(SeqStack* S);
int GetTop(SeqStack* S);

