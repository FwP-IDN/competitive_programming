#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
#define pb push_back

int aw = 0, ak, n, has = 0;
int par[maxn + 5];
int flow[maxn + 5];
int cap[maxn + 5][maxn + 5];
vector<int> adj[maxn + 5];

int bfs() {
	queue<int> qq;
	qq.push(aw);
	for(int i = 1; i <= ak; i++) {
		par[i] = -1;
	}
	flow[aw] = 1000000000;
	while(!qq.empty()) {
		int dep = qq.front(); qq.pop();
		// cout << "cok " << dep << "\n";
		if(dep == ak) {
			int a = par[ak];
			int b = ak;
			stack<int> path;
			path.push(b);
			do {
				cap[a][b] -= flow[ak];
				cap[b][a] += flow[ak];
				a = par[a];
				b = par[b];
				path.push(b);
			} while(b != aw);
			// cout << " path : ";
			// while(!path.empty()) {
			// 	cout << "-" << path.top(); path.pop();
			// }
			// cout << "\n";
			return flow[ak];
		}
		for(int nex : adj[dep]) {
			if(!cap[dep][nex] || par[nex] != -1) {
				continue;
			}
			par[nex] = dep;
			flow[nex] = min(flow[dep], cap[dep][nex]);
			qq.push(nex);
		}
	}
	return 0;
}

int maxflow() {
	int ret = 0;
	int tam;
	do {
		tam = bfs();
		ret += tam;
	} while(tam > 0);
	return ret;
}

void addEdge(int a, int b, int c) {
	adj[a].pb(b);
	adj[b].pb(a);
	cap[a][b] = c;
	cap[b][a] = 0;
}

int main() {
	scanf("%d", &n);
	ak = n + 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cap[i][j] = 1000000000;
		}
	}
	int val, kur, m, pt;
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &val, &kur, &m);
		val -= kur;
		// cout << i << " = " << val << "\n";
		if(val > 0) {
			addEdge(aw, i, val);
			has += val;
		}
		else if(val < 0) {
			addEdge(i, ak, -val);
		}
		for(int j = 1; j <= m; j++) {
			scanf("%d", &pt);
			addEdge(pt, i, 1000000000);
		}
	}
	has -= maxflow();
	printf("%d\n", has);
}