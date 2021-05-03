#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int N, a[10001] = { 0 }, sum[10001] = { 0, }, maxi_2 = -1,maxi_3 = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sum[0] = a[0];
    sum[1] = (a[0] + a[1]) > a[1] ? (a[0] + a[1]) : a[1];
    sum[2] = (a[0] + a[2]) > (a[1] + a[2]) ? (a[0] + a[2]) : (a[1] + a[2]);
    for (int i = 3; i < N; i++) {
        if (sum[i - 3] > maxi_3) maxi_3 = sum[i - 3];
        if (sum[i - 2] > maxi_2) maxi_2 = sum[i - 2];
        sum[i] = (maxi_3 + a[i - 1] + a[i]) > (maxi_2 + a[i]) ? (maxi_3 + a[i - 1] + a[i]) : (maxi_2 + a[i]);
    }
   if(maxi_2 < (sum[N - 1] > sum[N - 2] ? sum[N - 1] : sum[N - 2])) maxi_2 = (sum[N - 1] > sum[N - 2] ? sum[N - 1] : sum[N - 2]);
    printf("%d",maxi_2);
    return 0;
}
