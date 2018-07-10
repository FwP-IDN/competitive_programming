#include<bits/stdc++.h>
using namespace std;

#define ll long long


struct StructST {
	#define tole(x) x << 1
	#define tori(x) (x << 1) | 1
	static const int maxn = 100000;
	int N;

	struct StructPecahan {
		ll A;
		ll B;

		bool operator ==(StructPecahan other) {
			return A == other.A && B == other.B;
		}
	} ar[maxn + 5], zer;

	vector<StructPecahan> tree[520005], sumTree[520005]; // sum Tree nyimpen prefix sum dari tree 

	void init() {
		zer.A = 0;
		zer.B = 0;
	}

	void merge(vector<StructPecahan> &kiri, vector<StructPecahan> &kanan, vector<StructPecahan> &atas) {
		if(atas.empty()) {
			atas.push_back(zer);
		}
		int iki = 1;
		int ika = 1;
		while(iki < (int)kiri.size() && ika < (int)kanan.size()) {
			if((ll)kiri[iki].A * kanan[ika].B > (ll)kanan[ika].A * kiri[iki].B || kiri[iki] == zer) {
				atas.push_back(kiri[iki]);
				iki++;
			}
			else {
				atas.push_back(kanan[ika]);
				ika++;
			}
		}
		while(iki < (int)kiri.size()) {
			atas.push_back(kiri[iki]);
			iki++;
		}
		while(ika < (int)kanan.size()) {
			atas.push_back(kanan[ika]);
			ika++;
		}
	}

	void read() {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &ar[i].A);
		}
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &ar[i].B);
		}
	}

	void buildTree(int nod, int kiri, int kanan) {
		if(kiri == kanan) {
			tree[nod].push_back(zer);
			tree[nod].push_back(ar[kiri]);
			sumTree[nod].push_back(zer);
			sumTree[nod].push_back(ar[kiri]);
			return;
		}
		int ten = (kiri + kanan) / 2;
		buildTree(tole(nod), kiri, ten);
		buildTree(tori(nod), ten + 1, kanan);
		merge(tree[tole(nod)], tree[tori(nod)], tree[nod]);
		sumTree[nod].resize((int)tree[nod].size());
		for(int i = 1; i < (int)sumTree[nod].size(); i++) {
			sumTree[nod][i].A = sumTree[nod][i - 1].A + tree[nod][i].A;
			sumTree[nod][i].B = sumTree[nod][i - 1].B + tree[nod][i].B;
		}
	}

	void build_ST() {
		buildTree(1, 1, N);
	}

	int getIdx(vector<StructPecahan> &V, int C, int D) {
		int le = 0, ri = (int)V.size() - 1;
		while(le < ri) {
			int mid = (le + ri + 1) / 2;
			if(V[mid].A * C >= V[mid].B * D) {
				le = mid;
			}
			else {
				ri = mid - 1;
			}
		}
		return le;
	}

	ll find_ans(int nod, int kiri, int kanan, int aw, int ak, int C, int D) {
		// cout << nod << " " << kiri << " " << kanan << " " << aw << " " << ak << "\n";
		if(aw > kanan || kiri > ak) {
			return 0;
		}
		if(aw <= kiri && kanan <= ak) {
			int idx = getIdx(tree[nod], C, D);
			// cout << idx << " idx\n";
			return sumTree[nod][idx].A * C - sumTree[nod][idx].B * D;
		}
		int ten = (kiri + kanan) >> 1;
		return find_ans(tole(nod), kiri, ten, aw, ak, C, D) +
		find_ans(tori(nod), ten + 1, kanan, aw, ak, C, D);
	}

	void queries() {
		int Q, L, R, C, D;
		scanf("%d", &Q);
		while(Q--) {
			scanf("%d %d %d %d", &L, &R, &C, &D);
			printf("%lld\n", find_ans(1, 1, N, L, R, C, D));
			fflush(stdout);
		}
	}

	void walk(int nod, int kiri, int kanan) {
		for(StructPecahan x : tree[nod]) {
			printf("(%lld, %lld)", x.A, x.B);
		}
		cout << "\n ============ \n";
		if(kiri < kanan) {
			int ten = (kiri + kanan) / 2;
			walk(tole(nod), kiri, ten);
			walk(tori(nod), ten + 1, kanan);
		}
	}

} S;

int main() {
	S.init();
	S.read();
	S.build_ST();
	S.queries();
	// S.walk(1, 1, S.N);
}
