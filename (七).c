#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define MAX 20

void Sort(char* p)
{
	char tmp[MAX] = { 0 };
	if (strcmp(p, p + MAX) > 0)
	{
		strcpy(tmp, p);
		strcpy(p, p + MAX);
		strcpy(p + MAX, tmp);
	}
	if (strcmp(p, p + MAX + MAX) > 0)
	{
		strcpy(tmp, p);
		strcpy(p, p + MAX + MAX);
		strcpy(p + MAX + MAX, tmp);
	}
	if (strcmp(p + MAX, p + MAX + MAX) > 0)
	{
		strcpy(tmp, p + MAX);
		strcpy(p + MAX, p + MAX + MAX);
		strcpy(p + MAX + MAX, tmp);
	}
}

int main(void)
{
	char name[3][MAX] = { 0 };
	char* p = &name[0][0];
	printf("����������>:");
	scanf("%s", p); getchar();
	printf("������΢����>:");
	scanf("%s", p + MAX); getchar();
	printf("������QQ��>:");
	scanf("%s", p + (MAX * 2)); getchar();
	Sort(p);
	printf("�ַ����ɴ�С����Ϊ: %s  %s  %s", p, p + MAX, p + (2 * MAX));
	return 0;
}