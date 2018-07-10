#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

vector<int> ans;

int main() {
	ll P;
	int K;
	scanf("%lld %d", &P, &K);
	while(P) {
		for(int i = 0; i < K; i++) {
			if(((ll)i - P) % (ll)K == 0) {
				ans.pb(i);
				P = ((ll)i - P) / (ll)K;
			}
		}
	}
	printf("%d\n", ans.size());
	for(int x : ans) {
		printf("%d ", x);
	}
	printf("\n");
}