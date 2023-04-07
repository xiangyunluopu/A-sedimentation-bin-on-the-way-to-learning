#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// 菜单
// 初始化单链表 1
// 插入 2
// 删除 3
// 按值查找 4
// 按位置查找 5
// 计算结点个数 6
// 显示结点元素 7



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
			printf("输入错误，请重输\n");
			break;
		}
	} while (ret);

	return 0;
}