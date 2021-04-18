#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct string{
    char string[51];
    int length;
};
struct string input[51];
void sort_big(struct string input[51], int N) { //길이비교

    for (int i = 0; i < N; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (input[root].length < input[c].length) {
                struct string temp = input[c];
                input[c] = input[root];
                input[root] = temp;
            }
            c = root;
        } while (c != 0);
        
    }
    
    for (int i = N - 1; i >= 0; i--) {
        struct string temp = input[0];
        input[0] = input[i];
        input[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1; //root의 자식
            //자식 중에 더 큰 값을 찾ㄱ기
            if (input[c].length < input[c + 1].length && c < i - 1) {
                c++;
            }
            //부모보다 자식이 더 크다면 교환
            if (input[root].length < input[c].length && c < i) {
                struct string temp = input[root];
                input[root] = input[c];
                input[c] = temp;
            }
            
            root = c;
        } while (c < i);
    }
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N - 1; i++) {
            if (input[i].length == input[i + 1].length) {
                if (strcmp(input[i].string, input[i + 1].string) > 0) {
                    struct string temp = input[i];
                    input[i] = input[i + 1];
                    input[i + 1] = temp;
                }
            }
        }
    }
    
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", input[i].string);
    }
    for (int i = 0; i < N; i++) {
        input[i].length = strlen(input[i].string); //길이 대입 input에 이제 각각 입력의 글자와 길이 입력
    }
    sort_big(input, N); //길이비교 힙정렬
    
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            printf("%s \n", input[i].string);
        }
        else if (strcmp(input[i].string, input[i - 1].string) != 0) {
            printf("%s \n", input[i].string);
        }
        
    }

    return 0;
}
