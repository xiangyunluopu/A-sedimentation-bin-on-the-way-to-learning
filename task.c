#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
			break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break;






	}
	switch (i)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("������\n");
			break;
		case 6:
		case 7:
			printf("��Ϣ��\n");
	}
	if (i > 7)
		printf("������Χ��������1~7!!");
	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int i;
//	scanf("%d",&i);
//	if (i < 18)
//	{
//		printf("δ����\n");
//		printf("����̸������\n");
//	}
//	else if (i>=18 && i<28)
//	{
//		printf("����\n");
//	}
//	else if (i>=28 && i<50)
//	{
//		printf("׳��\n");
//	}
//	else if (i >= 50)
//	{
//		if (i < 88)
//		{
//			printf("������");
//		}
//		else (i >= 88);
//		{
//			printf("�ϲ���");
//		}
//
//	}
//
//	return 0;
//}