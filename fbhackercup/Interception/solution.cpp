#include <bits/stdc++.h>
using namespace std;

string ans[] = {"0", "1\n0.0"};

void work() {
	static int cas = 0;
	int N;
	scanf("%d", &N);
	cout << "Case #" << ++cas << ": " << ans[N&1] << "\n";
	int dum;
	while(N--) {
		cin >> dum;
	}
	cin >> dum;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		work();
	}
	int dum;
	if(cin >> dum) {
		assert(false);
	}
}