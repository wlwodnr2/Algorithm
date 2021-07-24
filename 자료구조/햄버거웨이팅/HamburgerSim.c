#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircleQueue.h"

#define CUS_COME_TERM 15 // 고객의 주문 간격 : 15초

#define CHE_BUR 0 // 치즈버거 상수
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12 // 치즈버거 제작 시간 : 12초 
#define BUL_TERM 15
#define DUB_TERM 24

int main(void)
{
    int makeProc = 0; //햄버거 제작 진행상황
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;
    int sec;

    Queue que;

    QueueInit(&que); // 큐 배열 초기화
    srand(time(NULL)); // 찐 난수 생성

    for (sec = 0; sec < 3600; sec++) // 1시간 기준 3600초 
    {
        if (sec % CUS_COME_TERM == 0) // 주문은 15초마다 
        {
            switch (rand() % 3) // 랜덤 숫자 나누기 3의 나머지가 0 , 1 , 2인 경우 아 랜덤 주문 
            {
            case CHE_BUR: // 치즈 버거인 경우 
                Enqueue(&que, CHE_TERM); //que에 치즈 버거 텀 추가 12초 
                cheOrder += 1; // 오더 수 증가  
                break;

            case BUL_BUR: // 불고기 버거인 경우
                Enqueue(&que, BUL_TERM); //que에 불고기 버거 텀 추가 15초 
                bulOrder += 1;
                break;

            case DUB_BUR: // 더블 버거인 경우
                Enqueue(&que, DUB_TERM); //que에 더블 버거 텀 추가 24초
                dubOrder += 1;
                break;
            }
        }
        if (makeProc <= 0 && !QIsEmpty(&que)) // makeProc이 0 이하고 QIsEmpty가 빈 공간이 아니라면 
            makeProc = Dequeue(&que); //que에서 맨 앞 주문 빼서 makeProc에 추가 

        makeProc--; //그리고 makeProc에 있는 주문은 걸리는 시간초만큼 0으로 향한다.
    }
    printf("Simulation Report! \n");
    printf(" - Cheese burger : %d \n", cheOrder);
    printf(" - Bulgogi burger : %d \n", bulOrder);
    printf(" - Double burger : %d \n", dubOrder);
    printf(" - Waiting room size : %d \n", QUE_LEN);
    return 0;
}
