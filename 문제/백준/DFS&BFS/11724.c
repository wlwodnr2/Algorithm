#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SZ 1001

int N, M;
int map[SZ][SZ];
int DFS_c[SZ] = { 0 };
int ans_cnt = 0;

void DFS(int v) {
    DFS_c[v] = 1;
    for (int k = 1; k <= N; k++) {
        if (DFS_c[k] == 0 && map[v][k] == 1) {
            DFS(k);
        }
    }
} //일반 적인 DFS

void solution() {
    for (int i = 1; i <= N; i++) {
        if (DFS_c[i] == 0) {
            ans_cnt++;
            DFS(i);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int u, v;
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
    }

    solution();
   
    printf("%d", ans_cnt);
}
