#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N, cnt[1000001] = { 0, };
    cnt[1] = 0; cnt[2] = 1; cnt[3] = 1;
    scanf("%d", &N);
    for (int i = 4; i <= N; i++) {
        if (i % 3 == 0 && i % 2 == 0) cnt[i] = ((cnt[i / 3] > cnt[i / 2]) ? (cnt[i / 2] > cnt[i - 1] ? cnt[i - 1] : cnt[i / 2]) : (cnt[i / 3] > cnt[i - 1] ? cnt[i - 1] : cnt[i / 3])) + 1;
        else if (i % 3 == 0) cnt[i] = ((cnt[i/3]>cnt[i-1])?cnt[i-1]:cnt[i/3])+1;
        else if (i % 2 == 0) cnt[i] = ((cnt[i/2]> cnt[i - 1]) ? cnt[i - 1]: cnt[i/2])+1;
        else cnt[i] = cnt[i-1]+1; 
    }
    printf("%d", cnt[N]);
    return 0;
}
