#include <bits/stdc++.h>
using namespace std;

long long N, le, ri, mid;

bool solve() {
	long long n = N;
	long long A = 0;
	while(n > 0) {
		A += min(n, mid);
		n = max(n - mid, (long long)0);
		n -= (n / (long long)10);
	}
	return A * (long long)2 >= N;
}

int main(int argc, char** argv) {
	cin >> N;
	le = 1, ri = N;
	while(le < ri) {
		mid = (le + ri) / (long long)2;
		if(solve()) {
			ri = mid;
		}
		else {
			le = mid + 1;
		}
	}
	cout << le << "\n";
}