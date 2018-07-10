#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int MAXX = 1e9;
int ar[100000];
int N, K;

int main(int argc, char** argv) {
	scanf("%d %d", &N, &K);
	if(N / 2 > K || (N / 2 == 0 && K > 0)) {
		printf("-1\n");
		return 0;
	}
	ar[0] = K - N / 2 + 1;
	ar[1] = ar[0] * 2;
	for(int i = N - 1; i >= 2; i--) {
		ar[i] = MAXX - i;
	}
	printf("%d", ar[0]);
	for(int i = 1; i < N; i++) {
		printf(" %d", ar[i]);
	}
	printf("\n");
}