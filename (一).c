#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int k = 0;
	float f = 0.0;
	printf("������ɼ����Ա�\n( �Ա��м���: 1 , �Ա�Ů����: 0)\n( �����ʽ:scord  sex)\n");
	scanf("%f %d", &f, &k);
	//printf("%f, %d", k, f);
	while (f <= 0)
	{
		printf("�ɼ����Ϸ��������¼���ɼ�>:");
		scanf("%f", &f);
	}
	while (k != 0 && k != 1)
	{
		printf("�Ա������������¼����Ա�( 0 �� 1 )>:");
		scanf("%d", &k);
	}
	if (f < 12)
	{
		if (k)
		{
			printf("�������Ӿ���\n");
		}
		else
		{
			printf("����Ů�Ӿ���\n");
		}

	}
	else
	{
		printf("���ź���û�н������\n");
	}
	return 0;
} 