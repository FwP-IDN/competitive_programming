#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 300000;

int par[MAXN + 5];
int anak[MAXN + 5];
vector<int> adj[MAXN + 5];
int a, b, val1, val2, n;

void dfsMakePar(int nod, int pt) {
	par[nod] = pt;
	anak[nod] = 1;
	for(int x : adj[nod]) {
		if(x == pt) {
			continue;
		}
		dfsMakePar(x, nod);
		anak[nod] += anak[x];
	}
}

bool dfsBool(int nod, int pt) {
	if(nod == b) {
		return false;
	}
	//is leaf
	if(adj[nod].size() == 1 && pt == adj[nod][0]) {
		return true;
	}
	for(int x : adj[nod]) {
		if(x == pt) {
			continue;
		}
		if(!dfsBool(x, nod)) {
			return false;
		}
	}
	return true;
}

void getVal1() {
	val1 = 1;
	for(int x : adj[a]) {
		// kan dia root
		if(dfsBool(x, a)) {
			val1 += anak[x];
		}
	}
}

void getVal2() {
	val2 = anak[b];
}

int main() {
	cin >> n >> a >> b;
	for(int lop = 0; lop < n - 1; lop++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfsMakePar(a, a);
	getVal1();
	getVal2();
	cout << (long long) n * (n - 1) - (long long)val1 * val2 << "\n";
}