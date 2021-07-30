//연결 리스트

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

typedef struct _node {
    int value;
    struct _node* next; //연결 리스트
}Node; 

int main(void)
{
    int cnt = 0, num, value1;
    char arr[10];
    scanf("%d", &num); //입력 횟수 

    Node* front = NULL; //앞쪽 가르키는 노드
    Node* back = NULL; //뒤쪽 가르키는 노드
    Node* newnode = NULL; //새로운 노드
    Node* delnode = NULL;

    while (num > 0)
    {
        scanf("%s", arr); //문자열 입력
        if (!strcmp(arr, "push"))
        {
            scanf("%d", &value1);
            newnode = (Node*)malloc(sizeof(Node));
            newnode->value = value1;
            newnode->next = NULL;

            if (front == NULL)
                front = newnode;
            else
                back->next = newnode; // 다음 노드가 newnode라는걸 이어주고
            back = newnode; //back 위치 조정
            cnt++;
        }
        else if (!strcmp(arr, "pop"))
        {
            if (!cnt)
                printf("-1\n"); //cnt = 0이면 pop -1
            else
            {
                printf("%d\n", front->value); //첫 번째 숫자 출력
                delnode = front;
                front = delnode->next;
                free(delnode);
                cnt--;
            }
        }
        else if (!strcmp(arr, "size"))
        {
            printf("%d\n", cnt);
        }
        else if (!strcmp(arr, "empty"))
        {
            if (!cnt)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!strcmp(arr, "front"))
        {
            if (!cnt)
                printf("-1\n");
            else
                printf("%d\n", front->value);
        }
        else if (!strcmp(arr, "back"))
        {
            if (!cnt)
                printf("-1\n");
            else
                printf("%d\n", back->value);
        }
        num--;
    }
}
