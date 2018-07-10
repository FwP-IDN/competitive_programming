#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
const int maxn = 100000;
const int logmax = 20;
	
string str;
pair<pair<int, int>, int> xx[maxn + 5], yy[maxn + 5];
int RA[logmax][maxn + 5];
int cnt[maxn + 5];
int SA[maxn + 5];

void counting_sort() {
	int sz = max(30, (int)str.length());
	for(int k = 0; k <= sz; k++) {
		cnt[k] = 0;
	}
	for(int i = 0; i < (int)str.length(); i++) {
		int k = xx[i].f.s;
		cnt[k]++;
	}
	for(int k = 1; k <= sz; k++) {
		cnt[k] += cnt[k - 1];
	}
	for(int i = (int)str.length() - 1; i >= 0; i--) {
		int k = xx[i].f.s;
		yy[--cnt[k]] = xx[i];
	}

	for(int k = 0; k <= sz; k++) {
		cnt[k] = 0;
	}
	for(int i = 0; i < (int)str.length(); i++) {
		int k = yy[i].f.f;
		cnt[k]++;
	}
	for(int k = 1; k <= sz; k++) {
		cnt[k] += cnt[k - 1];
	}
	for(int i = (int)str.length() - 1; i >= 0; i--) {
		int k = yy[i].f.f;
		xx[--cnt[k]] = yy[i];
	}
}

void testing() {
	for(int i = 0; i < (int)str.length(); i++) {
		cout << i << ". ";
		for(int j = SA[i]; j < (int)str.length(); j++) {
			cout << str[j];
		}
		cout << "\n";
	}
}

void printRA(int x) {
	for(int i = 0; i < (int)str.length(); i++) {
		cout << RA[x][i] << " ";
	}
	cout << "\n";
}

void make_suffix_array() {
		for(int j = 0; j < (int)str.length(); j++) {
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

int parse(string &wrd, int olap) {
	int i;
	for(i = 0; i < (int)wrd.length() && i + olap < str.length(); i++) {
		if(wrd[i] < str[i + olap]) {
			return -1;
		}
		else if(wrd[i] > str[i + olap]) {
			return 1;
		}
	}
	if(i < (int)wrd.length()) {
		return 1;
	}
	return 0;
}

string getFrom(int aw) {
	string ret = "";
	for(int i = aw; i < (int)str.length(); i++) {
		ret += str[i];
	}
	return ret;
}

void getMore(string &wrd) {
	// first => index jawaban
	// second => 0 -> terusin aja, 1 -> nex
	int le = 0, ri = (int)str.length() - 1;
	int pos = (int)str.length(), last_parse;
	while(le <= ri) {
		int mid = (le + ri) >> 1;
		// cout << getFrom(SA[mid]) << " " << parse(wrd, SA[mid]) << "\n";
		int cmp = parse(wrd, SA[mid]);
		if(cmp <= 0) {
			pos = min(pos, mid);
			if(pos == mid) last_parse = cmp;
			ri = mid - 1;
		}
		else if(cmp > 0) {
			le = mid + 1; 
		}
	}
	string ret;
	if(pos == (int)str.length()) {
		cout << "-1\n";
		return;
	}
	if(parse(wrd, SA[pos]) == 0) {
		if(SA[pos] + (int)wrd.length() == (int)str.length()) {
			pos++;
		}
	}
	if(pos == (int)str.length()) {
		cout << "-1\n";
		return;
	}
	ret = "";
	int i;
	for(i = 0; i < (int)wrd.length() && i + SA[pos] < (int)str.length() && wrd[i] == str[i + SA[pos]]; i++) {
		cout << str[i + SA[pos]];
	}		cout << str[i + SA[pos]] << "\n";
	return; 
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> str;
	make_suffix_array();
	int q; string word;
	cin >> q;
	while(q--) {
		cin >> word;
		getMore(word);
	}
}