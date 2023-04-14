#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main() {
//	char a = 3; 
//	//00000000000000000000000000000011
//	char b = 127;
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010
//	char h = a + b;
//	//11111111111111111111111110000010
//	//11111111111111111111111110000001
//	//10000000000000000000000001111110
//
//	printf("%d\n", h);
//	return 0;
//}

#include <stdio.h>

int main() {
	char c = 0;
	/*printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));*/
	printf("%d\n", sizeof(-c));
	
	return 0;
}