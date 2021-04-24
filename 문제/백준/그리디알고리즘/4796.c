#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int L, P, V, camp = 0;
	for (int j = 1;; j++) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V) break;
		camp = (V / P) * L;
		V = V % P;
		camp += V < L ? V : L;
		printf("Case %d: %d \n", j, camp);
		camp = 0;
	}
	return 0;
}
