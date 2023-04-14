#define _CRT_SECURE_NO_WARNINGS 1

#define MAXPV 20

typedef struct node {
	int tur;
	int password;
	struct node* next;
}L;

#include <stdio.h>
#include <stdlib.h>

int getlen(L* head) {
	int i = 0;
	L* p = head;
	for (i = 1; p->next != NULL; p = p->next, i += 1);
	return i;
}

void getpassword(L* head) {
	int i = 0;
	int getpassword = 0;
	int len = 0;
	L* p = head;
	len = getlen(head);
	for (i = 1; i <= len; p = p->next, i += 1) {
		printf("请输入%d位的密码>:", i);
		scanf("%d", &getpassword);
		if (MAXPV < getpassword || getpassword <= 0) {
			do {
				printf("值为 password <= 0 || %d < password\n请重新输入>:", MAXPV);
				scanf("%d", &getpassword);
			} while (MAXPV < getpassword || getpassword <= 0);
			p->password = getpassword;
		}
		else {
			p->password = getpassword;
		}
	}
	p = head;
	printf("输入的密码依次为:>");
	for (i = 1; i <= len; p = p->next, i += 1) {
		printf("%3d", p->password);
	}
}

int main() {
	L* head = (L*)malloc(sizeof(L));
	L* p = head;
	L* q = NULL;
   	int i = 0;
	head->tur = 1;
	int number = 0;
	head->next = NULL;
	printf("请输入想要体验的人数>:");
	scanf("%d", &number);
	for (i = 1; i < number; i += 1) {
		//    [1][2] <- p
		//    [2][#] <- q 
		//    [3][]
		//    [4][]
		q = (L*)malloc(sizeof(L));
		if (NULL == q) {
			printf("分配内存失败\n");
			exit(1);
		}
		q->tur = (i + 1);
		q->next = p->next;
		p->next = q;
		p = q;
	}
	int len = getlen(head);
	for (i = 0, p = head; i < len - 1; p = p->next, q = p, i += 1);
	
	p = head;
	getpassword(head);//装载密码；
	// 开始布置约瑟夫环
	
	int count = 1;
	int s = getlen(head);
	int array[20] = { 0 };
	int t = p->password;
	for (q->next = head, i = 0, count = 1; s > 0;) {
		if (t == count) {
			array[i] = p->tur;
			q->next = p->next;
			t = p->password;
			free(p);
			p = q->next;
			i += 1; count = 1; s -= 1;
		}
		else {
			q = p;
			p = p->next;
			count += 1;
		}
		
	}
	printf("出列顺序为>:");
	for (i = 0; i < len; i += 1) {
		printf("%3d", array[i]);
	}

	return 0;
}