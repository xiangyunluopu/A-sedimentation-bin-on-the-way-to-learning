#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int date = 0;
	double price = 5000;
	int grade = 0;
	printf("���������ĳ����·�(1 ~ 12)\n");
	up:
	scanf("%d", &date);
	if (4 <= date && date <= 10)
	{
		// ����
		printf("������ѡ��ͷ�Ȳջ��Ǿ��ò�? ͷ�Ȳ����� 1�����ò����� 2\n");
		scanf("%d", &grade);
		while (grade != 1 && grade != 2)
		{
			printf("���벻�Ϸ�������������(1 ~ 2)>:");
			scanf("%d", &grade);
		}
		if (1 == grade)
		{
			printf("���Ļ�Ʊ�۸�Ϊ��%lf", price * 0.9);
		}
		else
		{
			printf("���Ļ�Ʊ�۸�Ϊ��%lf", price * 0.6);
		}
	}
	else if (1 <= date && date < 4 || 10 < date && date <= 12)
	{
		// ����
		printf("������ѡ��ͷ�Ȳջ��Ǿ��ò�? ͷ�Ȳ����� 1�����ò����� 2\n");
		scanf("%d", &grade);
		while (grade != 1 && grade != 2)
		{
			printf("���벻�Ϸ�������������(1 ~ 2)>:");
			scanf("%d", &grade);
		}
		if (1 == grade)
		{
			printf("���Ļ�Ʊ�۸�Ϊ��%lf", price * 0.5);
		}
		else
		{
			printf("���Ļ�Ʊ�۸�Ϊ��%lf", price * 0.4);
		}
	}
	else
	{
		printf("�·������������������(1 ~ 12)>:");
		goto up;
	}
	return 0;
}