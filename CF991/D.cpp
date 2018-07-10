#include <bits/stdc++.h>
using namespace std;

string str[2];
vector<int> state, dp[3];

int solve(int mask, int idx) {
	if(idx >= (int)str[0].length() - 1) {
		return 0;
	}
	int &ret = dp[mask][idx];
	if(ret >= 0) {
		return ret;
	}
	ret = solve(state[idx + 1], idx + 1);
	if(mask >= 1 && state[idx + 1] == 2) {
		ret = max(ret, 1 + solve(0, idx + 1));
	}
	if(mask == 2 && state[idx + 1] >= 1) {
		ret = max(ret, 1 + solve(state[idx + 1] - 1, idx + 1));
	}
	return ret;
}

int main(int argc, char** argv) {
	cin >> str[0] >> str[1];
	state.resize(str[0].length() + 1);
	for(int i = 0; i < 3; i++) 
		dp[i].resize(str[0].length(), -1);
	for(int i = 0; i < (int)str[0].length(); i++) {
		if(str[0][i] == '0') {
			++state[i];
		}
		if(str[1][i] == '0') {
			++state[i];
		}
	}
	cout << solve(state[0], 0) << "\n";
}