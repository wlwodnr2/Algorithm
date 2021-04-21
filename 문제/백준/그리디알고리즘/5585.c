#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int cnt =0,money, charge;
    int coin[6] = {500,100,50,10,5,1};
    scanf("%d", &money); //물건 가격
    charge = 1000 - money;
    for (int i = 0; i < (sizeof(coin)/sizeof(int)); i++) {
        if ((charge / coin[i]) >= 1) {
            cnt += charge / coin[i];
            charge -= (coin[i]) * (charge/coin[i]);
        }
    }
    printf("%d", cnt);
    return 0;
}
