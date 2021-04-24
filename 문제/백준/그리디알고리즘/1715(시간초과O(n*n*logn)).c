#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2) return -1;
	else if (num1 > num2) return 1;
	else return 0;
}
int main() {
	int N, card[100001] = { 0, }, all = 0, sum =0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &card[i]);
	for (int i = 0; i < N-1; i++) {
		qsort(card, N, sizeof(int), cmp);
		card[0] = card[0] + card[1];
		card[1] = 10001;
		sum += card[0];
	}
	printf("%d", sum);
	return 0;
}
