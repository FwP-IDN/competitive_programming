#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ll k, d, t;
	cin >> k >> d >> t;
	//urus hitam putih
	ld tim = 0;
	ll nyawa = t * 2;
	ll sekaliNyawa = k * 2 + ((d - (k % d)) % d) ;
	ll sekaliTim = ((k + d - 1) / d) * d;
	tim = (nyawa / sekaliNyawa) * sekaliTim;
	nyawa %= sekaliNyawa;
	// cout << sekaliNyawa << "   " << sekaliTim << "\n";
	// cout << tim << "\n";
	// cout << nyawa << "\n";


	// tambah si hitam
	if(nyawa) {
		if(nyawa <= k * 2) {
			tim += ((double)nyawa / 2);
			nyawa = 0;
		}
		else {
			tim += k;
			nyawa -= k * 2;
		}
	}

	// tambah putih
	if(nyawa) {
		tim += (nyawa);
	}
	cout << fixed << setprecision(1) << tim << "\n";
}