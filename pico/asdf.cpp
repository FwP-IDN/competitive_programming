#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
ll pref[120];
ll dp[60][60];
ll mod = (ll)1000000007;

ll getVal(int aw, int ak) {
	if(aw > ak) {
		return 0;
	}
	ll kur;
	if(aw == 0) {
		kur = 0;
	}
	else {
		kur = pref[aw - 1];
	}
	return (pref[ak] - kur + mod) % mod;
}

int main() {
	int dist, addv;
	while(scanf("%d %d", &n, &m)) {
		if(!(n | m)) {
			return 0;
		}
		dp[0][0] = 1;
		pref[0] = dp[0][0];
		for(int j = 1; j < n - 1; j++) {
			pref[j] = (dp[0][j] + pref[j - 1]) % mod;
		}
		for(int j = n - 1; j < 2 * n - 2; j++) {
			pref[j] = (dp[0][j - (n - 1)] + pref[j - 1]) % mod;
		}

		dist = (m + 1) / (n - 1);
		addv = (m + 1) % (n - 1);

		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n - 1; j++) {
				dp[i][j] = (getVal(j + 1, j + n - 1 - addv) * dist) % mod;
				dp[i][j] = (dp[i][j] + getVal(j + n - addv, j + n - 1) * (dist + 1)) % mod;
			}
			pref[0] = dp[i][0];
			for(int j = 1; j < n - 1; j++) {
				pref[j] = (dp[i][j] + pref[j - 1]) % mod;
			}
			for(int j = n - 1; j < 2 * n - 2; j++) {
				pref[j] = (dp[i][j - (n - 1)] + pref[j - 1]) % mod;
			}
		}
		printf("%lld\n", (dp[n - 1][0] * n) % mod);
	}
}