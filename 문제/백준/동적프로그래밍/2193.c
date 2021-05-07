#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
    int N;
    long long a2[91] = { 0, }; //이친수의 자릿수
    scanf("%d", &N);
    a2[1] = 1; a2[2] = 1;
    for (int i = 3; i <= N; i++) { //자릿수에 따라 그 자릿수부터 ~ 자릿수 +1 까지
        a2[i] = a2[i - 1] + a2[i - 2];
    }
    printf("%lld", a2[N]);
    return 0;
}
