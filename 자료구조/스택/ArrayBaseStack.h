#ifndef __AB_STACK_H__ //헤더 파일이 두 번 불리면 안 되기 때문에 에러 방지용 
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data; //그냥 정수형인데 typedef는 마치 #define같은 느낌 

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack); //스택 초기화
int SIsEmpty(Stack* pstack); //스택 비었는가 ? 

void SPush(Stack* pstack, Data data); // 스택에 push , 여기서 data는 그냥 int형 변수 
Data SPop(Stack* pstack); //스택에 pop
Data Speek(Stack* pstack); //스택에 peek 

#endif
