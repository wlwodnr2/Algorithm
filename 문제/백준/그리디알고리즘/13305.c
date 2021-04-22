#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct city {
	long long city;
	long long km;
	long long cnt;
}city;
int main() {
	int N, fin = 0, start = 0;
	long long mon=0;
	scanf("%d", &N); //도시 개수 입력
	city* c1 = (city*)calloc(N, sizeof(city));
	for (int i = 0; i < N - 1; i++) scanf("%lld", &(c1+i)->km); //거리 입력
	for (int i = 0; i < N; i++) scanf("%lld", &(c1 + i)->city); //city 입력
	for (int i = 0; i != N-1; i++) {
		if ((c1 + i)->city >= (c1 + i + 1)->city) { //n번째 city의 기름 값이 n+1번째 city의 기름 값보다 비싸다면?
			(c1 + i)->cnt += (c1+i)->km;
		}
		else { //n번째 city의 기름 값이 n+1번째 city의 기름 값보다 작거나 같다면? -> 자기보다 작은거 찾아야돼 끝까지..
			(c1 + i)->cnt += ((c1 + i)->km + (c1+i+1)->km); //n번째와 n+1번째 km수 만큼 저장
			while (i+start + 2 < N - 1) { //n+1번째는 이미 n번째보다 크니깐 n+2번째부터 시작해서 N-1까지 
				if ((c1 + i)->city <= (c1 +i +2+start)->city) { //만약 n번째가 n+2번째보다 작다면? 계속 더해
					(c1 + i)->cnt += (c1 +i+ 2+start)->km;
					start++;
				}
				else break; //n번째가 n+2번째보다 크다면 break
			}
			i = i + 1 + start;
			start = 0;
		}
	}
	for (int i = 0; i < N-1; i++) mon+=(c1 + i)->cnt*(c1+i)->city; //city 입력
	printf("%lld", mon);
	return 0;
}
