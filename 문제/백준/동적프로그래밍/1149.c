#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int N, R[2], G[2], B[2], sum[1001] = { 0, };
    scanf("%d", &N); //집 개수
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &R[1], &G[1], &B[1]); //RGB의 현재 값 입력
        if (i == 1) {
            R[0] = R[1]; G[0] = G[1]; B[0] = B[1]; //현재 값을 과거 값으로
        }
        else {
            G[1] += R[0] > B[0] ? B[0] : R[0]; //현재값에 이전 값 중 작은 값 더하기
            R[1] += G[0] > B[0] ? B[0] : G[0];
            B[1] += R[0] > G[0] ? G[0] : R[0];
        }
        sum[i] = R[1] > G[1] ? (G[1] > B[1] ? B[1] : G[1]) : (R[1] > B[1] ? B[1] : R[1]); //합은 현재 값 중 제일 작은 값 대입 
        R[0] = R[1]; G[0] = G[1]; B[0] = B[1]; //현재값을 이전 값으로
    }
    printf("%d", sum[N]);
    return 0;
}
