#include<bits/stdc++.h>
using namespace std;

#define pb push_back
const int maxn = 100000;


vector<int> adj[maxn + 5];
int match[maxn + 5];
int dist[maxn + 5];
int N, M, K;

bool dfs(int now) {
	if(now == 0) {
		return true;
	}
	for(int ke : adj[now]) {
		int pake = match[ke];
		if(dist[pake] > dist[now]) {
			if(dfs(pake)) {
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
	for(int i = 1; i <= N; i++) {
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
				qq.push(pake);
				dist[pake] = dist[now] + 1;
			}
		}
	}
	if(dist[0] == -1) {
		return false;
	}
	dist[0] = INT_MAX;
	return true;
}

int mcbm() {
	int ret = 0;
	while(bfs()) {
		for(int i = 1; i <= N; i++) {
			if(match[i] == 0 && dfs(i)) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	int A, B;
	scanf("%d %d %d", &N, &M, &K);
	while(K--) {
		scanf("%d %d", &A, &B);
		B += N;
		adj[A].pb(B);
	}
	printf("%d\n", mcbm());
}