#include<bits/stdc++.h>
using namespace std;

int ar[100];
long long ans[100001];
int pt[100];

set<int> sen;
set<int>::iterator it;

int main() {
	int N, M;
	ans[0] = 1;
	while(true) {
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) {
			return 0;
		}
		for(int i = 0; i < N; i++) {
			scanf("%d", ar + i);
			pt[i] = 0;
		}
		sort(ar, ar + N);
		sen.clear();
		sen.insert(-1);

	}
}