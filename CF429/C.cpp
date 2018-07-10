#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct StructDP {
	static const int MAXN = 300;
	static const ll mod = (ll)1000000007;
	ll dp[MAXN + 5][MAXN + 5], fact[MAXN + 5], inv_fact[MAXN + 5], has;
	vector<int> inp, numb, cnt, suff;
	void read() {
		int N;
		scanf("%d", &N);
		inp.resize(N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &inp[i]);
		}
	}

	ll Qua(ll mas) {
		return mas * mas;
	}

	bool isQuadrat(ll mas) {
		ll sq = sqrt(mas);
		return Qua(sq) == mas || Qua(sq + 1) == mas || Qua(sq - 1) == mas;
	}

	ll pows(ll ret, int pan) {
		if(pan == 0) {
			return ret;
		}
		ll sav = 1;
		while(pan ^ 1) {
			if(pan & 1) {
				sav *= ret;
				sav %= mod;
			}
			pan >>= 1;
			ret *= ret;
			ret %= mod;
		}
		ret *= sav;
		ret %= mod;
		return ret;
	}

	ll inv(ll mas) {
		return pows(mas, mod - 2);
	}

	void precomp() {
		for(int i = 0; i < (int)inp.size(); i++) {
			int j;
			for(j = 0; j < (int)numb.size(); j++) {
				if(isQuadrat((ll)inp[i] * numb[j])) {
					cnt[j]++;
					break;
				}
			}
			if(j == (int)numb.size()) {
				numb.push_back(inp[i]);
				cnt.push_back(1);
			}
		}


		fact[0] = 1; inv_fact[0] = 1;
		for(int i = 1; i < MAXN + 5; i++) {
			fact[i] = (fact[i - 1] * i) % mod;
			inv_fact[i] = inv(fact[i]);
		}

		sort(cnt.begin(), cnt.end());

		suff.resize(cnt.size() + 1);
		for(int i = (int)suff.size() - 2; i >= 0; i--) {
			suff[i] = suff[i + 1] + cnt[i];
		}

		// for(int x : cnt) {
		// 	cout << x << " ";
		// }
		// cout << "\n";
	}

	ll Comb(int nn, int rr) {
		if(nn < rr || nn < nn - rr) {
			return 0;
		}
		ll ret = (fact[nn] * inv_fact[rr]) % mod;
		ret *= inv_fact[nn - rr];
		ret %= mod;
		return ret;
	}

	ll Perm(int nn, int rr) {
		if(nn < rr || nn < nn - rr) {
			return 0;
		}
		return (fact[nn] * inv_fact[nn - rr]) % mod;
	}

	ll solve(int blong, int idx) {
		// printf("===%d===%d========\n", blong, idx);
		ll &ret = dp[blong][idx];
		if(ret >= 0) {
			// printf("===%d===%d======ret\n", blong, idx);
			return ret;
		}
		if(idx == 0) {
			// printf("===%d===%d===blong\n", blong, idx);
			if(blong == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		ret = 0;
		for(int grup = 1; grup <= cnt[idx - 1]; grup++) {
			// cout << "grup " << grup << "\n";
			int add_blong = cnt[idx - 1] - grup;
			int freepos = suff[idx] + 1 - blong;
			ll comb_tanpa_perulangan = Comb(cnt[idx - 1] - 1, grup - 1);
			for(int buat_blong = 0; buat_blong <= min(grup, blong); buat_blong++) {
				// cout << "buat_blong " << buat_blong << "\n";
				int buat_freepos = grup - buat_blong;
				if(buat_freepos > freepos) {
					continue;
				}
				ll val = comb_tanpa_perulangan;
				// cout << "val " << val << "\n";
				val *= Comb(freepos, buat_freepos); val %= mod;
				val *= Comb(blong, buat_blong); val %= mod;
				val *= solve(blong + add_blong - buat_blong, idx - 1); val %= mod;
				ret += val;
				ret %= mod;
			}
		}
		// printf("===%d===%d========\n", blong, idx);
		return ret;
	}

	void solve_all() {
		memset(dp, -1, sizeof(dp));
		// cout << "cnt.back() " << cnt[0] << "\n";
		has = solve(cnt.back() - 1, (int)cnt.size() - 1);
		for(int i = 0; i < (int)cnt.size(); i++) {
			has *= fact[cnt[i]];
			has %= mod;
		}
	}

	void print() {
		printf("%lld\n", has);
	}
} D;

int main() {
	D.read();
	D.precomp();
	D.solve_all();
	D.print();
}