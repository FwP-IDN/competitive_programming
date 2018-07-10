#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define f first
#define s second

// struct SuffixArrayClass {
	string str;
	static const int logmax = 20;
	static const int maxn = 100000;
	int RA[logmax][maxn + 5];
	pair<pair<int, int>, int> xx[maxn + 5], yy[maxn + 5];
	int cnt[maxn + 5];
	int LCP[maxn + 5];
	int SA[maxn + 5];
	ll has;
	int kiri[maxn + 5], kanan[maxn + 5];

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

	void make_lcp() {
		LCP[0] = 0;
		for(int i = 1; i < (int)str.length(); i++) {
			int a = SA[i - 1];
			int b = SA[i];
			int &ans = LCP[i];
			for(int j = logmax - 1; j >= 0; j--) {
				if(RA[j][a] == RA[j][b]) {
					ans += (1 << j);
					a += (1 << j);
					b += (1 << j);
				}
			}
		}
	}

	void solve() {
		kiri[0] = 0;
		for(int i = 1; i < (int)str.length(); i++) {
			int now = i;
			while(true) {
				if(now == 0) {
					break;
				}
				if(LCP[now - 1] >= LCP[i]) {
					now = kiri[now - 1];
				}
				else {
					break;
				}
			}
			kiri[i] = now;
		}

		kanan[(int)str.length() - 1] = (int)str.length() - 1;
		for(int i = (int)str.length() - 2; i >= 0; i--) {
			int now = i;
			while(true) {
				if(now == (int)str.length() - 1) {
					break;
				}
				if(LCP[now + 1] >= LCP[i]) {
					now = kanan[now + 1];
				}
				else {
					break;
				}
			}
			kanan[i] = now;
		}
		has = (int)str.length();
		for(int i = 0; i < (int)str.length(); i++) {
			has = max(has, (ll)(kanan[i] - kiri[i] + 2) * LCP[i]);
		}
	}
// };

int main() {
	SuffixArrayClass S = SuffixArrayClass();
	cin >> S.str;
	S.make_suffix_array();
	S.make_lcp();
	S.solve();
	cout << S.has << "\n";
}