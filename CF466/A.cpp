#include<bits/stdc++.h>
using namespace std;

int pref[105];
int suff[105];

int n, d, A;


int main() {
	scanf("%d %d", &n, &d);
	while(n--) {
		scanf("%d", &A);
		pref[A]++;
		suff[A]++;
	}
	for(int i = 2; i <= 100; i++) {
		pref[i] += pref[i - 1];
	}
	for(int i = 99; i >= 1; i--) {
		suff[i] += suff[i + 1];
	}
	int has = INT_MAX;
	if(d == 100) {
		has = 0;
	}
	for(int i = 0; i + d + 2 <= 101; i++) {
		has = min(has, pref[i] + suff[i + d + 2]);
	}
	printf("%d\n", has);
}