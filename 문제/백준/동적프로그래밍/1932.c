#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N, st = 0, a[125251], s[125251], c = 2,d=1,max;
    scanf("%d", &N); //계단 개수
    for (int i = 1; i <= N; i++) st += i; //층의 총 개수만큼 ?
    for (int i = 1; i <= st; i++)scanf("%d", &a[i]); //층 입력
    s[1] = a[1]; //1층 합
    for (int i = 2; i <= st; i++) {
        if (i == d + 1) s[i] = s[i - c + 1] + a[i];
        else if (i == d + c) {
            s[i] = s[i - c] + a[i];
            d = i; //d를 맨 전층 맨 끝값
            c += 1; //1층 늘리기
        }
        else s[i] = (s[i - c] > s[i - c + 1] ? s[i - c] : s[i - c + 1]) + a[i]; //자기 위에 왼/오 중 큰 값을 더해라 
    }
    max = s[st];
    if (N == 1) max = s[1];
    else {
        for (int i = st - 1; i > st - N; i--) {
            max = max > s[i] ? max : s[i];
        }
    }
    printf("%d", max);
    return 0;
}
