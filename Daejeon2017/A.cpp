#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

struct StructCentroid {
	static const int MAXN = 100000;
	int has = MAXN + 1;
	void read() {
		cin >> N;
		int lop = N - 1;
		while(lop--) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
			incl[a].pb(0);
			incl[b].pb(0);
			excl[a].pb(0);
			excl[b].pb(0);
		}
	}

	void bfs() {
		for(int i = 1; i <= N; i++) {
			if(adj[i].size() == 1) {
				qq.push(i);
				dist[i] = 0;
			}
			else {
				dist[i] = -1;
			}
		}
		while(!qq.empty()) {
			int dep = qq.front();
			for(int x : adj[dep]) {
				if(dist[x] == -1) {
					dist[x] = dist[dep] + 1;
					qq.push(x);
				}
			}
		}
	}

	void init() {
		bfs();
		int nimax = -1;
		for(int i = 1; i <= N; i++) {
			nimax = max(nimax, dist[i]);
		}
		vector<int> stp; // start point
		for(int i = 1; i <= N; i++) {
			if(nimax == dist[i]) {
				stp.pb(i);
			}
		}
		if((int)stp.size() == 1) {
			dist[stp[0]] = 0;
			for(int x : adj[dist[stp[0]]]) {
				dist[x] = 1;
				dfs(x, 1);
			}
		}
		else {
			assert((int)stp.size() == 2);

		}
	}

	void solve_all() {
		init();
	}

	void print() {
		if(N <= 2) {
			has = 1;
		}
		cout << has << "\n";
	}
} C;

int main() {
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	C.read();
	C.solve_all();
	C.print();
}