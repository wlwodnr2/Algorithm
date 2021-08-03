/*
세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

//스택에 데이터를 집어넣는다.
int push(char ch) {
    if (top >= MAX - 1) return -1;
    return stack[++top] = ch;
}

//스택에서 데이터를 뽑는다.
int pop() {
    if (top < 0) return -1;
    return stack[top--] = '\0';
}

//스택 상단의 내용을 읽는다.
char peek() {
    return stack[top];
}

//균형잡힌 문자열인지를 판단
void Result(char* ch, int size) {
    for (int i = 0; i < size; i++) {
        if (ch[i] == '(' || ch[i] == ')' || ch[i] == '[' || ch[i] == ']') {
            //top가 -1이라면 무조건 push
            if (top == -1) push(ch[i]);
            else {
                //짝이라면 pop
                if (peek() == '(' && ch[i] == ')') pop();
                else if (peek() == '[' && ch[i] == ']') pop();
                //그 외 push
                else push(ch[i]);
            }
        }
    }
    //top가 -1이면 균형잡힌 문자열
    if (top == -1) printf("yes\n");
    else printf("no\n");
}

int main() {
    char str[MAX];
    while (1) {
        top = -1;
        gets(str);
        if (strcmp(str, ".") == 0) break;
        Result(str, strlen(str));
    }
    return 0;
}
