#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int MAX(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int N,i,arr[10001], dp[10001];
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &arr[i]);
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (i = 3; i <= N; i++) dp[i] = MAX(dp[i - 2] + arr[i], MAX(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]));
    printf("%d", dp[N]);
    return 0;
}
