#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//#include<Windows.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	
//	for (;;)
//	{
//		int i = 0;
//		system("cls");
//		www();
//		scanf("%d", &i);
//		if (0 == i)
//		{
//			break;
//		}
//		else if (1 == i)
//		{
//			game();
//		}
//		else
//		{
//			puts("�����������������\n");
//			system("pause");
//			system("cls");
//		}
//	}
//	return 0;
//}
//int www()
//{
//	puts("������\n");
//	puts("ȷ���밴1\n");
//	puts("�˳��밴0\n");
//	return 0;
//}
//int game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand() % 100;
//	for (;;)
//	{
//		printf("������->:");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			puts("\n�´���");
//		}
//		if (ret > guess)
//		{
//			puts("\n��С��");
//		}
//		if (ret == guess)
//		{
//			printf("\n�¶��� guess = %d", ret);
//			system("pause");
//			break;
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	syz:
//	printf("goto��ѭ������");
//	goto syz;
//	return 0;
//}
//#include<stdio.h>
//#include<Windows.h>
//#include<string.h>
//int main()
//{
//	char input[10] = { '0' };
//	system("shutdown /s /t 60");
//	printf("��ĵ�����60s�ڽ��ػ�����\n");
//	c:
//	printf("�����롰������ţ�����������ػ�����\n");
//	scanf("%s", input);
//	if (strcmp(input, "������ţ���") == 0)
//	{
//		system("shutdown /a");
//	}
//	else
//	{
//		goto c;
//	}
//	return 0;
//}