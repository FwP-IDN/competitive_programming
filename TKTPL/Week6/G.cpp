#include<bits/stdc++.h>
using namespace std;

struct StructAdHoc {
	static const int maxn = 100000;
	string str;
	int pref[maxn + 5];
	int has;
	
	void read() {
		cin >> str;
	}

	void flip() {
		if(str[(int)str.length() / 2] == '1') {
			for(int i = 0; i < (int)str.length(); i++) {
				str[i] ^= 1;
			}
		}
		for(int i = 0; i < (int)str.length(); i++) {
			pref[i + 1] = pref[i] + str[i] - '0';
		}
	}

	void solve() {
		int aw = 1, ak = (int)str.length();
		has = (int)str.length();
		while(pref[aw - 1] != pref[ak]) {
			has--;
			aw++;
			ak--;
		}
	}

	void print() {
		cout << has << "\n";
	}

} A;

int main() {
	A.read();
	A.flip();
	A.solve();
	A.print();
}