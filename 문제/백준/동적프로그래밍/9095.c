#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int T,n[12],num;
    scanf("%d", &T);
    n[0] = 1;
    n[1] = 2;
    n[2] = 4;
    for (int i = 3; i < 11; i++) {
        n[i] = n[i - 1] + n[i - 2] + n[i - 3]; //경우의 수 
    }
    for (int i = 0; i < T; i++) {
        scanf("%d", &num);
        printf("%d\n", n[num - 1]);
    }
    return 0;
}
