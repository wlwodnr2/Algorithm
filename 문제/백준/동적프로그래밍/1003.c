#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N,n;
    long long cnt0[41], cnt1[41];
    cnt0[0] = 1; cnt1[0] = 0;
    cnt0[1] = 0; cnt1[1] = 1;
    scanf("%d", &N);
    for (int i = 2; i <= 40; i++) {
        cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
        cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        printf("%lld %lld\n", cnt0[n], cnt1[n]);
    }
    return 0;
}
