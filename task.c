#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
			break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期七\n");
		break;






	}
	switch (i)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("工作日\n");
			break;
		case 6:
		case 7:
			printf("休息日\n");
	}
	if (i > 7)
		printf("超出范围，请输入1~7!!");
	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int i;
//	scanf("%d",&i);
//	if (i < 18)
//	{
//		printf("未成年\n");
//		printf("不能谈恋爱！\n");
//	}
//	else if (i>=18 && i<28)
//	{
//		printf("青年\n");
//	}
//	else if (i>=28 && i<50)
//	{
//		printf("壮年\n");
//	}
//	else if (i >= 50)
//	{
//		if (i < 88)
//		{
//			printf("老年人");
//		}
//		else (i >= 88);
//		{
//			printf("老不死");
//		}
//
//	}
//
//	return 0;
//}