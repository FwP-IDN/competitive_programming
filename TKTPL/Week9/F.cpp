#include<bits/stdc++.h>
using namespace std;

struct StructSegTree {
	set<int> sen;
	void read() {
		cin >> N;
		for(int i = 1; i <= N; i++) {
			cin >> ar[i];
		}
	}

	void compress() {
		for(int i = 1; i <= N; i++) {
			sen.insert(ar[i]);
		}
		for(int x : sen) {
			vev.push_bacK(x);
		}
		for(int i = 1; i <= N; i++) {
			ar[i] = lower_bound(vev.begin(), vev.end(), ar[i]) - vev.begin() + 1;
		}
	}
} S;

int main() {
	S.read();
	S.compress();	
}