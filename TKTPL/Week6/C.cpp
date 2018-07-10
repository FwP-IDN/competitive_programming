#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct StructKD {
	static const long long INF = (long long) 3123456789012345678;
	static const int X_sep = 0;
	static const int Y_sep = 1;
	static const int maxn = 100000;
	pair<int, int> ar[maxn + 5], inp[maxn + 5];
	long long ans;
	int N;
	
	struct Node {
		Node *le;
		Node *ri;
		pair<int, int> p;
		int sep;
	}; Node *root;

	void read() {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d %d", &ar[i].f, &ar[i].s);
			inp[i] = ar[i];
		}
	}

	static bool cmp(pair<int, int> aw, pair<int, int> ak) {
		if(aw.s < ak.s) {
			return true;
		}
		if(aw.s > ak.s) {
			return false;
		}
		return aw.f < ak.f;
	}

	Node* bangun(int L, int R, int _sep) {
		if(L > R) {
			return NULL;
		}
		if(_sep) {
			sort(ar + L, ar + R + 1, cmp);
		}
		else {
			sort(ar + L, ar + R + 1);
		}
		int mid = (L + R) / 2;
		Node* nod = new Node;
		nod -> p = ar[mid];
		nod -> sep = _sep;
		nod -> le = bangun(L, mid - 1, _sep ^ 1);
		nod -> ri = bangun(mid + 1, R, _sep ^ 1);
		return nod;
	}

	void construct() {
		root = bangun(1, N, X_sep);
	}

	long long calc_cost(pair<int, int> A, pair<int, int> B) {
		return (long long)(A.f - B.f) * (A.f - B.f) +
		(long long)(A.s - B.s) * (A.s - B.s);
	}

	bool isInLimit(Node *nod, pair<int, int> q) {
		if(nod -> sep) {
			return nod -> p.s == q.s;
		}
		else {
			return nod -> p.f == q.f;
		}
	}

	void solve(Node* nod, long long &ans, pair<int, int> q) {
		if(nod == NULL) {
			return;
		}
		long long cost = calc_cost(nod -> p, q);
		if(cost) {
			ans = min(ans, cost);
		}
		if(q == nod -> p) {
			solve(nod -> le, ans, q);
			solve(nod -> ri, ans, q);
			return;
		}
		int pp, qq;
		if(nod -> sep) {
			pp = nod -> p.s;
			qq = q.s;
		}
		else {
			pp = nod -> p.f;
			qq = q.f;
		}
		if(qq < pp || (qq == pp && q < nod -> p)) {
			// ke kiri
			solve(nod -> le, ans, q);
			// printf("(%d, %d) %lld\n", nod -> p.f, nod -> p.s, ans);
			if(ans > (long long)pp - qq) {
				solve(nod -> ri, ans, q);
			}
		}
		if(qq > pp || (qq == pp && q > nod -> p)) {
			// ke kanan
			solve(nod -> ri, ans , q);
			// printf("(%d, %d) %lld\n", nod -> p.f, nod -> p.s, ans);
			if(ans > (long long)qq - pp) {
				solve(nod -> le, ans , q);
			}
		}
	}

	void solve_all() {
		for(int i = 1; i <= N; i++) {
			ans = INF;
			solve(root, ans, inp[i]);
			printf("%lld\n", ans);
		}
	}

	void print(Node *nod) {
		if(nod == NULL) {
			printf("NULL");
		}
		else {
			printf("(%d, %d)", nod -> p.f, nod -> p.s);
		}
	}

	void print_now(Node* nod) {
		print(nod -> le);
		printf(" <<-- ");
		print(nod);
		printf(" -->> ");
		print(nod -> ri);
		printf("\n");
	}

	void walk(Node *nod) {
		if(nod == NULL) {
			return;
		}
		print_now(nod);
		walk(nod -> le);
		walk(nod -> ri);
	}

} K;


int main() {
	int tes;
	scanf("%d", &tes);
	while(tes--) {
		K.read();
		K.construct();
		K.solve_all();
		// K.walk(K.root);
	}
}