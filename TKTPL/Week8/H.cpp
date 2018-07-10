#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ar[50];

ll GCD(ll A, ll B) {
	return A == 0 ? B : GCD(B % A, A);
}

int main() {
	int tes, N, n;
	ll num1, num2, mini, temp;
	scanf("%d", &tes);
	for(int cas = 1; cas <= tes; ++cas) {
		scanf("%d", &N);
		num1 = 0; 
		num2 = 0;
		while(N-- ) {
			mini = LLONG_MAX;
			scanf("%d", &n);
			for(int i = 0; i < n; i++) {
				scanf("%lld", ar + i);
				mini = min(mini, ar[i]);
			}
			num2 += mini;
			for(int i = 0; i < n; i++) {
				ar[i] -= mini;
			}
			temp = 0;
			for(int i = 0; i < n; i++) {
				temp = GCD(temp, ar[i]);
			}
			num1 = GCD(num1, temp);
		}
		printf("Case #%d: %lld\n", cas, GCD(num1, num2));
	}
}