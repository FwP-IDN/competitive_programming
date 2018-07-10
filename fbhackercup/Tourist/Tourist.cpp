#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
const long long INF = 1e12+1;

char A[MAXN][21];
int used[MAXN];
long long comb[MAXN+1][MAXN+1];
long long fact[MAXN+1];

void precomp() {
	for(int i = 0; i <= 50; i++) {
		comb[i][0] = 1;
	}
	for(int i = 1; i <= 50; i++) {
		for(int j = 1; j <= i; j++) {
			comb[i][j] = min(INF, comb[i-1][j-1] + comb[i-1][j]);
		}
	}
}

void work() {
	static int cas = 0;
	int N, K;
	long long V;
	scanf("%d %d %lld", &N, &K, &V);
	V--;
	V %= comb[N][K];
	V++;
	for(int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	printf("Case #%d:", ++cas);
	int i = 0;
	while(K > 0) {
		if(comb[N-1][K-1] >= V) {
			printf(" %s", A[i]);
			K--;
		}
		else {
			V -= comb[N-1][K-1];
		}
		N--;
		i++;
	}
	puts("");
}

int main(int argc, char** argv) {
	precomp();
	int T;
	scanf("%d", &T);
	while(T--) {
		work();
	}
}