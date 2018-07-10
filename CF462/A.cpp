#include<bits/stdc++.h>
using namespace std;

#define maxn 2000

int ar[maxn + 5];
int dpfront[maxn + 5][4];
int dpback[maxn + 5][4];

int dprev[maxn + 5][maxn + 5][4];

int main() {
	int n, has = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for(int i = 1; i <= n; i++) {
		dpfront[i][ar[i] - 1] = dpfront[i - 1][ar[i] - 1];
		dpfront[i][ar[i]] = max(dpfront[i - 1][ar[i]], dpfront[i - 1][ar[i] - 1]) + 1;
		dpfront[i][ar[i] + 1] = dpfront[i - 1][ar[i] + 1];
	}
	for(int i = n; i >= 1; i--) {
		dpback[i][ar[i] - 1] = dpback[i + 1][ar[i] - 1];
		dpback[i][ar[i]] = max(dpback[i + 1][ar[i]], dpback[i + 1][ar[i] + 1]) + 1;
		dpback[i][ar[i] + 1] = dpback[i + 1][ar[i] + 1];
	}
	has = max(dpfront[n][1], dpfront[n][2]);
	for(int aw = 1; aw <= n; aw++) {
		for(int ak = aw; ak <= n; ak++) {
			int i = ak;
			dprev[aw][i][ar[i] - 1] = dprev[aw][i - 1][ar[i] - 1];
			dprev[aw][i][ar[i]] = max(dprev[aw][i - 1][ar[i]], dprev[aw][i - 1][ar[i] + 1]) + 1;
			dprev[aw][i][ar[i] + 1] = dprev[aw][i - 1][ar[i] + 1];
			// if(aw == 2 && ak == 3) {
			// 	cout << dp[aw - 1][1] << " " << dprev[aw][ak][2] << " "
			// }
			has = max(has, dpfront[aw - 1][1] + dprev[aw][ak][1] + dpback[ak + 1][2]);
		}
	}
	cout << has << "\n";
}