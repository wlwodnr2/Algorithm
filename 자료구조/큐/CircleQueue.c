#include <stdio.h>
#include <stdlib.h>
#include "CircleQueue.h"

void QueueInit(Queue* pq) // 텅 빈 Queue 초기화
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) // 큐의 다음 위치에 해당하는 인덱스 값 반환.
{
    if (pos == QUE_LEN - 1) //다음 위치가 QUE_LEN-1이면 ? 꽉찬거다 ? 
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue* pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front) //return 값이 front와 같다면 ? 
    {
        printf("Queue Memory Error !"); // 메모리 꽉 찼음
        exit(-1);
    }
    pq->rear = NextPosIdx(pq->rear); //rear값은 rear+1값으로 하나 추가 
    pq->queArr[pq->rear] = data; //데이터 추가할 공간 있으니깐 추가
}

Data Dequeue(Queue* pq)
{
    if (QIsEmpty(pq)) // Queue가 비어있으면 꺼낼게 없으니깐
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue* pq)
{
    if (QIsEmpty(pq)) // Queue가 비어있으면 볼 수 없으니
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)]; // front가 가리키고 있는 값은 빈 공간이다. 
}
