#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N;
	cin >> N;
	N++;
	if(N == 1) {
		N = 0;
		cout << N << "\n";
		return 0;
	}
	if(!(N % (long long)2)) {
		N /= 2;
	}
	cout << N << "\n";
}