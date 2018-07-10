#include<bits/stdc++.h>
using namespace std;

map<string, int> karyawanUnik;
int banyakKaryawanUnik = 0;
vector<string> ans;
string str;
int N;


int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> str;
		if(karyawanUnik.count(str)) {
			continue;
		}
		karyawanUnik[str] = banyakKaryawanUnik++;
	}
	ans.resize((int)karyawanUnik.size());
	map<string, int>::iterator it;
	for(it = karyawanUnik.begin(); it != karyawanUnik.end(); it++) {
		ans[it -> second] = it -> first;
	}
	cout << ans.size() << "\n";
	cout << ans[0];
	for(int i = 1; i < (int)ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << "\n";
}