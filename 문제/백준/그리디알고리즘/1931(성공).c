#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct time {
    int x;
    int y;
}time;

int cmp(const void* a, const void* b) {
    time *x1 = (time *)a;
    time *x2 = (time *)b;
    if (x1->y < x2->y)
        return -1;
    else if (x1->y > x2->y)
        return 1;
    else {
        if (x1->x <= x2->x)
            return -1;
        else if (x1->x > x2->x)
            return 1;
    }
}
int main() {
    int N, max_count = 1, last = 0;
    scanf("%d", &N);
    time *t = (time*)calloc(N, sizeof(time)); //0으로 초기화
    
    for (int i = 0; i < N; i++)
        scanf("%d %d", &(t+i)->x, &(t+i)->y);
    qsort(t, N, sizeof(time), cmp);
    last = t->y;
    for (int i = 1; i < N; i++) {
        if ((t + i)->x >= last) {
            max_count += 1;
            last = (t + i)->y;
        }
    }
    printf("%d", max_count);
    free(t);
    return 0;
}
