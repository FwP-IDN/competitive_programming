#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100000;

int N;
int has = 0;
int cnt = 0;
int cas = 0;

int vx[MAXN + 5];
int vy[MAXN + 5];
bool udah[MAXN + 5];
int nx[MAXN + 5];
int ny[MAXN + 5];
set<pii> hass;

int max_b(int aw, int ak) {
	int v = ak - aw;
	if(v > has) {
		has = v;
		cnt = 1;
		// cout << aw << " :: " << ak << "\n";
		hass.insert(mp(aw, ak));
	}
	else if(v == has) {
		if(!hass.count(mp(aw, ak))) {
			cnt++;
			hass.insert(mp(aw, ak));
			// cout << aw << " :: " << ak << "\n";
		}
	}
	return max(has, v);
}

void telx() {
	for(int i = 0; i < N; i++) {
		udah[i] = false;
	}
	for(int i = 0; i < N; i++) {
		int x = vx[i];
		if(udah[i]) {
			continue;
		}
		if(nx[i] == N - 1) {
			has = max_b(i, N);
			for(int j = i; j < N; j++) {
				udah[i] = true;
			}
			break;
		}
		int y = vy[nx[i] + 1];
		// cout << "x y " << x << " " << y << " " << ny[3] <<"\n";
		int j = nx[i] + 1;
		for(int k = i; k < j; k++) {
			udah[k] = true;
		}
		while(j < N) {
			if(vy[j] != y) {
				has = max_b(i, j);
				break;
			}
			j = ny[j] + 1;
			if(vx[j] != x) {
				has = max_b(i, j);
				break;
			}
			for(int k = j; k < nx[j] + 1; k++) {
				udah[k] = true;
			}
			j = nx[j] + 1;
		}
		has = max_b(i, j);
	}
}

void tely() {
	for(int i = 0; i < N; i++) {
		udah[i] = false;
	}
	for(int i = 0; i < N; i++) {
		int y = vy[i];
		if(udah[i]) {
			continue;
		}
		if(ny[i] == N - 1) {
			has = max_b(i, N);
			for(int j = i; j < N; j++) {
				udah[i] = true;
			}
			break;
		}
		int x = vx[ny[i] + 1];
		int j = ny[i] + 1;
		for(int k = i; k < j; k++) {
			udah[k] = true;
		}
		while(j < N) {
			if(vx[j] != x) {
				has = max_b(i, j);
				break;
			}
			j = nx[j] + 1;
			if(vy[j] != y) {
				has = max_b(i, j);
				break;
			}
			for(int k = j; k < ny[j] + 1; k++) {
				udah[k] = true;
			}
			j = ny[j] + 1;
		}
		has = max_b(i, j);
	}
}

void solve_all() {
	has = 0;
	hass.clear();
	cin >> N;
	int dd, aa, bb;
	for(int i = 0; i < N; i++) {
		cin >> dd >> aa >> bb;
		vx[i] = dd + aa;
		vy[i] = dd - bb;
		nx[i] = i;
		ny[i] = i;
	}
	for(int i = N - 2; i >= 0; i--) {
		if(vx[i] == vx[i + 1]) {
			nx[i] = nx[i + 1];
		}
		if(vy[i] == vy[i + 1]) {
			ny[i] = ny[i + 1];
		}
	}

	telx();
	tely();

	// for(int i = 0; i < N; i++) {
	// 	cout << vx[i] << ", " << vy[i] << "\n";
	// }

	cout << "Case #" << ++cas << ": " << has << " " << cnt << "\n";
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		solve_all();
	}	
}