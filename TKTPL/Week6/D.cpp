#include<bits/stdc++.h>
using namespace std;

struct StructTree {
	static const int MAXN = 1000000;
	static const int MAXV = 10000000;
	int N, rot;
	int val[MAXN + 1];
	int par[MAXN + 1];
	bool isPrime[MAXV + 1];
	vector<int> fact[MAXV + 1];
	int occ[MAXV + 1];
	int kiri[MAXN + 1], kanan[MAXN + 1];

	struct Node {
		int le;
		int ri;
	} nod[MAXN + 5];

	void read() {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", val + i);
		}
	}
	bool isValid() {
		if(rot == -1) {
			return false;
		}
		for(int i = 1; i <= N; i++) {
			if(nod[i].le == -1 || nod[i].ri == -1) {
				return false;
			}
			else {
				par[nod[i].le] = i;
				par[nod[i].ri] = i;
			}
		}
		return true;
	}

	void generate_factor() {
		// faktor yang diitung cuma yang kurang dari sqrt(10 ^ 7)
		fill(isPrime + 2, isPrime + MAXV + 1, 1);
		int sqn = 3162;
		for(int i = 2; i <= sqn; i++) {
			if(!isPrime[i]) {
				continue;
			}
			for(int j = i * i; j <= MAXV; j += i) {
				isPrime[j] = 0;
				fact[j].push_back(i);
			}
		}
	}

	void generate_span() {
		// span kiri
		fill(occ, occ + MAXV + 1, 0);
		for(int i = 1; i <= N; i++) {
			kiri[i] = 1;
			int num = val[i];
			for(int x : fact[val[i]]) {
				kiri[i] = max(kiri[i], occ[x] + 1);
				occ[x] = i;
				while(!(num % x)) {
					num /= x;
				}
			}
			if(num > 1) {
				kiri[i] = max(kiri[i], occ[num] + 1);
				occ[num] = i;
			}
		}

		// span kanan
		fill(occ, occ + MAXV + 1, N + 1);
		for(int i = N; i >= 1; i--) {
			kanan[i] = N;
			int num = val[i];
			for(int x : fact[val[i]]) {
				kanan[i] = min(kanan[i], occ[x] - 1);
				occ[x] = i;
				while(!(num % x)) {
					num /= x;
				}
			}
			if(num > 1) {
				kanan[i] = min(kanan[i], occ[num] - 1);
				occ[num] = i;
			}
		}
	}


	int solve(int L, int R) {
		if(L > R) {
			return 0;
		}
		for(int i = 0; i <= (R - L) / 2; i++) {
			if(kiri[L + i] <= L && kanan[L + i] >= R) {
				nod[L + i].le = solve(L, L + i - 1);
				nod[L + i].ri = solve(L + i + 1, R);
				return L + i;
			}

			if(kiri[R - i] <= L && kanan[R - i] >= R) {
				nod[R - i].le = solve(L, R - i - 1);
				nod[R - i].ri = solve(R - i + 1, R);
				return R - i;
			}
		}
		return -1;
	}

	void solve_all() {
		rot = solve(1, N);
	}

	void print() {
		if(!isValid()) {
			printf("impossible\n");
		}
		else {
			printf("%d", par[1]);
			for(int i = 2; i <= N; i++) {
				printf(" %d", par[i]);
			}
			printf("\n");
		}
	// 	for(int i = 1; i <= N; i++) {
	// 		cout << kiri[i] << " ";
	// 	}
	// 	cout << "\n";
	// 	for(int i = 1; i <= N; i++) {
	// 		cout << kanan[i] << " ";
	// 	}
	// 	cout << "\n";
	}
} T;

int main() {
	T.read();
	T.generate_factor();
	T.generate_span();
	T.solve_all();
	T.print();
}