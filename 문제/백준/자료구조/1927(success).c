/*
널리 잘 알려진 자료구조 중 최소 힙이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt, number, heap[200000] = { 0, }, arrlen = 0;

void change(int* hp, int p, int s) {
    int temp = hp[p];
    hp[p] = hp[s];
    hp[s] = temp;
}

void push(int* hp,int len, int num)
{
    int parent; // 부모 노드 위치

    if (len == 0) //만약 배열이 비어있다면 num을 넣어준다.
        hp[0] = num;
    else
    {
        hp[len] = num;
        while (len != 0) // 0번 위치가 아닐때까지 반복
        {
            parent = (len - 1) / 2; // 부모 노드
            if (hp[len] < hp[parent]) // 만약 부모 노드보다 자식 노드가 작다면 바꿔
            {
                change(hp, parent, len); //위치 변경
            }
            len = parent; // 자식이 부모 위치로 변경
        }
    }
}

int pop(int* hp, int len)
{
    int parent = 0, son, popnum = hp[0];

    hp[0] = hp[len - 1]; // 0번 위치에 마지막 인덱스 값 대입
    hp[len - 1] = 0; // 어차피 초기화니깐 상관 없음
    len--; //길이 하나 줄여주시고
    while (1)
    {
        son = parent * 2 + 1; // 왼쪽 자식
        if ((son != len-1) && hp[son] > hp[son + 1]) // 오른쪽 자식이 길이보다 작거나 같고, 왼쪽이 오른쪽보다 크면 오른쪽 자식으로 위치 이동
            son++;
        if (son>len-1 || (hp[son] > hp[parent] && hp[parent]!=0)) break;
        change(hp, parent, son);
        parent = son;
    }
    return popnum;
}

int main() {
    
    scanf("%d", &cnt); //입력 횟수 

    while (cnt > 0)
    {
        scanf("%d", &number);
        if (number == 0)
        {
            if (arrlen == 0) printf("0\n");
            else
            {
                printf("%d\n", pop(heap, arrlen));
                arrlen--;
            }
        }  
        else
        {
            push(heap, arrlen, number);
            arrlen++;
        }
        cnt--;
    }
    return 0;
}
