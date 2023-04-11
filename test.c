#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct stu
{
	char name[20];
	int age;
	char id[20];
};

struct p
{
	struct stu* next;
};

int main()
{
	struct stu s1 = { "ÕÅÈý", 20, "4988295" };
	struct stu* p = &s1;
	struct p* A = (struct p*)malloc(sizeof(struct p));
	A->next = p;
	printf("%s\n", (*p).name);
	printf("%d\n", p->age);
	printf("%s\n", A->next->id);
	
	/*printf("%s\n", s1.name);
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);*/
	return 0;
}