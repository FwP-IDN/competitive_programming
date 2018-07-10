#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int cnt[10];
int scnt[10];

map<vector<int>, long long> dp;
vector<int> vekos(10, 0);

int standar(const vector<int>& inp) {
	for(int i = 0; i < 10; i++) {
		if(scnt[i] > 0 && inp[i] == scnt[i]) {
			return 0;
		}
	}
	return 1;
}

long long solve(vector<int> state) {
	if(dp.count(state)) {
		return dp[state];
	}
	dp[state] = 0;
	map<vector<int>, long long>::iterator it = dp.lower_bound(state);
	it -> s = standar(state);
	// int prev = it -> s;
	vector<int> nex = state;
	for(int i = 0; i < 10; i++) {
		if(nex[i] == 0) {
			continue;
		}
		nex[i]--;
		it -> s += solve(nex);
		nex[i]++;
	}
	// cout << prev << " --> ";
	// for(int x : state) {
	// 	cout << x << " ";
	// } cout << " ==> " << it -> s << "\n";
	return it -> s;
}

long long solve_all(int* ar) {
	vector<int> v(ar, ar + 10);
	return solve(v);
}

int main(int argc, char** argv) {
	dp[vekos] = 1;
	string str;
	cin >> str;
	for(char c : str) {
		cnt[c - '0']++;
	}
	for(int i = 0; i < 10; i++) {
		scnt[i] = cnt[i];
	}
	long long has = 0;
	for(int i = 1; i < 10; i++) {
		if(cnt[i] == 0) {
			continue;
		}
		cnt[i]--;
		has += solve_all(cnt);
		cnt[i]++;
	}
	cout << has << "\n";
}