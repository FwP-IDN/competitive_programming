#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int ar[maxn + 5];
int br[maxn + 5];
string str;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	cin >> str;
	int idx = 0;
	for(char x : str) {
		br[++idx] = x - '0';
	}
	int L = -1000000000, R = 1000000000;
	for(int i = 5; i <= n; i++) {
		if(br[i] == 0 && br[i - 1] == 1) {
			// array kebesaran
			for(int j = i - 4; j <= i; j++) {
				R = min(R, ar[j] - 1);
			}
		}
		else if(br[i] == 1 && br[i - 1] == 0) {
			// array kekecilan
			for(int j = i - 4; j <= i; j++) {
				L = max(L, ar[j] + 1);
			}
		}
	}
	// if(L == 1000000001 && R == -1000000001) {
	// 	L = -L + 1;
	// 	R = -R - 1;
	// }
	cout << L << " " << R << "\n";
}