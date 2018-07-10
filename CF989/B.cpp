#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

int N, P;
string str;

int main(int argc, char** argv) {
	cin >> N >> P;
	cin >> str;
	bool bisa = false;
	for(int i = 0; i < P; i++) {
		if(str[i] == '.') {
			if(i + P < N) {
				if(str[i + P] == '.') {
					str[i] = '0';
					str[i + P] = '1';
				}
				else {
					str[i] = '1' - str[i + P] + '0';
				}
				bisa = true;
			}
			else {
				str[i] = '1';
			}
		}
	}
	for(int i = P; i < N; i++) {
		if(str[i] == '.') {
			str[i] = '1' - str[i - P] + '0';
			bisa = true;
		}
	}
	for(char x : str) {
		assert(x != '.');
	}
	if(bisa) {
		cout << str << "\n";
	}
	else {
		cout << "No\n";
	}
}