#include <bits/stdc++.h>
using namespace std;

vector<int> ar1, ar2;
int cas = 0;

void split_sort(vector<int> &v) {
	vector<int> vL(((int)v.size() + 1) / 2), vR((int)v.size() / 2);
	for(int i = 0; i < (int)v.size(); i += 2) {
		vL[i / 2] = v[i];
	}
	for(int i = 1; i < (int)v.size(); i += 2) {
		vR[i / 2] = v[i];
	}

	sort(vL.begin(), vL.end());
	sort(vR.begin(), vR.end());

	for(int i = 0; i < (int)v.size(); i += 2) {
		v[i] = vL[i / 2];
	}
	for(int i = 1; i < (int)v.size(); i += 2) {
		v[i] = vR[i / 2];
	}
}

void solve() {
	int N;
	cin >> N;
	ar1.resize(N);
	ar2.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> ar1[i];
		ar2[i] = ar1[i];
	}
	sort(ar1.begin(), ar1.end());
	split_sort(ar2);
	for(int i = 0; i < N; i++) {
		if(ar1[i] != ar2[i]) {
			cout << "Case #" << ++cas << ": " << i << "\n";
			return;
		}
	}
	cout << "Case #" << ++cas << ": OK\n";
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		solve();
	}
}