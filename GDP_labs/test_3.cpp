#include<bits/stdc++.h>
using namespace std;


string str_ar;
pair<int, int> ar[1005][1005], dp[1005][1005];
pair<pair<int, int>, int> maxx, minn;
int N, M;

int toInt(string str) {
	int ret = 0;
	for(char x : str) {
		ret = ret * 10 + x - '0';
	}
	return ret;
}

void find_max() {
		for(int j = 1; j <= M; j++) {
			dp[N][j] = ar[N][j];
		}
	for(int i = N - 1; i >= 1; i--) {
		for(int j = 1; j <= N; j++) {
			if(!ar[i][j].second) {
				dp[i][j] = dp[i + 1][j];
			}
			else {
				if(j == 1) {
					dp[i][j] = make_pair(dp[i + 1][j + 1].first + ar[i][j].first, dp[i + 1][j + 1].second + ar[i][j].second);
				}
				else if(j == M) {
					dp[i][j] = make_pair(dp[i + 1][j - 1].first + ar[i][j].first, dp[i + 1][j - 1].second + ar[i][j].second);
				}
				else {
					dp[i][j] = max(make_pair(dp[i + 1][j + 1].first + ar[i][j].first, dp[i + 1][j + 1].second + ar[i][j].second),
						make_pair(dp[i + 1][j - 1].first + ar[i][j].first, dp[i + 1][j - 1].second + ar[i][j].second));
				}
			}
		}
	}
}

void find_min() {
		for(int j = 1; j <= M; j++) {
			dp[N][j] = ar[N][j];
		}
	for(int i = N - 1; i >= 1; i--) {
		for(int j = 1; j <= N; j++) {
			if(!ar[i][j].second) {
				dp[i][j] = dp[i + 1][j];
			}
			else {
				if(j == 1) {
					dp[i][j] = make_pair(dp[i + 1][j + 1].first + ar[i][j].first, dp[i + 1][j + 1].second + ar[i][j].second);
				}
				else if(j == M) {
					dp[i][j] = make_pair(dp[i + 1][j - 1].first + ar[i][j].first, dp[i + 1][j - 1].second + ar[i][j].second);
				}
				else {
					dp[i][j] = min(make_pair(dp[i + 1][j + 1].first + ar[i][j].first, dp[i + 1][j + 1].second + ar[i][j].second),
						make_pair(dp[i + 1][j - 1].first + ar[i][j].first, dp[i + 1][j - 1].second + ar[i][j].second));
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> str_ar;
			if(str_ar == ".") {
				ar[i][j] = make_pair(0, 0);
			}
			else {
				ar[i][j] = make_pair(toInt(str_ar), 1);
			}
		}
	}
	find_max();
	maxx = {{-1000000000, 0}, 0};
	for(int j = 1; j <= M; j++) {
		maxx = max(maxx, make_pair(dp[1][j], j));
	}
	cout << maxx.second << " " << maxx.first.first << " " << maxx.first.second << "\n";

	find_min();
	minn = {{1000000000, 0}, 0};
	for(int j = 1; j <= M; j++) {
		minn = min(minn, make_pair(dp[1][j], j));
	}
	cout << minn.second << " " << minn.first.first << " " << minn.first.second << "\n";
}