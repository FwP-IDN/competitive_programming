#include<bits/stdc++.h>
using namespace std;

#define maxn 100000
#define ll long long
#define f first
#define s second
#define pli pair<ll, int>
#define mp make_pair

ll has;
ll ar[maxn + 5];
ll dp[maxn + 5]; // nyimpen dp
ll sumE[maxn + 5];
priority_queue<pli, vector<pli>, greater<pli> > pq;

int main() {
	int n, c;
	cin >> n >> c;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	if(c > n) {
		has = 0;
		for(int i = 1; i <= n; i++) {
			has += ar[i];
		}
		cout << has << "\n";
		return 0;
	}
	if(c == 1) {
		cout << 0 << "\n";
		return 0;
	}
	ll sum = 0;
	for(int i = 1; i < c; i++) {
		dp[i] = dp[i - 1] + ar[i];
		sumE[i] = dp[i];
		pq.push(mp(ar[i], i));
		sum += ar[i];
	}
	for(int i = c; i <= n; i++) {
		pq.push(mp(ar[i], i));
		sum += ar[i];
		sum -= ar[i - c];
		while(pq.top().s <= i - c) {
			// cout << pq.top().f << "  " << pq.top().s << "  " << pq.size() << "\n";
			// string cuk;
			// cin >> cuk;
			pq.pop();
		}
		sumE[i] = sum - pq.top().f;
		dp[i] = min(ar[i] + dp[i - 1], sumE[i] + dp[i - c]);
	}
	cout << dp[n] << "\n";
}