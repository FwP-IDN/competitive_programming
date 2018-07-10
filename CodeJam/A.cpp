#include <bits/stdc++.h>
using namespace std;

int cas = 0;
vector<char> Vc;
string inp;

void solve() {
	int val;
	cin >> val;
	cin >> inp;
	Vc.clear();
	for(int i = 0; i < (int)inp.length(); i++) {
		Vc.push_back(inp[i]);
	}
	int cnt = 0;
	for(char x : Vc) {
		if(x == 'C') {
			cnt++;
		}
		else if(x == 'S') {
			val -= (1 << cnt);
		}
	}
	int ans = 0;
	while(val < 0 && cnt > 0) {
		while(Vc.back() == 'C') {
			Vc.pop_back();
			cnt--;
		}
		if(cnt == 0) {
			break;
		}
		int idx = Vc.size() - 1;
		while(Vc[idx] == 'S') {
			idx--;
		}
		while(val < 0 && idx < (int)Vc.size() - 1) {
			swap(Vc[idx], Vc[idx + 1]);
			val += (1 << (cnt - 1));
			idx++;
			ans++;
		}
	}
	// for(char x : Vc) {
	// 	cout << x;
	// }
	// cout << "::\n";
	if(val >= 0 ) {
		cout << "Case #" << ++cas <<": " << ans << "\n";
	}
	else {
		cout << "Case #" << ++cas <<": " << "IMPOSSIBLE" << "\n";
	}
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		solve();
	}
}