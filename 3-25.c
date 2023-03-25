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
//			puts("输入错误，请重新输入\n");
//			system("pause");
//			system("cls");
//		}
//	}
//	return 0;
//}
//int www()
//{
//	puts("猜数字\n");
//	puts("确认请按1\n");
//	puts("退出请按0\n");
//	return 0;
//}
//int game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand() % 100;
//	for (;;)
//	{
//		printf("请输入->:");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			puts("\n猜大了");
//		}
//		if (ret > guess)
//		{
//			puts("\n猜小了");
//		}
//		if (ret == guess)
//		{
//			printf("\n猜对了 guess = %d", ret);
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
//	printf("goto死循环！！");
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
//	printf("你的电脑在60s内将关机！！\n");
//	c:
//	printf("请输入“我是天才！！”来解除关机！！\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是天才！！") == 0)
//	{
//		system("shutdown /a");
//	}
//	else
//	{
//		goto c;
//	}
//	return 0;
//}