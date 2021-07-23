#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayStack.h"

int GetOpPrec(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 5; //연산자 우선 순위 부여 
    case '+':
    case '-':
        return 3; //연산자 우선 순위 부여 
    case '(':
    case ')':
        return 1; //연산자 우선 순위 부여 
    }

    return -1;
}

int WhoPrecOp(char op1, char op2) //연산자 우선 순위 비교 
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) //1이 2보다 크면 return 1
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[])
{
    Stack stack;
    int explen = strlen(exp);
    char* convExp = (char*)malloc(explen + 1); //문자 길이만큼 문자형 포인터 동적 할당

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char) * explen + 1); //초기화 
    StackInit(&stack); //stack 구조체 초기화

    for (i = 0; i < explen; i++)
    {
        tok = exp[i];
        if (isdigit(tok)) //숫자를 판단하는 함수
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch (tok)
            {
            case '(': //만약에 (면 SPush
                SPush(&stack, tok);
                break;
            case ')': //만약에 )면 ~ 
                while (1)
                {
                    popOp = SPop(&stack); 
                    if (popOp == '(')
                        break;
                    convExp[idx++] = popOp; //pop해서 convExp에 집어넣기
                }
                break;

            case '+': case '-':
            case '*': case '/': // +, -, *, /면 비어있지 않고 + 맨 마지막 애가 tok보다 우선순위가 높으면 convExp에 추가
                while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                    convExp[idx++] = SPop(&stack);
                SPush(&stack, tok);
                break;
            }
        }
    }

    while (!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp);
    free(convExp);
}

