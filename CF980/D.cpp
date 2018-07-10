#include <bits/stdc++.h>
using namespace std;

int ar[5000];
int par[5000];
int ans[5000];
int N;
int cnt[5000];

bool isQua(long long mas) {
	if(mas < 0) {
		return false;
	}
	long long sq = sqrt(mas);
	if(sq * sq == mas) {
		return true;
	}
	if((sq - 1) * (sq - 1) == mas) {
		return true;
	}
	if((sq + 1) * (sq + 1) == mas) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> ar[i];
		par[i] = i;
	}
	for(int i = 0; i < N; i++) {
		if(par[i] != i) {
			continue;
		}
		for(int j = i + 1; j < N; j++) {
			if(isQua((long long)ar[i] * ar[j])) {
				par[j] = par[i];
			}
		}
	}
	int temp;
	for(int i = 0; i < N; i++) {
		temp = 0;
		for(int j = i; j < N; j++) {
			if(!cnt[par[j]]) {
				temp++;
			}
			cnt[par[j]]++;
			ans[temp - 1]++;
		}
		for(int j = i; j < N; j++) {
			cnt[par[j]] = 0;
		}
	}
	for(int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}