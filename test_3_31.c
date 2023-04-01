#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int IS()
//{
//	return -1;
//}
//
//int main()
//{
//	int i = 0;
//	if (i = IS())
//	{
//		printf("0");
//	}
//	else
//	{
//		printf("6");
//	}
//
//}

#include"Seqlist.h"

int main()
{
	Seqlist L;
	DataType x;
	int ret = 1;
	int diag = 0;
	char j = 0;
	int n = 0;
		do
		{
			if (0 == j)
			{
				InitList(&L);
				j = 1;
			}
			else
			{
				system("cls");
				DispList(&L);
			}
			Menu();
			scanf("%d", &ret);
			switch (ret)
			{
			case 1:
				//初始化顺序表；
				InitList(&L);
				//向顺序表输入初始元素；
				CreateList(&L);
				//显示顺序表；
				system("cls");
				DispList(&L);
				if (0 == L.Length
					)
				{
					puts("表为空！！");
				}
				break;
			case 2:
				//判读表是否满
				if (L.Length == MAXLEN)
				{
					printf("\n表满，想插入先去删除！！");
					break;
				}
				for (;;)
				{
					// 请输入要插入的位置；
					printf("\n请输入要插入的位置：");
					scanf("%d", &n);
					if (0 < n && n <= L.Length + 1)
					{
						// 想输入什么Data  x；
						printf("\n请输入元素:");
						scanf("%d", &x);
						InsElem(&L, n, x);
						break;
					}
					else
					{
						printf("\n位置不连续或想要插入的位置离谱！！");
						printf("\n你还想插入吗！！\nYes---1\nNo---0\n");
						scanf("%d", &n);
						if (0 == n)
						{
							break;
						}
					}
					
				}
				
				break;
			case 3:
				//表是否为空
				if (L.Length == 0)
				{
					printf("表空，没东西删！！\n");
					system("pause");
				}
				//想要删除的位置
				else
				{
					for (;;)
					{
						printf("\n请输入想要删除的位置：");
						scanf("%d", &n);
						if (0 < n && n <= L.Length)
						{
							DelElem(&L, n, &x);
							printf("\n已将[%d]位置的%d删除\n", n, x);
							system("pause");
							break;
						}
						else
						{
							printf("\n你想删除的地方没有元素！！");
							printf("\n你还想删除吗！！\nYes---1\nNo---0\n");
							scanf("%d", &n);
							if (0 == n)
							{
								break;
							}
						}
					}
				}
				break;
			case 4:
				//判读表是否为空
				if (L.Length == 0)
				{
					printf("表为空！！\n");
					system("pause");
					break;
				}
				//想要查找的位置
				else
				{
					for (;;)
					{
						printf("\n想要查找的位置：");
						scanf("%d", &n);
						if (0 < n && n <= L.Length)
						{
							GetElem(&L, n, &x);
							printf("[%d]:%d", n,x);
							printf("\n");
							system("pause");
							break;
						}
						else
						{
							printf("\n位置不合法");
							printf("还想继续查找吗？\nYes----1.\nNo----0.");
							scanf("%d", &n);
							if (0 == n)
							{
								break;
							}
						}
					}
				}
				//返回查找到的值
				
				
				break;
			case 5:
				//判断表是否为空
				if (0 == L.Length)
				{
					printf("表为空");
					printf("\n");
					system("pause");
					break;
				}
				//想要查找的值
				else
				{
					printf("\n请输入想要查找的值！！");
					scanf("%d", &x);
					diag = Locate(&L, &n, x);
					if (1 == diag)
					{
						printf("\n找到了，在[%d]号位", n);
						printf("\n");
						system("pause");
					}
					else
					{
						printf("\n找不到！！");
						printf("\n");
						system("pause");
					}

				}
				//反回查找值的位置
				break;
			case 6:
				if (L.Length == 0)
				{
					puts("表空");
					system("pause");
				}
				else
				{
					DispList(&L);
					printf("\n");
					system("pause");
				}
				break;
			case 0:
				ret = 0;
				break;
			default:
				system("cls");
				printf("输入不对，请重新输入\n");
				break;
			}


		} while (ret);
	


	return 0;
}




