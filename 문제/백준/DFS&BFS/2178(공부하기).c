#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int x; 
	int y;
	struct _Node* next;
} Node;

typedef struct _Queue {

	Node* front; //front부분
	Node* rear; //rear부분
	int count; //count?

} Queue;

void CreateQueue(Queue** queue); //queue 더블 포인터
Node* CreateNode(int x, int y); //CreateNode라는 함수 Node포인터 생성
void Push(Queue* queue, int x, int y); //Push
Node* Pop(Queue* queue); //Pop라는 함수 Node포인터 생성
void BFS(int end_x, int end_y, int graph[][101]); //BFS 함수


int main(void)
{
	int graph[100][101];
	int N, M; // N : y | M : x

	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%1d", &graph[y][x]);

	BFS(M, N, graph);

	printf("%d", graph[N - 1][M - 1]);

	return 0;
}


void CreateQueue(Queue** queue) //q생성
{
	(*queue) = (Queue*)malloc(sizeof(Queue)); //동적할당

	(*queue)->rear = NULL; //queue의 rear에 빈공간 형성
	(*queue)->front = NULL; //queue의 front에 빈공간 형성
	(*queue)->count = 0; //count = 0
}

Node* CreateNode(int x, int y)
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); //

	NewNode->x = x;
	NewNode->y = y;
	NewNode->next = NULL;

	return NewNode;
}

void Push(Queue* queue, int x, int y)
{
	Node* newNode = CreateNode(x, y);
	//when queue is empty
	if (!queue->count)
	{
		queue->rear = newNode;
		queue->front = newNode;
	}

	//when queue is not empty
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}

	queue->count++;
}

Node* Pop(Queue* queue)
{
	Node* PopNode = queue->front;

	if (queue->count == 1)
	{
		queue->rear = NULL;
		queue->front = NULL;
	}

	else
		queue->front = queue->front->next;

	queue->count--;
	return PopNode;
}

void BFS(int end_x, int end_y, int graph[][101])
{
	Queue* queue;
	CreateQueue(&queue);

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	int x, y, nx, ny;
	Node* temp;

	Push(queue, 0, 0);

	while (queue->count)
	{
		temp = Pop(queue);
		x = temp->x;
		y = temp->y;
		free(temp);

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > end_x || ny > end_y)
				continue;

			if (graph[ny][nx] == 1)
			{
				graph[ny][nx] = graph[y][x] + 1;
				Push(queue, nx, ny);
			}
		}
	}
}
