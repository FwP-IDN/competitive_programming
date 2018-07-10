#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 1000;

int ar[MAXN];

int N;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + N);
	cout << ar[(N - 1) / 2] << "\n";
}