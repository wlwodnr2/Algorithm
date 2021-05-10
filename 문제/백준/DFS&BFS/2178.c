#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
    int N, M, arr[101][101], queue_x[10001], queue_y[10001];
    long long check[101][101] = { 0, };
    scanf("%d %d", &N, &M); //N, M, V 입력
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            scanf("%1d", &arr[y][x]); //N*M 행렬 입력
        }
    }
    queue_x[1] = 1; queue_y[1] = 1;
    check[1][1] = 1;
    int front = 1, rear = 2; //앞을 1 뒤를 2
    while (front<rear) { //N*M행렬에 다다르면 탈출
        //상
        if (queue_y[front] != 1 && check[queue_y[front]-1][queue_x[front]] == 0 && arr[queue_y[front]-1][queue_x[front]] ==1) { //맨 첫줄이 아니고, 한 번도 지나가지 않았으며, 갈 수 있는 길일때
            queue_y[rear] = queue_y[front] - 1; //y값에서 -1한 값을 넣어야 하고
            queue_x[rear] = queue_x[front]; //x값은 그대로
            check[queue_y[front] - 1][queue_x[front]] = check[queue_y[front]][queue_x[front]] + 1; //옮기기 이전 값을 더해준다. 
            rear++; //뒷행으로 추가 추가와 실행을 동시에 ? 
        }
        //하
        if (queue_y[front] != N && check[queue_y[front] + 1][queue_x[front]] == 0 && arr[queue_y[front] + 1][queue_x[front]] == 1) { //맨 끝줄이 아닐때 아래로 갈 수 있다.
            queue_y[rear] = queue_y[front] + 1; 
            queue_x[rear] = queue_x[front]; 
            check[queue_y[front] + 1][queue_x[front]] = check[queue_y[front]][queue_x[front]] + 1; //옮기기 이전 값을 더해준다. 
            rear++; 
        }
        //좌
        if (queue_x[front] != 1 && check[queue_y[front]][queue_x[front]-1] == 0 && arr[queue_y[front]][queue_x[front]-1] == 1) { //맨 왼쪽줄이 아니면 왼쪽으로 갈 수 있고~
            queue_y[rear] = queue_y[front]; 
            queue_x[rear] = queue_x[front]-1; 
            check[queue_y[front]][queue_x[front]-1] = check[queue_y[front]][queue_x[front]] + 1; //옮기기 이전 값을 더해준다. 
            rear++;  
        }
        //우
        if (queue_x[front] != M && check[queue_y[front]][queue_x[front]+1] == 0 && arr[queue_y[front]][queue_x[front]+1] == 1) { //맨 오른쪽 줄이 아니면 오른쪽으로 갈 수 있다.
            queue_y[rear] = queue_y[front]; 
            queue_x[rear] = queue_x[front]+1; 
            check[queue_y[front]][queue_x[front]+1] = check[queue_y[front]][queue_x[front]] + 1; //옮기기 이전 값을 더해준다. 
            rear++; 
        }
        front++; //앞에 하나 움직여주기 
    }
    printf("%lld", check[N][M]);
    return 0;
}
