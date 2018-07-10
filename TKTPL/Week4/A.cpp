#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100000;

class StringHashClass {
public :
	static const ll pp = 53;
	ll hh[maxn + 5];
	ll powp[maxn + 5];
	string str;
	ll change(char kar) {
		if((int)kar & 32) {
			// huruf kecil
			return kar - 'a';
		}
		else {
			// huruf besar
			return kar - 'A' + 26;
		}
	}
	void make_hash() {
		hh[0] = change(str[0]);
		powp[0] = 1;
		for(int i = 1; i < (int)str.length(); i++) {
			hh[i] = hh[i - 1] * pp + change(str[i]);
			powp[i] = powp[i - 1] * pp;
		}
	}

	ll getHash(int aw, int ak) {
		ll ret = hh[ak];
		if(aw > 0) {
			ret -= hh[aw - 1] * (powp[ak - aw + 1]);
		}
		// cout << "hash " << aw << "  " << ak << "  " << ret << "\n";
		return ret;
	}

	int getAns(int i, int j) {
		int le = -1;
		int ri = (int)str.length() - 1 - j;
		while(le < ri) {
			int mid = (le + ri + 1) >> 1;
			// cout << "; " << le << " " << mid << " " << ri << "\n";
			if(getHash(i, i + mid) == getHash(j, j + mid)) {
				le = mid;
			}
			else {
				ri = mid - 1;
			}
		}
		return le;
	}
};



int main() {
	StringHashClass S = StringHashClass();
	cin >> S.str;
	S.make_hash();
	int Q;
	cin >> Q;
	while(Q--) {
		int i, j;
		cin >> i >> j;
		cout << S.getAns(i, j) + 1 << "\n";	}
}