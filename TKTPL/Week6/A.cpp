#include<bits/stdc++.h>
using namespace std;

struct StructMath {
	static const int maxn = 100000;
	static const int logmax = 16;
	bool vis[logmax * maxn + 1], dupl[maxn + 1];
	int cost[logmax + 1];
	long long has;
	int N;

	void read() {
		cin >> N;
	}

	void generate(int x) {
		cost[x] = cost[x - 1];
		for(int i = 2; i <= N; i++) {
			if(vis[i * x]) {
				cost[x]++;
			}
			else {
				vis[i * x] = 1;
			}
		}
	}

	void prekom() {
		for(int i = 1; i <= 16; i++) {
			generate(i);
		}
	}

	void solve() {
		// cout << "solve\n";
		has = (long long) (N - 1) * (N - 1);
		for(int i = 2; i <= N; i++) {
			int k = 0;
			if(dupl[i]) {
				continue;
			}
			for(long long j = i; j <= (long long)N; j *= (long long)i) {
				k++;
				dupl[j] = 1;
			}
			has -= cost[k];
		}
	}

	void print() {
		cout << has << "\n";
	}
} M;

int main() {
	M.read();
	M.prekom();
	M.solve();
	M.print();
}