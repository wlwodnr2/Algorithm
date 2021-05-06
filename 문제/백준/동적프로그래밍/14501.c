#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
    int N, tm[16][2] = { 0, }, i, j,max=0; //16*2배열
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d %d", &tm[i][0], &tm[i][1]); //시간과 돈 입력
    int sum[16] = { 0, };
    if (tm[1][0] <= N) sum[1] = tm[1][1];
    else sum[1] = 0;
    for (i = 2; i <= N; i++) {
        j = i-1;
        while (j>0) {
            if (i >= (tm[j][0] + j)) sum[i] = sum[i] > sum[j] ? sum[i] : sum[j]; //앞에 이어질 수 있는 값 중 제일 큰 sum값을 넣어라
            j--;
        }
        if (i + tm[i][0]-1 > N) sum[i] = 0; //만약 본인의 요일 + 걸리는 요일이 N을 넘어간다면 그건 0이다.
        else sum[i] += tm[i][1]; //안 넘어간다면 자신의 값을 더해서 저장.
    }
    for (i = 1; i <= N; i++) {
        if (sum[i] > max) max = sum[i];
    }
    printf("%d\n", max);
    return 0;
}
