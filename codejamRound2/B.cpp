#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct Adhoc {
	int A, B, C, has, cas = 0;
	int dp[505][505][505];
	vector<pair<int, int> > item;

	static bool sum_cmp(pair<int, int> a, pair<int, int> b) {
		return a.f + a.s < b.f + b.s;
	}

	void init() {
		item.clear();
	}

	void read() {
		scanf("%d %d", &A, &B);
	}

	void prepare() {
		for(int sum = 1; sum <= A + B; sum++) {
			for(int iA = max(0, sum - B); iA <= min(A, sum); iA++) {
				int iB = sum - iA;
				item.push_back(make_pair(iA, iB));
			}
		}
		C = min(500, (int)item.size());
		for(int i = 0; i <= A; i++) {
			for(int j = 0; j <= B; j++) {
				for(int k = 0; k <= C; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
	}

	int rek(int ida, int idb, int idc) {
		if(idc == C) {
			return 0;
		}
		if(ida == 0 && idb == 0) {
			return 0;
		}
		int &ret = dp[ida][idb][idc];
		if(ret >= 0) {
			return ret;
		}
		ret = rek(ida, idb, idc + 1);
		if(ida >= item[idc].f && idb >= item[idc].s) {
			ret = max(ret, 1 + rek(ida - item[idc].f, idb - item[idc].s, idc + 1));
		}
		return ret;
	}

	void solve_all() {
		has = rek(A, B, 0);
	}

	void print() {
		printf("Case #%d: %d\n", ++cas, has);
	}

} S;

int main() {
	// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tes;
	scanf("%d", &tes);
	while(tes--) {
		S.init();
		S.read();
		S.prepare();
		S.solve_all();
		S.print();
	}
}