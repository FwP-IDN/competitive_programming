#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000;

#define pb push_back
#define pii pair<int, int>
#define f first
#define s second

struct Tik {
	int nn;
	int cc;
	int rr;
};

vector<Tik> adj[maxn + 5];
int n, aw, ak, maxp, maxt;
int vis[maxn + 5], cap[maxn + 5];
pii par[maxn + 5];

//==============================

void init() {
	for(int nod = 0; nod <= ak; nod++) {
		adj[nod].clear();
		vis[nod] = 0;
	}
}

int enc(int x, int y) {
	return x * (maxt + 1) + y;
}

void addEdge(int a, int b, int c) {
	// cout << a << " - " << b << " ;; " << c << "  \
	//    " << a / (maxt + 1) << " -- " << b / (maxt + 1) << "\n";
	int szA = adj[a].size();
	int szB = adj[b].size();
	Tik x;
	x = {b, c, szB}; adj[a].pb(x);
	x = {a, 0, szA}; adj[b].pb(x);
	return;
}

void make_delay() {
	for(int i = 0; i < n; i++) {
		for(int tim = 0; tim < maxt; tim++) {
			addEdge(enc(i, tim), enc(i, tim + 1), maxp);
		}
	}
}

void make_medic() {
	int m, x;
	cin >> m;
	while(m--) {
		cin >> x;
		x--;
		for(int tim = 0; tim <= maxt; tim++) {
			addEdge(enc(x, tim), enc(n, 0), maxp);
		}
	}
}

void make_road() {
	int m, a, b, pp, tt;
	cin >> m;
	while(m--) {
		cin >> a >> b >> pp >> tt;
		a--; b--;
		for(int tim = 0; tim + tt <= maxt; tim++) {
			addEdge(enc(a, tim), enc(b, tim + tt), pp);
		}
	}
}


int bfs(int cnt) {
	queue<int> qq;
	qq.push(aw);
	vis[aw] = cnt;
	cap[aw] = 1000;
	while(!qq.empty()) {
		int dep = qq.front(); qq.pop();
		if(dep == ak) {
			stack<int> path;
			int a = par[ak].f;
			int b = ak;
			int ia = par[ak].s;
			int ib = adj[a][ia].rr;
			path.push(b);
			do {
				adj[a][ia].cc -= cap[ak];
				adj[b][ib].cc += cap[ak];
				a = par[a].f;
				b = par[b].f;
				ia = par[b].s;
				ib = adj[a][ia].rr;
				path.push(b);
			} while(b != aw);
			cout << "dengan anggaran  " << cap[ak] << " === ";
			while(!path.empty()) {
				cout << "- " << path.top(); path.pop();
			}
			cout << "\n";
			return cap[ak];
		}
		int cix = -1;
		for(Tik x : adj[dep]) {
			cix++;
			if(vis[x.nn] == cnt || x.cc == 0) {
				continue;
			}
			vis[x.nn] = cnt;
			cap[x.nn] = min(cap[dep], x.cc);
			par[x.nn] = {dep, cix};
			qq.push(x.nn);
		}
	}
	return 0;
}

int maxflow() {
	int ret = 0;
	int cnt = 0;
	int tam;
	do {
		tam = bfs(++cnt);
		ret += tam;
	} while(tam > 0 && ret < maxp);
	return ret;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tes, ss;
	cin >> tes;
	while(tes--) {
		cin >> n >> ss >> maxp >> maxt;
		ss--;
		aw = ss * (maxt + 1);
		ak = n * (maxt + 1);
		init();
		make_delay();
		make_medic();
		make_road();
		cout << min(maxflow(), maxp) << "\n";
	}
}