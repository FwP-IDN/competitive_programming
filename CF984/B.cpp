#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 100;
int N, M;
int ar[MAXN + 5][MAXN + 5];
char kar;

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> kar;
			if(kar == '.') {
				ar[i][j] = 0;
			}
			else if(kar == '*') {
				ar[i][j] = -1;
			}
			else {
				ar[i][j] = kar - '0';
			}
		}
	}
	bool bisa = true;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(ar[i][j] == -1) {
				continue;
			}
			int cnt = 0;
			for(int i2 = i - 1; i2 <= i + 1; i2++) {
				for(int j2 = j - 1; j2 <= j + 1; j2++) {
					if(ar[i2][j2] == -1) {
						cnt++;
					}
				}
			}
			if(ar[i][j] != cnt) {
				bisa = false;
			}
		}
	}
	if(bisa) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}