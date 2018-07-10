#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair
const int MAXN = 1000000;
long long ans[MAXN + 5];

void precomp() {
	for(int i = 1; i <= MAXN; i++) {
		ans[i] = i;
	}
	for(int i = 2; i <= MAXN; i++) {
		if(ans[i] == i) {
			for(int j = i; j <= MAXN; j += i) {
				ans[j] -= (ans[j] / (ll)i);
			}
		}
	}
	for(int i = 1; i <= MAXN; i++) {
		ans[i] += ans[i-1];
	}
}

int main() {
	int T, N, L;
	precomp();
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &L);
		printf("%lld\n", max((long long)0, ans[N/L] * 2 - 1));
	}
}