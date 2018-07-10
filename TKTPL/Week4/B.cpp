#include<bits/stdc++.h>
using namespace std;

const int se7 = 10000000;
const int se5 = 100000;

int dd, sep[8], dp[se7];
string str, wrd;

int toInt(string mas) {
	int ret = 0;
	for(char x : mas) {
		ret = ret * 10 + x - '0';
	}
	return ret;
}

string toStr(int mas) {
	string ret;
	ret.resize(dd);
	for(int i = dd - 1; i >= 0; i--) {
		ret[i] = char((mas % 10) + '0');
		mas /= 10;
	}
	return ret;
}

void prekom() {
	sep[0] = 1;
	for(int i = 1; i < 8; i++) {
		sep[i] = sep[i - 1] * 10;
	}
}

int main() {
	prekom();
	memset(dp, -1, sizeof(dp));
	int has = 0; int Q;
	cin >> Q;
	while(Q--) {
		cin >> str;
		dd =(int) str.length();
		wrd = str;
		int now = toInt(str);
		dp[now] = 0;
		for(int i = 0; i < dd; i++) {
			for(char j = '0'; j <= '9'; j++) {
				wrd[i] = j;
				int diff = abs(j - str[i]);
				int prev = toInt(wrd);
				if(dp[prev] != -1) {
					dp[now] = max(dp[now], dp[prev] + diff);
				}
			}
			wrd[i] = str[i];
		}
		has = max(has, dp[now]);
	}
	cout << has << "\n";
}