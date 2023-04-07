#pragma once

#define data_type int

typedef struct link_node
{
	data_type data;
	struct link_node* next;
}L;

#include<stdio.h>
#include<stdlib.h>

// 菜单
// 初始化单链表 
// 插入
// 删除
// 按值查找
// 按位置查找
// 计算结点个数
// 显示结点元素

void init_list(L* head);// 1
void ins_list(L* head);// 2
void dele_node(L* head);// 3
void sea_data(L* head); // 4
void sea_node(L* head); // 5
void list_node_count(L* head); // 6