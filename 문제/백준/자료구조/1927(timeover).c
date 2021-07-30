/*
널리 잘 알려진 자료구조 중 최소 힙이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt, number, heap[100001] = { 0, },arrlen = 0;


void change(int* hp, int p, int s) {
    int temp = hp[p];
    hp[p] = hp[s];
    hp[s] = temp;
}

void heapsort(int* hp, int len)
{
    for (int i = 1; i < len; i++) {
        int son = i;
        do {
            int parent = (son - 1) / 2;
            if (hp[parent] > hp[son]) {
                change(hp, parent, son);
            }
            son = parent;
        } while (son != 0);
    }

    for (int i = len - 1; i >= 0; i--) {
        int temp = hp[0];
        hp[0] = hp[i];
        hp[i] = temp;

        int parent = 0;
        int son = 1;

        do {
            son = 2 * parent + 1; //root의 자식

            //자식 중에 더 작은 값을 찾기
            if (heap[son] > heap[son + 1] && son < i - 1) {
                son++;
            }

            //루트보다 자식이 더 작다면 교환
            if (hp[parent] < hp[son] && son < i) {
                change(hp, parent, son);
            }
            parent = son;
        } while (son < i);
    }
}

int main(void) {
    scanf("%d", &cnt); //입력 횟수 
    
    while (cnt > 0)
    {
        scanf("%d", &number); //숫자 입력
        if (number == 0) //만약에 0번이면
        {
            if (arrlen == 0) //배열에 아무것도 없으면
                printf("0\n");
            else {
                printf("%d\n", heap[arrlen - 1]); // 제일 작은거 출력
                heap[arrlen - 1] = 0;
                arrlen--;
            }
        }
        else
        {
            heap[arrlen] = number;
            arrlen++;
        }
        heapsort(heap, arrlen);
        cnt--;
    }

    return 0;
}
