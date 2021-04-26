#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void cmp(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}
int main() {
    int N, arr[1002], sum=0,num=0;
	scanf("%d", &N);
	for (int k = 0; k < N; k++) scanf("%d", &arr[k]); //N만큼 수 입력
    qsort(arr, N,sizeof(int),cmp); //정렬 완료
    if (arr[0] != 1) num = 1;
    else{
        sum = 1;
        for (int i = 1; i < N; i++) {
            if (sum + 1 < arr[i]) break;
            sum += arr[i];
        }
        num = sum + 1;
    }
    printf("%d", num);
	return 0;
}
