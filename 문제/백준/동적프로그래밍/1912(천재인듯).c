#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int N, a, sum=-1001,maxcnt=-1001;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        sum = sum + a > a ? sum + a : a; 
        if (sum > maxcnt) maxcnt = sum;
    }
    printf("%d", maxcnt);
    return 0;
}
