#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//입력된 값을 5,3으로 만들기 (최소)
int main() {
    int N, count5, count3, var, duuri;
    int allcount = 0;
    scanf("%d", &N);
    //나머지가 1? 3? 5? 8?
    while (N%5 != 0) { //5로 나눴을때 나머지가 0이 아니면 실행 
        if (N < 0) break;
        N -= 3;
        allcount += 1;
    }
    if (N % 5 == 0) {
        allcount += N / 5;
    }
    else {
        allcount = -1;
    }
    printf("%d", allcount);
    return 0;
}
