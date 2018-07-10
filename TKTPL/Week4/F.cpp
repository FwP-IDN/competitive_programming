#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;
string ans, wrd, str;
int p[maxn];

int main() {
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin >> wrd) {
		ans = wrd;
		reverse(wrd.begin(), wrd.end());
		str = wrd + "$" + ans;
		p[0] = 0;
		for(int i = 1; i < str.length(); i++) {
			int x = p[i - 1];
			while(x > 0 && str[x] != str[i]) {
				x = p[x - 1];
			}
			if(str[x] == str[i]) {
				x++;
			}
			p[i] = x;
		}
		// for(int i = 0; i < str.length(); i++) {
		// 	cout << p[i] << " ";
		// }
		for(int i = p[str.length() - 1]; i < wrd.size(); i++) {
			ans += wrd[i];
		}
		cout << ans << "\n";
	}
}