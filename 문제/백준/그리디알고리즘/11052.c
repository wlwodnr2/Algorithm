#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[1001];
int dp[1001];
int Max(int a, int b)
{
    return a > b ? a : b;
}
void buy_cards(int N)
{
    dp[0] = 0;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            dp[i] = Max(dp[i], dp[i - j] + arr[j]);
        }
    }
    printf("%d", dp[i - 1]);
}
int main()
{
    int N;
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    buy_cards(N);
}
