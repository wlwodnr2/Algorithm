#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    //0(갈 수 있는 곳), 1(벽 또는 장애물), 2(먹이)
    //2,2에서 시작 
    
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d ", &arr[i][j]);
        }
    }
    
    int x = 1, y = 1;
    if (arr[x][y] == 2 || arr[x][y] ==1) {
        arr[x][y] = 9;
    }
    else {
        arr[x][y] = 9;
        while (1) {
            if (arr[x][y + 1] == 2) {
                y += 1;
                arr[x][y] = 9;
                break;
            }
            else if (arr[x][y + 1] == 0) {
                y = y + 1;
                arr[x][y] = 9;
            }
            else if (arr[x + 1][y] == 2) {
                x += 1;
                arr[x][y] = 9;
                break;
            }
            else if (arr[x + 1][y] == 0) {
                x = x + 1;
                arr[x][y] = 9;
            }
            else {
                break;
            }
            
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
