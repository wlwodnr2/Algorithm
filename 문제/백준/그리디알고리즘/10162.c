#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int T, cnt =0;
	scanf("%d", &T);
	if (T % 10 != 0) printf("-1");
	else {
		printf("%d ", T / 300);
		T -= 300 * (T / 300);
		printf("%d ", T / 60);
		T -= 60 * (T / 60);
		printf("%d", T / 10);
	}
	return 0;
}
