#include<bits/stdc++.h>
using namespace std;


#define f first
#define s second
string ss, tt;
map<char, int> pet;
int n, k;
char charIn[26];


void compose(){
	for(char x : ss) {
		pet[x] = 0;
	}
	int idx = 0;
	for(map<char, int> ::iterator it = pet.begin(); it != pet.end(); it++) {
		charIn[idx] = it -> f;
		it -> s = idx++;
	}
}

void case1() {
	tt = ss;
	for(int i = n; i < k; i++) {
		tt += charIn[0];
	}
}

void case2() {
	int ps = pet.size();
	// cout << ps << "\n";
	vector<int> vev(k);
	for(int i = 0; i < k; i++) {
		vev[i] = pet[ss[i]];
	}
	vev[k - 1]++;
	for(int i = k - 1; i >= 1; i--) {
		vev[i - 1] += vev[i] / ps;
		vev[i] %= ps;
	}
	for(int i = 0; i < k; i++) {
		tt += charIn[vev[i]];
	}
}

int main() {
	cin >> n >> k;
	cin >> ss;
	compose();
	if(k > n) {
		case1();
	}
	else {
		case2();
	}
	cout << tt << "\n";
}