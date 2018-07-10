#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

int R, C, E;
int cas = 0, tes;
int num[2005][2005];
vector<int> adj[2005];
int dist[2005];
int match[2005];
int vis[2005];

void read_input() {
	++cas;
	while(E--) {
		int a, b;
		cin >> a >> b;
		num[a][b] = cas;
	}
}

void make_graph() {
	for(int i = 1; i <= R; i++) {
		adj[i].clear();
		for(int j = 1; j <= C; j++) {
			if(num[i][j] == cas) {
				adj[i].pb(j + R);
			}
		}
	}
}

bool dfs1(int now) {
	if(now == 0) {
		return true;
	}
	for(int ke : adj[now]) {
		int pake = match[ke];
		if(dist[pake] > dist[now]) {
			if(dfs1(pake)) {
				match[now] = ke;
				match[ke] = now;
				return true;
			}
		}
	}
	return false;
}

bool bfs() {
	queue<int> qq;
	dist[0] = -1;
	for(int i = 1; i <= R; i++) {
		if(match[i] == 0) {
			dist[i] = 0;
			qq.push(i);
		}
		else {
			dist[i] = -1;
		}
	}
	while(!qq.empty()) {
		int now = qq.front(); qq.pop();
		for(int ke : adj[now]) {
			int pake = match[ke];
			if(dist[pake] == -1) {
				dist[pake] = dist[now] + 1;
				qq.push(pake);
			}
		}
	}
	if(dist[0] == -1) {
		return false;
	}
	dist[0] = INT_MAX;
	return true;
}

void dfs2(int now) {
	vis[now] = cas;
	for(int ke : adj[now]) {
		int pake = match[ke];
		if(pake == now) {
			continue;
		}
		if(vis[pake] != cas) {
			vis[ke] = cas;
			dfs2(pake);
		}
	}
}

void solve() {
	for(int i = 1; i <= R + C; i++) {
		match[i] = 0;
	}
	int ret = 0;
	while(bfs()) {
		for(int i = 1; i <= R; i++) {
			if(match[i] == 0 && dfs1(i)) {
				ret++;
			}
		}
	}
	for(int i = 1; i <= R; i++) {
		if(match[i] == 0) {
			dfs2(i);
		}
	}
	cout << ret;
	for(int i = 1; i <= R; i++) {
		if(vis[i] != cas && adj[i].size()) {
			cout << " r" << i;
			ret--;
		}
	}
	for(int i = R + 1; i <= R + C; i++) {
		if(vis[i] == cas) {
			cout << " c" << i - R; 
			ret--;
		}
	}
	cout << "\n";
	assert(ret == 0);
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin >> R >> C >> E) {
		if(R == 0 && C == 0 && E == 0) {
			return 0;
		}
		read_input();
		make_graph();
		solve();
	}
}