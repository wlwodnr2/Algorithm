#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//동전 종류 : N, 가치의 합 : K
int main() {
    int N, K, A[10], count = 0;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    //제일 큰 값으로 나눠야 되지 않나?
    for (int i = N-1; K > 0; i--) {
        if (K / A[i] >= 1) {
            count += K / A[i];
            K -= (K/A[i]) * A[i];
        }
    }
    printf("%d", count);
    return 0;
}
