#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;


int main() {
	int cnt[1005];
	memset(cnt, 0, sizeof(cnt));
	int M, N, A;
	cin >> M >> N;
	while(N--) {
		cin >> A;
		cnt[A]++;
	}
	int has = INT_MAX;
	for(int i = 1; i <= M; i++) {
		has = min(has, cnt[i]);
	}
	cout << has << "\n";
}