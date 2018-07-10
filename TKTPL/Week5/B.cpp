#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

const int maxn = 100000;

int pu[maxn + 5];
pair<int, int> x[maxn + 5], y[maxn + 5], z[maxn + 5];
pair<int, pair<int, int> > edge[3 * maxn + 15];

int fp(int nod) {
	if(nod == pu[nod]) {
		return nod;
	}
	return pu[nod] = fp(pu[nod]);
}

bool gabung(int a, int b) {
	int aa = fp(a);
	int bb = fp(b);
	if(aa == bb) {
		return false;
	}
	pu[bb] = aa;
	return true;
}

int main() {
	ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i].f >> y[i].f >> z[i].f;
		x[i].s = y[i].s = z[i].s = i;
	}
	for(int i = 0; i < n; i++) {
		pu[i] = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	sort(z, z + n);
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		edge[cnt++] = mp(x[i].f - x[i - 1].f, mp(x[i].s, x[i - 1].s));
	}
	for(int i = 1; i < n; i++) {
		edge[cnt++] = mp(y[i].f - y[i - 1].f, mp(y[i].s, y[i - 1].s));
	}
	for(int i = 1; i < n; i++) {
		edge[cnt++] = mp(z[i].f - z[i - 1].f, mp(z[i].s, z[i - 1].s));
	}
	sort(edge, edge + cnt);
	long long has = 0;
	for(int i = 0; i < cnt; i++) {
		if(gabung(edge[i].s.f, edge[i].s.s)) {
			has += (long long)edge[i].f;
		}
	}
	cout << has << "\n";
}