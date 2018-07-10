#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int A = str.length(), B = 0;
	for(int i = 0; i < (int)str.length(); i++) {
		if(str[i] == 'o') {
			B++;
		}
	}
	if(B != 0 && A % B) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}