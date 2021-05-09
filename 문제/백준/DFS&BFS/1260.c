#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int DFS_c[1001] = { 0, };
int BFS_c[1001] = { 0, };
int connect[1001][1001] = { 0, };
int queue[1001];

void DFS(int N, int start) {
    int i;
    DFS_c[start] = 1; //노드 시작하면서 지나갔다.
    printf("%d ", start);
    for (i = 1; i <= N; i++) {
        if (DFS_c[i] == 0 && connect[start][i] == 1) { //만약에 안 지나갔고 연결되어있다면
            DFS(N, i); //재귀함수로 연결된 노드부터 시작.
        }
    }
    return;
}

void BFS(int N, int start) {
    int front = 0, rear = 1;
    BFS_c[start] = 1; //시작 노드를 큐에서 뺏다고 가정하면서 거쳤다 1
    queue[front] = start; //queue에 시작 하나 추가
    printf("%d ", start);
    while (front < rear) {
        for (int i = 1; i <= N; i++) {
            if (connect[start][i] == 1 && BFS_c[i] == 0) {
                queue[rear] = i; //queue에 연결 된 노드들 추가
                BFS_c[i] = 1; //queue에 추가 되었으니 1로 바꿔주고
                rear += 1;
                printf("%d ", i);
            }
        }
        front += 1;
        start = queue[front]; //시작이 queue 다음 값으로.
    }
    return;
}
int main() {
    int N, M, V,a,b;
    scanf("%d %d %d", &N, &M, &V); //N, M, V 입력
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b); //노드들 입력하면
        connect[a][b] = 1; // 행렬에 값 대입
        connect[b][a] = 1; // 행렬 값 대입
    }
    DFS(N,V);
    printf("\n");
    BFS(N,V);
    return 0;
}
