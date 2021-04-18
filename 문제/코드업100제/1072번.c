#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num1,num2;
    scanf("%d", &num2);

print:
    num2 = num2 - 1;
    if (num2 >= 0) {
        scanf("%d", &num1);
        printf("%d\n", num1);
        goto print;
    }
    else
        goto end;
end:
    return 0;
}
