//Queue에 대한 배열 문제 풀이

/*
처음에 scanf로 몇 번 수행할건지 입력

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    int cnt, queue[10001] = { 0, }, num, fnt = 0, bck = 0;
    char arr[10];
    
    scanf("%d", &cnt); //count 입력

    while (cnt > 0)
    {
        scanf("%s", arr);

        if (strcmp(arr, "push") == 0) {
            scanf("%d", &num);
            queue[bck] = num; //back 해당하는 위치에 num 저장 push 역할
            bck++; //하나 추가하니깐 
        }
        else if (strcmp(arr, "pop") == 0) {
            if ((bck - fnt) == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", queue[fnt]); //제일 앞에 있는 숫자 출력
                queue[fnt] = 0;
                fnt++;
            }
        }
        else if (strcmp(arr, "size") == 0) {
            printf("%d\n", bck - fnt);
        }
        else if (strcmp(arr, "empty") == 0) {
            if ((bck - fnt) == 0) // 비어있으면 1
                printf("1\n");
            else //아니면 0
                printf("0\n");
        }
        else if (strcmp(arr, "front") == 0) {
            if ((bck - fnt) == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[fnt]);
        }
        else if (strcmp(arr, "back") == 0) {
            if ((bck - fnt) == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[bck-1]);
        }
        memset(arr, 0, 10);
        cnt--;
    }
}
