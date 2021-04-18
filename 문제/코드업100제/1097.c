#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2,num4;
    int num3[20][20] = {0,};
    
    for (int i = 1; i <= 19; i++) //한 줄씩 바둑판 상황 입력 받기
        for (int j = 1; j <= 19; j++)
            scanf("%d", &num3[i][j]);
    
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++) {
        scanf("%d %d", &num2, &num4);
        for (int j = 1; j <= 19; j++) {
            if (num3[num2][j] == 0)
                num3[num2][j] = 1;
            else
                num3[num2][j] = 0;
        }
        for (int k = 1; k <= 19; k++) {
            if (num3[k][num4] == 0)
                num3[k][num4] = 1;
            else
                num3[k][num4] = 0;
        }
    }
    for (int i = 1; i <= 19; i++) { //한 줄씩 바둑판 상황 입력 받기
        for (int j = 1; j <= 19; j++) {
            printf("%d ", num3[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}
