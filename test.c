#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main(){
//	int arr[100] = { 0 };
//	int sum = 0;
//	int j = 0;
//
//	scanf("%d %d", &sum, &j);
//	if (0 == sum || 0 == j) {
//		return 0;
//	};
//
//	int i = 0;
//	for (i = 0; i < sum; i += 1) {
//		arr[i] = i + 1;
//	}
//	
//	int count = 0;
//	int ret = 0;
//	int sub = 0;
//	for (ret = sum, count = 1;ret > 1;) {
//		if (arr[sub] == 0) {
//			sub = (sub + 1) % sum;
//		}
//		else {
//			if (count != j) {
//				sub = (sub + 1) % sum;
//				count += 1;
//			}
//			else {
//				arr[sub] = 0;
//				count = 1;
//				ret -= 1;
//			}
//		}
//	}
//
//	for (i = 0; i < sum; i += 1) {
//		if (0 != arr[i]) {
//			printf("%d", arr[i]);
//		}
//	}
//
//	return 0;
//}

#include <stdio.h>

int main() {
	int arr[100] = { 0 };
	int p = 0;
	int q = 0;
	int sum = 0;
	int n = 0;
	scanf("%d %d", &sum, &n);
	if (0 == sum || 0 == n) {
		return 0;
	}
	int i = 0;
	for (i = 0; i < sum; i += 1) {
 		arr[i] = i + 1;
	}
	arr[i] = 0;
	int count = 0;
	p = 0;
	q = sum - 1;
	for (count = 1; p != q;) {
		if (count != n) {
			q = p;
			p = arr[p];
			count += 1;
		}
		else {  
			// [2] [2] [3] [4] [5] [6] [7] [8] [9] [0]
			// [0] [1] [2] [3] [4] [5] [6] [7] [8] [9]
			//  q       p
			arr[q] = arr[p];
			p = arr[q];
			count = 1;
		}
	}
	printf("%d", &arr[p]);
	return 0;
}