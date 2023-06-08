#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int k = 0;
	float f = 0.0;
	printf("请输入成绩和性别\n( 性别男键入: 1 , 性别女键入: 0)\n( 键入格式:scord  sex)\n");
	scanf("%f %d", &f, &k);
	//printf("%f, %d", k, f);
	while (f <= 0)
	{
		printf("成绩不合法，请重新键入成绩>:");
		scanf("%f", &f);
	}
	while (k != 0 && k != 1)
	{
		printf("性别键入错误，请重新键入性别( 0 或 1 )>:");
		scanf("%d", &k);
	}
	if (f < 12)
	{
		if (k)
		{
			printf("进入男子决赛\n");
		}
		else
		{
			printf("进入女子决赛\n");
		}

	}
	else
	{
		printf("很遗憾，没有进入决赛\n");
	}
	return 0;
} 