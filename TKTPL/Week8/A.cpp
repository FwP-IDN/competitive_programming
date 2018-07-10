#include <bits/stdc++.h>
using namespace std;

int ans;
int sr[1001];
int ar[1001];
int llogg[10001];
int N;

void dfs(int nod, int idx) {
	sr[idx] = nod;
	if(idx + llogg[N / nod] > ans) {
		return;
	}
	if(nod == N) {
		for(int i = 1; i <= idx; i++) {
			ar[i] = sr[i];
		}
		ans = idx;
		return;
	}
	if(idx == ans - 1 && nod != N) {
		return;
	}
	for(int i = idx; i>= 0; i--) {
		if(nod + sr[i] > N) {
			continue;
		}
		dfs(nod + sr[i], idx + 1);
	}
	return;
}

void precomp() {
	llogg[1] = 0;
	for(int i = 1; i <= 10000; i++) {
		if((i - 1) == ((i - 1) & (1 - i))) {
			llogg[i] = llogg[i - 1] + 1;
		}
		else {
			llogg[i] = llogg[i - 1];
		}
	}
}

int main() {
	precomp();
	ar[0] = 1;
	sr[0] = 1;
	while(cin >> N && N) {
		ans = N * 2;
		if(N == 1) {
			cout << "1\n";
		}
		else if(N == 2) {
			cout << "1 2\n";
		}
		else {
			dfs(2, 1);
			for(int i = 0; i < ans; i++) {
				cout << ar[i] << " ";
			}
			cout << ar[ans] << "\n";
		}
	}
}