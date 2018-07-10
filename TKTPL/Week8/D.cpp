#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
	return a == 0 ? b : GCD(b % a, a);
}

int LCM(int a, int b) {
	return a / GCD(a, b) * b;
}

int main() {
	int N, K;
	int L = 1;
	scanf("%d %d", &N, &K);
	int A;
	for(int i = 0; i < N; i++) {
		scanf("%d", &A);
		L = LCM(L, GCD(K, A));
	}
	if(K == L) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}
