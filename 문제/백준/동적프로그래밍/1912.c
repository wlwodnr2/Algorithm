#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N, a[100001] = { 0, }, sum[100001] = { 0, };
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]); //수열 입력
    sum[0] = a[0];
    int maxcnt = sum[0];
    for (int i = 1; i < N; i++) {
        sum[i] = (sum[i - 1] + a[i]) > a[i] ? (sum[i - 1] + a[i]) : a[i]; //이전꺼를 더한게 큰지 아니면 자기 자신이 큰지 
        maxcnt = maxcnt > sum[i] ? maxcnt : sum[i];
    }
    printf("%d", maxcnt);
    return 0;
}
