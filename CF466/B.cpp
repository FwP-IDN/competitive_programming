#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a, b, k, n;

ll solve(ll x) {
	if(x < k || k == 1) {
		return a * (x - 1);
	}
	ll ret = min((ll)a * (x - 1), a * (x % k) + b + solve(x / k));
	// cout << x << "  " << ret << "\n";
	return ret;
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
	printf("%lld\n", solve(n));
}