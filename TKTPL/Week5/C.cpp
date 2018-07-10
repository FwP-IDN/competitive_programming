#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000000;

int p[maxn + 5];
int n;
string str;

int main() {
	cin >> n;
	cin >> str;
	p[0] = 0;
	for(int i = 1; i < n; i++) {
		int j = p[i - 1];
		while(j > 0 && str[i] != str[j]) {
			j = p[j - 1];
		}
		if(str[i] == str[j]) {
			j++;
		}
		p[i] = j;
	}
	cout << n - p[n - 1] << "\n";
}