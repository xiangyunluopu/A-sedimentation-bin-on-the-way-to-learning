#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int date = 0;
	double price = 5000;
	int grade = 0;
	printf("请输入您的出行月份(1 ~ 12)\n");
	up:
	scanf("%d", &date);
	if (4 <= date && date <= 10)
	{
		// 旺季
		printf("请问您选择头等舱还是经济舱? 头等舱输入 1，经济舱输入 2\n");
		scanf("%d", &grade);
		while (grade != 1 && grade != 2)
		{
			printf("输入不合法，请重新输入(1 ~ 2)>:");
			scanf("%d", &grade);
		}
		if (1 == grade)
		{
			printf("您的机票价格为：%lf", price * 0.9);
		}
		else
		{
			printf("您的机票价格为：%lf", price * 0.6);
		}
	}
	else if (1 <= date && date < 4 || 10 < date && date <= 12)
	{
		// 淡季
		printf("请问您选择头等舱还是经济舱? 头等舱输入 1，经济舱输入 2\n");
		scanf("%d", &grade);
		while (grade != 1 && grade != 2)
		{
			printf("输入不合法，请重新输入(1 ~ 2)>:");
			scanf("%d", &grade);
		}
		if (1 == grade)
		{
			printf("您的机票价格为：%lf", price * 0.5);
		}
		else
		{
			printf("您的机票价格为：%lf", price * 0.4);
		}
	}
	else
	{
		printf("月份输入错误，请重新输入(1 ~ 12)>:");
		goto up;
	}
	return 0;
}