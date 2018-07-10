#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;


struct StructLine {
	bool bisa = true;
	int N;
	map<pair<int, int>, int> gradCount;
	static const int MAXN = 100000;
	int x[MAXN + 5], y[MAXN + 5];

	void read() {
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
		}
	}

	int gcd(int a, int b) {
		a = abs(a); b = abs(b);
		if(a > b) swap(a, b);
		return a == 0 ? b : gcd(b % a, a);
	}

	void norm(int &a, int &b) {
		if(a < 0) {
			a = -a;
			b = -b;
		}
		else if(a == 0) {
			b = abs(b);
		}
	}

	pair<int, int> findGrad(int x1, int y1, int x2, int y2, int &rx, int &ry) {
		ry = y2 - y1;
		rx = x2 - x1;
		int gg = gcd(rx, ry);
		// if(gg == 0) {
		// 	cout << rx << " " << ry << "   " << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
		// 	cout << "loh\n";
		// }
		ry /= gg;
		rx /= gg;
		norm(rx, ry);
		return mp(rx, ry);
	}

	void record_grad() {
		for(int i = 1; i < N; i++) {
			int gx, gy;
			findGrad(x[0], y[0], x[i], y[i], gx, gy);
			gradCount[mp(gx, gy)]++;
		}
	}

	void solve() {
		if(gradCount.size() <= 2) {
			cout << "YES\n";
			return;
		}
		int maxi = 0;
		for(map<pair<int, int>, int>::iterator it = gradCount.begin(); it != gradCount.end(); it++) {
			if(maxi > 1 && it ->s > 1) {
				cout << "NO\n";
				return;
			}
			// cout << it -> f.f << " :: " << it -> f.s << "\n";
			maxi = max(maxi, it -> s);
		}

		pair<int, int> i_grad;
		for(map<pair<int, int> , int>::iterator it = gradCount.begin(); it != gradCount.end(); it++) {
			if(maxi == it ->s) {
				i_grad = it -> f;
			}
		}

		int sz = N;
		N = 0;
		int pivx = x[0], pivy = y[0];
		int dumx, dumy;
		for(int i = 1; i < sz; i++) {
			if(i_grad != findGrad(pivx, pivy, x[i], y[i], dumx, dumy)) {
				x[N] = x[i];
				y[N] = y[i];
				N++;
			}
		}
		gradCount.clear();
		record_grad();
		if(gradCount.size() <= 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

} L;

int main() {
	L.read();
	L.record_grad();
	L.solve();
}