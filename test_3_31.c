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
				//��ʼ��˳���
				InitList(&L);
				//��˳��������ʼԪ�أ�
				CreateList(&L);
				//��ʾ˳���
				system("cls");
				DispList(&L);
				if (0 == L.Length
					)
				{
					puts("��Ϊ�գ���");
				}
				break;
			case 2:
				//�ж����Ƿ���
				if (L.Length == MAXLEN)
				{
					printf("\n�������������ȥɾ������");
					break;
				}
				for (;;)
				{
					// ������Ҫ�����λ�ã�
					printf("\n������Ҫ�����λ�ã�");
					scanf("%d", &n);
					if (0 < n && n <= L.Length + 1)
					{
						// ������ʲôData  x��
						printf("\n������Ԫ��:");
						scanf("%d", &x);
						InsElem(&L, n, x);
						break;
					}
					else
					{
						printf("\nλ�ò���������Ҫ�����λ�����ף���");
						printf("\n�㻹������𣡣�\nYes---1\nNo---0\n");
						scanf("%d", &n);
						if (0 == n)
						{
							break;
						}
					}
					
				}
				
				break;
			case 3:
				//���Ƿ�Ϊ��
				if (L.Length == 0)
				{
					printf("��գ�û����ɾ����\n");
					system("pause");
				}
				//��Ҫɾ����λ��
				else
				{
					for (;;)
					{
						printf("\n��������Ҫɾ����λ�ã�");
						scanf("%d", &n);
						if (0 < n && n <= L.Length)
						{
							DelElem(&L, n, &x);
							printf("\n�ѽ�[%d]λ�õ�%dɾ��\n", n, x);
							system("pause");
							break;
						}
						else
						{
							printf("\n����ɾ���ĵط�û��Ԫ�أ���");
							printf("\n�㻹��ɾ���𣡣�\nYes---1\nNo---0\n");
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
				//�ж����Ƿ�Ϊ��
				if (L.Length == 0)
				{
					printf("��Ϊ�գ���\n");
					system("pause");
					break;
				}
				//��Ҫ���ҵ�λ��
				else
				{
					for (;;)
					{
						printf("\n��Ҫ���ҵ�λ�ã�");
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
							printf("\nλ�ò��Ϸ�");
							printf("�������������\nYes----1.\nNo----0.");
							scanf("%d", &n);
							if (0 == n)
							{
								break;
							}
						}
					}
				}
				//���ز��ҵ���ֵ
				
				
				break;
			case 5:
				//�жϱ��Ƿ�Ϊ��
				if (0 == L.Length)
				{
					printf("��Ϊ��");
					printf("\n");
					system("pause");
					break;
				}
				//��Ҫ���ҵ�ֵ
				else
				{
					printf("\n��������Ҫ���ҵ�ֵ����");
					scanf("%d", &x);
					diag = Locate(&L, &n, x);
					if (1 == diag)
					{
						printf("\n�ҵ��ˣ���[%d]��λ", n);
						printf("\n");
						system("pause");
					}
					else
					{
						printf("\n�Ҳ�������");
						printf("\n");
						system("pause");
					}

				}
				//���ز���ֵ��λ��
				break;
			case 6:
				if (L.Length == 0)
				{
					puts("���");
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
				printf("���벻�ԣ�����������\n");
				break;
			}


		} while (ret);
	


	return 0;
}




