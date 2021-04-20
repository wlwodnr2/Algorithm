#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//회의 시작 시간에 맞춘 끝 시간 정렬?
int data1[100001]; 
int data2[100001];
void merge(int a[],int b[], int m, int middle, int n) {// 배열 , 시작, 중간, 끝
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            data1[k] = a[i];
            data2[k] = b[i];
            i++;
        }
        else {
            data1[k] = a[j];
            data2[k] = b[j];
            j++;
        }
        k++;
    }
    //남은 데이터도 삽입
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            data1[k] = a[t];
            data2[k] = b[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            data1[k] = a[t];
            data2[k] = b[t];
            k++;
        }
    }
    //정렬된 배열을 삽입
    for (int t = m; t <= n; t++) {
        a[t] = data1[t];
        b[t] = data2[t];
    }
}
void mergeSort(int a[], int b[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, b, m, middle);
        mergeSort(a, b, middle + 1, n);
        merge(a, b, m, middle, n);
    }
}
//c가 그 순서, d는 회의 개수
void conference(int N,int j[], int k[], int c, int *d) {
    int init = c;

    if (c >= N) {
        return 0;
    }
    while (1) {

        if (k[init] <= j[c + 1]) {
            *d += 1;
            conference(N,j, k, c+1, d);
            break;
        }
        else c += 1;
        if (c >= N) break;   
    }
    
}

int main() {
    int N, start[100001] = { 0, }, end[100001] = { 0, }, count=1, max_count = 1;
    scanf("%d", &N); //회의 개수
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }
    mergeSort(start,end, 0, N-1);
    for (int i = 0; i < N; i++) {
        conference(N, start, end, i, &count);
        if (count > max_count) {
            max_count = count;
        }
        count = 1;
    }
    printf("%d", max_count);
    
    return 0;
}
