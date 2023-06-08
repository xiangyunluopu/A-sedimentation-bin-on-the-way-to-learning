#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include <Windows.h>

#define MAXAC 12
#define MAX_ACCOUNT_STR 8 + 1 // 多出来的一位用来陈放 '\0'
#define MAX_PASSWORD 6 + 1 // 多出来的一位用来陈放 '\0'
#define N 999

typedef struct
{
	char 学号[21];
	char 姓名[21];
	char 性别[3]; // 多出来的一个字符存放 '\0'
	int 年龄;
	float 数学;
	float 计算机;
	float 总分;
}学生单元;

typedef struct
{
	学生单元 学生[N];
	int 学生个数;
}学生列表;

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

学生列表 学生列表壹 = { 0 };

void Menu_Account(Account* Ac)
{
	printf("\n\t账户管理界面");
	//printf("\n\t1.登录");
	printf("\n\t1.修改账户名或账户密码");
	printf("\n\t2.创建账户(本系统剩余创建账户个数：%d)", MAXAC - Ac->count_account);
	printf("\n\t3.删除账户");
	printf("\n\t0.返回");
	printf("\n\t请输入菜单号>:");
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
		printf("\n请创建用户名(字符限制%d)>:", MAX_ACCOUNT_STR - 1);
		scanf("%s", ch1); getchar();
		num1 = Str_Len(ch1);
		if (num1 > MAX_ACCOUNT_STR - 1 || Ver(Ac, ch1))
		{
			printf("创建的用户名字符超出限制或该用户名已经存在，请重试");
			goto up1;
		}
		else
		{
			strcpy(Ac->List[Ac->count_account].account, ch1);
			printf("请初始用户：%s 的密码\n", Ac->List[Ac->count_account].account);
			up2:
			printf("输入密码(字符限制%d)>:", MAX_PASSWORD - 1);
			scanf("%s", ch1); getchar();
			num1 = Str_Len(ch1);
			if (num1 > MAX_PASSWORD - 1)
			{
				printf("输入的密码字符超出限制，请重新");
				goto up2;
			}
			else
			{
				strcpy(Ac->List[Ac->count_account++].password, ch1);
				//printf("%s", Ac->List[Ac->count_account].password);
				//printf("%d", Ac->count_account);
				printf("创建成功\n");
				//system("pause");
			}
		}
	}
	else
	{
		printf("\n剩余账户为零无法创建");
	}
}

void change_password(Account* Ac, int i)
{
	//int num1 = 0;
	char str1[100];
	printf("\n请输入新密码(字符限制%d)>:", MAX_PASSWORD - 1);
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > MAX_PASSWORD - 1)
	{
		printf("字符超出限制，请重新输入新密码(字符限制%d)>:", MAX_PASSWORD - 1);
		scanf("%s", str1); getchar();
	}
	strcpy(Ac->List[i].password, str1);
	printf("账户：%s 的密码修改为：%s 成功", Ac->List[i].account, Ac->List[i].password);
}

void change_account(Account* Ac, int i)
{
	char str1[100] = {0};
	char str2[MAX_ACCOUNT_STR] = { 0 };
	printf("\n请输入新的账户名(字符限制%d)>:", MAX_ACCOUNT_STR - 1);
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > MAX_ACCOUNT_STR - 1 || Ver(Ac, str1))
	{
		printf("\n字符超出限制或账户名已存在，请重新输入新的账户名(字符限制%d)>:", MAX_ACCOUNT_STR - 1);
		scanf("%s", str1);
	}
	strcpy(str2, Ac->List[i].account);
	strcpy(Ac->List[i].account, str1);
	printf("\n该账户名已从 %s 修改为 %s", str2, Ac->List[i].account);
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
		printf("\n账户数为零，无法修改");
		return;
	}
	while ('y' == ch1)
	{
		printf("\n请输入想修改的账户名>:");
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
			printf("\n用户命不存在");
		}
		else
		{
			printf("\n请输入密码>:");
			scanf("%s", str1); getchar();
			if (0 == strcmp(str1, Ac->List[i].password))
			while (1)
			{
				printf("\n修改账户名请按 0 ，修改账户密码请按 1 ");
				printf("请输入>:");
				scanf("%d", &num1); getchar();
				while (num1 != 0 && num1 != 1)
				{
					printf("输入不合法，请重新输入>:");
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
				printf("\n继续修改此账户请按 0 ，否则 1 ");
				printf("\n请输入>:");
				scanf("%d", &num1); getchar();
				while (num1 != 0 && num1 != 1)
				{
					printf("输入不合法，请重新输入>:");
					scanf("%d", &num1); getchar();
				}
				if (num1)
				{
					break;
				}
			}
			else
			{
				printf("\n密码错误");
			}
		}
		printf("\n还想继续修改吗?");
		printf("\n继续修该请按 0 ，否则 1");
		printf("\n请输入>:");
		scanf("%d", &num1);
		while (num1 != 0 && num1 != 1)
		{
			printf("输入不合法，请重新输入>:");
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
		printf("\n账户数为零，无法删除账户");
		return;
	}
	printf("\n请输入想删除的账户名>:");
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
		printf("\n账户不存在");
	}
	else
	{
		printf("\n请输入用户 %s 的密码>:", Ac->List[i].account);
		scanf("%s", str1); getchar();
		if (0 == strcmp(Ac->List[i].password, str1))
		{
			for (j = i + 1; j < Ac->count_account; j++)
			{
				Ac->List[j - 1] = Ac->List[j];
			}
			Ac->count_account -= 1;
			printf("\n成功删除");
		}
		else
		{
			printf("\n密码错误, 不许删除");
		}
	}
}

void Menu_Student_Achievement_Management_System(void)
{
	printf("\n\t学生成绩管理界面");
	printf("\n\t1.添加学生信息(本系统可储存%d个学生信息，剩余储存量为:%d)", N, N - 学生列表壹.学生个数);
	printf("\n\t2.浏览学生信息");
	printf("\n\t3.查询学生信息");
	printf("\n\t4.删除学生信息");
	printf("\n\t5.按总分排序");
	printf("\n\t6.退出管理界面");
	printf("\n\t请输入菜单号(1 ~ 6)>:");
}

int Str_stu_cmp(学生列表* 学生, char* str)
{
	int i = 0;
	if (0 == 学生->学生个数)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < 学生->学生个数; i += 1)
		{
			if (0 == strcmp(学生->学生[i].学号, str))
			{
				return 1;
			}
		}
		return 0;
	}
}

void 添加学生信息(学生列表* 学生)
{
	char str1[100] = { 0 };
	int num1 = 0;
	float f1 = 0;
	char str2[3] = "男";
	char str3[3] = "女";
	system("cls");
	if (N == 学生->学生个数)
	{
		printf("\n学生列表已满，无法添加");
	}
	else
	{
		printf("\n请输入学生学号(字符限制 20)>:");
		scanf("%s", str1); getchar();
		while (Str_Len(str1) > 20 || Str_stu_cmp(学生, str1))
		{
			printf("\n超出限制或已存在,请重新输入学号(字符限制 20)>:");
			scanf("%s", str1); getchar();
		}
		strcpy(学生->学生[学生->学生个数].学号, str1);
		printf("\n请输入学生姓名(字符限制 20)>:");
		scanf("%s", str1); getchar();
		while (Str_Len(str1) > 20)
		{
			printf("\n超出限制，请重新输入姓名(字符限制 20)>:");
			scanf("%s", str1); getchar();
		}
		strcpy(学生->学生[学生->学生个数].姓名, str1);
		printf("\n请输入学生性别(男请按 0 女请按 1 )>:");
		scanf("%d", &num1); getchar();
		while (0 != num1 && 1 != num1)
		{
			printf("输入不合法，请重新输入(0 ~ 1)>:");
			scanf("%d", &num1); getchar();
		}
		if (num1)
		{
			strcpy(学生->学生[学生->学生个数].性别, str3);
		}
		else
		{
			strcpy(学生->学生[学生->学生个数].性别, str2);
		}
		printf("\n请输入学生年龄(1 ~ 200)>:");
		scanf("%d", &num1); getchar();
		while (num1 < 1 || num1 > 200)
		{
			printf("超出范围，请重新输入学生年龄(1 ~ 200)>:");
			scanf("%d", &num1); getchar();
		}
		学生->学生[学生->学生个数].年龄 = num1;
		printf("\n请输入学生数学成绩(0 ~ 100)>:");
		scanf("%f", &f1); getchar();
		while (num1 < 0 || num1 > 100)
		{
			printf("超出范围，请重新输入学生成绩(0 ~ 100)>:");
			scanf("%f", &f1);
		}
		学生->学生[学生->学生个数].数学 = f1;
		printf("\n请输入学生计算机成绩(0 ~ 100)>:");
		scanf("%f1", &f1); getchar();
		while (num1 < 0 || num1 > 100)
		{
			printf("超出范围，请重新输入学生成绩(0 ~ 100)>:");
			scanf("%f", &f1);
		}
		学生->学生[学生->学生个数].计算机 = f1;
		学生->学生[学生->学生个数].总分 = 学生->学生[学生->学生个数].数学 + 学生->学生[学生->学生个数].计算机;
		学生->学生个数 += 1;
		printf("\n添加成功");
	}
	printf("\n");
	system("pause");
}

void Disp_stu(学生列表* G)
{
	int i = 0;
	system("cls");
	if (0 == G->学生个数)
	{
		printf("学生列表为空\n");
	}
	else
	{
		for (i = 0; i < G->学生个数; i += 1)
		{
			printf("序号%d 学号:%s 姓名:%s 性别:%s 年龄:%d 数学成绩:%.1f 计算机成绩:%.1f 总分:%.1f\n", i + 1, G->学生[i].学号, G->学生[i].姓名, G->学生[i].性别, G->学生[i].年龄, G->学生[i].数学, G->学生[i].计算机, G->学生[i].总分);
		}
	}
	system("pause");
}

int Str_stu_cmp_1(学生列表* 学生, char* str)
{
	int i = 0;
	if (0 == 学生->学生个数)
	{
		return -1;
	}
	else
	{
		for (i = 0; i < 学生->学生个数; i += 1)
		{
			if (0 == strcmp(学生->学生[i].学号, str))
			{
				return i;
			}
		}
		return -1;
	}
}


void 查询学生信息(学生列表* G)
{
	int i = -1;
	char str1[100] = { 0 };
	system("cls");
	printf("\n请输入查询的学生学号(字符限制 20)>:");
	scanf("%s", str1); getchar();
	while (Str_Len(str1) > 20)
	{
		printf("\n超出限制,请重新输入学号(字符限制 20)>:");
		scanf("%s", str1); getchar();
	}
	i = Str_stu_cmp_1(G, str1);
	if (-1 == i)
	{
		printf("\n此学号不存在");
	}
	else
	{
		printf("\n学号:%s 姓名:%s 性别:%s 年龄:%d 数学成绩:%.1f 计算机成绩:%.1f 总分:%.1f", G->学生[i].学号, G->学生[i].姓名, G->学生[i].性别, G->学生[i].年龄, G->学生[i].数学, G->学生[i].计算机, G->学生[i].总分);
	}
	printf("\n");
	system("pause");
}

void 删除学生信息(学生列表* G)
{
	char str1[100] = { 0 };
	int k = 0;
	int i = 0;
	system("cls");
	if (0 == G->学生个数)
	{
		printf("\n学生列表为空，无法删除");
	}
	else
	{
		printf("\n请输入想要删除的学生信息学号>:");
		scanf("%s", str1); getchar();
		k = Str_stu_cmp_1(G, str1);
		if (-1 == k)
		{
			printf("\n该学号不存在");
		}
		else
		{
			for (i = k; i < G->学生个数 - 1; i += 1)
			{
				G->学生[i] = G->学生[i + 1];
			}
			G->学生个数 -= 1;
			printf("\n成功删除");
		}
	}
	printf("\n");
	system("pause");
}

void 按总分排序(学生列表* G)
{
	int i = 0;
	int j = 0;
	char flag = 0;
	学生单元 tmp = { 0 };
	system("cls");
	if (0 == G->学生个数 || 1 == G->学生个数)
	{
		printf("\n学生个数为0或1，不满足排序条件");
	}
	else
	{
		//  0   1   2   3   4   5
		// [1] [2] [3] [4] [5] [6]
		//               ___
		for (i = G->学生个数 - 1; i > 0; i -= 1)
		{
			flag = 1;
			for (j = 0; j < i; j += 1)
			{
				if (G->学生[j].总分 < G->学生[j + 1].总分)
				{
					flag = 0;
					tmp = G->学生[j];
					G->学生[j] = G->学生[j + 1];
					G->学生[j + 1] = tmp;
				}
			}
		}
		printf("\n学生列表按总分从高到低排序完成");
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
			添加学生信息(&学生列表壹);
			break;
		case 2:
			Disp_stu(&学生列表壹);
			break;
		case 3:
			查询学生信息(&学生列表壹);
			break;
		case 4:
			删除学生信息(&学生列表壹);
			break;
		case 5:
			按总分排序(&学生列表壹);
			break;
		case 6:
			printf("\n即将退出管理界面");
			break;
		default:
			printf("\n输入不合法");
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
		printf("\n账户数为零，无法登录");
	}
	else
	{
		printf("\n请输入用户名>:");
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
			printf("\n账户名不存在");
		}
		else
		{
			up3:
			printf("\n请输入登录密码>:");
			scanf("%s", str1); getchar();
			if (0 == strcmp(Ac->List[i].password, str1))
			{
				printf("\n登录成功\n");
				system("pause");
				system("cls");
				//printf("\n即将登入学生成绩管理系统\n");
				//system("pause");
				//system("cls");
				Student_Achievement_Management_System();
			}
			else
			{
				printf("\n密码错误");
				count += 1;
				if (count < 3)
				{
					printf("\n重试一下");
					goto up3;
				}
				else
				{
					printf("\n算了别试了");
				}
			}
		}
	}
	
}

void menus(void)
{
	system("cls");
	printf("登录请按1，账户管理请按2,退出请按0(请输入)>:");
}

void passp(Account* Ac)
{
	char password[10] = "123456";
	char str[100] = { 0 };
	printf("创建账户需要系统管理密码，请输入>:");
	scanf("%s", str); getchar();
	if (0 == strcmp(password, str))
	{
		Create_Account(Ac);
	}
	else
	{
		printf("密码错误\n");
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
					//printf("\n返回\n");
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
					printf("\n输入不合法\n");
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
			printf("输入不合法\n");
			system("pause");
		}
	}
	

	return 0;
}