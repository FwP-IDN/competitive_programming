#include<bits/stdc++.h>
using namespace std;


int N, K;
long double dp[50000 + 5], ar[20000 + 5], ps[20000 + 5];

void solve(int x) {
	int smaller_than = upper_bound(ar, ar + N, dp[x - 1]) - ar;
	int rest_sum = ps[smaller_than];
	dp[x] = (rest_sum + dp[x - 1] * smaller_than) / N;
}

void work() {
	cin >> N >> K;
	dp[0] = 0;
	for(int i = 0; i < N; i++) {
		cin >> ar[i];
		dp[0] += ar[i];
	}
	for(int i = N; i >= 0; i--) {
		ps[i] = 0;
	}
	sort(ar, ar + N);
	for(int i = N - 1; i >= 0; i--) {
		ps[i] = ps[i + 1] + ar[i];
	}
	dp[0] /= N;
	for(int i = 1; i <= K; i++) {
		solve(i);
	}
}

int main() {
	int tes;
	cin >> tes;
	for(int cas = 1; cas <= tes; cas++) {
		work();
		cout << "Case #" << cas << ": " << fixed << setprecision(10) << dp[K] << "\n";
	}	
}