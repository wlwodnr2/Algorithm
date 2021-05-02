#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N, a[1001], cnt[1001] = { 0, }, maxcnt;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]); //수열 입력 
    cnt[0] = 1; 
    for (int i = 1; i < N; i++) {
        int max = 0;
        for (int j = i-1; j >= 0; j--) {
            if (a[i] > a[j]) {
                if (cnt[j] > max) {
                    cnt[i] = cnt[j] + 1;
                    max = cnt[j];
                }
            }
        }
        if (cnt[i] == 0) cnt[i] += 1;
    }
    maxcnt = cnt[0];
    for (int i = 1; i < N; i++) maxcnt = maxcnt > cnt[i] ? maxcnt : cnt[i];
    printf("%d", maxcnt);
    return 0;
}
