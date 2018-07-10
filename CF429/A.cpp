#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct AdHoc {
	static const int MAXN = 200000;
	int N;
	int ar[MAXN + 5], ans[MAXN + 5];
	pair<int, int> br[MAXN + 5];
	void read() {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &ar[i]);
		}
		for(int i = 0; i < N; i++) {
			scanf("%d", &br[i].f);
			br[i].s = i;
		}
	}

	void solve() {
		sort(br, br + N);
		reverse(br, br + N);
		sort(ar, ar + N);
		for(int i = 0; i < N; i++) {
			ans[br[i].s] = ar[i];
		}
	}

	void print() {
		for(int i = 0; i < N; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
} A;

int main() {
	A.read();
	A.solve();
	A.print();
}