#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// �˵�
// ��ʼ�������� 1
// ���� 2
// ɾ�� 3
// ��ֵ���� 4
// ��λ�ò��� 5
// ��������� 6
// ��ʾ���Ԫ�� 7



int main()
{
	int ret = 0;
	L* head = (L*)malloc(sizeof(L));
	head->next = NULL;
	do
	{
		menu();
		scanf("%d", &ret);
		switch (ret)
		{
		case 0:
			break;
		case 1:
			init_list(head);
			break;
		case 2:
			ins_list(head);
			break;
		case 3:
			dele_node(head);
			break;
		case 4:
			sea_data(head);
			break;
		case 5:
			sea_node(head);
			break;
		case 6:
			list_node_count(head);
			break;
		case 7:
			disp_node_all(head);
			break;
		default:
			printf("�������������\n");
			break;
		}
	} while (ret);

	return 0;
}