#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
int arr[10],front =0, rear=0;
void put() {
    if (rear >= sizeof(arr) / sizeof(int)) {//만약 뒤를 가르키는 숫자가 크기를 초과하면 return 함수 종료
        printf("큐 포화상태입니다.\n");
        return;
    }
    printf("값을 입력해주세요 : ");
    scanf("%d", &arr[rear]); //rear 값 입력
    rear += 1; //입력한 값 뒤 빈공간으로 이동
}
void get() {
    if (front == rear) { //뒤를 가르키는 것과 앞을 가르키는 것이 같으면 빼낼 자료가 없는 것이니 return
        printf("삭제할 큐가 없습니다.\n");
        return; 
    }
    printf("꺼내진 정수는 :  %d\n", arr[0]); 
    memcpy(&arr[0], &arr[front+1], sizeof(int)*(rear - front-1)); //맨 앞에 삭제니깐 맨 앞+1부터 rear-front+1까지
    rear -= 1; //뒤를 한자리 앞으로 땡기기.
}
int main() {
    for (int i = 0; i < 11; i++) {
        put();
        printf("Queue(front:%d, rear:%d) : ",front,rear);
        for (int j = 0; j < rear; j++) {
            printf(" %d || ",arr[j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 11; i++) {
        get();
        printf("Queue(front:%d, rear:%d) : ", front, rear);
        for (int j = 0; j < rear; j++) {
            printf("%d || ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}
