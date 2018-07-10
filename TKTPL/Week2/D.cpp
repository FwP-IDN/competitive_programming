#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 500000

ll ar[maxn + 5];
set<ll> sen[maxn + 5];
set<ll> senall;
int n;

ll gcd(ll a, ll b) {
	return (a == 0 ? b : gcd(b % a, a));
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", ar + i);
		for(set<ll>::iterator it = sen[i - 1].begin(); it != sen[i - 1].end(); it++) {
			ll val = gcd(*it, ar[i]);
			senall.insert(val);
			sen[i].insert(val);
		}
		senall.insert(ar[i]);
		sen[i].insert(ar[i]);
		sen[i - 1].clear();
	}
	printf("%d\n", (int)senall.size());
}