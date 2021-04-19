#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//터렛 두 원의 교점 수 구하기
int main() {
    int count;
    int x1, x2, y1, y2, r1, r2;
    double d,sub; //이 double 때문에 틀렸다. ㅡㅡ 
    scanf("%d", &count);
    
    for (int i = 0; i < count; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));    

        sub = r1 > r2 ? r1 - r2 : r2 - r1;

        if (d == 0 && r1 == r2) {
            printf("-1\n");
        }
        else if (d < r1 + r2 && sub < d) {
            printf("2\n");
        }
        else if (d == r1 + r2 || d == sub) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    

    return 0;
}
