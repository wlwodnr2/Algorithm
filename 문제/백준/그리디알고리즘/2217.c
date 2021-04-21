#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2) return -1;
	else if (num1 <= num2) return 1;
}
int main() {
	int N, rope[100000], maxwg =0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &rope[i]);
	qsort(rope, N, sizeof(int), compare);
	for (int i = 0; i < N; i++) {
		if (maxwg < rope[i]*(i+1)) maxwg = rope[i]*(i+1);
	}
	printf("%d", maxwg);
	return 0;
}
