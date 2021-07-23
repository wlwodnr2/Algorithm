#include <string.h>
#include <ctype.h>
#include "ArrayStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int explen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for (i = 0; i < explen; i++)
    {
        tok = exp[i];

        if (isdigit(tok))
        {
            SPush(&stack, tok - '0'); //문자형 정수를 정수형으로 변환
        }
        else
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok)
            {
            case '+':
                SPush(&stack, op1 + op2);
                break;
            case '-':
                SPush(&stack, op1 + op2);
                break;
            case '*':
                SPush(&stack, op1 * op2);
                break;
            case '/':
                SPush(&stack, op1 / op2);
                break;

            }
        }
    }
    return SPop(&stack);
}
