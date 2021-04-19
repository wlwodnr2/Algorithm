#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int data[1001];
void merge(int a[], int m, int middle, int n) {// 배열 , 시작, 중간, 끝
    int i = m;
    int j = middle + 1;
    int k = m; //i랑 동일 선상에 있다고 보면 됨
    //작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            data[k] = a[i];
            i++;
        }
        else {
            data[k] = a[j];
            j++;
        }
        k++;
    }
    //남은 데이터도 삽입
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            data[k] = a[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            data[k] = a[t];
            k++;
        }
    }
    //정렬된 배열을 삽입
    for (int t = m; t <= n; t++) {
        a[t] = data[t];
    }
}
void mergeSort(int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
int main(void) {
    int N, allsum = 0;
    int array[1001];
    int sum[1001] = { 0, };
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    mergeSort(array, 0, N - 1);
    sum[0] = array[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i-1] + array[i];
    }
    for (int i = 0; i < N; i++) {
        allsum = allsum + sum[i];
    }
    printf("%d", allsum);
    return 0;
}
