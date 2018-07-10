#include <bits/stdc++.h>
using namespace std;

char ar[4][99];

int main() {
	int N, K;
	memset(ar, '.', sizeof(ar));
	cin >> N >> K;
	if(K & 1) {
		ar[1][N / 2] = '#';
		K--;
		for(int i = 1; i < N / 2 && K > 0; i++) {
			K -= 2;
			ar[1][i] = ar[1][N - 1 - i] = '#';
		}
		for(int i = 1; i < N / 2 && K > 0; i++) {
			K -= 2;
			ar[2][i] = ar[2][N - 1 - i] = '#';
		}
	}
	else {
		for(int i = 1; i <= K / 2; i++) {
			ar[1][i] = ar[2][i] = '#';
		}
	}
	cout << "YES\n";
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < N; j++) {
			cout << ar[i][j];
		}
		cout << "\n";
	}
}
