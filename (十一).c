#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include <Windows.h>

#define MAXAC 12
#define MAX_ACCOUNT_STR 8 + 1 // �������һλ�����·� '\0'
#define MAX_PASSWORD 6 + 1 // �������һλ�����·� '\0'
#define N 999

typedef struct
{
	char ѧ��[21];
	char ����[21];
	char �Ա�[3]; // �������һ���ַ���� '\0'
	int ����;
	float ��ѧ;
	float �����;
	float �ܷ�;
}ѧ����Ԫ;

typedef struct
{
	ѧ����Ԫ ѧ��[N];
	int ѧ������;
}ѧ���б�;

typedef struct
{
	char account[MAX_ACCOUNT_STR];
	char password[MAX_PASSWORD];
}acc;

typedef struct
{
	acc List[MAXAC];
	int count_account;
}Account;

ѧ���б� ѧ���б�Ҽ = { 0 };

void Menu_Account(Account* Ac)
{
	printf("\n\t�˻��������");
	//printf("\n\t1.��¼");
	printf("\n\t1.�޸��˻������˻�����");
	printf("\n\t2.�����˻�(��ϵͳʣ�ഴ���˻�������%d)", MAXAC - Ac->count_account);
	printf("\n\t3.ɾ���˻�");
	printf("\n\t0.����");
	printf("\n\t������˵���>:");
}

int Str_Len(char* str)
{
	int count = 0;
	while (*str++ != '\0')
	{
		count += 1;
	}
	return count;
}

int Ver(Account* Ac, char* str)
{
	int i = 0;
	for (i = 0;i < Ac->count_account; i += 1)
	{
		if (0 == strcmp(Ac->List[i].account, str))
		{
			return 1;
		}
	}
	return 0;
}

void Create_Account(Account* Ac)
{
	char ch1[100] = { 0 };
	int num1 = 0;
	system("cls");
	if (MAXAC - Ac->count_account)
	{
		up1:
		printf("\n�봴���û���(�ַ�����%d)>:", MAX_ACCOUNT_STR - 1);
		scanf("%s", ch1); getchar();
		num1 = Str_Len(ch1);
		if (num1 > MAX_ACCOUNT_STR - 1 || Ver(Ac, ch1))
		{
			printf("�������û����ַ��������ƻ���û����Ѿ����ڣ�������");
			goto up1;
		}
		else
		{
			strcpy(Ac->List[Ac->count_account].account, ch1);
			printf("���ʼ�û���%s ������\n", Ac->List[Ac->count_account].account);
			up2:
			printf("��������(�ַ�����%d)>:", MAX_PASSWORD - 1);
			scanf("%s", ch1); getchar();
			num1 = Str_Len(ch1);
			if (num1 > MAX_PASSWORD - 1)
			{
				printf("����������ַ��������ƣ�������");
				goto up2;
			}
			else
			{
				strcpy(Ac->List[Ac->count_account++].password, ch1);
				//printf("%s", Ac->List[Ac->count_account].password);
				//printf("%d", Ac->count_account);
				printf("�����ɹ�\n");
				//system("pause");
			}
		}
	}
	else
	{
		printf("\nʣ���˻�Ϊ���޷�����");
	}
}

void change_password(Account* Ac, int i)
{
	//int num1 = 0;
	char str1[100];
	printf("\n������������(�ַ�����%d)>:", MAX_PASSWORD - 1);
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > MAX_PASSWORD - 1)
	{
		printf("�ַ��������ƣ�����������������(�ַ�����%d)>:", MAX_PASSWORD - 1);
		scanf("%s", str1); getchar();
	}
	strcpy(Ac->List[i].password, str1);
	printf("�˻���%s �������޸�Ϊ��%s �ɹ�", Ac->List[i].account, Ac->List[i].password);
}

void change_account(Account* Ac, int i)
{
	char str1[100] = {0};
	char str2[MAX_ACCOUNT_STR] = { 0 };
	printf("\n�������µ��˻���(�ַ�����%d)>:", MAX_ACCOUNT_STR - 1);
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > MAX_ACCOUNT_STR - 1 || Ver(Ac, str1))
	{
		printf("\n�ַ��������ƻ��˻����Ѵ��ڣ������������µ��˻���(�ַ�����%d)>:", MAX_ACCOUNT_STR - 1);
		scanf("%s", str1);
	}
	strcpy(str2, Ac->List[i].account);
	strcpy(Ac->List[i].account, str1);
	printf("\n���˻����Ѵ� %s �޸�Ϊ %s", str2, Ac->List[i].account);
}

void Change_Account(Account* Ac)
{
	int i = 0;
	int num1 = 0;
	char ch1 = 'y';
	char str1[100] = { 0 };
	system("cls");
	if (Ac->count_account == 0)
	{
		printf("\n�˻���Ϊ�㣬�޷��޸�");
		return;
	}
	while ('y' == ch1)
	{
		printf("\n���������޸ĵ��˻���>:");
		scanf("%s", str1); getchar();
		for (i = 0; i < MAXAC; i += 1)
		{
			if (0 == strcmp(str1, Ac->List[i].account))
			{
				break;
			}
		}
		if (i >= MAXAC)
		{
			printf("\n�û���������");
		}
		else
		{
			printf("\n����������>:");
			scanf("%s", str1); getchar();
			if (0 == strcmp(str1, Ac->List[i].password))
			while (1)
			{
				printf("\n�޸��˻����밴 0 ���޸��˻������밴 1 ");
				printf("������>:");
				scanf("%d", &num1); getchar();
				while (num1 != 0 && num1 != 1)
				{
					printf("���벻�Ϸ�������������>:");
					scanf("%d", &num1); getchar();
				}
				if (num1)
				{
					change_password(Ac, i);
				}
				else
				{
					change_account(Ac, i);
				}
				printf("\n�����޸Ĵ��˻��밴 0 ������ 1 ");
				printf("\n������>:");
				scanf("%d", &num1); getchar();
				while (num1 != 0 && num1 != 1)
				{
					printf("���벻�Ϸ�������������>:");
					scanf("%d", &num1); getchar();
				}
				if (num1)
				{
					break;
				}
			}
			else
			{
				printf("\n�������");
			}
		}
		printf("\n��������޸���?");
		printf("\n�����޸��밴 0 ������ 1");
		printf("\n������>:");
		scanf("%d", &num1);
		while (num1 != 0 && num1 != 1)
		{
			printf("���벻�Ϸ�������������>:");
			scanf("%d", &num1); getchar();
		}
		if (num1)
		{
			ch1 = 'n';
		}
	}
}

void Del_Account(Account* Ac)
{
	int i = 0;
	int j = 0;
	char str1[100] = { 0 };
	system("cls");
	if (0 == Ac->count_account)
	{
		printf("\n�˻���Ϊ�㣬�޷�ɾ���˻�");
		return;
	}
	printf("\n��������ɾ�����˻���>:");
	scanf("%s", str1); getchar();
	for (i = 0; i < Ac->count_account; i += 1)
	{
		if (0 == strcmp(str1, Ac->List[i].account))
		{
			break;
		}
	}
	if (i >= Ac->count_account)
	{
		printf("\n�˻�������");
	}
	else
	{
		printf("\n�������û� %s ������>:", Ac->List[i].account);
		scanf("%s", str1); getchar();
		if (0 == strcmp(Ac->List[i].password, str1))
		{
			for (j = i + 1; j < Ac->count_account; j++)
			{
				Ac->List[j - 1] = Ac->List[j];
			}
			Ac->count_account -= 1;
			printf("\n�ɹ�ɾ��");
		}
		else
		{
			printf("\n�������, ����ɾ��");
		}
	}
}

void Menu_Student_Achievement_Management_System(void)
{
	printf("\n\tѧ���ɼ��������");
	printf("\n\t1.���ѧ����Ϣ(��ϵͳ�ɴ���%d��ѧ����Ϣ��ʣ�ഢ����Ϊ:%d)", N, N - ѧ���б�Ҽ.ѧ������);
	printf("\n\t2.���ѧ����Ϣ");
	printf("\n\t3.��ѯѧ����Ϣ");
	printf("\n\t4.ɾ��ѧ����Ϣ");
	printf("\n\t5.���ܷ�����");
	printf("\n\t6.�˳��������");
	printf("\n\t������˵���(1 ~ 6)>:");
}

int Str_stu_cmp(ѧ���б�* ѧ��, char* str)
{
	int i = 0;
	if (0 == ѧ��->ѧ������)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < ѧ��->ѧ������; i += 1)
		{
			if (0 == strcmp(ѧ��->ѧ��[i].ѧ��, str))
			{
				return 1;
			}
		}
		return 0;
	}
}

void ���ѧ����Ϣ(ѧ���б�* ѧ��)
{
	char str1[100] = { 0 };
	int num1 = 0;
	float f1 = 0;
	char str2[3] = "��";
	char str3[3] = "Ů";
	system("cls");
	if (N == ѧ��->ѧ������)
	{
		printf("\nѧ���б��������޷����");
	}
	else
	{
		printf("\n������ѧ��ѧ��(�ַ����� 20)>:");
		scanf("%s", str1); getchar();
		while (Str_Len(str1) > 20 || Str_stu_cmp(ѧ��, str1))
		{
			printf("\n�������ƻ��Ѵ���,����������ѧ��(�ַ����� 20)>:");
			scanf("%s", str1); getchar();
		}
		strcpy(ѧ��->ѧ��[ѧ��->ѧ������].ѧ��, str1);
		printf("\n������ѧ������(�ַ����� 20)>:");
		scanf("%s", str1); getchar();
		while (Str_Len(str1) > 20)
		{
			printf("\n�������ƣ���������������(�ַ����� 20)>:");
			scanf("%s", str1); getchar();
		}
		strcpy(ѧ��->ѧ��[ѧ��->ѧ������].����, str1);
		printf("\n������ѧ���Ա�(���밴 0 Ů�밴 1 )>:");
		scanf("%d", &num1); getchar();
		while (0 != num1 && 1 != num1)
		{
			printf("���벻�Ϸ�������������(0 ~ 1)>:");
			scanf("%d", &num1); getchar();
		}
		if (num1)
		{
			strcpy(ѧ��->ѧ��[ѧ��->ѧ������].�Ա�, str3);
		}
		else
		{
			strcpy(ѧ��->ѧ��[ѧ��->ѧ������].�Ա�, str2);
		}
		printf("\n������ѧ������(1 ~ 200)>:");
		scanf("%d", &num1); getchar();
		while (num1 < 1 || num1 > 200)
		{
			printf("������Χ������������ѧ������(1 ~ 200)>:");
			scanf("%d", &num1); getchar();
		}
		ѧ��->ѧ��[ѧ��->ѧ������].���� = num1;
		printf("\n������ѧ����ѧ�ɼ�(0 ~ 100)>:");
		scanf("%f", &f1); getchar();
		while (num1 < 0 || num1 > 100)
		{
			printf("������Χ������������ѧ���ɼ�(0 ~ 100)>:");
			scanf("%f", &f1);
		}
		ѧ��->ѧ��[ѧ��->ѧ������].��ѧ = f1;
		printf("\n������ѧ��������ɼ�(0 ~ 100)>:");
		scanf("%f1", &f1); getchar();
		while (num1 < 0 || num1 > 100)
		{
			printf("������Χ������������ѧ���ɼ�(0 ~ 100)>:");
			scanf("%f", &f1);
		}
		ѧ��->ѧ��[ѧ��->ѧ������].����� = f1;
		ѧ��->ѧ��[ѧ��->ѧ������].�ܷ� = ѧ��->ѧ��[ѧ��->ѧ������].��ѧ + ѧ��->ѧ��[ѧ��->ѧ������].�����;
		ѧ��->ѧ������ += 1;
		printf("\n��ӳɹ�");
	}
	printf("\n");
	system("pause");
}

void Disp_stu(ѧ���б�* G)
{
	int i = 0;
	system("cls");
	if (0 == G->ѧ������)
	{
		printf("ѧ���б�Ϊ��\n");
	}
	else
	{
		for (i = 0; i < G->ѧ������; i += 1)
		{
			printf("���%d ѧ��:%s ����:%s �Ա�:%s ����:%d ��ѧ�ɼ�:%.1f ������ɼ�:%.1f �ܷ�:%.1f\n", i + 1, G->ѧ��[i].ѧ��, G->ѧ��[i].����, G->ѧ��[i].�Ա�, G->ѧ��[i].����, G->ѧ��[i].��ѧ, G->ѧ��[i].�����, G->ѧ��[i].�ܷ�);
		}
	}
	system("pause");
}

int Str_stu_cmp_1(ѧ���б�* ѧ��, char* str)
{
	int i = 0;
	if (0 == ѧ��->ѧ������)
	{
		return -1;
	}
	else
	{
		for (i = 0; i < ѧ��->ѧ������; i += 1)
		{
			if (0 == strcmp(ѧ��->ѧ��[i].ѧ��, str))
			{
				return i;
			}
		}
		return -1;
	}
}


void ��ѯѧ����Ϣ(ѧ���б�* G)
{
	int i = -1;
	char str1[100] = { 0 };
	system("cls");
	printf("\n�������ѯ��ѧ��ѧ��(�ַ����� 20)>:");
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > 20)
	{
		printf("\n��������,����������ѧ��(�ַ����� 20)>:");
		scanf("%s", str1); getchar();
	}
	i = Str_stu_cmp_1(G, str1);
	if (-1 == i)
	{
		printf("\n��ѧ�Ų�����");
	}
	else
	{
		printf("\nѧ��:%s ����:%s �Ա�:%s ����:%d ��ѧ�ɼ�:%.1f ������ɼ�:%.1f �ܷ�:%.1f", G->ѧ��[i].ѧ��, G->ѧ��[i].����, G->ѧ��[i].�Ա�, G->ѧ��[i].����, G->ѧ��[i].��ѧ, G->ѧ��[i].�����, G->ѧ��[i].�ܷ�);
	}
	printf("\n");
	system("pause");
}

void ɾ��ѧ����Ϣ(ѧ���б�* G)
{
	char str1[100] = { 0 };
	int k = 0;
	int i = 0;
	system("cls");
	if (0 == G->ѧ������)
	{
		printf("\nѧ���б�Ϊ�գ��޷�ɾ��");
	}
	else
	{
		printf("\n��������Ҫɾ����ѧ����Ϣѧ��>:");
		scanf("%s", str1); getchar();
		k = Str_stu_cmp_1(G, str1);
		if (-1 == k)
		{
			printf("\n��ѧ�Ų�����");
		}
		else
		{
			for (i = k; i < G->ѧ������ - 1; i += 1)
			{
				G->ѧ��[i] = G->ѧ��[i + 1];
			}
			G->ѧ������ -= 1;
			printf("\n�ɹ�ɾ��");
		}
	}
	printf("\n");
	system("pause");
}

void ���ܷ�����(ѧ���б�* G)
{
	int i = 0;
	int j = 0;
	char flag = 0;
	ѧ����Ԫ tmp = { 0 };
	system("cls");
	if (0 == G->ѧ������ || 1 == G->ѧ������)
	{
		printf("\nѧ������Ϊ0��1����������������");
	}
	else
	{
		//  0   1   2   3   4   5
		// [1] [2] [3] [4] [5] [6]
		//               ___
		for (i = G->ѧ������ - 1; i > 0; i -= 1)
		{
			flag = 1;
			for (j = 0; j < i; j += 1)
			{
				if (G->ѧ��[j].�ܷ� < G->ѧ��[j + 1].�ܷ�)
				{
					flag = 0;
					tmp = G->ѧ��[j];
					G->ѧ��[j] = G->ѧ��[j + 1];
					G->ѧ��[j + 1] = tmp;
				}
			}
		}
		printf("\nѧ���б��ִܷӸߵ����������");
	}
	printf("\n");
	system("pause");
}

void Student_Achievement_Management_System(void)
{
	int num1 = 0;
	while (1)
	{
		system("cls");
		Menu_Student_Achievement_Management_System();
		scanf("%d", &num1); getchar();
		switch (num1)
		{
		case 1:
			���ѧ����Ϣ(&ѧ���б�Ҽ);
			break;
		case 2:
			Disp_stu(&ѧ���б�Ҽ);
			break;
		case 3:
			��ѯѧ����Ϣ(&ѧ���б�Ҽ);
			break;
		case 4:
			ɾ��ѧ����Ϣ(&ѧ���б�Ҽ);
			break;
		case 5:
			���ܷ�����(&ѧ���б�Ҽ);
			break;
		case 6:
			printf("\n�����˳��������");
			break;
		default:
			printf("\n���벻�Ϸ�");
			system("pause");
			break;
		}
		if (6 == num1)
		{
			break;
		}
	}
}

void Log_in(Account* Ac)
{
	char str1[100] = { 0 };
	int i = 0;
	int count = 0;
	system("cls");
	if (0 == Ac->count_account)
	{
		printf("\n�˻���Ϊ�㣬�޷���¼");
	}
	else
	{
		printf("\n�������û���>:");
		scanf("%s", str1); getchar();
		for (i = 0; i < Ac->count_account; i += 1)
		{
			if (0 == strcmp(Ac->List[i].account, str1))
			{
				break;
			}
		}
		if (i >= Ac->count_account)
		{
			printf("\n�˻���������");
		}
		else
		{
			up3:
			printf("\n�������¼����>:");
			scanf("%s", str1); getchar();
			if (0 == strcmp(Ac->List[i].password, str1))
			{
				printf("\n��¼�ɹ�\n");
				system("pause");
				system("cls");
				//printf("\n��������ѧ���ɼ�����ϵͳ\n");
				//system("pause");
				//system("cls");
				Student_Achievement_Management_System();
			}
			else
			{
				printf("\n�������");
				count += 1;
				if (count < 3)
				{
					printf("\n����һ��");
					goto up3;
				}
				else
				{
					printf("\n���˱�����");
				}
			}
		}
	}
	
}

void menus(void)
{
	system("cls");
	printf("��¼�밴1���˻������밴2,�˳��밴0(������)>:");
}

void passp(Account* Ac)
{
	char password[10] = "123456";
	char str[100] = { 0 };
	printf("�����˻���Ҫϵͳ�������룬������>:");
	scanf("%s", str); getchar();
	if (0 == strcmp(password, str))
	{
		Create_Account(Ac);
	}
	else
	{
		printf("�������\n");
	}
}

int main(void)
{
	Account Ac = { "0" };
	//char ch1 = 'y';
	int num1 = 0;
	while (1)
	{
		menus();
		scanf("%d", &num1); getchar();
		if (1 == num1)
		{
			 Log_in(&Ac);
			 system("pause");
		}
		else if (2 == num1)
		{
			while (1)
			{
				system("cls");
				Menu_Account(&Ac);
				scanf("%d", &num1); getchar();
				switch (num1)
				{
				case 0:
					//ch1 = '0';
					//printf("\n����\n");
					break;
					//case 1:
						//Log_in(&Ac);
						//break;
				case 1:
					Change_Account(&Ac);
					break;
				case 2:
					passp(&Ac);
					break;
				case 3:
					Del_Account(&Ac);
					break;
				default:
					printf("\n���벻�Ϸ�\n");
					break;
				}
				printf("\n");
				if (0 == num1)
				{
					break;
				}
				system("pause");
			}
		}
		else if (0 == num1)
		{
			break;
		}
		else
		{
			printf("���벻�Ϸ�\n");
			system("pause");
		}
	}
	

	return 0;
}