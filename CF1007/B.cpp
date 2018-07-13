#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

const int MAXN = 1e5;

#define FLAG1 1
#define FLAG2 2
#define FLAG3 4
#define ALLFLAG 7

int A, B, C;
int sz1, sz2, sz3;
int has;

int target[500];
int cnt[ALLFLAG + 1];
int flag[MAXN+5];
vector<int> fact[MAXN+5];

inline void precomp() {
	for(int i = 1; i <= MAXN; i++) {
		for(int j = i; j <= MAXN; j += i) {
			fact[j].pb(i);
		}
	}
}

int comb(int nn, int rr) {
	nn += rr;
	int ret = 1;
	for(int i = 0; i < rr; i++) {
		ret *= (nn - i);
	}
	for(int i = 0; i < rr; i++) {
		ret /= (rr - i);
	}
	return ret;
}

inline void solve() {
	has = 0;
	cin >> A >> B >> C;
	sz3 = 0; sz1 = 0; sz2 = 0;
	for(int x : fact[A]) {
		target[sz1++] = x;
	}
	sz2 = sz1;
	for(int x : fact[B]) {
		target[sz2++] = x;
	}
	sz3 = sz2;
	for(int x : fact[C]) {
		target[sz3++] = x;
	}
	for(int i = 0; i < sz3; i++) {
		flag[target[i]] = 0;
	}
	for(int i = 0; i < sz1; i++) {
		flag[target[i]] |= FLAG1;
	}
	for(int i = sz1; i < sz2; i++) {
		flag[target[i]] |= FLAG2;
	}
	for(int i = sz2; i < sz3; i++) {
		flag[target[i]] |= FLAG3;
	}
	// for(int i = 0; i < sz3; i++) {
	// 	cout << target[i] << " " << flag[target[i]] << "  ";
	// }
	// cout << "--\n";
	sort(target, target+sz3);
	sz3 = unique(target, target+sz3) - target;
	for(int i = 0; i <= ALLFLAG; i++) {
		cnt[i] = 0;
	}
	for(int i = 0; i < sz3; i++) {
		cnt[flag[target[i]]]++;
	}
	// 3 sama 
	has += comb(cnt[7]-1, 3);
	// 2 sama
	for(int i = 1; i <= 7; i++) {
		for(int j = 1; j <= 7; j++) {
			if(i == j || i == (i&(-i))) {
				continue;
			}
			if((i|j) == 7) {
				has += comb(cnt[i]-1,2)*cnt[j];
			}
		}
	}
	// 1 sama
	for(int i = 1; i <= 7; i++) {
		for(int j = i+1; j <= 7; j++) {
			for(int k = j+1; k <= 7; k++) {
				if((i|j|k) == 7) {
					has += cnt[i]*cnt[j]*cnt[k];
				}
			}
		}
	}
	cout << has << "\n";
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	precomp();
	int asw = 0;
	for(int i = 1; i <= MAXN; i++) {
		asw = max(asw, (int)fact[i].size());
	}
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}