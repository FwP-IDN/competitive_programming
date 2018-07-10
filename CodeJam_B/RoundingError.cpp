#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

vector<int> ar;
int cas = 0;

void solve_all() {
	int N, L, has = 0;
	cin >> N >> L;
	ar.resize(L);
	int rem = N;
	int mod = 2 * N;
	for(int i = 0; i < L; i++) {
		cin >> ar[i];
		rem -= ar[i];
		ar[i] *= 200;
		has += (ar[i] / mod);
		ar[i] %= mod;
	}
	// cout << "debug 1 " << has << "\n";
	sort(ar.begin(), ar.end());
	while(!ar.empty() && ar.back() >= N) {
		has++;
		ar.pop_back();
	}
	// cout << "debug 2 " << has << "\n";

	reverse(ar.begin(), ar.end());

	int each = 200 % mod;
	has += (200 / mod * rem);
	// cout << "debug 3 " << has << "\n";
	for(int i = 0; i < (int)ar.size() && rem > 0; i++) {
		while(ar[i] < N && rem > 0) {
			rem--;
			ar[i] += each;
		}
		if(ar[i] >= N) {
			has++;
		}
	}
	if(each > 0) {
		int mindip = (N + each - 1) / each;
		has += (rem / mindip);
	}
	// cout << "debug 4 " << has << "\n";
	cout << "Case #" << ++cas << ": " << has << "\n"; 
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		solve_all();
	}	
}