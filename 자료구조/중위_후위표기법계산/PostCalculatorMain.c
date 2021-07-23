#include <stdio.h>
#include "PostCalculator.h"

int main(void)
{
    char postExp1[] = "42*8+"; // 4*2 = 88+ -> 8+8 = 16
    char postExp2[] = "123+*4/"; // 2+3 = 15*4/ -> 1*5 = 54/ -> 5/4 = 1.25

    printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
    printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

    return 0;
}
