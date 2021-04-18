#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char num1;
   
    while (1) {
        scanf("%c", &num1);
        printf("%c", num1);
        if (num1 == 'q') {
            break;
        }
    }
    return 0;
}
