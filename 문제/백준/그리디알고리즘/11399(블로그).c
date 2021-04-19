#include <stdio.h> 
int main(void) {
    int N, i, t, sum;
    int P[1001] = { 0 };
    int time[1000] = { 0 }; /* input */ 
    scanf("%d", &N); 
    for (i = 0; i < N; i++) { 
        scanf("%d", &t); P[t]++; 
    } /* solve */ 
    sum = 0; 
    t = 0; 
    for (i = 1; i < 1001; i++) { 
        while (P[i] > 0) { 
            sum += i; 
            time[t] = sum; 
            t++; 
            P[i]--; 
        } 
    } /* output */ 
    sum = 0; 
    for (i = 0; i < N; i++) sum += time[i]; 
    printf("%d\n", sum); return 0;
}

출처: https://suri78.tistory.com/27 [공부노트]
