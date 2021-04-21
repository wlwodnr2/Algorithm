#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    int i =0,j=0,z=0;
    char sik[51], k[51] = { 0, };
    scanf("%s", &sik);
    do {
        if ((sik[i] == '-') || (sik[i] == '+')) {
            k[j] = sik[i];
            sik[i] = ' ';
            j++;
        }
        i++;
    } while (sik[i] != '\0'); //'+' '-' 숫자랑 분리
    
    char *ptr = strtok(sik, " ");
    int sum = atoi(ptr);
    int minus_cnt = 0;
    while (z < j)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        ptr = strtok(NULL, " ");
        if (k[z] == '-') minus_cnt += 1;
        if (minus_cnt >= 1) sum -= atoi(ptr);
        else sum += atoi(ptr);
        z++;
    }
    printf("%d", sum);
    return 0;
}
