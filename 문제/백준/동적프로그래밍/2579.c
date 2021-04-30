#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int N, stair[301], sum[301];
    scanf("%d", &N); //계단 개수
    for (int i = 0; i < N; i++) scanf("%d", &stair[i]); //계단 가중치 입력
    sum[0] = stair[0]; 
    sum[1] = (stair[0]>stair[0] + stair[1])?stair[0]:(stair[0]+stair[1]); 
    sum[2] = (stair[1] + stair[2])> (stair[0] + stair[2])?(stair[1] + stair[2]):(stair[0] + stair[2]);
    for (int i = 3; i < N; i++) sum[i] = (sum[i - 3] + stair[i - 1] + stair[i]) > (sum[i - 2] + stair[i]) ? (sum[i - 3] + stair[i - 1] + stair[i]) : (sum[i - 2] + stair[i]);
    printf("%d", sum[N-1]);
    return 0;
}
