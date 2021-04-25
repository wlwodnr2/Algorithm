#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void heapsort(int heap[],int number) {
    for (int i = 1; i < number; i++) {
        int sun = i;
        do { //일단 부모들이 자식들보다 크게 정렬 , //최대힙
            int parent = (sun - 1) / 2; // 부모 = (자식 -1)/2 , 자식 왼쪽 = 2*부모 +1
            if (heap[parent] < heap[sun]) { //부모가 자식보다 작다면 바꿔
                int temp = heap[parent];
                heap[parent] = heap[sun];
                heap[sun] = temp;
            }
            sun = parent; // 자식이 부모로 이동해서 
        } while (sun != 0);
    }
    
    for (int i = number - 1; i >= 0; i--) { // 맨 끝에서부터
        int temp = heap[0]; //최대 힙에서 맨 윗대가리 맨 끝으로 바꿔주기
        heap[0] = heap[i];
        heap[i] = temp;
        int parent = 0; //부모는 0번째 맨 위 그럼 작은애가 올라가 있을거임 
        int sun = 1; //자식은 1
        do {
            sun = 2 * parent + 1; //자식 식
            if (heap[sun] < heap[sun + 1] && sun < i - 1) { //오른쪽 자식이 왼쪽 자식보다 크다면, 오른쪽 자식 기준 제일 작은게 i-2번째니깐
                sun++; //자식+1? 
            }
            if (heap[parent] < heap[sun] && sun < i) { //부모가 더 큰 자식보다 작고, 왼쪽 자식 기준 제일 작은게 i-1번째
                int temp = heap[parent];
                heap[parent] = heap[sun];
                heap[sun] = temp;
            }
            parent = sun;
        } while (sun < i);
    }
}

int main() {
	int N,arr[10001],sum=0;
	scanf("%d", &N);
	for (int k = 0; k < N; k++) scanf("%d", &arr[k]); //N만큼 수 입력
    heapsort(arr, N); //정렬 완료
    int i = N - 1;
    for (i; i >=0; i--) {
        if (arr[i] >= 0) {
            if (i == 0) sum += arr[i];
            else if (arr[i] == 1 || arr[i - 1] == 1) sum += arr[i];
            else if (arr[i] > 0 && arr[i - 1] > 0) { //양수면 큰 거 두개끼리 계속 묶어서 더하기
                sum += arr[i] * arr[i - 1];
                i--;
            }
            else if (arr[i] == 0 || arr[i - 1] == 0) {
                if (arr[i] == 0) { //앞에가 0일경우
                    if (i % 2 == 1) { //남은게 홀수일 경우
                        sum += arr[i] * arr[i - 1];
                        i--;
                    }
                }
                else sum += arr[i];//뒤에가 0일 경우에는
            }
            else sum += arr[i]; //하나 양수 하나 음수인 경우?
        }
        else break;
    }
    for (int j = 0; j <= i; j+=2) {
        if (j+1<=i)sum += arr[j] * arr[j + 1];
        else sum += arr[j];
    }
    printf("%d", sum);
	return 0;
}
