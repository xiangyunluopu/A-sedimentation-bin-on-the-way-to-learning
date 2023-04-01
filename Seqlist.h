#pragma once
#define MAXLEN 100

#include<stdio.h>
#include<Windows.h>

typedef int DataType;
typedef struct
{
	DataType Data[MAXLEN];
	int Length;
}Seqlist;

void Menu();
void CreateList(Seqlist* L);
void DispList(Seqlist* L);
void InsElem(Seqlist* L, int n, int x);
void InitList(Seqlist* L);
void DelElem(Seqlist* L, int n, DataType* x);
void GetElem(Seqlist* L, int n, DataType* x);
int Locate(Seqlist* L, int* n, DataType x);