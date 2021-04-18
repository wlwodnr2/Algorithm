#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num1;
    scanf("%X", &num1);

    for (int i = 1; i < 16; i++) {
        printf("%X*%X=%X \n", num1, i, num1 * i);
    }
    return 0;
}
