#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 5000;

int ar[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5];

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N, Q;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> ar[i][i];
		dp[i][i] = ar[i][i];
	}
	for(int j = 1; j <= N - 1; j++) {
		for(int i = 1; i + j <= N; i++) {
			ar[i][i + j] = ar[i][i + j - 1] ^ ar[i + 1][i + j];
			dp[i][i + j] = max(ar[i][i + j], max(dp[i][i + j - 1], dp[i + 1][i + j]));
		}
	}
	cin >> Q;
	while(Q--) {
		int aw, ak;
		cin >> aw >> ak;
		cout << dp[aw][ak] << "\n";
	}
}