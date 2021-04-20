#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//회의 시작 시간에 맞춘 끝 시간 정렬?
#include<stdlib.h>
typedef struct time {
    int x;
    int y;
}time;
//c가 그 순서, d는 회의 개수

int cmp(const void* a, const void* b) {
    time *x1 = (time *)a;
    time *x2 = (time *)b;
    if (x1->x < x2->x)
        return -1;
    else if (x1->x > x2->x)
        return 1;
    else {
        if (x1->y < x2->y)
            return -1;
        else if (x1->y > x2->y)
            return 1;
        else
            return 0;
    }
        

}
// 정렬 끝

int main() {
    int N, count=1, max_count = 0, last = 0;
    scanf("%d", &N);
    time* t = (time*)calloc(N, sizeof(time)); //0으로 초기화
    for (int i = 0; i < N; i++)
        scanf("%d %d", &t[i].x, &t[i].y);
    qsort(t, N, sizeof(time), cmp);

    printf("%d", max_count);
    free(t);
    return 0;
}
