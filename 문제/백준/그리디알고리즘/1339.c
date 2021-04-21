#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct Alpha {
	int len;
	char c1[9];
}Alpha;
int cmp(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2) return -1;
	else return 1;
}
int main() {
	int N, dis, count[26] = { 0, },sum=0,k=0;
	scanf("%d", &N);
	Alpha* ap = (Alpha *)malloc(sizeof(Alpha));
	for (int i = 0; i < N; i++) {
		scanf("%s", &(ap + i)->c1);
		(ap + i)->len = strlen((ap + i)->c1);
	}
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < (ap + i)->len; j++) { //각 길이만큼 반복
			dis = (ap + i)->c1[j] - 'A'; //A와의 차이값
			count[dis] += pow(10,(ap + i)->len -j-1);
		}
	}
	qsort(count, 26, sizeof(int), cmp);
	for (int i = 9; i > 0; i--) {
		sum += count[k] * i;
		k++;
	}
	printf("%d", sum);
	free(ap);
	return 0;
}
