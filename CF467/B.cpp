#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair

const int maxn = 100000;

int dp[maxn + 5][2], par[maxn + 5][2], der[maxn + 5];
int n, m, ak;
queue<pii> qq;
vector<int> adj[maxn + 5];
int WHITE = 0;
int GRAY = 1;
int BLACK = 2;
int col[maxn + 5];
bool Lop;
vector<int> rev[maxn + 5];


void dfs(int now) {
	col[now] = GRAY;
	for(int ke : rev[now]) {
		if(col[ke] == WHITE) {
			dfs(ke);
		}
		else if(col[ke] == GRAY) {
			Lop = true;
			return;
		}
	}
	col[now] = BLACK;
}


void bfs() {
	while(!qq.empty()) {
		pii now = qq.front(); qq.pop();
		for(int ke : adj[now.f]) {
			if(!dp[ke][now.s ^ 1]){
				dp[ke][now.s ^ 1] = 1;
				qq.push(mp(ke, now.s ^ 1));
				par[ke][now.s ^ 1] = now.f;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> der[i];
		if(der[i] == 0) {
			qq.push(mp(i, 0));
			dp[i][0] = 1;
			par[i][0] = -1;
		}
		int j, ci = der[i];
		while(ci--) {
			cin >> j;
			adj[j].pb(i);
			rev[i].pb(j);
		}
	}
	cin >> ak;

	bfs();
	if(dp[ak][1]) {
		cout << "Win\n";
		pii nod = mp(ak, 1);
		do {
			cout << nod.f << " ";
			nod = mp(par[nod.f][nod.s], nod.s ^ 1);
		} while(nod.f != -1);
		cout << "\n";
	}
	else if(!dp[ak][0]) {
		cout << "Draw\n";
	}
	else {
		Lop = false;
		dfs(1);
		if(!Lop) {
			cout << "Lose\n";	
		}
		else {
			cout << "Draw\n";
		}
	}
}