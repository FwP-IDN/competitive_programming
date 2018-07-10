#include<bits/stdc++.h>
using namespace std;


#define ll long long
const int maxn = 1000;

struct Matrix {
	int elem[maxn][maxn];
};

struct Vector {
	ll elem[maxn];
};

struct LinearAlg {
	int sz;
	Matrix A, B;
	Vector v0, v1, v2, v3;
	static const ll mod = 1000000007;
	static ll getRand() {
		return ((ll)RAND_MAX * rand() + rand() ) % mod;
	}

	void mul(Matrix& M, Vector& V, Vector& res) {
		for(int i = 0; i < sz; i++) {
			res.elem[i] = 0;
			for(int k = 0; k < sz; k++) {
				res.elem[i] += (ll)M.elem[i][k] * V.elem[k];
			}
		}
	}

	bool same(Vector& A, Vector &B) {
		for(int k = 0; k < sz; k++) {
			if(A.elem[k] != B.elem[k]) {
				return false;
			}
		}
		return true;
	}

	void print(Vector& V) {
		for(int k = 0; k < sz; k++) {
			cout << V.elem[k] << " ";
		}
		cout << "\n";
	}
} S;



int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(true) {
		cin >> S.sz;
		if(S.sz == 0) {
			return 0;
		}
		for(int i = 0; i < S.sz; i++) {
			for(int j = 0; j < S.sz; j++) {
				cin >> S.A.elem[i][j];
			}
		}
		for(int i = 0; i < S.sz; i++) {
			for(int j = 0; j < S.sz; j++) {
				cin >> S.B.elem[i][j];
			}
		}
		for(int k = 0; k < S.sz; k++) {
			S.v0.elem[k] = S.getRand();
		}
		S.mul(S.A, S.v0, S.v1);
		S.mul(S.A, S.v1, S.v2);
		S.mul(S.B, S.v0, S.v3);
		// S.print(S.v0);
		// S.print(S.v1);
		// S.print(S.v2);
		// S.print(S.v3);
		if(S.same(S.v2, S.v3)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}