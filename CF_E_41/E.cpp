#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;


struct StructTree {
	static const int MAXN = 200000;
	int BIT[MAXN + 5];
	ll has = 0;
	vector<int> adj[MAXN + 5];
	int N;
	int A[MAXN + 5];

	void read() {
		cin >> N;
		for(int i = 1; i <= N; i++) {
			cin >> A[i]; A[i] = min(A[i], N);
			adj[A[i]].pb(i);
		}
		// for(int i = 1; i <= N; i++) {
		// 	cout << A[i] << " ";
		// }
		// cout << "\n";
	}

	int queryBIT(int pos) {
		if(pos == 0) {
			return 0;
		}
		return BIT[pos] + queryBIT(pos - (pos & (-pos)));
	}

	void updateBIT(int pos, int vv) {
		if(pos > N) {
			return;
		}
		BIT[pos] += vv;
		updateBIT(pos + (pos & (-pos)), vv);
	}

	void solve() {
		for(int i = N; i >= 1; i--) {
			for(int x : adj[i]) {
				// cout << "u " << x << "\n";
				updateBIT(x, 1);
			}
			has += (ll)max(0, queryBIT(A[i]) - queryBIT(i));
			// cout << i << "  " << has << "\n";
		}
		cout << has << "\n";
	}

} T;

int main() {
	T.read();
	T.solve();
}