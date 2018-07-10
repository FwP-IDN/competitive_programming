#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;


const int MAXN = 100000;

int N, K;
int inpa[MAXN + 5], inpt[MAXN + 5];
ll pref[MAXN + 5];

int main() {
	cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		cin >> inpa[i];
	}
	for(int i = 1; i <= N; i++) {
		cin >> inpt[i];
	}
	ll has = 0;
	for(int i = 1; i <= N; i++) {
		has += (ll)inpa[i] * inpt[i];
	}
	for(int i = 1; i <= N; i++) {
		pref[i] = pref[i - 1];
		if(inpt[i] == 0) {
			pref[i] += (ll)inpa[i];
		}
	}
	ll tam = 0;
	for(int i = K; i <= N; i++) {
		tam = max(tam, pref[i] - pref[i - K]);
	}
	cout << has + tam << "\n";
}