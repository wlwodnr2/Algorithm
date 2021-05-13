#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[101][101] = { 0 };
int DFS_c[101] = { 0 };

void DFS(int N, int start,int *cnt) {
	
	DFS_c[start] = 1; //노드 시작하면서 지나갔다.
	
	for (int i = 1; i <= N; i++) {
		if (DFS_c[i] == 0 && graph[start][i] == 1) { //DFS_c는 지나갔으면 1이고, 안 지나갔으면 0임. graph는 연결 되어있어 ? 
			*cnt = *cnt +1;
			DFS(N, i,cnt); //재귀함수로 연결된 노드부터 시작.
		}
	}
	return;
}

int main(void)
{
	int N,M,a,b; // N: 컴퓨터 수, M : 연결된 쌍의 수 
	int cnt = 0;

	scanf("%d", &N);
	scanf("%d", &M);
	
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1; graph[b][a] = 1; //연결된 노드끼리 값 1
	}

	DFS(N, 1,&cnt);
	printf("%d", cnt);

	return 0;
}
