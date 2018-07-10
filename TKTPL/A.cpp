#include<bits/stdc++.h>
using namespace std;

#define maxn 100000

int ar[maxn + 5];
int _front[maxn + 5];
int _back[maxn + 5];

int main() {
	int n;
	scanf("%d", &n);
	ar[n + 1] = INT_MAX;
	_back[n + 1] = ar[n + 1];
	ar[0] = INT_MIN;
	_front[0] = ar[0];
	for(int i = 1; i <= n; i++) {
		scanf("%d", ar + i);
		_front[i] = max(_front[i - 1], ar[i]);
	}
	for(int i = n; i >= 1; i--) {
		_back[i] = min(_back[i + 1], ar[i]);
	}
	int has = 0;
	for(int i = 1; i <= n; i++) {
		if(_front[i - 1] <= ar[i] && ar[i] <= _back[i + 1]) {
			has++;
		}
	}
	printf("%d\n", has);
}