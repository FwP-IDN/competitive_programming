#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int maxn = 200;

int N, M, has = 0;
vector<int> act; // active node
bool vis[maxn + 5];
int cost[maxn + 5][maxn + 5];
int dp[1 << 22];

int getAns(int bit) {
	int &ret = dp[bit];
	if(ret >= 0) {
		return ret;
	}
	if(bit == 0) {
		return 0;
	}
	ret = INT_MAX;
	int fbit = 0;
	for(; !((1 << fbit) & bit); fbit++) {

	}
	for(int pp = fbit + 1; pp < (int)act.size(); pp++) {
		if((1 << pp) & bit) {
			int a = act[fbit];
			int b = act[pp];
			ret = min(ret, cost[a][b] + getAns(bit ^ (1 << fbit) ^ (1 << pp)));
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cost[i][j] = INT_MAX;
		}
	}
	while(M--) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = c;
		cost[b][a] = c;
 	}
 	for(int i = 1; i <= N; i++) {
 		if(vis[i]) {
 			continue;
 		}
 		act.clear();
 		vis[i] = 1;
 		act.pb(i);
 		for(int j = i + 1; j <= N; j++) {
 			if(cost[i][j] != INT_MAX) {
 				vis[j] = 1;
 				act.pb(j);
 			}
 		}
 		if(act.size() & 1) {
 			cout << "impossible\n";
 			return 0;
 		}
 		for(int j = 0; j < (1 << act.size()); j++) {
 			dp[j] = -1;
 		}
 		has += getAns((1 << act.size()) - 1);
 	}
 	cout << has << "\n";
}
