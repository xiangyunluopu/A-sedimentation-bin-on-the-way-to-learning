#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node
//{
//	int m;
//	struct node* next;
//}node;
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	node* head = (node*)malloc(sizeof(node));
//	node* p = NULL;
//	node* q = NULL;
//	head->m = -1;
//	scanf("%d %d", &m, &n);
//	
//	for (i = 1, q = head; i <= m; i += 1)
//	{
//		//      [?][1] <- head
//		// q -> [1][2] 
//		// p -> [2][1]   
//		p = (node*)malloc(sizeof(node));
//		p->next = q->next;
//		q->next = p;
//		q = p;
//		q->m = i;
//	}
//	q->next = head->next;
//	p = head->next;
//
//	for (count = 1;p != q;)
//	{
//		if (count != n)
//		{
//			q = p;
//			p = q->next;
// 			count += 1;
//		}
//		else
//		{
//			q->next = p->next;
//			free(p);
//			p = q->next;
//			count = 1;
//		}
//	}
//	printf("%d", q->m);
//
//
//	return 0;
//}

#include <stdio.h>

int main()
{
	int arr[100] = { 0 };
	int m = 0;
	int ms = 0;
	int n = 0;
	int i = 0;
	int count = 1;
	int flag = 0;
	scanf("%d %d", &m, &n);

	for (i = 1; i <= m; i += 1)
	{
		arr[i] = i;
	}
	ms = m;
	for (; ms > 1;)
	{
		
		if (count != n)
		{
			for (; arr[flag] == 0;)
			{
				flag = (flag + 1) % m;
			}
			flag = (flag + 1) % m;
			count += 1;
		}
		else
		{
			for (; arr[flag] == 0;)
			{
				flag = (flag + 1) % m;
			}
			arr[flag] = 0;
			count = 1;
			ms -= 1;
		}
		
	}
	printf("%d\n", arr[flag]);
	return 0;
}