#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num1, num2, num3, num4;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    
    printf("%.1f MB", (float)num1*num2*num3*num4/8/1024/1024);
    
    return 0;
}
