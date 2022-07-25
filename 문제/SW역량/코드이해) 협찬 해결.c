#include <stdio.h>

int N;//협찬 물품의 수
int D[100000 + 10];//선호도
int sol = -30001;//첫번째 방법의 최대 선호도
int max[100000 + 10];

void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &D[i]);
	}
}

void Solve(void)
{
	int i, sum = 0;
	for (i = 0; i < N - 2; i++) {
		sum = D[i] + D[i + 1] + D[i + 2];
		if (sum > sol) sol = sum;
	}

}

void CalculateMax(void)
{
	max[0] = D[0];
	max[1] = max[0] + D[1] > D[1] ? max[0] + D[1] : D[1];
	
	for(int i = 2; i < N; i++){
		int sum1;
		sum1 = max[i-1] + D[i];
		max[i] = sum1 > D[i] ? sum1 : D[i];
	}
}
void FindMax(void)
{
	for(int i = 0; i<N; i++) sol = sol > max[i] ? sol : max[i];
}

int main(void) {
	InputData();//입력 함수
	Solve();
	CalculateMax();
	FindMax();
	printf("%d\n", sol);//출력 
	return 0;
}
