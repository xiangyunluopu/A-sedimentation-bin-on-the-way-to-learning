#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	int arr[100] = { 0 };
	int pre = 0;
	int last = 0;
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	int i = 0;
 	for (i = 0; i < m; i += 1) {
		arr[i] = i + 1;
	}
	arr[i - 1] = 0;
	pre = 0;
	last = m - 1;
	int t = m;
	int count = 1;
	for (; t > 1;) {
		if (count == n)
		{
			arr[last] = arr[pre];
			pre = arr[last];
			count = 1;
			t -= 1;
		}
		else {
			last = pre;
			pre = arr[last];
			count += 1;
		}
	}

	printf("%d\n", arr[pre] + 1);
	return 0;
}