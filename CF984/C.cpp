#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

long long Q, p, q, b;

long long GCD(long long a, long long b) {
	return a == 0 ? b : GCD(b % a, a);
}

const string FINITE = "Finite\n";
const string INFINITE = "Infinite\n";

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> Q;
	while(Q--) {
		cin >> p >> q >> b;
		
		p = GCD(p, q);
		q /= p;

		p = GCD(q, b);
		if(q == 1) {
			cout << FINITE;
		}
		else if(p == 1) {
			cout << INFINITE;
		}
		else {
			while((q % p) == 0 && p > 1) {
				q /= p;
				p = GCD(p, q);
			}
			if(q != 1) {
				cout << INFINITE;
			}
			else {
				cout << FINITE;
			}
		}
	}
}