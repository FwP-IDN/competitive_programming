#include<bits/stdc++.h>
using namespace std;

#define maxn 10000
#define pb push_back

int N, M, aw, ak;

struct Tik {
	int nod;
	int liv;
	int rev;
};
vector<Tik> adj[maxn + 5];
int par[maxn + 5], nodnum[maxn + 5];


Tik setTik(int a, int b, int c) {
	Tik ret;
	ret.nod = a;
	ret.liv = b;
	ret.rev = c;
	return ret;
}

void init() {
	for(int i = 1; i <= N; i++) {
		adj[i].clear();
	}
}

void bfs(int count) {
	queue<int> qq;
	for(int i = 1; i <= N; i++) {
		par[i] = -1;
		nodnum[i] = -1;
	}
	par[aw] = 0;
	qq.push(aw);
	while(!qq.empty()) {
		int dep = qq.front(); qq.pop();
		int idx = -1;
		for(Tik x : adj[dep]) {
			idx++;
			if(!x.liv || par[x.nod] != -1) {
				continue;
			}
			qq.push(x.nod);
			par[x.nod] = dep;
			nodnum[x.nod] = idx;
		}
	}
	int now = ak;
	while(par[now] > 0) {
		int a = par[now];
		int b = now;
		int ia = nodnum[now];
		int ib = adj[a][ia].rev;
		adj[a][ia].liv--;
		adj[b][ib].liv++;
		// cout << a << b << adj[b][ib].nod << adj[a][ia].nod << "\n";
		now = par[now];
	}
	return;
}

int main() {
	int cas = 0;
	while(true) {
		scanf("%d %d", &N, &M);
		if(!(N | M)) {
			return 0;
		}
		init();
		while(M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			int szA = adj[a].size();
			int szB = adj[b].size();
			adj[a].pb(setTik(b, 1, szB));
			adj[b].pb(setTik(a, 1, szA));
		}
		scanf("%d %d", &aw, &ak);
		bfs(1);
		bfs(2);
		char res[3];
		if(par[ak] != -1) {
			strcpy(res, "YES");
		}
		else {
			strcpy(res, "NO");
		}
		printf("Case %d: %s\n", ++cas, res);
	}
}