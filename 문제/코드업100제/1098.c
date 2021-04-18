#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int h,w,num1,l,d,x,y;
    int num3[100][100] = { 0, };
    scanf("%d %d", &h, &w);
    
    scanf("%d", &num1); //막대개수

    for (int i = 0; i < num1; i++) {
        scanf("%d %d %d %d", &l, &d, &x, &y);
        for (int j = 0; j < l; j++) {
            if (d == 1) {
                num3[x + j][y] = 1;
            }
            else {
                num3[x][y + j] = 1;
            }
        }
    }

    for (int i = 1; i <= h; i++) { //출력
        for (int j = 1; j <= w; j++) {
            printf("%d ", num3[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}
