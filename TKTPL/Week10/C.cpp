#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long pows(long long ret, int pan, long long mod) {
	if(pan == 0) {
		return 1;
	}
	ll sav = 1;
	while(pan ^ 1) {
		if(pan & 1) {
			sav *= ret;
			sav %= mod;
		}
		ret *= ret;
		ret %= mod;
		pan >>= 1;
	}
	ret *= sav;
	ret %= mod;
	return ret;
}

long long inv(int num, int mod) {
	return pows(num, mod - 2, mod);
}

int cium(int bil, int mod) {
	if(bil < mod) {
		return 0;
	}
	return bil / mod + cium(bil / mod, mod);
}

int solve(int nn, int rr, int mod) {
	if(nn < rr) {
		return 0;
	}
	else if(nn == rr) {
		return 1;
	}
	long long mul = solve(nn / mod, rr / mod, mod);
	nn %= mod;
	rr %= mod;
	if(nn < rr) {
		return 0;
	}
	long long ret = 1;
	long long denom = 1;
	for(int i = 0; i < rr; i++) {
		ret *= (long long)(nn - i); ret %= (long long)mod;
		denom *= (long long)(rr - i); denom %= (long long)mod;
	}
	ret = (ret * inv(denom, mod)) % (long long)mod;
	ret = (ret * mul) % (long long)mod;
	return ret;
}

int main() {
	int T, N, M, P;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &N, &M, &P);
		printf("%d\n", solve(N + M, min(N, M), P));
	}
}