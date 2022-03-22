#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int N, map[26][26] = { 0 };
int check[26][26] = { 0 };
int house_cnt[320] = { 0 };
int cnt = 0, z = 0;;

void cmp(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 >= num2) return 1;
    if (num1 < num2) return -1;
}

void DFS(int y, int x) {
    check[y][x] = 1; //지나갔어요
    cnt++;
    //만약 x-1값이 over가 아니고, map에서 1이라면 DFS ㄱ
    if (x - 1 >= 0 && map[y][x - 1] == 1 && check[y][x - 1] == 0) DFS(y, x - 1);

    //만약 x+1값이 over가 아니고, map에서 1이라면 DFS ㄱ
    if (x + 1 < N && map[y][x + 1] == 1 && check[y][x + 1] == 0) DFS(y, x + 1); 

    //만약 y-1값이 over가 아니고, map에서 1이라면 DFS ㄱ
    if (y - 1 >= 0 && map[y - 1][x] == 1 && check[y - 1][x] == 0) DFS(y - 1, x); 

    //만약 y+1값이 over가 아니고, map에서 1이라면 DFS ㄱ
    if (y + 1 < N && map[y + 1][x] == 1 && check[y + 1][x] == 0) DFS(y + 1, x);
    
    return;     
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]); 
        }
    }
    //시작점 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && check[i][j] == 0) { //map에서 1값이고, 안 지나간 곳이라면 시작점이다.
                DFS(i, j);
                house_cnt[z] = cnt;
                z++;
                cnt = 0;
            }
        }
    }
    qsort(house_cnt, z, sizeof(int), cmp);
    printf("%d\n", z);
    for (int i = 0; i < z; i++) printf("%d\n", house_cnt[i]);
    return 0;
}
