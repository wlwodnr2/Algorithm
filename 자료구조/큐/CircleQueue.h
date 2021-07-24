#ifndef __C_Queue_H__
#define __C_Queue_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data; // 형변환이 쉬운 int 형임

typedef struct _cQueue
{
    int front; //F
    int rear;  //R
    Data queArr[QUE_LEN]; // int형 배열 
}CQueue;
typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq); //근데 왜 Data로 선언한지 모르겠음 어차피 int 형인데


#endif
