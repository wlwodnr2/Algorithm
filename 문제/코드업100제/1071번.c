#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num1;

print:
    scanf("%d", &num1);
    if (num1 != 0) {
        printf("%d\n", num1);
        goto print;
    }
    else
        goto end;
end:
    return 0;
}
