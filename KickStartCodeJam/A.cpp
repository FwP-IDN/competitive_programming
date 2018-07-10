#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct AdHoc {
	string str;

	void add_front_to_even(string &ss, int end_idx) {
		for(int i = end_idx - 1; i >= 0; i--) {
			if(ss[i] == '8') {
				ss[i] = '0';
			}
			else {
				ss[i] += 2;
				break;
			}
		}
	}

	ll reduce(string &a, string &b) {
		ll ret = 0;
		for(int i = 0; i < (int)a.length(); i++) {
			ret = ret * 10 + a[i] - b[i];
		}
		return ret;
	}

	ll bigger() {
		string other = str;
		int firstOdd;
		for(firstOdd = 0; firstOdd < (int)str.length(); firstOdd++) {
			if(((int)str[firstOdd] & 1)) {
				break;
			}
		}
		if(firstOdd == (int)str.length()) {
			return 0;
		}
		if(other[firstOdd] == '9') {
			add_front_to_even(other, firstOdd);
			other[firstOdd] = '0';
		}
		else other[firstOdd]++;
		for(int i = firstOdd + 1; i < (int)other.length(); i++) {
			other[i] = '0';
		}
		return reduce(other, str);
	}

	ll smaller() {
		string other = str;
		int firstOdd;
		for(firstOdd = 0; firstOdd < (int)str.length(); firstOdd++) {
			if((int)str[firstOdd] & 1) {
				break;
			}
		}
		if(firstOdd == (int)str.length()) {
			return 0;
		}
		other[firstOdd]--;
		for(int i = firstOdd + 1; i < (int)other.length(); i++) {
			other[i] = '8';
		}
		return reduce(str, other);
	}

} A;

int main() {
	int tes;
	cin >> tes;
	for(int cas = 1; cas <= tes; cas++) {
		cin >> A.str;
		A.str = "0" + A.str;
		cout << "Case #" << cas << ": " << min(A.bigger(), A.smaller()) << "\n";
	}
}