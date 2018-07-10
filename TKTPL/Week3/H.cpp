#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

ll A, B;
int K, D;
ll mod = (ll)1000000007;
ll filling[1 << 10];
ll has, denom;
ll dp[2][20][1 << 10];
ll comb1[11]; // kombinasi berbeda dengan at least parameter titik yang mirip
// dp[1][..][..] // valuenya terbatas, index setelahnya sama dengan bilangan batasnya
// dp[0][..][..] // valuenya cenderung bebas, index setelah PASTI lebih kecil

ll pang(ll ret, int pan) {
	if(pan == 0) {
		return 1;
	}
	ll sim = 1;
	while(pan ^ 1) {
		if(pan & 1) {
			sim *= ret;
			sim %= mod;
		}
		pan >>= 1;
		ret *= ret;
		ret %= mod;
	}
	ret *= sim;
	ret %= mod;
	return ret;
}

ll inv(ll mas) {
	if(mas == 0) {
		return 1;
	}
	return pang(mas, mod - 2);
}

void getFill(ll num, int times) {
	if(num == 0) {
		return;
	}
	vector<int> ven;
	while(num) {
		ven.pb((int)(num % (ll)10));
		num /= (ll)10;
	}
	// init dp
	for(int k = 0; k < 2; k++) {
		for(int i = 0; i < (int)ven.size(); i++) {
			for(int j = 0; j < (1 << 10); j++) {
				dp[k][i][j] = 0;
			}
		}	
	}
	int sv = ven.size();
	int mostDig = ven.back();
	dp[1][sv - 1][1 << mostDig] = 1;
	for(int i = 1; i < mostDig; i++) {
		dp[0][sv - 1][1 << i] = 1;
	}
	if(sv > 1) {
		dp[0][sv - 1][0] = 1;
	}
	for(int i = (int)ven.size() - 1; i >= 1; i--) {
		for(int j = 0; j < (1 << 10); j++) {
			int k;
			k = 0; // sabeb
			if(j > 0) {
				int d = 0;
				dp[0][i - 1][j | (1 << d)] += dp[k][i][j];
				dp[0][i - 1][j | (1 << d)] %= mod;
			}
			else if(i > 1) {
				// kasih kosongan di belakangnya
				dp[0][i - 1][j] += dp[k][i][j];
				dp[0][i - 1][j] %= mod;
			}
			for(int d = 1; d < 10; d++) {
				dp[0][i - 1][j | (1 << d)] += dp[k][i][j];
				dp[0][i - 1][j | (1 << d)] %= mod;
			}
			k = 1; // terbatas
			// dikasihin ke sama sama terbatas
			int nexNum = ven[i - 1];
			int d = nexNum;
			dp[1][i - 1][j | (1 << d)] += dp[k][i][j];
			dp[1][i - 1][j | (1 << d)] %= mod;
			for(d = nexNum - 1; d >= 0; d--) {
				dp[0][i - 1][j | (1 << d)] += dp[k][i][j];
				dp[0][i - 1][j | (1 << d)] %= mod;	
			}
		}
	}
	for(int i = 0; i < (1 << 10); i++) {
		filling[i] += (mod + mod + dp[0][0][i] * times + dp[1][0][i] * times) % mod;
	}
}


void construct() {
	fill(filling, filling + (1 << 10), 0);
	getFill(B, 1);
	getFill(A - 1, -1);
	// for(int i = 0; i < (1 << 10); i++) {
	// 	if(filling[i]) {
	// 		for(int j = 0; j < 10; j++) {
	// 			if(i & (1 << j)) {
	// 				cout << j;
	// 			}
	// 			else {
	// 				cout << '*';
	// 			}
	// 		}
	// 		cout << " " << filling[i] << "\n";
	// 	}
	// }
	for(int i = 0; i < (1 << 10); i++) {
		for(int j = i + 1; j < (1 << 10); j++) {
			if((i & j) == i) {
				filling[i] += filling[j]; filling[i] %= mod;
			}
		}
	}
	for(int i = 0; i <= 10; i++) {
		comb1[i] = 0;
	}
	// for(int i = 0; i < (1 << 10); i++) {
	// 	if(filling[i]) {
	// 		cout << i << " " << filling[i] << " ;;\n";
	// 	}
	// }
	for(int i = 0; i < (1 << 10); i++) {
		int d = __builtin_popcount(i);
		ll tam = 1;
		for(ll j = filling[i]; j >= filling[i] - K + 1; j--) {
			tam *= j; tam %= mod;
		}
		tam *= inv(denom); tam %= mod;
		comb1[d] += tam; comb1[d] %= mod;
	}
}

void solve() {
	// Inclusion dan Exclusion
	// for(int i = 0; i <= 10; i++) {
	// 	cout << i << " " << comb1[i] << "\n";
	// }
	ll res = comb1[D];
	ll runVal = 1;
	for(int nn = D + 1, rr = 1; nn <= 10; nn++, rr++) {
		runVal *= (ll)nn; runVal %= mod;
		runVal *= inv(rr); runVal %= mod;
		if(rr & 1) {
			res += (mod - ((runVal * comb1[nn]) % mod)); res %= mod;
		}
		else {
			res += (runVal * comb1[nn]); res %= mod;
		}
	}
	has = res;
}

int main() {
	int tes;
	scanf("%d", &tes);
	while(tes--) {
		scanf("%lld %lld %d %d", &A, &B, &K, &D);
		denom = 1;
		for(int i = 2; i <= K; i++) {
			denom *= i;
			denom %= mod;
		}
		construct();
		solve();
		printf("%lld\n", has);
	}
}