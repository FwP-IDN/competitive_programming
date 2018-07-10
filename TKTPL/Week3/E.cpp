#include<bits/stdc++.h>
using namespace std;


#define pb push_back

const int MAXN = 1000;


int N, M;
int dist[MAXN * 2 + 5];
int match[MAXN * 2 + 5];
vector<int> adj[MAXN * 2 + 5];

void init() {
	for(int i = 1; i <= N; i++) {
		adj[i].clear();
		match[i] = 0;
		match[i + N] = 0;
	}
}

void read_input() {
	scanf("%d %d", &N, &M);
	init();
	int a, b;
	while(M--) {
		scanf("%d %d", &a, &b);
		b += N;
		adj[a].pb(b);
	}
}

bool bfs() {
	queue<int> qq;
	dist[0] = -1;
	for(int i = 1; i <= N; i++) {
		if(match[i] == 0) {
			qq.push(i);
			dist[i] = 0;
		}
		else {
			dist[i] = -1;
		}
	}
	while(!qq.empty()) {
		int dep = qq.front(); qq.pop();
		for(int i = 0; i < (int)adj[dep].size(); i++) {
			int ke = adj[dep][i];
			int pake = match[ke];
			if(dist[pake] == -1) {
				qq.push(pake);
				dist[pake] = dist[dep] + 1;
			}
		}
	}
	if(dist[0] != -1) {
		dist[0] = INT_MAX;
		return true;
	}
	return false;
}

bool dfs(int nod) {
	// cout << " " << nod << "\n";
	// int cuk; cin >> cuk;
	if(nod == 0) {
		return true;
	}
	for(int i = 0; i < (int)adj[nod].size(); i++) {
		int ke = adj[nod][i];
		int pake = match[ke];
		if(dist[pake] > dist[nod]) if(dfs(pake)) {
			match[nod] = ke;
			match[ke] = nod;
			return true;
		}
	}
	return false;
}

int mcbm() {
	int ret = 0;
	while(bfs()) {
		for(int i = 1; i <= N; i++) {
			if(match[i] == 0 && dfs(i)) {
				ret++;
			}
		}
		// for(int i = 1; i <= N * 2; i++) {
		// 	cout << i << "  " << match[i] << "\n";
		// }
	}
	return ret;
}

void solve(int tcnum) {
	printf("Case %d: %d\n", tcnum, N - mcbm());
}

int main() {
	int tes;
	scanf("%d", &tes);
	for(int cas = 1; cas <= tes; cas++) {
		read_input();
		solve(cas);
	}
}