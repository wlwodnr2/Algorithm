#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define mod 1000000000
int main()
{
    int N, a[101][10] = { 0, }, sum = 0;
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++) a[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 8; j++) a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % mod;
        a[i][0] = a[i - 1][1] % mod;
        a[i][9] = a[i - 1][8] % mod;
    }
    for (int i = 0; i <= 9; i++) {
        sum += a[N][i];
        sum %= mod;
    }
    printf("%d", sum);
    return 0;
}
