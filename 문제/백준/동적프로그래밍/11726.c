#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int N, cnt[1001] = { 0, };
    cnt[1] = 1; cnt[2] = 2;
    scanf("%d", &N);
    for (int i = 3; i <= N; i++) cnt[i] = (cnt[i - 1] + cnt[i - 2]) % 10007;
    printf("%d", cnt[N]);
    return 0;
}
