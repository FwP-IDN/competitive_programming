#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define f first
#define s second

// struct SuffixArrayClass {
	string str;
	static const int logmax = 20;
	static const int maxn = 200000;
	int RA[logmax][maxn + 5];
	pair<pair<int, int>, int> xx[maxn + 5], yy[maxn + 5];
	int cnt[maxn + 5];
	int LCP[maxn + 5];
	int SA[maxn + 5];
	ll has;
	int nex[2][maxn + 5];
	int batas;

	void counting_sort() {
		for(int k = 0; k <= max(30, (int)str.length()); k++) {
			cnt[k] = 0;
		}
		for(int i = 0; i < (int)str.length(); i++) {
			cnt[xx[i].f.s]++;
		}
		for(int k = 1; k <= max(30, (int)str.length()); k++) {
			cnt[k] += cnt[k - 1];
		}
		for(int i = (int)str.length() - 1; i >= 0; i--) {
			int k = xx[i].f.s;
			yy[--cnt[k]] = xx[i];
		}

		for(int k = 0; k <= max(30, (int)str.length()); k++) {
			cnt[k] = 0;
		}
		for(int i = 0; i < (int)str.length(); i++) {
			cnt[yy[i].f.f]++;
		}
		for(int k = 1; k <= max(30, (int)str.length()); k++) {
			cnt[k] += cnt[k - 1];
		}
		for(int i = (int)str.length() - 1; i >= 0; i--) {
			int k = yy[i].f.f;
			xx[--cnt[k]] = yy[i];
		}
	}

	string getFrom(int st) {
		string ret = "";
		for(int i = st; i < (int)str.length(); i++) {
			ret += str[i];
		}
		return ret;
	}

	void testing() {
		for(int i = 0; i < (int)str.length(); i++) {
			cout << i << "  " << SA[i] << " " << getFrom(SA[i]) << "\n";
		}
		return;
	}

	void printRA(int x) {
		cout << "RA " << x << ":";
		for(int j = 0; j < (int)str.length(); j++) {
			cout << " " << RA[x][j];
		}
		cout << "\n";
	}

	void printxx(int x) {
		cout << "xx " << x << ":";
		for(int j = 0; j < (int)str.length(); j++) {
			cout << " " << xx[j].f.f << ","  << xx[j].f.s;
		}
		cout << "\n";
	}

	void make_suffix_array() {
			for(int j = 0; j < str.length(); j++) {
				RA[0][j] = str[j] - 'a' + 1;
			}
		for(int i = 1; i < logmax; i++) {
			for(int j = 0; j < (int)str.length(); j++) {
				xx[j].f.f = RA[i - 1][j];
				int span = (1 << (i - 1));
				if(j + span < (int)str.length()) {
					xx[j].f.s = RA[i - 1][j + span];
				}
				else {
					xx[j].f.s = 0;
				}
				xx[j].s = j;
			}
			// printxx(i);
			counting_sort();
			for(int j = 0; j < (int)str.length(); j++) {
				int k = xx[j].s;
				int ans = j + 1;
				if(j > 0) {
					int prev_k = xx[j - 1].s;
					if(xx[j].f == xx[j - 1].f) {
						ans = RA[i][prev_k];
					}
				}
				RA[i][k] = ans;
			}
			// printRA(i);
		}
		for(int j = 0; j < (int)str.length(); j++) {
			int k = RA[logmax - 1][j];
			SA[k - 1] = j;
		}
		// testing();
	}

	int get_lcp(int id_a, int id_b) {
		if(min(id_a, id_b) == -1) {
			return 0;
		}
		int a = SA[id_a], b = SA[id_b];
		int ret = 0;
		for(int j = logmax - 1; j >= 0; j--) {
			if(RA[j][a] == RA[j][b]) {
				ret += (1 << j);
				a += (1 << j);
				b += (1 << j);
			}
		}
		// cout << SA[id_a] << " -- " << SA[id_b] << " " << ret << "\n";
		return ret;
	}

	void solve() {
		nex[0][(int)str.length() - 1] = -1;
		nex[1][(int)str.length() - 1] = -1;
		for(int i = (int)str.length() - 2; i >= 0; i--) {
			nex[0][i] = nex[0][i + 1];
			nex[1][i] = nex[1][i + 1];
			nex[(SA[i] >= batas)][i] = i;
		}
		for(int i = 0; i < (int)str.length(); i++) {
			int los = max(get_lcp(i - 1, i), get_lcp(nex[0][i], nex[1][i]));
			has -= los;
			// cout << i << ". " << los << "\n";
		}
	}
// };

int main() {
	string A, B;
	cin >> A >> B;
	has = (ll)(A.length() * (A.length() + 1) / 2) + (ll)(B.length() * (B.length() + 1) / 2);
	str = A + "{" + B;
	batas = A.length();
	make_suffix_array();
	solve();
	cout << has << "\n";
}