#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  // 调用打印函数的头文件
#include<time.h>   // 调用时间戳的头文件，不知道时间戳也没有关系，不影响使用
#include<stdlib.h> // 这个头文件包含着随机数生成函数
				   // 利用时间戳作为随机数生成的起点，就可以得到真正的随机数，因为这个随机数生成的基础是时间
				   // 生成随机数就是实现随机组合的关键；
typedef struct {   // 定义一个保存名字的结构体
	char name[20]; // 其中的整数变量 i 是为了标记，而这个标记的作用面讲
	int i;
}d;

d a0 = { "陈奇峰", 1 }; // 将名字保存在全局变量中
d a1 = { "彭施涛", 1 }; // 并且将i 赋值为1；
d a2 = { "黄俊", 1 };
d a3 = { "王维", 1 };
d a4 = { "封浩然", 1 };
d a5 = { "雷程", 1 };
d a6 = { "李冰", 1 };
d a7 = { "尹晶", 1 };
d a8 = { "杨琪", 1 };
d a9 = { "屈柏臣", 1 };
d a10 = { "黄剑波", 1 };
d a11 = { "许赛", 1 };
d a12 = { "吴威鹏", 1 };
d a13 = { "杨鑫", 1 };
d a14 = { "龙丹", 1 };
d a15 = { "周海涛", 1 };
d a16 = { "王章杭", 1 };
d a17 = { "杨俊伟", 1 };
d a18 = { "张杨发", 1 };
d a19 = { "朱智辉", 1 };

// =========================================
int re(int c) {
	switch (c) {
	case 0:
		return a0.i;
		break;
	case 1:
		return a1.i;
		break;
	case 2:
		return a2.i;
		break;
	case 3:
		return a3.i;
		break;
	case 4:
		return a4.i;
		break;
	case 5:
		return a5.i;
		break;
	case 6:
		return a6.i;
		break;
	case 7:
		return a7.i;
		break;
	case 8:
		return a8.i;
		break;
	case 9:
		return a9.i;
		break;
	case 10:
		return a10.i;
		break;
	case 11:
		return a11.i;
		break;
	case 12:
		return a12.i;
		break;
	case 13:
		return a13.i;
		break;
	case 14:
		return a14.i;
		break;
	case 15:
		return a15.i;
		break;
	case 16:
		return a16.i;
		break;
	case 17:
		return a17.i;
		break;
	case 18:
		return a18.i;
		break;
	case 19:
		return a19.i;
		break;
	}
}

//=======================================

void rere(int a, int b) {
	switch (a) {
	case 0:
		a0.i = 0;
		printf("%s", a0.name);
		break;
	case 1:
		a1.i = 0;
		printf("%s", a1.name);
		break;
	case 2:
		a2.i = 0; printf("%s", a2.name);
		break;
	case 3:
		a3.i = 0; printf("%s", a3.name);
		break;
	case 4:
		a4.i = 0; printf("%s", a4.name);
		break;
	case 5:
		a5.i = 0; printf("%s", a5.name);
		break;
	case 6:
		a6.i = 0; printf("%s", a6.name);
		break;
	case 7:
		a7.i = 0; printf("%s", a7.name);
		break;
	case 8:
		a8.i = 0; printf("%s", a8.name);
		break;
	case 9:
		a9.i = 0; printf("%s", a9.name);
		break;
	case 10:
		a10.i = 0; printf("%s", a10.name);
		break;
	case 11:
		a11.i = 0; printf("%s", a11.name);
		break;
	case 12:
		a12.i = 0; printf("%s", a12.name);
		break;
	case 13:
		a13.i = 0; printf("%s", a13.name);
		break;
	case 14:
		a14.i = 0; printf("%s", a14.name);
		break;
	case 15:
		a15.i = 0; printf("%s", a15.name);
		break;
	case 16:
		a16.i = 0; printf("%s", a16.name);
		break;
	case 17:
		a17.i = 0; printf("%s", a17.name);
		break;
	case 18:
		a18.i = 0; printf("%s", a18.name);
		break;
	case 19:
		a19.i = 0; printf("%s", a19.name);
		break;
	}
	printf(" + ");
	switch (b) {
	case 0:
		a0.i = 0;
		printf("%s", a0.name);
		break;
	case 1:
		a1.i = 0;
		printf("%s", a1.name);
		break;
	case 2:
		a2.i = 0; printf("%s", a2.name);
		break;
	case 3:
		a3.i = 0; printf("%s", a3.name);
		break;
	case 4:
		a4.i = 0; printf("%s", a4.name);
		break;
	case 5:
		a5.i = 0; printf("%s", a5.name);
		break;
	case 6:
		a6.i = 0; printf("%s", a6.name);
		break;
	case 7:
		a7.i = 0; printf("%s", a7.name);
		break;
	case 8:
		a8.i = 0; printf("%s", a8.name);
		break;
	case 9:
		a9.i = 0; printf("%s", a9.name);
		break;
	case 10:
		a10.i = 0; printf("%s", a10.name);
		break;
	case 11:
		a11.i = 0; printf("%s", a11.name);
		break;
	case 12:
		a12.i = 0; printf("%s", a12.name);
		break;
	case 13:
		a13.i = 0; printf("%s", a13.name);
		break;
	case 14:
		a14.i = 0; printf("%s", a14.name);
		break;
	case 15:
		a15.i = 0; printf("%s", a15.name);
		break;
	case 16:
		a16.i = 0; printf("%s", a16.name);
		break;
	case 17:
		a17.i = 0; printf("%s", a17.name);
		break;
	case 18:
		a18.i = 0; printf("%s", a18.name);
		break;
	case 19:
		a19.i = 0; printf("%s", a19.name);
		break;
	}
	printf("\n");
}

//=================================================

int main(void) {
	int count = 20; // 定义一个计数器来检测是否将所有人都排好了
	int a = 0;      
	int b = 0;
	srand((unsigned int)time(NULL));  // 利用时间戳作为随机数生成的起点
	while (count) {
		a = rand() % 20;	// 生成一个0 到 19 的随机数；因为只有20个人
		b = rand() % 20;    
		if (a != b && re(a) && re(b)) {  // 在 两个数不相等的时候且两个人的i都为1时 其实就是随机生成了两个人的标号
			rere(a, b);					 // 其中我们每一个数都指代了一个人
			count -= 2;				     // re() 这个自定义函数用来返回每个人的 i 值是否为 1，我们用i== 1 代表这个人未被排序
							  //rere() 我们用来打印两个人的名字并且将他们的i 赋值为 0 来代表这两个人已经被排好了 
		}  // 每次排完两个人，我们给计数器的值减去一个2；
	}      // 在count被减为零的时候就代表所有人都排完了；
	getchar();// 这个函数用来暂定窗口，不然程序运行就一闪而过了；
	return 0;
}