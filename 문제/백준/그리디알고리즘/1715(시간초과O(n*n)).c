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
int doublemin(int N, int arr[]) {
	int min1 = 1002, min2 = 1002, i = 0, j = 0,k=0;
	while (i<N) {
		if (arr[i] < min1) {
			min2 = min1;
			j = k;
			min1 = arr[i];
			k = i;
		}
		else if (arr[i] < min2) {
			min2 = arr[i];
			j = i;
		}
		i++;
	}
	arr[j] = 1002;
	arr[k] = min1+min2;
	return k;
}
int main() {
	int N,k, card[100001] = { 0, }, all = 0, sum =0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &card[i]);
	qsort(card, N, sizeof(int), cmp); //전체 정렬
	for (int i = 0; i < N-1; i++) {
		k = doublemin(N, card);
		sum += card[k];
	}
	printf("%d", sum);
	return 0;
}
