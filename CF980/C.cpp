#include <bits/stdc++.h>
using namespace std;

int ar[100000];
int code[256];

int main() {
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> ar[i];
	}
	memset(code, -1, sizeof(code));
	for(int i = 0; i < N; i++) {
		if(code[ar[i]] != -1) {
			continue;
		}
		int kiri = max(0, ar[i] - K + 1);
		if(code[kiri] != -1) {
			while(code[kiri] != -1 && code[kiri] + K - 1 < ar[i]) {
				kiri++;
			}
			if(code[kiri] != -1) {
				kiri = code[kiri];
			}
		}
		for(int j = kiri; j <= ar[i]; j++) {
			code[j] = kiri;
		}
	}
	for(int i = 0; i < N; i++) {
		cout << code[ar[i]] << " ";
	}
	cout << "\n";
}