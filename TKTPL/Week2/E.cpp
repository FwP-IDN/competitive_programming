#include<bits/stdc++.h>
using namespace std;

#define maxn 100
#define pb push_back


int aw, ak, n;
vector<int> adj[maxn + 5];
int par[maxn + 5], flow[maxn + 5];
int cap[maxn + 5][maxn + 5];

void init() {
	for(int i = 1; i <= n; i++) {
		adj[i].clear();
		for(int j = 1; j <= n; j++) {
			cap[i][j] = 0;
		}
	}
}

int bfs() {
	queue<int> qq;
	for(int i = 1; i <= n; i++) {
		par[i] = -1;
	}
	par[aw] = aw;
	flow[aw] = INT_MAX;
	qq.push(aw);
	int dep;
	while(!qq.empty()) {
		dep = qq.front(); qq.pop();
		for(int ke : adj[dep]) {
			if(par[ke] == -1 && cap[dep][ke]) {
				par[ke] = dep;
				flow[ke] = min(flow[dep], cap[dep][ke]);
				qq.push(ke);
			}
		}
	}
	if(par[ak] == -1) {
		return 0;
	}
	int sek = par[ak], kar = ak;
	while(sek != kar) {
		cap[sek][kar] -= flow[ak];
		cap[kar][sek] += flow[ak];
		sek = par[sek];
		kar = par[kar];
	}
	return flow[ak];
}

int maxflow() {
	int ret = 0, tam;
	do {
		tam = bfs();
		ret += tam;
	} while(tam);
	return ret;
}

int main() {
	int cas = 0, a, b, c, m;
	while(cin >> n) {
		if(n == 0) {
			return 0;
		}
		cas++;
		init();
		cin >> aw >> ak >> m;
		while(m--) {
			cin >> a >> b >> c;
			adj[a].pb(b);
			adj[b].pb(a);
			cap[a][b] += c;
			cap[b][a] += c;
		}
		cout << "Network " << cas << "\n";
		cout << "The bandwidth is " << maxflow() << ".\n";
		cout << "\n";
	}
}