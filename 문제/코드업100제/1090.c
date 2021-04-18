#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    long long int num1, num2, num3, num4;
    scanf("%lld %lld %lld", &num1, &num2, &num3);
    for (int i = 0; i < num3-1; i++) {
        num1 = num1 * num2;
    }
    printf("%lld", num1);
    
    return 0;
}
