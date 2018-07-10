#include<bits/stdc++.h>
using namespace std;


struct StructTree {
	int N, M;
	static const int MAXN = 300000;

	struct Edge {
		int nexNod;
		int edgeNum;

		Edge(int a, int b) {
			nexNod = a;
			edgeNum = b;
		}
	};

	struct NodeTree {
		int par;
		int edgeNum;
		NodeTree() {
			par = 0;
			edgeNum = 0;
		}
		NodeTree(int a, int b) {
			par = a;
			edgeNum = b;
		}
	} nodTree[MAXN + 5];

	vector<Edge> adj[MAXN + 5], tree[MAXN + 5];
	vector<int> one, minusOne;
	vector<int> ans;
	bool vis[MAXN + 5];
	bool val[MAXN + 5];


	void read() {
		scanf("%d %d", &N, &M);
		int v;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &v);
			if(v == 1) {
				one.push_back(i);
			}
			else if(v == -1) {
				minusOne.push_back(i);
			}
		}
		int a, b;
		for(int i = 1; i <= M; i++) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(Edge(b, i));
			adj[b].push_back(Edge(a, i));
		}
	}

	void dfs_tree(int nod ,int pt) {
		#define dfs dfs_tree
		vis[nod] = 1;
		for(Edge x : adj[nod]) {
			if(!vis[x.nexNod]) {
				vis[x.nexNod] = 1;
				nodTree[x.nexNod] = NodeTree(nod, x.edgeNum);
				tree[nod].push_back(x);
				dfs(x.nexNod, nod);
			}
		}
		#undef dfs
	}

	void make_tree() {
		dfs_tree(1, -1);
	}

	void dfs_dp(int nod) {
		for(Edge x : tree[nod]) {
			dfs_dp(x.nexNod);
			val[nod] ^= val[x.nexNod];
		}
	}

	void solve_all() {
		if(((int)one.size() & 1) && minusOne.empty()) {
			printf("-1\n");
		}
		else {
			for(int x : one) {
				val[x] = 1;
			}
			if(one.size() & 1) {
				val[minusOne[0]] = 1;
			}
			dfs_dp(1);
			for(int i = 2; i <= N; i++) {
				if(val[i]) {
					ans.push_back(nodTree[i].edgeNum);
				}
			}
			printf("%d\n", (int)ans.size());
			for(int x : ans) {
				printf("%d ", x);
			}
			if(ans.size()) printf("\n");
		}
	}
} T;

int main() {
	T.read();
	T.make_tree();
	T.solve_all();
}