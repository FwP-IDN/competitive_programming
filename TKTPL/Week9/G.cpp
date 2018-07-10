#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

long long has = 1;
long long mod = 1e9 + 7;
int ar[MAXN + 1];
int N, L;

int main() {
	cin >> N >> L;
	for(int i = 1; i <= L; i++) {
		cin >> ar[i];
		if(ar[i] <= ar[i - 1]) {
			has = 0;
		}
	}
	if(ar[L] != N) {
		cout << "0\n";
	}
	else {
		for(int i = L - 1; i >= 0; i--) {
			for(int j = ar[i] + 1; j <= ar[i + 1] - 1; j++) {
				has *= (long long)(N - j);
				has %= mod;
			}
		}
		cout << has << "\n";
	}
}