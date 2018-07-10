#include<bits/stdc++.h>
using namespace std;

const int maxn = 500000;

#define ll long long
ll mod = (ll)1000000007;
ll pow2[maxn + 5], cnt_front_1[maxn + 5], cnt_front__[maxn + 5], cnt_back__[maxn + 5];
string str;

void prekom() {
	pow2[0] = 1;
	for(int i = 1; i < maxn + 5; i++) {
		pow2[i] = (pow2[i - 1] * 2) % mod;
	}
}

int main() {
	prekom();
	ll has, tam1, tam2;
	cin >> str;
	int n = (int)str.length();
	for(int i = 1; i < n; i++) {
		cnt_front_1[i] = cnt_front_1[i - 1];
		cnt_front__[i] = cnt_front__[i - 1];
		if(str[i - 1] == '1') {
			cnt_front_1[i]++;
		}
		else if(str[i - 1] == '?') {
			cnt_front__[i]++;
		}
	}
	for(int i = n - 2; i >= 0; i--) {
		cnt_back__[i] = cnt_back__[i + 1];
		if(str[i + 1] == '?') {
			cnt_back__[i]++;
		}
	}
	has = 0;
	for(int i = 0; i < n; i++) {
		if(str[i] == '1') {

		}
		else {
			// itung 1 di depan
			tam1 = (cnt_front_1[i] * pow2[cnt_back__[i] + cnt_front__[i]]) % mod;

			// itung ? in case dia jadi 1
			tam2 = (cnt_front__[i] * pow2[cnt_back__[i] + cnt_front__[i]]) % mod;
			tam2 *= (ll)500000004;
			tam2 %= mod;

			has = (has + tam1 + tam2) % mod;
		}
	}
	assert(has >= 0 && has < mod);
	cout << has << "\n";
}