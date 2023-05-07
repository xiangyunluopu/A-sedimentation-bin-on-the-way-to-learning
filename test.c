#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct {
	char name[20];
	int i;
}d;

d a0 = { "³ÂÆæ·å", 1 };
d a1 = { "ÅíÊ©ÌÎ", 1 };
d a2 = { "»Æ¿¡", 1 };
d a3 = { "ÍõÎ¬", 1 };
d a4 = { "·âºÆÈ»", 1 };
d a5 = { "À×³Ì", 1 };
d a6 = { "Àî±ù", 1 };
d a7 = { "Òü¾§", 1 };
d a8 = { "Ñîç÷", 1 };
d a9 = { "Çü°Ø³¼", 1 };
d a10 = { "»Æ½£²¨", 1 };
d a11 = { "ĞíÈü", 1 };
d a12 = { "ÎâÍşÅô", 1 };
d a13 = { "ÑîöÎ", 1 };
d a14 = { "Áúµ¤", 1 };
d a15 = { "ÖÜº£ÌÎ", 1 };
d a16 = { "ÍõÕÂº¼", 1 };
d a17 = { "Ñî¿¡Î°", 1 };
d a18 = { "ÕÅÑî·¢", 1 };
d a19 = { "ÖìÖÇ»Ô", 1 };

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

int main(void) {
	int count = 20;
	int a = 0;
	int b = 0;
	srand((unsigned int)time(NULL));
	while (count) {
		a = rand() % 20;
		b = rand() % 20;
		if (a != b && re(a) && re(b)) {
			rere(a, b);
			count -= 2;
		}
	}
	getchar();
	return 0;
}